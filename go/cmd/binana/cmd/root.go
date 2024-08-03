/*
Copyright © 2024 NAME HERE <EMAIL ADDRESS>
*/
package cmd

import (
	"os"

	"github.com/spf13/cobra"
)

// rootCmd represents the base command when called without any subcommands
var rootCmd = &cobra.Command{
	Use:   "binana",
	Short: "Binana helper tool",
}

// Execute adds all child commands to the root command and sets flags appropriately.
// This is called by main.main(). It only needs to happen once to the rootCmd.
func Execute() {
	err := rootCmd.Execute()
	if err != nil {
		os.Exit(1)
	}
}

func init() {
	// Here you will define your flags and configuration settings.
	// Cobra supports persistent flags, which, if defined here,
	// will be global for your application.

	// rootCmd.PersistentFlags().StringVar(&cfgFile, "config", "", "config file (default is $HOME/.binana.yaml)")

	// Cobra also supports local flags, which will only run
	// when this action is called directly.
	// rootCmd.Flags().BoolP("toggle", "t", false, "Help message for toggle")

	ida_gen.Flags().StringP("game", "g", "3.3.5a", "the game profile")
	rootCmd.AddCommand(ida_gen)

	x64dbg_gen.Flags().StringP("game", "g", "3.3.5a", "the game profile")
	x64dbg_gen.Flags().StringP("module-name", "m", "wow.exe", "the name of the module")
	x64dbg_gen.Flags().StringP("base-address", "b", "00400000", "the base address of the module")

	rootCmd.AddCommand(x64dbg_gen)
	rootCmd.AddCommand(x64dbg_typesort)
}
