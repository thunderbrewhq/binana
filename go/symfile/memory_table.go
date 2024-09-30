package symfile

import (
	"fmt"
	"slices"
	"sort"
)

// Most tables are reasonably-sized and can be kept in memory
type InMemoryTable struct {
	Entries []Entry
}

func (t *InMemoryTable) Insert(entry *Entry) (err error) {
	i := sort.Search(len(t.Entries), func(i int) bool {
		return t.Entries[i].StartAddress >= entry.StartAddress
	})

	if i < len(t.Entries) {
		if t.Entries[i].StartAddress == entry.StartAddress {
			err = fmt.Errorf("symfile: (*InMemoryTable).Insert() failed: duplicate entry: %s", entry.Name)
			return
		}
		t.Entries = slices.Insert(t.Entries, i, *entry)
	} else {
		t.Entries = append(t.Entries, *entry)
	}

	return
}

func (t *InMemoryTable) Len() int {
	return len(t.Entries)
}

func NewInMemoryTable() *InMemoryTable {
	return new(InMemoryTable)
}
