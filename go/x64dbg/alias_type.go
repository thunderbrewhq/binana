package x64dbg

type AliasType struct {
	Type      string `json:"type"`
	Name      string `json:"name"`
	ArraySize int32  `json:"arrsize,omitempty"`
}

func (alias *AliasType) GetName() string {
	return alias.Name
}

func (alias *AliasType) Dependencies() []string {
	return []string{
		alias.Type,
	}
}
