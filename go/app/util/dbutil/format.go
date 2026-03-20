package dbutil

import "errors"

type DatabaseFormat uint8

const (
	DatabaseParquet DatabaseFormat = iota
	DatabaseJSON
)

var (
	ErrUnknownDatabaseFormat = errors.New("dbutil: unknown database format")
)
