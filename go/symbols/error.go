package symbols

import "fmt"

var (
	ErrDuplicateSymbol = fmt.Errorf("symbols: a symbol already exists at that address")
	ErrLineLeftEmpty   = fmt.Errorf("symbols: line was left empty")
)
