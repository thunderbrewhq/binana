package dbutil

import (
	"encoding/json"
	"fmt"
	"io"
	"os"

	"github.com/parquet-go/parquet-go"
)

type Writer[T any] struct {
	write func([]T) (err error)
	close func() (err error)
}

func (writer *Writer[T]) WriteEntries(entries []T) (err error) {
	err = writer.write(entries)
	return
}

func (writer *Writer[T]) Close() (err error) {
	err = writer.close()
	return
}

func Open[T any](name string, format DatabaseFormat) (writer *Writer[T], err error) {
	writer = new(Writer[T])
	var (
		file   *os.File
		output io.Writer
	)
	if name == "" {
		output = os.Stdout
	} else {
		file, err = os.Create(name)
		if err != nil {
			return
		}
		output = file
	}
	switch format {

	case DatabaseJSON:
		encoder := json.NewEncoder(output)
		writer.write = func(entries []T) (err error) {
			for _, entry := range entries {
				if err = encoder.Encode(&entry); err != nil {
					return
				}
			}
			return
		}
		writer.close = func() (err error) {
			if file != nil {
				err = file.Close()
			}
			return
		}
	case DatabaseParquet:
		generic_writer := parquet.NewGenericWriter[T](output)
		writer.write = func(entries []T) (err error) {
			_, err = generic_writer.Write(entries)
			return
		}
		writer.close = func() (err error) {
			if err = generic_writer.Close(); err != nil {
				return
			}
			if file != nil {
				err = file.Close()
			}

			return
		}
	default:
		err = fmt.Errorf("%w: %d", ErrUnknownDatabaseFormat, format)
	}
	return
}
