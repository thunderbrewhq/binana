package util

import (
	"debug/pe"
	"os"
)

func get_exe_base_address(name string) (base_address uint64, err error) {
	var file *os.File
	file, err = os.Open(name)
	if err != nil {
		return
	}
	var (
		pe_file *pe.File
	)
	pe_file, err = pe.NewFile(file)
	if err != nil {
		return
	}
	base_address = uint64(0x400000)

	switch h := pe_file.OptionalHeader.(type) {
	case *pe.OptionalHeader32:
		base_address = uint64(h.ImageBase)
	case *pe.OptionalHeader64:
		base_address = h.ImageBase
	}
	file.Close()
	return
}
