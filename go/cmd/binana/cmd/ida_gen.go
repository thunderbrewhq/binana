package cmd

import (
	"fmt"
	"os"

	"github.com/spf13/cobra"
	"github.com/thunderbrewhq/binana/go/profile"
)

var ida_gen = &cobra.Command{
	Use:   "ida-gen",
	Short: "Generate IDC file using symbol file",
	Run:   ida_gen_func,
}

func ida_gen_func(cmd *cobra.Command, args []string) {
	// get command line arguments
	// module_name, err := cmd.Flags().GetString("module-name")
	// if err != nil {
	// 	panic(err)
	// }

	game_profile_directory, err := cmd.Flags().GetString("game")
	if err != nil {
		panic(err)
	}

	game_profile, err := profile.Open(game_profile_directory)
	if err != nil {
		panic(err)
	}

	if err = game_profile.CreateIDAFiles(); err != nil {
		fmt.Println(err)
		os.Exit(1)
	}
}
