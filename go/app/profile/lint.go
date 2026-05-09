package profile

import (
	"fmt"
	"strings"

	"github.com/fatih/color"
	"github.com/thunderbrewhq/binana/go/symbols"
)

type linter struct {
	warnings                    uint64
	named_functions_count       uint64
	typed_function_count        uint64
	last_function_boundary      function_boundary
	have_last_function_boundary bool
}

func (linter *linter) warn(s *symbols.TableEntry, f string, args ...any) {
	linter.warnings++
	color.Set(color.FgRed)
	fmt.Printf("  warning: ")
	color.Unset()
	fmt.Printf(" in %s:%d: ( %s @ %08X ) ", s.Filename, s.Linenumber, s.Symbol.Name, s.Symbol.StartAddress)
	fmt.Printf(f, args...)
}

type LintParams struct {
	Profile      string
	Constructors bool
	Bounds       bool
}

type function_boundary struct {
	start, end uint64
}

func (b1 function_boundary) OverlapsWith(b2 function_boundary) bool {
	// b1 = { 0, 4 }
	// b2 = { 1, 9 }
	// ----------
	// 0123456789
	// ....
	//  ........
	//

	t := b1.start < b2.end && b2.start < b1.end
	return t
}

func Lint(params *LintParams) {
	Open(params.Profile)
	defer Close()

	var (
		linter linter
	)

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
				var current_function_boundary function_boundary
				current_function_boundary.start = entry.Symbol.StartAddress
				if entry.Symbol.EndAddress == 0 {
					current_function_boundary.end = entry.Symbol.StartAddress
				} else {
					current_function_boundary.end = entry.Symbol.EndAddress
				}

				if linter.have_last_function_boundary {
					if linter.last_function_boundary.OverlapsWith(current_function_boundary) {
						last_symbol, err := Profile.Symbols.Lookup(linter.last_function_boundary.start)
						if err != nil {
							panic(err)
						}
						linter.warn(entry, "overlaps a previous function (%s @ %08X)\n", last_symbol.Symbol.Name, last_symbol.Symbol.StartAddress)
					}
				} else {
					linter.have_last_function_boundary = true
				}
				linter.last_function_boundary = current_function_boundary

				if entry.Symbol.EndAddress == 0 {
					linter.warn(entry, "is missing an end address\n")
				}
			}

			if entry.Symbol.DataType != "" {
				linter.typed_function_count++
			}
		}
	}

	if Profile.Info.FunctionCount != 0 {
		ratio := float64(linter.named_functions_count) / float64(Profile.Info.FunctionCount)
		fmt.Printf("%d out of %d functions named (%f%%)\n", linter.named_functions_count, Profile.Info.FunctionCount, ratio*100.0)
		fmt.Printf("%d warnings generated\n", linter.warnings)
	}

	if linter.named_functions_count != 0 {
		typed_ratio := float64(linter.typed_function_count) / float64(linter.named_functions_count)
		fmt.Printf("%d out of %d (%f%%) named functions have type information", linter.typed_function_count, linter.named_functions_count, typed_ratio*100.0)
	}
}
