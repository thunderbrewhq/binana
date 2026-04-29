package query

import (
	"math"

	"github.com/spf13/cobra"
	"github.com/thunderbrewhq/binana/go/app"
	"github.com/thunderbrewhq/binana/go/app/cmd/root"
	"github.com/thunderbrewhq/binana/go/app/util"
)

var query_cmd = cobra.Command{
	Use:   "q regexp",
	Args:  cobra.MinimumNArgs(1),
	Short: "query the token database for information",
	Run:   run_query_cmd,
}

func init() {
	f := query_cmd.Flags()
	f.Bool("regex", false, "use regex to for matching token names")
	f.Uint32("min-build", 0, "the minimum build to return tokens for")
	f.Uint32("max-build", math.MaxUint32, "the maximum build to return tokens for")
	f.StringSlice("program", nil, "a list of programs to return tokens for")
	f.StringSlice("os", nil, "a list of kernel names to return tokens for (windows, darwin, linux)")
	f.StringSlice("arch", nil, "a list of CPU architectures to return tokens for (ppc, 386, amd64)")
	f.String("present", "normal", "control the way tokens are presented to console (name, sample-name)")
	f.Bool("quote", false, "quote strings before presenting")
	root.RootCmd.AddCommand(&query_cmd)
}

func run_query_cmd(cmd *cobra.Command, args []string) {
	f := cmd.Flags()
	var (
		params            util.QueryParams
		err               error
		presentation_mode string
	)
	params.RegEx, err = f.GetBool("regex")
	if err != nil {
		app.Fatal(err)
	}
	params.MinBuild, err = f.GetUint32("min-build")
	if err != nil {
		app.Fatal(err)
	}
	params.MaxBuild, err = f.GetUint32("max-build")
	if err != nil {
		app.Fatal(err)
	}
	params.Program, err = f.GetStringSlice("program")
	if err != nil {
		app.Fatal(err)
	}
	params.OS, err = f.GetStringSlice("os")
	if err != nil {
		return
	}
	params.Arch, err = f.GetStringSlice("arch")
	if err != nil {
		return
	}
	presentation_mode, err = f.GetString("present")
	if err != nil {
		return
	}
	params.Quote, err = f.GetBool("quote")
	if err != nil {
		return
	}
	switch presentation_mode {
	case "normal":
		params.Present = util.PresentQueryNormal
	case "name-only":
		params.Present = util.PresentQueryNameOnly
	case "sample-name":
		params.Present = util.PresentQuerySampleName
	default:
		cmd.Help()
		return
	}
	params.Token = args[0]
	util.Query(&params)
}
