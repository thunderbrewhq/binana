package util

import (
	"bufio"
	"bytes"
	"fmt"
	"os"
	"os/exec"
	"path/filepath"
	"strconv"
	"strings"

	"github.com/thunderbrewhq/binana/go/app"
	"github.com/thunderbrewhq/binana/go/app/util/dbutil"
	"github.com/thunderbrewhq/binana/go/db"
)

type MakeSampleDatabaseParams struct {
	// A file name that corresponds to a tree of sample files.
	// Anything in this tree will be collected into the sample database
	Source string

	// The name of the file to write the database to
	Output string

	// Sets the format of the database file
	Format dbutil.DatabaseFormat

	// URLs that maps to the root of the sample tree hierarchy.
	// Used to generate a list of mirror URLs for sample binaries
	DirectMirrors []string

	// List of IPFS Gateway URLs
	// If not empty, a CID for the sample tree will be created,
	// Actually uploading anything in the sample tree, however,
	// is outside the scope of this tool
	IPFSGateways []string
}

type sample_database struct {
	writer        *dbutil.Writer[db.Sample]
	ipfs_tree_cid string
	buffer        []db.Sample
}

func (sample_database *sample_database) add(sample db.Sample) (err error) {
	sample_database.buffer = append(sample_database.buffer, sample)
	return
}

func (sample_database *sample_database) Close() (err error) {
	if err = sample_database.writer.WriteEntries(sample_database.buffer); err != nil {
		return
	}
	err = sample_database.writer.Close()
	return
}

func (sample_database *sample_database) make_sample_file(params *MakeSampleDatabaseParams, name, relative_name string) (err error) {
	var sample db.Sample
	// infer mime-type from extension
	switch filepath.Ext(name) {
	case ".exe":
		sample.MimeType = "application/vnd.microsoft.portable-executable"
	case ".pdb":
		sample.MimeType = "application/x-ms-pdb"
		// associate the PDB with its EXE
		sample_exe_name := strings.TrimSuffix(name, ".pdb") + ".exe"
		if _, err = os.Stat(sample_exe_name); err == nil {
			sample.Executable, err = hash_file(sample_exe_name)
			if err != nil {
				panic(err)
			}
		}
	case ".macho":
		sample.MimeType = "application/x-mach-binary"
	case ".elf":
		sample.MimeType = "application/x-executable"
	default:
		// don't care about this
		return
	}

	sample.ID, err = hash_file(name)
	if err != nil {
		panic(err)
	}

	// get the base filename
	base_name := filepath.Base(name)

	// split the base filename without its extension
	filename_components := strings.Split(strings.TrimSuffix(base_name, filepath.Ext(base_name)), "-")
	// now, parse the filename (these must be correctly named!)
	sample.Program = filename_components[0]
	sample.Version = filename_components[1]
	var build uint64
	build, err = strconv.ParseUint(filename_components[2], 0, 64)
	if err != nil {
		panic(err)
	}
	sample.Build = uint32(build)
	sample.OS = filename_components[3]
	sample.Arch = filename_components[4]

	// now, create various mirrors
	for _, direct_mirror := range params.DirectMirrors {
		sample.Mirrors = append(sample.Mirrors, db.SampleMirror{
			Kind: db.MirrorDirect,
			URL:  direct_mirror + relative_name,
		})
	}
	for _, ipfs_gateway := range params.IPFSGateways {
		sample.Mirrors = append(sample.Mirrors, db.SampleMirror{
			Kind: db.MirrorIPFS,
			URL:  ipfs_gateway + "/" + sample_database.ipfs_tree_cid + relative_name,
		})
	}

	// now write the sample

	if err = sample_database.add(sample); err != nil {
		return
	}
	return
}

func (sample_database *sample_database) make_tree(params *MakeSampleDatabaseParams, name, relative_name string) (err error) {
	var (
		tree_entries []os.DirEntry
	)

	tree_entries, err = os.ReadDir(name)
	if err != nil {
		return
	}

	for _, tree_entry := range tree_entries {
		if tree_entry.IsDir() {
			if err = sample_database.make_tree(params, name+"/"+tree_entry.Name(), relative_name+"/"+tree_entry.Name()); err != nil {
				return
			}
		} else {
			if err = sample_database.make_sample_file(params, name+"/"+tree_entry.Name(), relative_name+"/"+tree_entry.Name()); err != nil {
				return
			}
		}
	}

	return
}

func ipfs_generate_file_cid(name string) (cid string, err error) {

	// todo
	// use command:
	//   ipfs add -qr --only-hash .
	// inside the root of the sample tree
	// the last CID is the root of the tree

	var (
		wd string
	)
	wd, err = os.Getwd()
	if err != nil {
		return
	}
	err = os.Chdir(name)
	if err != nil {
		return
	}

	command := exec.Command("ipfs", "add", "-qr", "--only-hash", ".")
	var command_output bytes.Buffer
	command.Stdout = &command_output
	command.Run()
	if command.ProcessState.ExitCode() != 0 {
		os.Chdir(wd)
		err = fmt.Errorf("util: ipfs tool exited: %d", command.ProcessState.ExitCode())
		return
	}

	// Parse command Output
	command_output_scanner := bufio.NewScanner(&command_output)

	for command_output_scanner.Scan() {
		cid = command_output_scanner.Text()
	}

	err = os.Chdir(wd)

	return

}

func MakeSampleDatabase(params *MakeSampleDatabaseParams) {
	var (
		err             error
		sample_database sample_database
	)

	// if we want to generate IPFS links, start by getting the CID for the sample tree
	if len(params.IPFSGateways) != 0 {
		sample_database.ipfs_tree_cid, err = ipfs_generate_file_cid(params.Source)
		if err != nil {
			app.Fatal(err)
			return
		}
	}

	sample_database.writer, err = dbutil.Open[db.Sample](params.Output, params.Format)
	if err != nil {
		app.Fatal(err)
	}

	// make the root tree, with our params, the source as the first tree, and "" (root) as the relative path
	if err = sample_database.make_tree(params, params.Source, ""); err != nil {
		app.Fatal(err)
	}

	if err = sample_database.Close(); err != nil {
		app.Fatal(err)
	}
}
