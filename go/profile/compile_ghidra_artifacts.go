package profile

import (
	"os"
	"path/filepath"

	"github.com/thunderbrewhq/binana/go/symbols"
)

func compile_ghidra_artifacts(profile *Profile, params *CompileArtifactsParams) (err error) {
	ghidra_path := filepath.Join(profile.ArtifactsDirectory, "ghidra")
	if err = os.MkdirAll(ghidra_path, 0755); err != nil {
		return
	}
	var symbol_file *os.File
	symbol_file, err = os.Create(filepath.Join(ghidra_path, "all.sym"))
	if err != nil {
		return
	}
	// strip out autoanalysis symbols
	var symbol_table symbols.Table
	symbol_table.Init()
	for entry := range profile.Symbols.Entries() {
		if !entry.Symbol.Auto {
			if err = symbol_table.Insert(entry); err != nil {
				return
			}
		}
	}

	_, err = symbol_table.WriteTo(symbol_file)
	symbol_file.Close()
	return
}
