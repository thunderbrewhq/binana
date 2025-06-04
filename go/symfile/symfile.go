package symfile

import (
	"fmt"
	"io"
	"strings"
)

// What kind of Entry is this?
type EntryKind uint8

const (
	// Something that can be executed
	Function EntryKind = 'f'
	// Something that is read or written to
	DataLabel EntryKind = 'l'
)

var (
	valid_kinds = []EntryKind{Function, DataLabel}
)

// An entry in the table
type Entry struct {
	LineNumber uint64
	// Undecorated, raw name
	Name string
	// Offset to the start of the function or data
	StartAddress uint64
	// What kind of Entry is this?
	Kind EntryKind
	// Any table entry can have a comment after a ';' column
	Comment string
	// Attributes
	//  end=AABBCCEEDD
	EndAddress uint64
	//  type=void*
	// The C syntax type of the data
	DataType string
}

func (entry *Entry) String() string {
	var b strings.Builder
	fmt.Fprintf(&b, "%s %08X %c", entry.Name, entry.StartAddress, entry.Kind)
	if entry.EndAddress != 0 {
		fmt.Fprintf(&b, " end=%08X", entry.EndAddress)
	}
	if entry.DataType != "" {
		fmt.Fprintf(&b, " type=\"%s\"", entry.DataType)
	}
	if entry.Comment != "" {
		fmt.Fprintf(&b, " ; %s", entry.Comment)
	}
	return b.String()
}

type Table interface {
	Insert(entry *Entry) (err error)
}

func Load(table Table, text io.Reader) (err error) {
	err = load(text, table)
	return
}
