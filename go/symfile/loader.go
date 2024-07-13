package symfile

import (
	"bufio"
	"errors"
	"fmt"
	"io"
	"slices"
	"strconv"
	"strings"
)

const min_columns = 3

type loader struct {
	input       *bufio.Reader
	table       Table
	line_number int
}

func (l *loader) read_line() (line string, err error) {
	l.line_number++
	line, err = l.input.ReadString('\n')
	if err != nil {
		return
	}
	line = strings.TrimRight(line, "\r\n")
	return
}

func (l *loader) parse_line(line string) (err error) {
	// trim extraneous whitespace
	line = strings.Trim(line, " \t")

	// split into columns
	columns := strings.Split(line, " ")

	// validate
	if len(columns) < min_columns {
		// this line is discarded but not in error
		return
	}
	var (
		start_address uint64
		comment_text  string
	)

	// get name of symbol
	name_column := columns[0]
	if name_column == "" {
		return fmt.Errorf("symfile: (*loader).parse_line: line %d: entry has invalid name '%s", l.line_number, name_column)
	}

	start_address, err = strconv.ParseUint(columns[1], 16, 64)
	if err != nil {
		return
	}

	kind_column := columns[2]
	if len(kind_column) != 1 {
		return fmt.Errorf("symfile: (*loader).parse_line: line %d: entry has invalid kind", l.line_number)
	}

	kind := EntryKind(kind_column[0])

	if !slices.Contains(valid_kinds, kind) {
		return fmt.Errorf("symfile: (*loader).parse_line: line %d: entry has invalid kind", l.line_number)
	}

	// find index of comment column
	index_of_comment := slices.Index(columns, ";")

	var num_semantic_columns int

	if index_of_comment != -1 {
		num_semantic_columns = index_of_comment
		comment_text_columns := columns[index_of_comment+1:]
		comment_text = strings.Join(comment_text_columns, " ")
	} else {
		num_semantic_columns = len(columns)
	}

	// Start to build entry
	var entry Entry
	entry.Name = name_column
	entry.StartAddress = start_address
	entry.Kind = kind
	entry.Comment = comment_text

	// build attributes
	if num_semantic_columns > 3 {
		for _, column := range columns[3:] {
			key, value, found := strings.Cut(column, "=")
			if found {
				switch key {
				case "end":
					entry.EndAddress, err = strconv.ParseUint(value, 16, 64)
					if err != nil {
						return
					}
				default:
					return fmt.Errorf("symfile: (*loader).parse_line: line %d: unknown attribute '%s'", l.line_number, key)
				}
			}
		}
	}

	err = l.table.Insert(&entry)
	return
}

func load(text io.Reader, table Table) (err error) {
	l := new(loader)

	l.input = bufio.NewReader(text)
	l.table = table

	var (
		line string
	)

	for {
		line, err = l.read_line()
		if err != nil {
			if errors.Is(err, io.EOF) {
				err = nil
				break
			} else {
				return
			}
		}

		if err = l.parse_line(line); err != nil {
			return
		}
	}

	return
}
