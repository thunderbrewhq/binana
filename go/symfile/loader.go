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

func parse_attributes(attribute_columns []string) (attributes map[string]string, err error) {
	attributes = make(map[string]string)
	var (
		scanning_quoted_string bool
		current_key            string
		current_value          string
	)
	for _, attribute_column := range attribute_columns {
		if scanning_quoted_string {
			current_value += " "
			current_value += attribute_column

			if strings.HasSuffix(attribute_column, `"`) {
				scanning_quoted_string = false
				attributes[current_key], err = strconv.Unquote(current_value)
				if err != nil {
					return
				}
				current_key = ""
				current_value = ""
				continue
			} else {
				continue
			}
		}

		key, value_start, found := strings.Cut(attribute_column, "=")
		if !found {
			err = fmt.Errorf("extraneous column: '%s'", attribute_column)
			return
		}

		current_key = key

		if strings.HasPrefix(value_start, `"`) {
			current_value = value_start
			if strings.HasSuffix(value_start, `"`) {
				attributes[current_key], err = strconv.Unquote(value_start)
				if err != nil {
					return
				}
				continue
			} else {
				scanning_quoted_string = true
			}
		} else {
			// unquoted, we can succeed immediately
			attributes[current_key] = value_start
			current_value = ""
			current_key = ""
			continue
		}
	}

	if scanning_quoted_string {
		err = fmt.Errorf("line ends in the middle of a quoted attribute --> \"%s", current_value)
		return
	}

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
		extra_columns := columns[3:num_semantic_columns]

		var attributes map[string]string
		attributes, err = parse_attributes(extra_columns)
		if err != nil {
			return fmt.Errorf("symfile: (*loader).parse_line: line %d: error parsing attribute: '%s'", l.line_number, err)
		}

		if data_type, found := attributes["type"]; found {
			entry.DataType = data_type
		}

		if end_address, found := attributes["end"]; found {
			entry.EndAddress, err = strconv.ParseUint(end_address, 16, 64)
			if err != nil {
				return
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
				err = fmt.Errorf("symfile: error reading at line %d: %w", l.line_number, err)
				return
			}
		}

		if err = l.parse_line(line); err != nil {
			err = fmt.Errorf("symfile: error parsing at line %d: %w", l.line_number, err)
			return
		}
	}

	return
}
