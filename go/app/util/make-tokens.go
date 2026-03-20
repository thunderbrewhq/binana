package util

import (
	"compress/gzip"
	"debug/macho"
	"encoding/json"
	"fmt"
	"os"
	"path/filepath"
	"slices"
	"strings"
	"time"

	"github.com/thunderbrewhq/binana/go/app"
	"github.com/thunderbrewhq/binana/go/app/util/dbutil"
	"github.com/thunderbrewhq/binana/go/db"
	"github.com/thunderbrewhq/binana/go/pdbconv"
	"github.com/thunderbrewhq/binana/go/stringrecovery"
)

type MakeTokenDatabaseParams struct {
	Source string
	Output string
	Format dbutil.DatabaseFormat
}

func MakeTokenDatabase(params *MakeTokenDatabaseParams) {
	var (
		tokens_database tokens_database
		err             error
	)
	if err = tokens_database.Open(params.Output, params.Format); err != nil {
		app.Fatal(err)
	}
	if err = tokens_database.make(params.Source); err != nil {
		app.Fatal(err)
	}
	if err = tokens_database.Close(); err != nil {
		app.Fatal(err)
	}
}

type tokens_database struct {
	sequence uint64
	writer   *dbutil.Writer[db.Token]
}

func (tokens_database *tokens_database) next_token_id() (id uint64) {
	id = tokens_database.sequence
	tokens_database.sequence++
	return
}

func (tokens_database *tokens_database) Open(name string, format dbutil.DatabaseFormat) (err error) {
	tokens_database.sequence = 1
	tokens_database.writer, err = dbutil.Open[db.Token](name, format)
	return
}

func (tokens_database *tokens_database) Close() (err error) {
	err = tokens_database.writer.Close()
	return
}

func (tokens_database *tokens_database) Write(token *db.Token) (err error) {
	tokens := []db.Token{*token}
	if err = tokens_database.writer.WriteEntries(tokens); err != nil {
		return
	}
	return
}

func (tokens_database *tokens_database) make_file_pdb(name string) (err error) {
	exe_name := strings.TrimSuffix(name, ".pdb") + ".exe"
	var base_address uint64
	base_address, err = get_exe_base_address(exe_name)
	if err != nil {
		return
	}

	fmt.Fprintln(os.Stderr, "[pdb]", name)
	var source_id string
	source_id, err = hash_file(name)
	if err != nil {
		return
	}
	fmt.Fprintln(os.Stderr, "[pdb]", source_id)
	// check for the existence of an alternate, .pdb.json.gz file
	_, err = os.Stat(name + ".json.gz")
	if err != nil {
		return
	}

	var (
		gzip_file   *os.File
		gzip_reader *gzip.Reader
	)
	gzip_file, err = os.Open(name + ".json.gz")
	if err != nil {
		return
	}

	var pdb pdbconv.ProgramDatabase
	gzip_reader, err = gzip.NewReader(gzip_file)
	json_decoder := json.NewDecoder(gzip_reader)

	if err = json_decoder.Decode(&pdb); err != nil {
		return
	}

	gzip_file.Close()

	var v pdb_token_visitor
	v.init(tokens_database, source_id, base_address)
	if err = v.visit_all(&pdb); err != nil {
		return
	}
	if err = v.write_tokens(); err != nil {
		return
	}

	return
}

func (tokens_database *tokens_database) write_string_token(source_id string, section_name string, address uint64, str string) (err error) {
	var db_token db.Token
	db_token.ID = tokens_database.next_token_id()
	db_token.Source = source_id
	db_token.Section = section_name
	db_token.Kind = db.OriginalStringToken
	db_token.Offset = fmt.Sprintf("%X", address)

	db_token.Names = append(db_token.Names, db.TokenName{db.OriginalName, str})

	// detect if this is a mangled type identifier
	if looks_mangled(str) {
		demangled, err := demangle(str)
		if err == nil {
			db_token.Names = append(db_token.Names, db.TokenName{db.DemangledName, demangled})
		}
	}

	err = tokens_database.Write(&db_token)
	return
}

func (tokens_database *tokens_database) make_file_pe(name string) (err error) {
	var id string
	id, err = hash_file(name)
	if err != nil {
		return
	}
	err = stringrecovery.RecoverFile(name, func(section_name string, address uint64, str string) {
		fmt.Fprintf(os.Stderr, "[pe] string found: %s %08X %s\n", section_name, address, str)
		tokens_database.write_string_token(id, section_name, address, str)
	})
	return
}

