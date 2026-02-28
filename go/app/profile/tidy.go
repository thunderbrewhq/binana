package profile

import (
	"os"
	"path/filepath"

	"github.com/thunderbrewhq/binana/go/app"
	"github.com/thunderbrewhq/binana/go/symbols"
)

type TidyParams struct {
	Profile string
}

func tidy_symbol_file(name string, params *TidyParams) (err error) {
	var symbol_table symbols.Table
	symbol_table.Init()
	if err = symbol_table.Load(name); err != nil {
		return
	}
	var f *os.File
	f, err = os.Create(name)
	if err != nil {
		return
	}
	if _, err = symbol_table.WriteTo(f); err != nil {
		f.Close()
		return
	}
	err = f.Close()
	return
}

func tidy_symbol_directory(name string, params *TidyParams) (err error) {
	var contents []os.DirEntry
	contents, err = os.ReadDir(name)
	if err != nil {
		return
	}
	for _, content := range contents {
		if content.IsDir() {
			if err = tidy_symbol_directory(filepath.Join(name, content.Name()), params); err != nil {
				return
			}
		} else {
			if err = tidy_symbol_file(filepath.Join(name, content.Name()), params); err != nil {
				return
			}
		}
	}
	return
}

func Tidy(params *TidyParams) {
	// tidy symbols
	profile_symbols := filepath.Join("profile", params.Profile, "symbol")

	if err := tidy_symbol_directory(profile_symbols, params); err != nil {
		app.Fatal(err)
	}
}
