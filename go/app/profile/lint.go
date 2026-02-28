package profile

import (
	"fmt"
	"strings"

	"github.com/fatih/color"
	"github.com/thunderbrewhq/binana/go/symbols"
)

type linter struct {
	warnings              uint64
	named_functions_count uint64
}

func (linter *linter) warn(s *symbols.TableEntry, f string, args ...any) {
	linter.warnings++
	color.Set(color.FgRed)
	fmt.Printf("  warning: ")
	color.Unset()
	fmt.Printf(" in %s:%d: %s", s.Filename, s.Linenumber, s.Symbol.Name)
	fmt.Printf(f, args...)
}

type LintParams struct {
	Profile      string
	Constructors bool
	Bounds       bool
}

func Lint(params *LintParams) {
	Open(params.Profile)
	defer Close()

	var linter linter
	for entry := range Profile.Symbols.Entries() {
		sn := entry.Symbol.Name

		if entry.Symbol.Kind == symbols.Function {
			linter.named_functions_count++

			if params.Constructors {
				//
				b, a, found := strings.Cut(sn, "__")
				if found {
					if b == a {
						linter.warn(entry, "this style of naming a constructor function is preferred: ClassName__constructor\n")
					}
				}
			}

			if params.Bounds {
				if entry.Symbol.EndAddress == 0 {
					linter.warn(entry, "does not have an end address\n")
				}
			}
		}
	}

	if Profile.Info.FunctionCount != 0 {
		ratio := float64(linter.named_functions_count) / float64(Profile.Info.FunctionCount)
		fmt.Printf("%d out of %d functions named (%f%%)\n", linter.named_functions_count, Profile.Info.FunctionCount, ratio*100.0)
		fmt.Printf("%d warnings generated\n", linter.warnings)
	}
}
