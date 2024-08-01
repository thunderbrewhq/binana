package x64dbg

type UnionType struct {
	Name    string      `json:"name"`
	Members []AliasType `json:"members,omitempty"`
}

func (union *UnionType) GetName() string {
	return union.Name
}

func (union *UnionType) Dependencies() (s []string) {
	for _, member := range union.Members {
		s = append(s, member.Type)
	}

	return
}
