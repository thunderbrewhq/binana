package x64dbg

func SortTypes(types *Types) (err error) {
	graph := new_type_dependency_graph()
	if err = graph.Load(types); err != nil {
		return
	}

	var sorted *Types
	sorted, err = graph.Save()
	if err != nil {
		return
	}

	*types = *sorted
	return
}
