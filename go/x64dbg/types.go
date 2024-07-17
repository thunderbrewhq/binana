package x64dbg

import (
	"encoding/json"
	"os"
)

type Type struct {
	Type      string `json:"type"`
	Name      string `json:"name"`
	ArraySize int32  `json:"arrsize,omitempty"`
}

type StructMemberType struct {
	Type      string `json:"type"`
	Name      string `json:"name"`
	ArraySize int32  `json:"arrsize,omitempty"`
	Offset    int32  `json:"offset,omitempty"`
}

type StructType struct {
	Name    string             `json:"name"`
	Members []StructMemberType `json:"members,omitempty"`
}

type UnionType struct {
	Name    string `json:"name"`
	Members []Type `json:"members,omitempty"`
}

type FunctionType struct {
	ReturnType     string `json:"rettype"`
	CallConvention string `json:"callconv"`
	NoReturn       bool   `json:"noreturn"`
	Name           string `json:"name"`
	Arguments      []Type `json:"arguments,omitempty"`
}

type Types struct {
	Types     []Type         `json:"types,omitempty"`
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
