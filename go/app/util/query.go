package util

import (
	"encoding/json"
	"fmt"
	"os"
	"regexp"
	"slices"
	"strconv"

	"github.com/parquet-go/parquet-go"
	"github.com/thunderbrewhq/binana/go/app"
	"github.com/thunderbrewhq/binana/go/db"
)

type QueryPresentationMode uint8

const (
	PresentQueryNormal QueryPresentationMode = iota
	PresentQueryNameOnly
	PresentQuerySampleName
)

type QueryParams struct {
	//
	Present QueryPresentationMode
	// If true, presents the quoted version of the token name
	Quote bool
	// Match pattern for profile
	Profile string
	// Possible values for Program
	Program []string
	// Possible values for OS
	OS []string
	// Possible values for arch
	Arch []string
	// Range of builds to return information for
	MinBuild uint32
	MaxBuild uint32
	// Regular expression for tokens (symbols/type information)
	Token string
	// If true, Token is a RE2 regular expression
	RegEx bool
}

type token_query struct {
	params          *QueryParams
	sample_database map[string]db.Sample
	token_regexp    *regexp.Regexp
}

func format_sample_name(sample db.Sample) (name string) {
	var ext string
	switch sample.MimeType {
	case "application/x-ms-pdb":
		ext = "pdb"
	case "application/vnd.microsoft.portable-executable":
		ext = "exe"
	case "application/x-executable":
		ext = "elf"
	case "application/x-mach-binary":
		ext = "macho"
	default:
		ext = "bin"
	}
	name = fmt.Sprintf("%s-%s-%d-%s-%s.%s", sample.Program, sample.Version, sample.Build, sample.OS, sample.Arch, ext)
	return
}

func (token_query *token_query) present_token(token *db.Token) {
	sample, ok := token_query.sample_database[token.Source]
	if !ok {
		panic(token.Source)
	}
	name_wrap := func(s string) string {
		return s
	}
	if token_query.params.Quote {
		name_wrap = strconv.Quote
	}
	if token_query.params.Present == PresentQueryNameOnly {
		for _, name := range token.Names {
			if token_query.token_regexp.MatchString(name.Name) {
				fmt.Println(name_wrap(name.Name))
			}
		}
		return
	} else if token_query.params.Present == PresentQuerySampleName {
		sample_name := format_sample_name(sample)
		for _, name := range token.Names {
			if token_query.token_regexp.MatchString(name.Name) {
				fmt.Println(sample_name, name_wrap(name.Name))
			}
		}
		return
	}
	kind_name := ""
	switch token.Kind {
	case db.OriginalConstantToken:
		kind_name = "original constant"
	case db.OriginalDatatypeToken:
		kind_name = "original datatype"
	case db.OriginalStringToken:
		kind_name = "original string"
	case db.OriginalSymbolToken:
		kind_name = "original symbol"
	default:
		return
	}
	fmt.Printf("%s in sample: ('%s', %s) section: '%s'", kind_name, token.Source[:8], format_sample_name(sample), token.Section)
	if token.Offset != "" {
		fmt.Printf(" at %s", token.Offset)
	}
	if token.Datatype != "" {
		fmt.Printf(" with datatype: '%s'", token.Datatype)
	}
	fmt.Printf("\n")
	fmt.Printf("names:\n")

	for _, name := range token.Names {
		name_kind_name := ""
		switch name.Kind {
		case db.OriginalName:
			name_kind_name = "original name"
		case db.DemangledName:
			name_kind_name = "demangled name"
		case db.BinanaizedName:
			name_kind_name = "binanaized name"
		default:
			panic(name.Kind)
		}

		fmt.Printf("%s: %s\n", name_kind_name, name_wrap(name.Name))
	}

	fmt.Printf("--\n\n")
}

// attempt to match token and report to stdout
// if returns quit = true, the search is halted
func (token_query *token_query) match_token(token *db.Token) (quit bool) {
	matched := false
	sample, ok := token_query.sample_database[token.Source]
	if !ok {
		m, err := json.Marshal(token)
		if err != nil {
			panic(err)
		}

		fmt.Fprintln(os.Stderr, string(m))
		app.Fatal(fmt.Errorf("a token references a sample (%s) that does not exist in the sample database. please fix your database", token.Source))
		return
	}
	// filter out tokens from samples we don't care about
	if sample.Build < token_query.params.MinBuild || sample.Build > token_query.params.MaxBuild {
		return
	}
	if len(token_query.params.Program) > 0 {
		if !slices.Contains(token_query.params.Program, sample.Program) {
			return
		}
	}
	if len(token_query.params.OS) > 0 {
		if !slices.Contains(token_query.params.OS, sample.OS) {
			return
		}
	}
	if len(token_query.params.Arch) > 0 {
		if !slices.Contains(token_query.params.Arch, sample.Arch) {
			return
		}
	}

	for _, name := range token.Names {
		if token_query.token_regexp.MatchString(name.Name) {
			matched = true
			break
		}
	}
	if matched {
		token_query.present_token(token)
	}
	return
}

func (token_query *token_query) load_sample_database() (err error) {
	token_query.sample_database = make(map[string]db.Sample)

	var samples []db.Sample
	samples, err = parquet.ReadFile[db.Sample]("db/samples.parquet")
	if err != nil {
		return
	}

	for _, sample := range samples {
		token_query.sample_database[sample.ID] = sample
	}
	return
}

func Query(params *QueryParams) {
	var token_query token_query
	token_query.params = params
	if params.RegEx {
		token_query.token_regexp = regexp.MustCompile(token_query.params.Token)
	} else {
		token_query.token_regexp = regexp.MustCompile(regexp.QuoteMeta(params.Token))
	}

	if err := token_query.load_sample_database(); err != nil {
		app.Fatal(err)
	}

	tokens_db_file, err := os.Open("db/tokens.parquet")
	if err != nil {
		app.Fatal(err)
	}

	rows := make([]db.Token, 1024)
	reader := parquet.NewGenericReader[db.Token](tokens_db_file)
read_loop:
	for {
		n, err := reader.Read(rows)
		if err != nil {
			break
		}
		for _, token := range rows[:n] {
			if token_query.match_token(&token) {
				break read_loop
			}
		}
	}
	reader.Close()
	tokens_db_file.Close()
}
