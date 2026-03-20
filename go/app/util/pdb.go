package util

import (
	"crypto/sha256"
	"encoding/hex"
	"fmt"
	"maps"
	"slices"
	"sort"
	"strconv"

	"github.com/thunderbrewhq/binana/go/db"
	"github.com/thunderbrewhq/binana/go/pdbconv"
)

type pdb_token_visitor struct {
	tokens_database *tokens_database

	// location of the base module
	base_address  uint64
	pdb_source_id string
	strings       map[string]*db.Token
	datatypes     map[string]*db.Token
	// maps a symbol to a token
	symbols map[uint64]*db.Token

	constants []db.Token
}

func (v *pdb_token_visitor) init(tokens_database *tokens_database, pdb_source_id string, base_address uint64) {
	v.base_address = base_address
	v.pdb_source_id = pdb_source_id
	v.strings = make(map[string]*db.Token)
	v.datatypes = make(map[string]*db.Token)
	// map of address to token
	v.symbols = make(map[uint64]*db.Token)
	v.tokens_database = tokens_database
}

func (v *pdb_token_visitor) visit_class(class *pdbconv.Class) (err error) {
	token, ok := v.datatypes[class.Name]
	if !ok {
		token = new(db.Token)
		v.datatypes[class.Name] = token
	}

	// set token source to pdb
	token.Source = v.pdb_source_id
	// kind is debug information token
	token.Kind = db.OriginalDatatypeToken

	// set original name
	token.Names = append(token.Names, db.TokenName{db.OriginalName, class.Name})

	// set the basic type
	token.Keyword = "class"

	for _, member := range class.Members {
		var token_member db.TokenMember
		if member.Kind == "Member" {
			token_member.Kind = db.FieldMember
		} else if member.Kind == "Unknown" && member.Datatype == "void *" {
			token_member.Kind = db.MethodMember
		} else {
			continue
		}
		token_member.Key = member.Name
		token_member.Value = member.Datatype

		if !slices.Contains(token.Members, token_member) {
			token.Members = append(token.Members, token_member)
		}
	}
	return
}

func (v *pdb_token_visitor) visit_datatype(datatype *pdbconv.Datatype) (err error) {
	token, ok := v.datatypes[datatype.Name]
	if !ok {
		token = new(db.Token)
		v.datatypes[datatype.Name] = token
	}

	// set token source to pdb
	token.Source = v.pdb_source_id
	// kind is debug information token
	token.Kind = db.OriginalDatatypeToken

	// set original name
	token.Names = append(token.Names, db.TokenName{db.OriginalName, datatype.Name})

	// set the basic type
	if datatype.Kind == "Structure" {
		token.Keyword = "struct"
	} else if datatype.Kind == "Union" {
		token.Keyword = "union"
	} else {
		err = fmt.Errorf("unhandled datatype kind '%s'", datatype.Kind)
		return
	}

	for _, member := range datatype.Members {
		var token_member db.TokenMember
		if member.Kind == "Member" {
			token_member.Kind = db.FieldMember
		} else if member.Kind == "Unknown" && member.Datatype == "void *" {
			token_member.Kind = db.MethodMember
		} else {
			continue
		}
		token_member.Key = member.Name
		token_member.Value = member.Datatype

		if !slices.Contains(token.Members, token_member) {
			token.Members = append(token.Members, token_member)
		}
	}
	return
}

