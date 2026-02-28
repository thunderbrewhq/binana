package profile

import (
	"os"
	"path/filepath"
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
	_, err = profile.Symbols.WriteTo(symbol_file)
	symbol_file.Close()
	return
}
