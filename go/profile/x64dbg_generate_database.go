package profile

import (
	"fmt"
	"path/filepath"

	"github.com/thunderbrewhq/binana/go/symfile"
	"github.com/thunderbrewhq/binana/go/x64dbg"
)

func hex_address(u uint64) string {
	return fmt.Sprintf("0x%x", u)
}

func (profile *Profile) generate_x64dbg_database(compress bool) (err error) {
	// Convert symbol table into x64dbg database

	is_64bit := profile.Info.Arch == "amd64"

	module_name := profile.Info.ModuleName
	base_address := profile.Info.ModuleBase

	var dd x64dbg.Database

	for _, entry := range profile.SymbolTable.Entries {
		relative_start_address := entry.StartAddress - base_address
		relative_end_address := relative_start_address

		if entry.EndAddress != 0 {
			relative_end_address = entry.EndAddress - base_address
			// for x64dbg, the end address is the last instruction.
			// for us, the end address is the address immediately after the last instruction.
			relative_end_address -= 1
		}

		if relative_end_address < relative_start_address || relative_end_address-relative_start_address >= 50000 {
			fmt.Printf("Strange symbol %s %08x %08x (offset %d)\n", entry.Name, relative_start_address, relative_end_address, relative_end_address-relative_start_address)
		}

		// create label
		var label x64dbg.Label
		label.Manual = true
		label.Address = hex_address(relative_start_address)
		label.Text = entry.Name
		label.Module = module_name
		dd.Labels = append(dd.Labels, label)

		if entry.Kind == symfile.Function {
			var fn x64dbg.Function
			fn.Manual = true
			fn.Start = hex_address(relative_start_address)
			fn.End = hex_address(relative_end_address)

			fn.Module = module_name

			fn.InstructionCount = hex_address(0)
			fn.Parent = hex_address(relative_start_address)

			dd.Functions = append(dd.Functions, fn)
		}
	}

	filename := "game.dd32"
	if is_64bit {
		filename = "game.dd64"
	}

	// save database
	dd_path := filepath.Join(profile.Directory, "x64dbg", filename)
	if err = x64dbg.SaveDatabase(dd_path, &dd, compress); err != nil {
		return
	}

	fmt.Println("database generated!", dd_path)

	return
}
