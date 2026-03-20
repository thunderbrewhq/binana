package pdbconv

type GhidraXml struct {
	Classes struct {
		Class []struct {
			Length string `xml:"length,attr"`
			Name   string `xml:"name,attr"`
			Member []struct {
				Datatype string `xml:"datatype,attr"`
				Kind     string `xml:"kind,attr"`
				Length   string `xml:"length,attr"`
				Name     string `xml:"name,attr"`
				Offset   string `xml:"offset,attr"`
			} `xml:"member"`
		} `xml:"class"`
	} `xml:"classes"`
	Datatypes struct {
		Datatype []struct {
			Kind   string `xml:"kind,attr"`
			Length string `xml:"length,attr"`
			Name   string `xml:"name,attr"`
			Member []struct {
				Datatype string `xml:"datatype,attr"`
				Kind     string `xml:"kind,attr"`
				Length   string `xml:"length,attr"`
				Name     string `xml:"name,attr"`
				Offset   string `xml:"offset,attr"`
			} `xml:"member"`
		} `xml:"datatype"`
	} `xml:"datatypes"`
	Enums struct {
		Enum []struct {
			Length string `xml:"length,attr"`
			Name   string `xml:"name,attr"`
			Type   string `xml:"type,attr"`
			Member []struct {
				Name  string `xml:"name,attr"`
				Value int    `xml:"value,attr"`
			} `xml:"member"`
		} `xml:"enum"`
	} `xml:"enums"`
	Functions struct {
		Function []struct {
			Address    string `xml:"address,attr"`
			Length     string `xml:"length,attr"`
			Name       string `xml:"name,attr"`
			LineNumber []struct {
				Addr       string `xml:"addr,attr"`
				End        int    `xml:"end,attr"`
				Length     int    `xml:"length,attr"`
				SourceFile string `xml:"source_file,attr"`
				Start      int    `xml:"start,attr"`
			} `xml:"line_number"`
			StackVariable []struct {
				Datatype string `xml:"datatype,attr"`
				Kind     string `xml:"kind,attr"`
				Length   string `xml:"length,attr"`
				Name     string `xml:"name,attr"`
				Offset   string `xml:"offset,attr"`
			} `xml:"stack_variable"`
		} `xml:"function"`
	} `xml:"functions"`
	Tables struct {
		Table []struct {
			Name    string `xml:"name,attr"`
			Segment []struct {
				Address string `xml:"address,attr"`
				Number  int    `xml:"number,attr"`
			} `xml:"segment"`
			SourceFile []struct {
				ID   string `xml:"id,attr"`
				Name string `xml:"name,attr"`
			} `xml:"source_file"`
			Symbol []struct {
				Address     string `xml:"address,attr"`
				Datatype    string `xml:"datatype,attr"`
				Index       string `xml:"index,attr"`
				Kind        string `xml:"kind,attr"`
				Length      string `xml:"length,attr"`
				Name        string `xml:"name,attr"`
				Tag         string `xml:"tag,attr"`
				Undecorated string `xml:"undecorated,attr"`
				Value       string `xml:"value,attr"`
			} `xml:"symbol"`
		} `xml:"table"`
	} `xml:"tables"`
	Typedefs struct {
		Typedef []struct {
			Basetype string `xml:"basetype,attr"`
			Name     string `xml:"name,attr"`
		} `xml:"typedef"`
	} `xml:"typedefs"`
}
