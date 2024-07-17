package profile

import (
	"fmt"
	"io/fs"
	"os"
	"path/filepath"

	"github.com/thunderbrewhq/binana/go/symfile"
)

type Profile struct {
	Directory   string
	SymbolTable *symfile.InMemoryTable
}

func Open(profile_directory string) (profile *Profile, err error) {
	var dir fs.FileInfo
	dir, err = os.Stat(profile_directory)
	if err != nil {
		return
	}

	if !dir.IsDir() {
		err = fmt.Errorf("profile: game profile is not a directory")
		return
	}

	fmt.Println("Opening profile", profile_directory)

	profile = new(Profile)
	profile.Directory = profile_directory

	path_to_symbols_file := filepath.Join(profile_directory, "symbol", "main.sym")
	var symbols_file *os.File
	symbols_file, err = os.Open(path_to_symbols_file)
	if err != nil {
		return
	}

	profile.SymbolTable = new(symfile.InMemoryTable)

	if err = symfile.Load(profile.SymbolTable, symbols_file); err != nil {
		return
	}

	symbols_file.Close()

	//
	return
}
