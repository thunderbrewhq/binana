package db

type (
	TokenKind       uint8
	TokenNameKind   uint8
	TokenMemberKind uint8
)

const (
	// OriginalName means this string appeared verbatim in the original sample, and was not altered.
	OriginalName TokenNameKind = iota
	// DemangledName is provided in the case that the OriginalName was mangled by the compiler.
	DemangledName
	// Mangled names can be automatically Binanaized, i.e. converted into a naive syntax for wide
	// compatibility with SRE tools
	BinanaizedName
)

const (
	// The token was obtained from a PDB or a Mach-O symtab
	OriginalSymbolToken TokenKind = iota
	// The token was found by scanning the non-executable sections of the binary for 0-terminated ASCII strings
	OriginalStringToken
	// The token is a datatype was obtained from a PDB or DWARF debugging file
	OriginalDatatypeToken
	// This token is a constant named value with no address
	OriginalConstantToken
)

const (
	ConstantValueMember TokenMemberKind = iota
	EnumMember
	// This is a part of a struct
	// key = the field name
	// value = the C type of the field
	FieldMember
	// This is a method of a class
	MethodMember
	// This in argument to a function
	ParameterMember
	// This is a local variable in a function
	LocalMember
	// This is a statically declared variable in a function
	StaticLocalMember
)

type TokenName struct {
	Kind TokenNameKind `json:"kind" parquet:"kind"`
	Name string        `json:"name" parquet:"name,dict"`
}

type TokenMember struct {
	Kind  TokenMemberKind `json:"kind" parquet:"kind"`
	Key   string          `json:"key,omitempty" parquet:"key,dict"`
	Value string          `json:"value" parquet:"value,dict"`
}

type Token struct {
	// Unique 64-bit identifier
	ID uint64 `json:"id" parquet:"id"`
	// The SHA-256 hash id of the sample which generated the token
	Source string `json:"src" parquet:"src,dict"`
	// The color and subhead of the token
	Kind TokenKind `json:"kind" parquet:"kind"`
	// If this is a datatype, keyword tells you what kind of datatype it is. Useful when generating C code.
	Keyword string `json:"keyword,omitempty" parquet:"keyword,dict"`
	// If this is a global variable/constant, this tells you the data type
	Datatype string `json:"datatype,omitempty" parquet:"datatype,dict"`
	// The section where the token originated
	Section string `json:"section,omitempty"`
	// The offset (in hexadecimal) where the symbol
	Offset string `json:"offset,omitempty"`
	// Alternate names for the token
	Names []TokenName `json:"names"`
	// Clickable references to other tokens
	Highlights []string `json:"crumbs,omitempty"`
	// Struct/Enum members
	Members []TokenMember `json:"members,omitempty"`
}
