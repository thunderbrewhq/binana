package profile

import (
	"fmt"
	"os"
	"path/filepath"

	"github.com/thunderbrewhq/binana/go/app"
	"github.com/thunderbrewhq/binana/go/symbols"
)

type AddSymbolParams struct {
	Profile string
	Group   string
	Symbols []symbols.Symbol
}

func AddSymbol(params *AddSymbolParams) {
	Open(params.Profile)

	// Detect collisions
	// TODO: check if address exists within a function's range
	for i, symbol := range params.Symbols {
		entry, err := Profile.Symbols.Lookup(symbol.StartAddress)
		if err == nil {
			app.Fatal(fmt.Errorf(
				"profile: cannot add symbol '%s' (--:%d), another symbol '%s' (%s:%d) already exists at the same address (%08X)",
				symbol.Name,
				i+1,
				entry.Symbol.Name,
				entry.Filename,
				entry.Linenumber,
				symbol.StartAddress,
			))
		}
	}

	// Load all symbols, and rewrite them
	group_symbol_directory := filepath.Join(Profile.Directory, "symbol", params.Group)
	var group_symbols symbols.Table
	group_symbols.Init()

	group_symbols_file_info, err := os.Stat(group_symbol_directory)
	if err != nil {
		err = os.MkdirAll(group_symbol_directory, 0755)
		if err != nil {
			app.Fatal(err)
		}
	} else {
		if !group_symbols_file_info.IsDir() {
			app.Fatal(fmt.Errorf("profile: symbol group '%s' has invalid directory structure", params.Group))
		}
		if err = group_symbols.Load(group_symbol_directory); err != nil {
			app.Fatal(err)
		}
	}

	for i, symbol := range params.Symbols {
		var entry symbols.TableEntry
		entry.Filename = "--"
		entry.Linenumber = i + 1
		entry.Symbol = symbol
		if err := group_symbols.Insert(&entry); err != nil {
			panic(err)
		}
	}

	label_file_name := filepath.Join(group_symbol_directory, "label.sym")
	func_file_name := filepath.Join(group_symbol_directory, "func.sym")
	label_file_tmp_name := label_file_name + ".tmp"
	func_file_tmp_name := func_file_name + ".tmp"
	label_file, err := os.Create(label_file_tmp_name)
	if err != nil {
		app.Fatal(err)
	}
	func_file, err := os.Create(func_file_tmp_name)
	if err != nil {
		app.Fatal(err)
	}
	var (
		labels, functions int
	)

save_loop:
	for entry := range group_symbols.Entries() {
		switch entry.Symbol.Kind {
		case symbols.DataLabel:
			labels++
			if _, err = entry.Symbol.WriteTo(label_file); err != nil {
				break save_loop
			}
			if _, err = label_file.Write([]byte("\n")); err != nil {
				break save_loop
			}
		case symbols.Function:
			functions++
			if _, err = entry.Symbol.WriteTo(func_file); err != nil {
				break save_loop
			}
			if _, err = func_file.Write([]byte("\n")); err != nil {
				break save_loop
			}
		default:
			err = fmt.Errorf("unhandled function kind %c", entry.Symbol.Kind)
		}
	}
	if err != nil {
		label_file.Close()
		func_file.Close()
		os.Remove(label_file_name)
		os.Remove(func_file_name)
		return
	}
	label_file.Close()
	func_file.Close()
	if labels == 0 {
		os.Remove(label_file_name)
		os.Remove(label_file_tmp_name)
	} else {
		if err = os.Rename(label_file_tmp_name, label_file_name); err != nil {
			return
		}
	}
	if functions == 0 {
		os.Remove(func_file_name)
		os.Remove(func_file_tmp_name)
	} else {
		if err = os.Rename(func_file_tmp_name, func_file_name); err != nil {
			return
		}
	}
}
