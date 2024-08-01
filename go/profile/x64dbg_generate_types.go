package profile

import (
	"fmt"
	"path/filepath"
	"slices"
	"sort"

	"github.com/thunderbrewhq/binana/go/x64dbg"
	"modernc.org/cc/v3"
)

func sort_string_ids(ids []cc.StringID) {
	sort.Slice(ids, func(i, j int) bool {
		return ids[i] < ids[j]
	})
}

func cc_type_to_struct_member_type(t cc.Type) (m x64dbg.StructMemberType) {
	var s string
	var arrsize int32 = 1
	var array bool

loop:
	for t != nil {
		if t.Name().String() != "" {
			s = t.Name().String() + s
			break
		}

		switch t.Kind() {
		case cc.Ptr:
			s = "*" + s
		case cc.Array:
			array = true
			arrsize *= int32(t.Len())
		case cc.Function:
			s = "void*" + s
			break loop
		default:
			s = t.Kind().String() + s
			break loop
		}

		t = t.Elem()
	}

	if array {
		m.ArraySize = arrsize
	}

	m.Offset = -1
	m.Type = s

	return
}

func cc_type_to_typedef(t cc.Type) (m x64dbg.AliasType) {
	var s string
	var arrsize int32 = 1
	var array bool

loop:
	for t != nil {

		if t.Name().String() != "" && t.Kind() != cc.Enum {
			s = t.Name().String() + s
			break
		}

		switch t.Kind() {
		case cc.Enum:
			s = t.EnumType().String() + s
			break loop
		case cc.Ptr:
			s = "*" + s
		case cc.Array:
			array = true
			arrsize *= int32(t.Len())
		case cc.Function:
			s = "void*" + s
		default:
			s = t.Kind().String() + s
			break loop
		}

		t = t.Elem()
	}

	if array {
		m.ArraySize = arrsize
	}

	m.Type = s

	return
}

// parses the C headers and generates a matching x64dbg types.json file
func (profile *Profile) generate_x64dbg_types() (err error) {
	// parse C headers
	var cc_config cc.Config
	cc_config.ABI, err = cc.NewABI("windows", "386")
	if err != nil {
		panic(err)
	}

	cc_include_paths := []string{
		filepath.Join(profile.Directory, "include"),
	}

	cc_system_include_paths := []string{
		filepath.Join("go", "profile", "include"),
	}

	cc_sources := []cc.Source{
		cc.Source{
			Name: filepath.Join(profile.Directory, "include", "main.h"),
		},
	}

	var ast *cc.AST
	ast, err = cc.Translate(&cc_config, cc_include_paths, cc_system_include_paths, cc_sources)
	if err != nil {
		return
	}

	var x64_types x64dbg.Types

	// Parse integer types
	var scope_ids []cc.StringID
	for name := range ast.Scope {
		scope_ids = append(scope_ids, name)
	}

	sort_string_ids(scope_ids)

	// these types needed by the C parser can't be included in x64dbg json
	ignore_types := []string{
		"int8_t",
		"int16_t",
		"int32_t",
		"int64_t",

		"uint8_t",
		"uint16_t",
		"uint32_t",
		"uint64_t",

		"bool",
	}

	for _, scope_id := range scope_ids {
		scope := ast.Scope[scope_id]
		for _, node := range scope {
			if declarator, ok := node.(*cc.Declarator); ok {
				if declarator.IsTypedefName {
					if declarator.Type().Kind() != cc.Struct {
						var x64_type x64dbg.AliasType = cc_type_to_typedef(declarator.Type())
						x64_type.Name = scope_id.String()
						if !slices.Contains(ignore_types, x64_type.Name) {
							x64_types.Types = append(x64_types.Types, x64_type)
						}
					}
				}
			}
		}
	}

	var struct_names []cc.StringID
	for struct_name := range ast.StructTypes {
		struct_names = append(struct_names, struct_name)
	}
	sort.Slice(struct_names, func(i, j int) bool {
		return struct_names[i] < struct_names[j]
	})

	for _, struct_name := range struct_names {
		struct_type := ast.StructTypes[struct_name]

		var x64_struct x64dbg.StructType
		x64_struct.Name = struct_name.String()
		x64_struct.Size = int32(struct_type.Size())

		for i := range struct_type.NumField() {
			struct_member := struct_type.FieldByIndex([]int{i})

			// If struct member is a union
			if struct_member.Type().Kind() == cc.Union {
				union_member_name := struct_member.Name().String()
				if union_member_name == "" {
					// union is anonymous
					union_member_name = fmt.Sprintf("%04d", struct_member.Offset())
				}

				union_type_name := fmt.Sprintf("%s__%s", struct_name.String(), union_member_name)

				var x64_union x64dbg.UnionType
				x64_union.Name = union_type_name

				for i := range struct_member.Type().NumField() {
					union_field := struct_member.Type().FieldByIndex([]int{i})
					var x64_union_member x64dbg.AliasType = cc_type_to_typedef(union_field.Type())
					x64_union_member.Name = union_field.Name().String()
					x64_union.Members = append(x64_union.Members, x64_union_member)
				}

				x64_types.Unions = append(x64_types.Unions, x64_union)

				x64_struct_member := x64dbg.StructMemberType{}
				x64_struct_member.Type = union_type_name
				x64_struct_member.Name = struct_member.Name().String()
				x64_struct_member.Offset = int32(struct_member.Offset())
				// x64_struct_member.Offset = -1
				x64_struct.Members = append(x64_struct.Members, x64_struct_member)
			} else {

				x64_struct_member := cc_type_to_struct_member_type(struct_member.Type())
				x64_struct_member.Name = struct_member.Name().String()
				// x64_struct_member.Offset = -1
				x64_struct_member.Offset = int32(struct_member.Offset())
				x64_struct.Members = append(x64_struct.Members, x64_struct_member)
			}
		}

		x64_types.Structs = append(x64_types.Structs, x64_struct)
	}

	types_file_path := filepath.Join(profile.Directory, "x32dbg", "types.json")

	err = x64dbg.SortTypes(&x64_types)
	if err != nil {
		return
	}

	err = x64dbg.SaveTypes(types_file_path, &x64_types)
	if err != nil {
		return
	}

	fmt.Println("types generated!", types_file_path)

	return
}
