package profile

import (
	"fmt"
	"slices"
)

type CompileArtifactsParams struct {
	CompressX64dbgDatabase bool
}

func (profile *Profile) CompileArtifacts(params *CompileArtifactsParams) (err error) {
	if !profile.loaded {
		panic(profile.loaded)
	}
	compilers := []struct {
		OS   []string
		Name string
		Fn   func(*Profile, *CompileArtifactsParams) error
	}{
		{[]string{"windows", "linux", "darwin"}, "Ghidra", compile_ghidra_artifacts},
		{[]string{"windows", "linux", "darwin"}, "IDA Pro", compile_idapro_artifacts},
		{[]string{"windows"}, "x64dbg", compile_x64dbg_artifacts},
	}

	for _, compiler := range compilers {
		if slices.Contains(compiler.OS, profile.Info.OS) {
			fmt.Println("compiling artifacts for", compiler.Name)
			if err = compiler.Fn(profile, params); err != nil {
				return
			}
		}
	}
	return
}
