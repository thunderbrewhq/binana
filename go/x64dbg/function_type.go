package x64dbg

type FunctionType struct {
	ReturnType     string      `json:"rettype"`
	CallConvention string      `json:"callconv"`
	NoReturn       bool        `json:"noreturn"`
	Name           string      `json:"name"`
	Arguments      []AliasType `json:"arguments,omitempty"`
}

func (function *FunctionType) GetName() string {
	return function.Name
}

func (function *FunctionType) Dependencies() (s []string) {
	if function.ReturnType != "" {
		s = append(s, function.ReturnType)
	}
	for _, t := range function.Arguments {
		s = append(s, t.Type)
	}
	return
}
