package make_samples

import (
	"github.com/spf13/cobra"
	"github.com/thunderbrewhq/binana/go/app"
	"github.com/thunderbrewhq/binana/go/app/cmd/root"
	"github.com/thunderbrewhq/binana/go/app/util"
	"github.com/thunderbrewhq/binana/go/app/util/dbutil"
)

var make_samples_cmd = cobra.Command{
	Use: "make-samples",
	Run: run_make_samples_command,
}

func init() {
	f := make_samples_cmd.Flags()
	f.StringP("source", "s", "", "required: source tree of sample binaries")
	f.StringP("output-file", "o", "", "write the database to a file")
	f.StringSlice("direct-mirror", nil, "list of direct mirror URLs that already contain the sample binaries")
	f.StringSlice("ipfs-gateway", nil, "list of IPFS gateways")
	f.StringP("format", "f", "json", "the format of the output database [json|parquet]")
	root.RootCmd.AddCommand(&make_samples_cmd)
}

func run_make_samples_command(cmd *cobra.Command, args []string) {
	f := cmd.Flags()
	var (
		params util.MakeSampleDatabaseParams
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

	params.DirectMirrors, err = f.GetStringSlice("direct-mirror")
	if err != nil {
		app.Fatal(err)
	}
	params.IPFSGateways, err = f.GetStringSlice("ipfs-gateway")
	if err != nil {
		app.Fatal(err)
	}

	util.MakeSampleDatabase(&params)
}
