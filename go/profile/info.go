package profile

import (
	"encoding/json"
	"fmt"
	"os"
	"slices"
	"strconv"
)

var (
	valid_os = []string{
		"windows",
		"darwin",
		"linux",
	}

	valid_arch = []string{
		"386",
		"amd64",
		"ppc",
	}
)

type info_schema struct {
	OS            string `json:"os"`
	Arch          string `json:"arch"`
	ModuleName    string `json:"module_name"`
	ModuleBase    string `json:"module_base"`
	FunctionCount uint64 `json:"function_count"`
}

type Info struct {
	OS            string
	Arch          string
	ModuleName    string
	ModuleBase    uint64
	FunctionCount uint64
}

func read_info(filename string, info *Info) (err error) {
	var b []byte
	b, err = os.ReadFile(filename)
	if err != nil {
		return
	}
	var is info_schema
	err = json.Unmarshal(b, &is)
	if err != nil {
		return
	}

	if !slices.Contains(valid_os, is.OS) {
		err = fmt.Errorf("profile: invalid os '%s'", is.OS)
		return
	}

	if !slices.Contains(valid_arch, is.Arch) {
		err = fmt.Errorf("profile: invalid arch '%s'", is.Arch)
		return
	}

	info.ModuleName = is.ModuleName

	info.OS = is.OS
	info.Arch = is.Arch

	info.ModuleBase, err = strconv.ParseUint(is.ModuleBase, 16, 64)
	if err != nil {
		return
	}

	info.FunctionCount = is.FunctionCount

	return
}
