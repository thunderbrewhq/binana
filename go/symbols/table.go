package symbols

import (
	"fmt"
	"io"
	"iter"
	"os"
	"path/filepath"
	"slices"
	"strings"
)

type TableEntry struct {
	// the file where the symbol appears
	Filename string
	// the line number where the symbol appears in the file
	Linenumber int
	Symbol     Symbol
}

// Most tables are reasonably sized and can be kept in memory
type Table struct {
	entries map[uint64]*TableEntry
}

func (table *Table) Init() {
	table.entries = make(map[uint64]*TableEntry)
}

// Open opens a symbol file or a tree of symbol files.
func (table *Table) Load(name string) (err error) {
	var (
		root_info os.FileInfo
	)
	root_info, err = os.Stat(name)
	if err != nil {
		return
	}

	if root_info.IsDir() {
		var tree_entries []os.DirEntry
		tree_entries, err = os.ReadDir(name)
		if err != nil {
			return
		}
		slices.SortFunc(tree_entries, func(a, b os.DirEntry) int {
			return strings.Compare(a.Name(), b.Name())
		})
		for _, tree_entry := range tree_entries {
			tree_child_name := filepath.Join(name, tree_entry.Name())
			if err = table.Load(tree_child_name); err != nil {
				return
			}
		}
	} else {
		var symbol_file *os.File
		symbol_file, err = os.Open(name)
		if err != nil {
			return
		}
		err = table.LoadFile(name, symbol_file)
		symbol_file.Close()
		if err != nil {
			return
		}

	}

	return
}

func (table *Table) Entries() iter.Seq[*TableEntry] {
	sorted_entries := make([]*TableEntry, len(table.entries))
	var i int
	for _, entry := range table.entries {
		sorted_entries[i] = entry
		i++
	}
	slices.SortFunc(sorted_entries, func(a, b *TableEntry) int {
		if a.Symbol.StartAddress < b.Symbol.StartAddress {
			return -1
		} else if a.Symbol.StartAddress == b.Symbol.StartAddress {
			return 0
		} else {
			return 1
		}
	})
	return func(yield func(*TableEntry) bool) {
		for _, entry := range sorted_entries {
			if !yield(entry) {
				break
			}
		}
	}
}

// LoadFile reads all symbols from the input stream
func (table *Table) LoadFile(name string, file io.Reader) (err error) {
	err = load(name, file, table)
	return
}

func (table *Table) Insert(entry *TableEntry) (err error) {
	conflicting_symbol, ok := table.entries[entry.Symbol.StartAddress]
	if ok {
		err = fmt.Errorf(
			"%w: cannot insert symbol '%s' (%s:%d) because another symbol '%s' (%s:%d) already exists at that address '%08x'",
			ErrDuplicateSymbol,
			entry.Symbol.Name,
			entry.Filename,
			entry.Linenumber,
			conflicting_symbol.Symbol.Name,
			conflicting_symbol.Filename,
			conflicting_symbol.Linenumber,
			conflicting_symbol.Symbol.StartAddress,
		)
		return
	}

	table.entries[entry.Symbol.StartAddress] = entry

	return
}

func (table *Table) WriteTo(w io.Writer) (n int64, err error) {
	for entry := range table.Entries() {
		var b int64
		b, err = entry.Symbol.WriteTo(w)
		if err != nil {
			return
		}
		n += b
		_, err = w.Write([]byte("\n"))
		if err != nil {
			return
		}
		n++
	}

	return
}

func (table *Table) Len() int {
	return len(table.entries)
}
