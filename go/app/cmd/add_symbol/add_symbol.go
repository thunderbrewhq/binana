package add_symbol

import (
	"bufio"
	"os"

	"github.com/spf13/cobra"
	"github.com/thunderbrewhq/binana/go/app"
	"github.com/thunderbrewhq/binana/go/app/cmd/root"
	"github.com/thunderbrewhq/binana/go/app/profile"
	"github.com/thunderbrewhq/binana/go/symbols"
)

func as_func(cmd *cobra.Command, args []string) {
	f := cmd.Flags()
	var (
		err    error
		params profile.AddSymbolParams
	)
	params.Profile = args[0]
	params.Group, err = f.GetString("group")
	if err != nil {
		return
	}
	// TODO: infer the group
	if params.Group == "" {
		app.Fatal("pass in the group (-g, --group) that will store the symbol(s)")
		return
	}
	if len(args) < 2 {
		// read normally formatted symbols from stdin
		scanner := bufio.NewScanner(os.Stdin)
		for scanner.Scan() {
			line := scanner.Text()
			var symbol symbols.Symbol
			if err = symbol.Parse(line); err != nil {
				app.Fatal(err)
				return
			}
			params.Symbols = append(params.Symbols, symbol)
		}
	} else {
		// use args to add symbol
		if len(args) < 4 {
			cmd.Help()
			return
		}
		params.Symbols = make([]symbols.Symbol, 1)
		if err = params.Symbols[0].ParseCommandLine(args[1:]); err != nil {
			return
		}
		params.Symbols[0].Comment, err = f.GetString("comment")
	}

	profile.AddSymbol(&params)
}

var as_cmd = cobra.Command{
	Use:   "as profile [symbol_name] [address] [l|f] [type=...]",
	Args:  cobra.MinimumNArgs(1),
	Short: "Add symbols to profile",
	Long:  "Adds symbol passed through command-line arguments, or add one or more normally-formatted symbols by passing them through stdin",
	Run:   as_func,
}

func init() {
	f := as_cmd.Flags()
	f.StringP("group", "g", "", "the profile symbol group to record symbols into (e.g. 'feature1' to record into profile/<profile>/symbol/feature1)")
	f.StringP("comment", "m", "", "the comment to pass to the symbol")
	root.RootCmd.AddCommand(&as_cmd)
}
