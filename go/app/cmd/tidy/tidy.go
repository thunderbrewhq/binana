package tidy

import (
	"github.com/spf13/cobra"
	"github.com/thunderbrewhq/binana/go/app/cmd/root"
	"github.com/thunderbrewhq/binana/go/app/profile"
)

var tidy_cmd = cobra.Command{
	Use:   "tidy profile",
	Short: "sort all symbol files in a profile",
	Args:  cobra.MinimumNArgs(1),
	Run:   tidy_func,
}

func init() {
	//f := tidy_cmd.Flags()
	root.RootCmd.AddCommand(&tidy_cmd)
}

func tidy_func(cmd *cobra.Command, args []string) {
	var params profile.TidyParams
	params.Profile = args[0]
	profile.Tidy(&params)
}
