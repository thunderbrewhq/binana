package x64dbg

import (
	"encoding/json"
	"io"
	"os"

	"github.com/pierrec/lz4/v4"
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

func SaveDatabase(name string, database *Database, compress bool) (err error) {
	var file *os.File
	file, err = os.Create(name)
	if err != nil {
		return
	}

	var writecloser io.WriteCloser = file

	if compress {
		lz4_writer := lz4.NewWriter(file)
		writecloser = lz4_writer
	}

	e := json.NewEncoder(writecloser)
	e.SetIndent("", "  ")
	if err = e.Encode(database); err != nil {
		return
	}

	if compress {
		writecloser.Close()
	}

	err = file.Close()
	return
}
