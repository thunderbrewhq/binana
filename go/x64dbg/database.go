package x64dbg

import (
	"encoding/json"
	"os"
)

type Function struct {
	Manual           bool   `json:"manual,omitempty"`
	Start            string `json:"start,omitempty"`
	End              string `json:"end,omitempty"`
	Module           string `json:"module,omitempty"`
	InstructionCount string `json:"icount,omitempty"`
	Parent           string `json:"parent,omitempty"`
}

type Comment struct {
	Manual  bool   `json:"manual,omitempty"`
	Module  string `json:"module,omitempty"`
	Text    string `json:"text,omitempty"`
	Address string `json:"address,omitempty"`
}

type Label struct {
	Manual  bool   `json:"manual,omitempty"`
	Module  string `json:"module,omitempty"`
	Text    string `json:"text,omitempty"`
	Address string `json:"address,omitempty"`
}

type Bookmark struct {
	Manual  bool   `json:"manual,omitempty"`
	Module  string `json:"module,omitempty"`
	Address string `json:"address,omitempty"`
}

type Breakpoint struct {
	Address          string `json:"address,omitempty"`
	CommandText      string `json:"commandText,omitempty"`
	Enabled          bool   `json:"enabled,omitempty"`
	FastResume       string `json:"fastResume,omitempty"`
	OldBytes         string `json:"oldbytes,omitempty"`
	Type             string `json:"type,omitempty"`
	Module           string `json:"module,omitempty"`
	TitanType        string `json:"titantype,omitempty"`
	Name             string `json:"name,omitempty"`
	BreakCondition   string `json:"breakCondition,omitempty"`
	LogText          string `json:"logText,omitempty"`
	LogCondition     string `json:"logCondition,omitempty"`
	Silent           string `json:"silent,omitempty"`
	CommandCondition string `json:"commandCondition,omitempty"`
}

type Database struct {
	Functions   []Function   `json:"functions,omitempty"`
	Comments    []Comment    `json:"comments,omitempty"`
	Labels      []Label      `json:"labels,omitempty"`
	Bookmarks   []Bookmark   `json:"bookmarks,omitempty"`
	Breakpoints []Breakpoint `json:"breakpoints,omitempty"`
}

func SaveDatabase(name string, database *Database) (err error) {
	var file *os.File
	file, err = os.Create(name)
	if err != nil {
		return
	}

	e := json.NewEncoder(file)
	e.SetIndent("", "  ")
	if err = e.Encode(database); err != nil {
		return
	}

	err = file.Close()
	return
}
