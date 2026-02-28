package profile

func compile_x64dbg_artifacts(profile *Profile, params *CompileArtifactsParams) (err error) {
	if err = compile_x64dbg_types(profile); err != nil {
		return
	}
	err = compile_x64dbg_database(profile, params.CompressX64dbgDatabase)
	return
}