func (v *pdb_token_visitor) visit_function(function *pdbconv.Function) (err error) {
	var address uint64
	address, err = strconv.ParseUint(function.Address, 0, 64)
	if err != nil {
		return
	}

	address = v.base_address + address

	token, ok := v.symbols[address]
	if !ok {
		token = new(db.Token)
		v.symbols[address] = token
	}

	// set token source to pdb
	token.Source = v.pdb_source_id
	// kind is symbol information token
	token.Kind = db.OriginalSymbolToken
	// set address
	token.Offset = fmt.Sprintf("%X", address)
	// set original name
	token.Names = append(token.Names, db.TokenName{db.OriginalName, function.Name})

	if looks_mangled(function.Name) {
		demangled, demangler_err := demangle(function.Name)
		if demangler_err == nil {
			token.Names = append(token.Names, db.TokenName{db.DemangledName, demangled})
		}
	}

	// visit source files
	for _, line_number := range function.LineNumbers {
		if err = v.visit_string(line_number.SourceFile); err != nil {
			return
		}
	}

	// classify stack variables as members
	for _, stack_variable := range function.StackVariables {
		var token_member db.TokenMember
		if stack_variable.Kind == "Parameter" || stack_variable.Kind == "ObjectPointer" {
			token_member.Kind = db.ParameterMember
		} else if stack_variable.Kind == "Local" {
			token_member.Kind = db.LocalMember
		} else if stack_variable.Kind == "StaticLocal" {
			token_member.Kind = db.StaticLocalMember
		} else if stack_variable.Kind == "Constant" {
			// these are repeated elsewhere
			continue
		} else {
			err = fmt.Errorf("unhandled stack variable kind '%s'", stack_variable.Kind)
			return
		}

		token_member.Key = stack_variable.Name
		token_member.Value = stack_variable.Datatype

		token.Members = append(token.Members, token_member)
	}

	return
}

func (v *pdb_token_visitor) visit_enum(enum *pdbconv.Enum) (err error) {
	// create hash of enum's contents and use to key the datatype
	h := sha256.New()
	h.Write([]byte(enum.Name))
	for _, member := range enum.Members {
		h.Write([]byte(member.Name))
		h.Write([]byte(fmt.Sprintf("%d", member.Value)))
	}
	name := hex.EncodeToString(h.Sum(nil))

	token, ok := v.datatypes[name]
	if !ok {
		token = new(db.Token)
		v.datatypes[name] = token
	}

	token.Source = v.pdb_source_id

	token.Keyword = "enum"

	// apply name (may be __unnamed)
	token.Names = append(token.Names, db.TokenName{db.OriginalName, enum.Name})

	// this is an original datatype
	token.Kind = db.OriginalDatatypeToken

	for _, member := range enum.Members {
		var token_member db.TokenMember
		token_member.Kind = db.EnumMember
		token_member.Key = member.Name
		token_member.Value = fmt.Sprintf("%d", member.Value)

		if !slices.Contains(token.Members, token_member) {
			token.Members = append(token.Members, token_member)
		}
	}

	return
}

func (v *pdb_token_visitor) visit_string(s string) (err error) {
	token, ok := v.strings[s]
	if !ok {
		token = new(db.Token)
		v.strings[s] = token
	}

	// apply source
	token.Source = v.pdb_source_id

	// this is a string token
	token.Kind = db.OriginalStringToken

	// add name
	var token_name db.TokenName
	token_name.Kind = db.OriginalName
	token_name.Name = s
	token.Names = []db.TokenName{token_name}

	return
}

func (v *pdb_token_visitor) visit_source_files_table(table *pdbconv.Table) (err error) {
	for _, source_file := range table.SourceFiles {
		if err = v.visit_string(source_file.Name); err != nil {
			return
		}
	}

	return
}

func (v *pdb_token_visitor) visit_constant(symbol *pdbconv.TableSymbol) (err error) {
	var token db.Token
	token.ID = v.tokens_database.next_token_id()
	token.Source = v.pdb_source_id
	token.Keyword = "const"
	token.Datatype = symbol.Datatype

	if symbol.Name != "" {
		var name db.TokenName
		name.Kind = db.OriginalName
		name.Name = symbol.Name
		token.Names = append(token.Names, name)
	}

	if symbol.Undecorated != "" {
		var name db.TokenName
		name.Kind = db.OriginalName
		name.Name = symbol.Undecorated
		token.Names = append(token.Names, name)
	}

	var value db.TokenMember
	value.Kind = db.ConstantValueMember
	value.Value = symbol.Value

	token.Members = append(token.Members, value)

	v.constants = append(v.constants, token)
	return
}

