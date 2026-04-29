package fix_labels

import (
	"github.com/spf13/cobra"
	"github.com/thunderbrewhq/binana/go/app"
	"github.com/thunderbrewhq/binana/go/app/cmd/root"
	"github.com/thunderbrewhq/binana/go/app/util"
)

var fix_labels_cmd = cobra.Command{
	Use:   "fix-labels fixlist capture-regex fix-pattern",
	Args:  cobra.MinimumNArgs(3),
	Short: "quickly edit symbols by regex matching tokens against a list of known good symbols",
	Run:   run_fix_labels_cmd,
}

func init() {
	f := fix_labels_cmd.Flags()
	f.StringP("symbols", "s", "", "optional: specify a file to read from instead of stdin")
	root.RootCmd.AddCommand(&fix_labels_cmd)
}

func run_fix_labels_cmd(cmd *cobra.Command, args []string) {
	f := cmd.Flags()
	var (
		err    error
		params util.FixLabelsParams
	)
	params.Input, err = f.GetString("symbols")
	if err != nil {
		app.Fatal(err)
	}
	params.FixList = args[0]
	params.Capture = args[1]
	params.FixPattern = args[2]
	util.FixLabels(&params)
}
