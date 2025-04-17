package symfile

import (
	"bufio"
	"errors"
	"fmt"
	"io"
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
	var entry Entry
	if err = entry.Parse(line); err != nil {
		err = fmt.Errorf("%w: line %d", err, l.line_number)
		return
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
