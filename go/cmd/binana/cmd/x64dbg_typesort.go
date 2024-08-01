package cmd

import (
	"encoding/json"
	"os"

	"github.com/spf13/cobra"
	"github.com/thunderbrewhq/binana/go/x64dbg"
)

var x64dbg_typesort = &cobra.Command{
	Use:   "x64dbg-typesort [types.json file]",
	Short: "sort a x64dbg types file",
	Run:   x64dbg_typesort_func,
}

func x64dbg_typesort_func(cmd *cobra.Command, args []string) {
	types, err := x64dbg.LoadTypes(args[0])
	if err != nil {
		panic(err)
	}

	if err = x64dbg.SortTypes(types); err != nil {
		panic(err)
	}

	encoder := json.NewEncoder(os.Stdout)
	encoder.SetIndent("", "  ")
	if err = encoder.Encode(types); err != nil {
		panic(err)
	}
}
