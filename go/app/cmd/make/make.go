package make

import (
	"github.com/spf13/cobra"
	"github.com/thunderbrewhq/binana/go/app/cmd/root"
	"github.com/thunderbrewhq/binana/go/app/profile"
)

func mk_func(cmd *cobra.Command, args []string) {
	compress, err := cmd.Flags().GetBool("compress")
	if err != nil {
		panic(err)
	}

	var params profile.MakeParams
	params.Profile = args[0]
	params.CompressX64dbgDatabase = compress
	profile.Make(&params)
}

var mk_cmd = cobra.Command{
	Use:   "mk profile",
	Args:  cobra.MinimumNArgs(1),
	Short: "Convert source files into various tool formats",
	Run:   mk_func,
}

func init() {
	f := mk_cmd.Flags()
	f.BoolP("compress", "c", true, "enable/disable compression of the x64dbg database file")
	root.RootCmd.AddCommand(&mk_cmd)
}
