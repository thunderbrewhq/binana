package cmd

import (
	"fmt"
	"os"

	"github.com/spf13/cobra"
	"github.com/thunderbrewhq/binana/go/profile"
)

var generate = &cobra.Command{
	Use:   "generate",
	Short: "Convert source files into various tool formats",
	Run:   generate_func,
}

func generate_func(cmd *cobra.Command, args []string) {
	compress, err := cmd.Flags().GetBool("compress")
	if err != nil {
		panic(err)
	}

	game_profile_directory, err := cmd.Flags().GetString("profile")
	if err != nil {
		panic(err)
	}

	game_profile, err := profile.Open(game_profile_directory)
	if err != nil {
		panic(err)
	}

	if err = game_profile.Generate(compress); err != nil {
		fmt.Println(err)
		os.Exit(1)
	}
}
