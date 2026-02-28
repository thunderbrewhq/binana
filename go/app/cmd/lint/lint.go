package cmd

import (
	"github.com/spf13/cobra"
	"github.com/thunderbrewhq/binana/go/app"
	"github.com/thunderbrewhq/binana/go/app/profile"
)

var lint_cmd = cobra.Command{
	Use:   "lint profile",
	Short: "show warnings and coverage for a profile",
	Run:   lint_func,
}

func init() {
	f := lint_cmd.Flags()
	f.Bool("bounds", false, "check for bad function boundaries")
	f.Bool("constructors", false, "check for outdated class constructor names")
}

func lint_func(cmd *cobra.Command, args []string) {
	if len(args) < 1 {
		cmd.Help()
		return
	}
	f := cmd.Flags()
	var params profile.LintParams
	params.Profile = args[0]

	var err error

	params.Constructors, err = f.GetBool("constructors")
	if err != nil {
		app.Fatal(err)
	}

	params.Bounds, err = f.GetBool("bounds")
	if err != nil {
		app.Fatal(err)
	}

	profile.Lint(&params)
}
