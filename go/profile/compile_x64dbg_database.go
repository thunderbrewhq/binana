package profile

import (
	"fmt"
	"os"
	"path/filepath"

	"github.com/thunderbrewhq/binana/go/symbols"
	"github.com/thunderbrewhq/binana/go/x64dbg"
)

func hex_address(u uint64) string {
	return fmt.Sprintf("0x%x", u)
}

func compile_x64dbg_database(profile *Profile, compress bool) (err error) {
	// Convert symbol table into x64dbg database

	is_64bit := profile.Info.Arch == "amd64"

	module_name := profile.Info.ModuleName
	base_address := profile.Info.ModuleBase

	var dd x64dbg.Database

	for entry := range profile.Symbols.Entries() {
		relative_start_address := entry.Symbol.StartAddress - base_address
		relative_end_address := relative_start_address

		if entry.Symbol.EndAddress != 0 {
			relative_end_address = entry.Symbol.EndAddress - base_address
			// for x64dbg, the end address is the last instruction.
			// for us, the end address is the address immediately after the last instruction.
			relative_end_address -= 1
		}

		if relative_end_address < relative_start_address || relative_end_address-relative_start_address >= 50000 {
			fmt.Printf("Strange symbol %s %08x %08x (offset %d)\n", entry.Symbol.Name, relative_start_address, relative_end_address, relative_end_address-relative_start_address)
		}

		// create label
		var label x64dbg.Label
		label.Manual = true
		label.Address = hex_address(relative_start_address)
		label.Text = entry.Symbol.Name
		label.Module = module_name
		dd.Labels = append(dd.Labels, label)

		if entry.Symbol.Kind == symbols.Function {
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
	dd_path := filepath.Join(profile.ArtifactsDirectory, "x64dbg")
	if err = os.MkdirAll(dd_path, 0755); err != nil {
		return
	}
	if err = x64dbg.SaveDatabase(filepath.Join(dd_path, filename), &dd, compress); err != nil {
		return
	}

	fmt.Println("database generated!", dd_path)

	return
}