func (tokens_database *tokens_database) make_file_macho(name string) (err error) {
	fmt.Fprintln(os.Stderr, "[mach-o]", name)
	var source_id string
	source_id, err = hash_file(name)
	if err != nil {
		return
	}
	fmt.Fprintln(os.Stderr, "[mach-o]", source_id)
	var (
		file       *os.File
		macho_file *macho.File
	)
	file, err = os.Open(name)
	if err != nil {
		return
	}

	macho_file, err = macho.NewFile(file)
	if err != nil {
		return
	}
	_, dwarf_err := macho_file.DWARF()
	if dwarf_err == nil {
		fmt.Fprintln(os.Stderr, "DWARF!")
		time.Sleep(5 * time.Second)
	}
	fmt.Fprintln(os.Stderr, "[mach-o]", "cpu", macho_file.FileHeader.Cpu)
	fmt.Fprintln(os.Stderr, "[mach-o]", "loads:")
	// for _, load := range macho_file.Loads {
	//	fmt.Fprintln(os.Stderr, "[mach-o]", load.String())
	// }
	fmt.Fprintln(os.Stderr, "[mach-o]", "sections:")
	for _, section := range macho_file.Sections {
		fmt.Fprintln(os.Stderr, "section", section.SectionHeader.Name)
	}

	if macho_file.Dysymtab != nil {
		fmt.Fprintln(os.Stderr, "[mach-o]", "does not contain a dysymtab")
	} else {
		fmt.Fprintln(os.Stderr, "[mach-o]", "dysymtab:")
	}

	var imported_symbols []string
	imported_symbols, err = macho_file.ImportedSymbols()
	if err != nil {
		return
	}
	if macho_file.Symtab == nil {
		fmt.Fprintln(os.Stderr, "[mach-o]", "does not contain a symtab")
	} else {
		fmt.Fprintln(os.Stderr, "[mach-o]", "symtab:")
		for _, sym := range macho_file.Symtab.Syms {
			imported := slices.Contains(imported_symbols, sym.Name)
			var section_name string
			if sym.Sect != 0 {
				section_name = macho_file.Sections[sym.Sect-1].SectionHeader.Name
			}
			if imported {
				fmt.Fprintf(os.Stderr, "[mach-o] imported %s %02x %s\n", section_name, sym.Type, sym.Name)
			} else {
				if sym.Name == "" {
					//	fmt.Fprintln(os.Stderr, "[mach-o]", "symbol has no name", "sect="+section_name, sym.Type, sym.Value, sym.Desc)
				} else {
					fmt.Fprintf(os.Stderr, "[mach-o] internal %s %02x %s\n", section_name, sym.Type, sym.Name)
					var token db.Token
					token.ID = tokens_database.next_token_id()
					token.Source = source_id
					token.Kind = db.OriginalSymbolToken
					token.Section = section_name
					token.Offset = fmt.Sprintf("%X", sym.Value)
					token.Names = append(token.Names, db.TokenName{db.OriginalName, sym.Name})

					if looks_mangled(sym.Name) {
						demangled, err := demangle(sym.Name)
						if err == nil {
							token.Names = append(token.Names, db.TokenName{db.DemangledName, demangled})
						}
					}

					tokens_database.Write(&token)
				}
			}
		}
	}

	file.Close()

	if err = stringrecovery.RecoverFile(name, func(section_name string, address uint64, str string) {
		fmt.Fprintf(os.Stderr, "[mach-o] string found: %s %08X %s\n", section_name, address, str)
		tokens_database.write_string_token(source_id, section_name, address, str)
	}); err != nil {
		return
	}

	return
}

func (tokens_database *tokens_database) make_file(name string) (err error) {
	switch filepath.Ext(name) {
	case ".macho":
		err = tokens_database.make_file_macho(name)
	case ".pdb":
		err = tokens_database.make_file_pdb(name)
	case ".exe":
		err = tokens_database.make_file_pe(name)
	}
	return
}

func (tokens_database *tokens_database) make_directory(name string) (err error) {
	var entries []os.DirEntry
	entries, err = os.ReadDir(name)
	if err != nil {
		return
	}

	for _, entry := range entries {
		if entry.IsDir() {
			if err = tokens_database.make_directory(filepath.Join(name, entry.Name())); err != nil {
				return
			}
		} else {
			if err = tokens_database.make_file(filepath.Join(name, entry.Name())); err != nil {
				return
			}
		}
	}

	return
}

func (tokens_database *tokens_database) make(name string) (err error) {
	var fi os.FileInfo
	fi, err = os.Stat(name)
	if err != nil {
		return
	}
	if fi.IsDir() {
		err = tokens_database.make_directory(name)
	} else {
		err = tokens_database.make_file(name)
	}
	return
}
