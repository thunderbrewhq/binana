package x64dbg

import (
	"slices"
	"strings"
)

type type_graph_set []*type_graph_node

type graph_type interface {
	GetName() string
	Dependencies() []string
}

type type_graph_node struct {
	t                 graph_type
	depends_on        type_graph_set
	is_depended_on_by type_graph_set
}

func (t *type_graph_node) String() string {
	return t.t.GetName()
}

var builtins = []string{
	"char",
	"bool",
	"long",
	"short",
	"long long",
	"int",
	"float",
	"double",
	"char*",
	"void*",
	"int8_t",
	"int16_t",
	"int32_t",
	"int64_t",
	"uint8_t",
	"uint16_t",
	"uint32_t",
	"uint64_t",
}

func is_type_name_builtin(t string) bool {
	if strings.HasSuffix(t, "*") {
		return true
	}
	return slices.Contains(builtins, t)
}
