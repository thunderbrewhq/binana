package symbols

import "fmt"

var (
	ErrSymbolNotFound  = fmt.Errorf("symbols: symbol not found")
	ErrDuplicateSymbol = fmt.Errorf("symbols: a symbol already exists at that address")
	ErrLineLeftEmpty   = fmt.Errorf("symbols: line was left empty")
)
