package x64dbg

type StructMemberType struct {
	Type      string `json:"type"`
	Name      string `json:"name"`
	ArraySize int32  `json:"arrsize,omitempty"`
	Offset    int32  `json:"offset"`
}

type StructType struct {
	Name    string             `json:"name"`
	Size    int32              `json:"size"`
	Members []StructMemberType `json:"members,omitempty"`
}

func (struct_ *StructType) GetName() string {
	return struct_.Name
}

func (struct_ *StructType) Dependencies() (s []string) {
	for _, member := range struct_.Members {
		s = append(s, member.Type)
	}

	return
}
