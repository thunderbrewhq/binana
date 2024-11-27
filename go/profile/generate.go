package profile

func (profile *Profile) Generate(compress_db bool) (err error) {
	if err = profile.CreateIDAFiles(); err != nil {
		return
	}

	if profile.Info.OS == "windows" {
		if err = profile.CreateX64dbgFiles(compress_db); err != nil {
			return
		}
	}

	return
}
