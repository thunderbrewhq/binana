package symbols

import (
	"bufio"
	"errors"
	"fmt"
	"io"
	"strings"
)

const min_columns = 3

type loader struct {
	filename    string
	input       *bufio.Reader
	table       *Table
	line_number int
}

func (l *loader) read_line() (line string, err error) {
	line, err = l.input.ReadString('\n')
	if err != nil {
		return
	}
	line = strings.TrimRight(line, "\r\n")
	l.line_number++
	return
}

func (l *loader) parse_line(line string) (err error) {
	var table_entry TableEntry
	table_entry.Filename = l.filename
	table_entry.Linenumber = l.line_number

	if line == "" {
		//err = fmt.Errorf("%w: %s:%d", ErrLineLeftEmpty, table_entry.Filename, table_entry.Linenumber)
		return
	}

	if err = table_entry.Symbol.Parse(line); err != nil {
		err = fmt.Errorf("%w: %s:%d", err, table_entry.Filename, table_entry.Linenumber)
		return
	}

	err = l.table.Insert(&table_entry)
	return
}

func load(filename string, file io.Reader, table *Table) (err error) {
	l := new(loader)

	l.input = bufio.NewReader(file)
	l.filename = filename
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
				err = fmt.Errorf("symbols: error reading at line %d: %w", l.line_number, err)
				return
			}
		}

		if err = l.parse_line(line); err != nil {
			err = fmt.Errorf("symbols: error parsing at line %d: %w", l.line_number, err)
			return
		}
	}

	return
}
