package x64dbg

import (
	"encoding/json"
	"os"
)

// Describes the format of an x64dbg type information file
type Types struct {
	Types     []AliasType    `json:"types,omitempty"`
	Structs   []StructType   `json:"structs,omitempty"`
	Unions    []UnionType    `json:"unions,omitempty"`
	Functions []FunctionType `json:"functions,omitempty"`
}

func SaveTypes(name string, types *Types) (err error) {
	var file *os.File
	file, err = os.Create(name)
	if err != nil {
		return
	}

	e := json.NewEncoder(file)
	e.SetIndent("", "  ")
	if err = e.Encode(types); err != nil {
		return
	}

	err = file.Close()
	return
}

func LoadTypes(name string) (types *Types, err error) {
	var file *os.File
	file, err = os.Open(name)
	if err != nil {
		return
	}

	types = new(Types)

	e := json.NewDecoder(file)
	if err = e.Decode(types); err != nil {
		return
	}

	err = file.Close()
	return
}
