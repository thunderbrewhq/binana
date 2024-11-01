package x64dbg

import (
	"fmt"
	"slices"
	"sort"
)

type type_dependency_graph struct {
	all_types map[string]*type_graph_node
}

func (graph *type_dependency_graph) get(name string) *type_graph_node {
	return graph.all_types[name]
}

func new_type_dependency_graph() *type_dependency_graph {
	t := new(type_dependency_graph)
	t.all_types = make(map[string]*type_graph_node)
	return t
}

func new_type_graph_node() *type_graph_node {
	t := new(type_graph_node)
	return t
}

func (graph *type_dependency_graph) get_node_dependencies(t *type_graph_node) (nodes []*type_graph_node, err error) {
	nodes = t.depends_on
	return
}

func (graph *type_dependency_graph) check_sub_dependency_cycle(root_node, sub_node *type_graph_node) (err error) {
	var sub_node_deps []*type_graph_node
	sub_node_deps, err = graph.get_node_dependencies(sub_node)
	for _, dependency_node := range sub_node_deps {
		if dependency_node == root_node {
			return fmt.Errorf("cycle detected with %s", root_node.t.GetName())
		}

		// recursively check for deeper dependency cycles
		if err = graph.check_sub_dependency_cycle(root_node, dependency_node); err != nil {
			return
		}
	}

	return
}

func (graph *type_dependency_graph) check_root_dependency_cycle(node *type_graph_node) (err error) {
	var node_deps []*type_graph_node
	node_deps, err = graph.get_node_dependencies(node)
	for _, dependency_node := range node_deps {
		// check for obvious self-referential
		if dependency_node == node {
			return fmt.Errorf("immediate %s->%s self-reference", node.t.GetName(), node.t.GetName())
		}

		// recursively check for deeper dependency cycles
		if err = graph.check_sub_dependency_cycle(node, dependency_node); err != nil {
			return
		}
	}

	return
}

func (graph *type_dependency_graph) remove_edge(dependency, dependent *type_graph_node) (err error) {
	dependent_index := slices.Index(dependent.depends_on, dependency)
	if dependent_index == -1 {
		err = fmt.Errorf("dependency %s not found in dependent %s", dependency.t.GetName(), dependent.t.GetName())
		return
	}

	dependency_index := slices.Index(dependency.is_depended_on_by, dependent)

	if dependency_index == -1 {
		err = fmt.Errorf("dependent %s not found in dependency %s", dependent.t.GetName(), dependency.t.GetName())
		return
	}

	dependent.depends_on = slices.Delete(dependent.depends_on, dependent_index, dependent_index+1)
	dependency.is_depended_on_by = slices.Delete(dependency.is_depended_on_by, dependency_index, dependency_index+1)

	return nil
}

func (graph *type_dependency_graph) Load(types *Types) (err error) {
	// combine all types into an array
	var all_types []*type_graph_node

	type_exists := map[string]bool{}

	for _, alias_type := range types.Types {
		t := new_type_graph_node()
		at := alias_type
		t.t = &at

		if !type_exists[t.String()] {
			type_exists[t.String()] = true
			all_types = append(all_types, t)
		}
	}

	for _, struct_type := range types.Structs {
		t := new_type_graph_node()
		st := struct_type
		t.t = &st

		if !type_exists[t.String()] {
			type_exists[t.String()] = true
			all_types = append(all_types, t)
		}
	}

	for _, union_type := range types.Unions {
		t := new_type_graph_node()
		ut := union_type
		t.t = &ut

		if !type_exists[t.String()] {
			type_exists[t.String()] = true
			all_types = append(all_types, t)
		}
	}

	for _, func_type := range types.Functions {
		t := new_type_graph_node()
		ft := func_type
		t.t = &ft

		if !type_exists[t.String()] {
			type_exists[t.String()] = true
			all_types = append(all_types, t)
		}
	}

	// load types into map
	graph.all_types = make(map[string]*type_graph_node)
	for _, t := range all_types {
		graph.all_types[t.t.GetName()] = t
	}

	// build graph
	for _, t := range all_types {
		for _, dependency_name := range t.t.Dependencies() {
			if is_type_name_builtin(dependency_name) {
				continue
			}

			dependency_type := graph.get(dependency_name)
			if dependency_type == nil {
				err = fmt.Errorf("unknown dependency name '%s' from type '%s'", dependency_name, t.t.GetName())
				return
			}

			if !slices.Contains(t.depends_on, dependency_type) {
				t.depends_on = append(t.depends_on, dependency_type)
			}

			if !slices.Contains(dependency_type.is_depended_on_by, t) {
				dependency_type.is_depended_on_by = append(dependency_type.is_depended_on_by, t)
			}
		}
	}

	// check for cycles
	for _, t := range all_types {
		if err = graph.check_root_dependency_cycle(t); err != nil {
			return
		}
	}

	return
}

type type_dependency_sorter struct {
	graph      *type_dependency_graph
	type_names []string
}

func new_type_dependency_sorter(graph *type_dependency_graph) *type_dependency_sorter {
	sorter := new(type_dependency_sorter)
	sorter.graph = graph
	for k := range sorter.graph.all_types {
		sorter.type_names = append(sorter.type_names, k)
	}
	sort.Strings(sorter.type_names)
	return sorter
}

func (sorter *type_dependency_sorter) sort() (sorted []*type_graph_node, err error) {
	// first, peel off types with no dependencies.
	var s []*type_graph_node
	var l []*type_graph_node

	for _, type_name := range sorter.type_names {
		node := sorter.graph.all_types[type_name]
		//
		if len(node.depends_on) == 0 {
			s = append(s, node)
		}
	}

	for len(s) != 0 {
		n := s[0]
		s = s[1:]

		l = append(l, n)

		n_dependents := make([]*type_graph_node, len(n.is_depended_on_by))
		copy(n_dependents, n.is_depended_on_by)
		for i := range n_dependents {
			m := n_dependents[i]

			if err = sorter.graph.remove_edge(n, m); err != nil {
				return
			}

			if len(m.depends_on) == 0 {
				s = append(s, m)
			}
		}
	}

	sorted = l
	return
}

func (graph *type_dependency_graph) Save() (types *Types, err error) {
	sorter := new_type_dependency_sorter(graph)

	var sorted []*type_graph_node
	sorted, err = sorter.sort()
	if err != nil {
		return
	}
	types = new(Types)

	for _, t := range sorted {
		switch xt := t.t.(type) {
		case *AliasType:
			types.Types = append(types.Types, *xt)
		case *StructType:
			types.Structs = append(types.Structs, *xt)
		case *UnionType:
			types.Unions = append(types.Unions, *xt)
		case *FunctionType:
			types.Functions = append(types.Functions, *xt)
		default:
			panic(t)
		}
	}

	return

}
