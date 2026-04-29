package util

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"regexp"
	"strings"

	"github.com/thunderbrewhq/binana/go/symbols"
)

type FixLabelsParams struct {
	// the input symbols file
	Input string
	// the list of fixed symbol names
	FixList string
	// regex to capture a word that will be matched against the fixlist
	Capture string
	// pattern to insert the match into so it may be checked against the fixlist
	FixPattern string
}

func read_fixlist(path string) ([]string, error) {
	file, err := os.Open(path)
	if err != nil {
		return nil, err
	}
	defer file.Close()

	var lines []string
	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		lines = append(lines, scanner.Text())
	}
	return lines, scanner.Err()
}

func FixLabels(params *FixLabelsParams) {
	capture := regexp.MustCompile(params.Capture)
	var (
		input      io.Reader
		input_file *os.File
		fixlist    []string
		table      symbols.Table
		err        error
	)

	if params.Input != "" {
		input_file, err = os.Open(params.Input)
		if err != nil {
			return
		}
		input = input_file
	} else {
		input = os.Stdin
	}

	if params.FixList == "" {
		panic("must have fix list")
	}

	fixlist, err = read_fixlist(params.FixList)
	if err != nil {
		panic(err)
	}

	table.Init()
	if err = table.LoadFile(params.Input, input); err != nil {
		return
	}
	if input_file != nil {
		input_file.Close()
	}

	for entry := range table.Entries() {
		symbol := entry.Symbol
		matches := capture.FindAllStringSubmatch(symbol.Name, 1)
		if len(matches) > 0 {
			//fmt.Fprintln(os.Stderr, "matches: ", matches)
			match := matches[0][1]
			fixed_match := strings.Replace(params.FixPattern, "$", match, 1)
			for _, fix := range fixlist {
				if strings.ToUpper(fixed_match) == strings.ToUpper(fix) {
					symbol.Name = fix
					break
				}
			}
		}
		fmt.Println(symbol.String())
	}
}
