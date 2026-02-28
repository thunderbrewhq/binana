package symbols

import (
	"fmt"
	"io"
	"strings"
)

// What kind of Symbol is this?
type SymbolKind uint8

const (
	// Something that can be executed
	Function SymbolKind = 'f'
	// Something that is read or written to
	DataLabel SymbolKind = 'l'
)

var (
	valid_kinds = []SymbolKind{Function, DataLabel}
)

// An entry in the table
type Symbol struct {
	// Undecorated, raw name
	Name string
	// Offset to the start of the function or data
	StartAddress uint64
	// What kind of Symbol is this?
	Kind SymbolKind
	// Any table entry can have a comment after a ';' column
	Comment string
	// Attributes
	//  end=AABBCCEEDD
	EndAddress uint64
	//  type=void*
	// The C syntax type of the data
	DataType string
}

func (entry *Symbol) String() string {
	var b strings.Builder
	entry.WriteTo(&b)
	return b.String()
}

func (entry *Symbol) WriteTo(w io.Writer) (n int64, err error) {
	var b int
	b, err = fmt.Fprintf(w, "%s %08X %c", entry.Name, entry.StartAddress, entry.Kind)
	if err != nil {
		return
	}
	n += int64(b)
	if entry.EndAddress != 0 {
		b, err = fmt.Fprintf(w, " end=%08X", entry.EndAddress)
		if err != nil {
			return
		}
		n += int64(b)
	}

	if entry.DataType != "" {
		b, err = fmt.Fprintf(w, " type=\"%s\"", entry.DataType)
		if err != nil {
			return
		}
		n += int64(b)
	}
	if entry.Comment != "" {
		b, err = fmt.Fprintf(w, " ; %s", entry.Comment)
		if err != nil {
			return
		}
		n += int64(b)
	}
	return
}
