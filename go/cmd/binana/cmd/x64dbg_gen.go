package cmd

import (
	"fmt"
	"os"
	"strconv"

	"github.com/spf13/cobra"
	"github.com/thunderbrewhq/binana/go/profile"
)

var x64dbg_gen = &cobra.Command{
	Use:   "x64dbg-gen",
	Short: "Generate x64dbg database using a symfile",
	Run:   x64dbg_gen_func,
}

func x64dbg_gen_func(cmd *cobra.Command, args []string) {
	// get command line arguments
	module_name, err := cmd.Flags().GetString("module-name")
	if err != nil {
		panic(err)
	}

	base_address_s, err := cmd.Flags().GetString("base-address")
	if err != nil {
		panic(err)
	}

	// parse the base address of game EXE
	base_address, err := strconv.ParseUint(base_address_s, 16, 64)
	if err != nil {
		panic(err)
	}

	game_profile_directory, err := cmd.Flags().GetString("game")
	if err != nil {
		panic(err)
	}

	game_profile, err := profile.Open(game_profile_directory)
	if err != nil {
		panic(err)
	}

	if err = game_profile.CreateX64dbgFiles(module_name, base_address); err != nil {
		fmt.Println(err)
		os.Exit(1)
	}
}
