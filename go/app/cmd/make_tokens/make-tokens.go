package make_tokens

import (
	"github.com/spf13/cobra"
	"github.com/thunderbrewhq/binana/go/app"
	"github.com/thunderbrewhq/binana/go/app/cmd/root"
	"github.com/thunderbrewhq/binana/go/app/util"
	"github.com/thunderbrewhq/binana/go/app/util/dbutil"
)

var make_tokens_cmd = cobra.Command{
	Use: "make-tokens",
	Run: run_make_tokens_command,
}

func init() {
	f := make_tokens_cmd.Flags()
	f.StringP("source", "s", "", "required: source tree of sample binaries")
	f.StringP("output-file", "o", "", "write the database to a file")
	f.StringP("format", "f", "json", "the format of the output database [json|parquet]")
	root.RootCmd.AddCommand(&make_tokens_cmd)
}

func run_make_tokens_command(cmd *cobra.Command, args []string) {
	f := cmd.Flags()
	var (
		params util.MakeTokenDatabaseParams
		err    error
		format string
	)
	params.Source, err = f.GetString("source")
	if err != nil {
		app.Fatal(err)
	}
	if params.Source == "" {
		cmd.Help()
		return
	}
	params.Output, err = f.GetString("output-file")
	if err != nil {
		app.Fatal(err)
	}
	format, err = f.GetString("format")
	if err != nil {
		app.Fatal(err)
	}
	switch format {
	case "json":
		params.Format = dbutil.DatabaseJSON
	case "parquet":
		params.Format = dbutil.DatabaseParquet
	default:
		app.Fatal("unknown format", format)
	}

	util.MakeTokenDatabase(&params)
}
