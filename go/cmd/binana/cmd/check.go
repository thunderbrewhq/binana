package cmd

import (
	"fmt"
	"strings"

	"github.com/fatih/color"
	"github.com/spf13/cobra"
	"github.com/thunderbrewhq/binana/go/profile"
	"github.com/thunderbrewhq/binana/go/symfile"
)

type check_params struct {
	ProfileName  string
	Constructors bool
	Bounds       bool
}

func check(params *check_params) {
	p, err := profile.Open(params.ProfileName)
	if err != nil {
		panic(err)
	}

	named_function_count := uint64(0)

	warnings := uint64(0)

	warn := func(s *symfile.Entry, f string, args ...any) {
		warnings++
		color.Set(color.FgRed)
		fmt.Printf("  warning: ")
		color.Unset()
		fmt.Printf("in line %d: (%s): ", s.LineNumber, s.Name)
		fmt.Printf(f, args...)
	}

	for _, s := range p.SymbolTable.Entries {
		sn := s.Name

		if s.Kind == symfile.Function {
			named_function_count++

			if params.Constructors {
				//
				b, a, found := strings.Cut(sn, "__")
				if found {
					if b == a {
						warn(&s, "this style of naming a constructor function is preferred: ClassName__constructor\n")
					}
				}
			}

			if params.Bounds {
				if s.EndAddress == 0 {
					warn(&s, "does not have an end address\n")
				}
			}
		}
	}

	if p.Info.FunctionCount != 0 {
		ratio := float64(named_function_count) / float64(p.Info.FunctionCount)
		fmt.Printf("%d out of %d functions named (%f%%)\n", named_function_count, p.Info.FunctionCount, ratio*100.0)
		fmt.Printf("%d warnings generated\n", warnings)
	}
}

func check_run(cmd *cobra.Command, args []string) {
	if len(args) < 1 {
		cmd.Help()
		return
	}
	f := cmd.Flags()
	var params check_params
	params.ProfileName = args[0]

	var err error

	params.Constructors, err = f.GetBool("constructors")
	if err != nil {
		panic(err)
	}

	params.Bounds, err = f.GetBool("bounds")
	if err != nil {
		panic(err)
	}

	check(&params)
}

var check_cmd = cobra.Command{
	Use:   "check profile",
	Short: "check a profile for correctness",
	Run:   check_run,
}