func (v *pdb_token_visitor) visit_table_symbol(symbol *pdbconv.TableSymbol) (err error) {
	if symbol.Address == "0x0" {
		if symbol.Value != "" && symbol.Kind == "Constant" {
			err = v.visit_constant(symbol)
			return
		}

		// so, this does not correspond to an actual symbol.
		// we can still mine it for string tokens.
		if symbol.Name != "" {
			if err = v.visit_string(symbol.Name); err != nil {
				return
			}
		}

		if symbol.Undecorated != "" {
			if err = v.visit_string(symbol.Name); err != nil {
				return
			}
		}

		return
	}

	// this corresponds to an address
	// compute the real address
	var address uint64
	address, err = strconv.ParseUint(symbol.Address, 0, 64)
	if err != nil {
		return
	}

	address = v.base_address + address

	token, ok := v.symbols[address]
	if !ok {
		token = new(db.Token)
		v.symbols[address] = token
	}
	token.Source = v.pdb_source_id

	if symbol.Datatype != "" {
		token.Datatype = symbol.Datatype
	}

	if symbol.Kind == "FileStatic" {
		token.Keyword = "static"
	} else if symbol.Kind == "Global" {
		token.Keyword = "global"
	}

	if symbol.Name != "" {
		token_name := db.TokenName{db.OriginalName, symbol.Name}
		if !slices.Contains(token.Names, token_name) {
			token.Names = append(token.Names, token_name)
		}
	}

	if symbol.Undecorated != "" {
		undecorated := db.TokenName{db.OriginalName, symbol.Undecorated}
		if !slices.Contains(token.Names, undecorated) {
			token.Names = append(token.Names, undecorated)
		}
	}

	return
}

func (v *pdb_token_visitor) visit_symbols_table(table *pdbconv.Table) (err error) {
	for _, symbol := range table.Symbols {
		if err = v.visit_table_symbol(&symbol); err != nil {
			return
		}
	}

	return
}

func (v *pdb_token_visitor) visit_table(table *pdbconv.Table) (err error) {
	if table.Name == "SourceFiles" {
		err = v.visit_source_files_table(table)
	} else if table.Name == "Symbols" {
		err = v.visit_symbols_table(table)
	}
	return
}

func (v *pdb_token_visitor) visit_typedef(typedef *pdbconv.Typedef) (err error) {
	token, ok := v.datatypes[typedef.Name]
	if !ok {
		token = new(db.Token)
		v.datatypes[typedef.Name] = token
	}

	token.Source = v.pdb_source_id

	token.Kind = db.OriginalDatatypeToken

	var token_name db.TokenName
	token_name.Kind = db.OriginalName
	token_name.Name = typedef.Name

	if !slices.Contains(token.Names, token_name) {
		token.Names = append(token.Names, token_name)
	}

	token.Datatype = typedef.Basetype

	return
}

func (v *pdb_token_visitor) visit_all(pdb *pdbconv.ProgramDatabase) (err error) {
	for _, class := range pdb.Classes {
		if err = v.visit_class(&class); err != nil {
			return
		}
	}

	for _, datatype := range pdb.Datatypes {
		if err = v.visit_datatype(&datatype); err != nil {
			return
		}
	}

	for _, enum := range pdb.Enums {
		if err = v.visit_enum(&enum); err != nil {
			return
		}
	}

	for _, function := range pdb.Functions {
		if err = v.visit_function(&function); err != nil {
			return
		}
	}

	for _, table := range pdb.Tables {
		if err = v.visit_table(&table); err != nil {
			return
		}
	}

	for _, typedef := range pdb.Typedefs {
		if err = v.visit_typedef(&typedef); err != nil {
			return
		}
	}

	return
}

func (v *pdb_token_visitor) write_tokens() (err error) {
	datatypes := slices.Collect(maps.Keys(v.datatypes))
	sort.Strings(datatypes)
	symbols := slices.Collect(maps.Keys(v.symbols))
	slices.SortFunc(symbols, func(a, b uint64) int {
		if a < b {
			return -1
		} else if a == b {
			return 0
		}
		return 1
	})
	strings := slices.Collect(maps.Keys(v.strings))
	sort.Strings(strings)
	for _, datatype := range datatypes {
		if err = v.tokens_database.Write(v.datatypes[datatype]); err != nil {
			return
		}
	}
	for _, symbol := range symbols {
		if err = v.tokens_database.Write(v.symbols[symbol]); err != nil {
			return
		}
	}
	for _, string := range strings {
		if err = v.tokens_database.Write(v.strings[string]); err != nil {
			return
		}
	}
	for _, constant := range v.constants {
		if err = v.tokens_database.Write(&constant); err != nil {
			return
		}
	}
	return
}
