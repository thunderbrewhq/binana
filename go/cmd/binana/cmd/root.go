/*
Copyright © 2024 NAME HERE <EMAIL ADDRESS>
*/
package cmd

import (
	"os"

	"github.com/spf13/cobra"
)

// rootCmd represents the base command when called without any subcommands
var root = cobra.Command{
	Use:   "binana",
	Short: "Binana helper tool",
}

// Execute adds all child commands to the root command and sets flags appropriately.
// This is called by main.main(). It only needs to happen once to the rootCmd.
func Execute() {
	err := root.Execute()
	if err != nil {
		os.Exit(1)
	}
}

func init() {
	generate_cmd.Flags().StringP("profile", "p", "3.3.5a", "the game profile")
	generate_cmd.Flags().BoolP("compress", "c", true, "enable/disable compression of the x64dbg database file")

	check_cmd.Flags().Bool("bounds", false, "check for bad function boundaries")
	check_cmd.Flags().Bool("constructors", false, "check for outdated class constructor names")

	root.AddCommand(&generate_cmd)
	root.AddCommand(&format_symbols_cmd)
	root.AddCommand(&x64dbg_typesort_cmd)
	root.AddCommand(&check_cmd)
}
