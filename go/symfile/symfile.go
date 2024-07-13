package symfile

import (
	"io"
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
}

type Table interface {
	Insert(entry *Entry) (err error)
	// Find() (iter func() (entry *Entry, err error))
}

func Load(table Table, text io.Reader) (err error) {
	err = load(text, table)
	return
}
