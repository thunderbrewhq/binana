package cmd

import (
	"fmt"
	"os"
	"path/filepath"
	"strconv"

	"github.com/spf13/cobra"
	"github.com/thunderbrewhq/binana/go/symfile"
	"github.com/thunderbrewhq/binana/go/x64dbg"
)

func hex_address(u uint64) string {
	return fmt.Sprintf("0x%x", u)
}

// rootCmd represents the base command when called without any subcommands
var x64dbg_gen = &cobra.Command{
	Use:   "x64dbg-gen",
	Short: "Generate x64dbg database using a symfile",
	Run:   x64dbg_gen_func,
}

func x64dbg_gen_func(cmd *cobra.Command, args []string) {
	compress, err := cmd.Flags().GetBool("compress")
	if err != nil {
		panic(err)
	}

	module_name, err := cmd.Flags().GetString("module-name")
	if err != nil {
		panic(err)
	}

	base_address_s, err := cmd.Flags().GetString("base-address")
	if err != nil {
		panic(err)
	}

	base_address, err := strconv.ParseUint(base_address_s, 16, 64)
	if err != nil {
		panic(err)
	}

	game_profile, err := cmd.Flags().GetString("game")
	if err != nil {
		panic(err)
	}

	symfile_path := filepath.Join(game_profile, "symbol", "main.sym")

	file, err := os.Open(symfile_path)
	if err != nil {
		fmt.Println(err)
		os.Exit(1)
		return
	}

	table := new(symfile.InMemoryTable)

	if err := symfile.Load(table, file); err != nil {
		fmt.Println(err)
		os.Exit(1)
		return
	}

	file.Close()

	fmt.Printf("loaded %d symbols\n", table.Len())

	var dd x64dbg.Database

	for _, entry := range table.Entries {
		relative_start_address := entry.StartAddress - base_address
		relative_end_address := relative_start_address

		if entry.EndAddress != 0 {
			relative_end_address = entry.EndAddress - base_address
			// for x64dbg, the end address is the last instruction.
			// for us, the end address is the address immediately after the last instruction.
			relative_end_address -= 1
		}

		if relative_end_address < relative_start_address || relative_end_address-relative_start_address >= 10000 {
			fmt.Printf("Wtf symbol %s %08x %08x (offset %d)\n", entry.Name, relative_start_address, relative_end_address, relative_end_address-relative_start_address)
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

	dd_path := filepath.Join(game_profile, "x32dbg", "game.dd32")
	if err = x64dbg.SaveDatabase(dd_path, &dd, compress); err != nil {
		fmt.Println(err)
		os.Exit(1)
	}
}
