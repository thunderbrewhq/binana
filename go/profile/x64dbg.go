package profile

func (profile *Profile) CreateX64dbgFiles(compress_db bool) (err error) {
	if err = profile.generate_x64dbg_database(compress_db); err != nil {
		return
	}

	if err = profile.generate_x64dbg_types(); err != nil {
		return
	}

	return
}
