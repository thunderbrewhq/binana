package profile

func (profile *Profile) CreateX64dbgFiles(module_name string, base_address uint64) (err error) {
	if err = profile.generate_x64dbg_database(module_name, base_address); err != nil {
		return
	}

	if err = profile.generate_x64dbg_types(); err != nil {
		return
	}

	return
}
