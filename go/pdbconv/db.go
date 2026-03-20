package pdbconv

type ClassMember struct {
	Datatype string `json:"datatype,omitempty"`
	Kind     string `json:"kind,omitempty"`
	Length   uint64 `json:"length,omitempty"`
	Name     string `json:"name,omitempty"`
	Offset   uint64 `json:"offset,omitempty"`
}

type Class struct {
	Length  string        `json:"length,omitempty"`
	Name    string        `json:"name,omitempty"`
	Members []ClassMember `json:"member,omitempty"`
}

type DatatypeMember struct {
	Datatype string `json:"datatype,omitempty"`
	Kind     string `json:"kind,omitempty"`
	Length   uint64 `json:"length,omitempty"`
	Name     string `json:"name,omitempty"`
	Offset   uint64 `json:"offset,omitempty"`
}

type Datatype struct {
	Kind    string           `json:"kind,omitempty"`
	Length  string           `json:"length,omitempty"`
	Name    string           `json:"name,omitempty"`
	Members []DatatypeMember `json:"member,omitempty"`
}

type EnumMember struct {
	Name  string `json:"name,omitempty"`
	Value int    `json:"value,omitempty"`
}

type Enum struct {
	Length  uint64       `json:"length,omitempty"`
	Name    string       `json:"name,omitempty"`
	Type    string       `json:"type,omitempty"`
	Members []EnumMember `json:"member,omitempty"`
}

type FunctionLineNumber struct {
	Address    string `json:"addr,omitempty"`
	End        int    `json:"end,omitempty"`
	Length     int    `json:"length,omitempty"`
	SourceFile string `json:"source_file,omitempty"`
	Start      int    `json:"start,omitempty"`
}

type FunctionStackVariable struct {
	Datatype string `json:"datatype,omitempty"`
	Kind     string `json:"kind,omitempty"`
	Length   uint64 `json:"length,omitempty"`
	Name     string `json:"name,omitempty"`
	Offset   uint64 `json:"offset,omitempty"`
}

type Function struct {
	Address        string                  `json:"address,omitempty"`
	Length         uint64                  `json:"length,omitempty"`
	Name           string                  `json:"name,omitempty"`
	LineNumbers    []FunctionLineNumber    `json:"line_numbers,omitempty"`
	StackVariables []FunctionStackVariable `json:"stack_variables,omitempty"`
}

type TableSegment struct {
	Address string `json:"address,omitempty"`
	Number  int    `json:"number,omitempty"`
}

type TableSourceFile struct {
	ID   string `json:"id,omitempty"`
	Name string `json:"name,omitempty"`
}

type TableSymbol struct {
	Address     string `json:"address,omitempty"`
	Datatype    string `json:"datatype,omitempty"`
	Index       uint64 `json:"index,omitempty"`
	Kind        string `json:"kind,omitempty"`
	Length      uint64 `json:"length,omitempty"`
	Name        string `json:"name,omitempty"`
	Tag         string `json:"tag,omitempty"`
	Undecorated string `json:"undecorated,omitempty"`
	Value       string `json:"value,omitempty"`
}

type Table struct {
	Name        string            `json:"name,omitempty"`
	Segments    []TableSegment    `json:"segments,omitempty"`
	SourceFiles []TableSourceFile `json:"source_files,omitempty"`
	Symbols     []TableSymbol     `json:"symbols,omitempty"`
}

type Typedef struct {
	Basetype string `json:"basetype,omitempty"`
	Name     string `json:"name,omitempty"`
}

type ProgramDatabase struct {
	Classes   []Class    `json:"classes,omitempty"`
	Datatypes []Datatype `json:"datatypes,omitempty"`
	Enums     []Enum     `json:"enums,omitempty"`
	Functions []Function `json:"functions,omitempty"`
	Tables    []Table    `json:"tables,omitempty"`
	Typedefs  []Typedef  `json:"typedefs,omitempty"`
}
