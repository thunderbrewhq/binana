package cmd

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strings"

	"github.com/ianlancetaylor/demangle"
	"github.com/spf13/cobra"
	"github.com/thunderbrewhq/binana/go/symfile"
)

func demangle_symbol_name(name string) (bn_name string, dm_name string, type_str string, err error) {
	// var ast demangle.AST
	// ast, err = demangle.ToAST(name)
	// if err != nil {
	// 	bn_name = name
	// 	err = nil
	// 	return
	// }

	// var name []string
	// var args []string

	// ast.Traverse(func(a demangle.AST) bool {
	// 	if fn_type, ok := a.(*demangle.FunctionType); ok {
	// 		args = append(args, fn_)
	// 	}
	// })

	var dm_err error
	dm_name, dm_err = demangle.ToString(name)
	if dm_err != nil {
		bn_name = name
		return
	}
	bn_name = dm_name

	if strings.Contains(bn_name, "(") {
		var arg string
		bn_name, arg, _ = strings.Cut(bn_name, "(")
		type_str = fmt.Sprintf("uint32_t func(%s", arg)
	}

	bn_name = strings.ReplaceAll(bn_name, "::", "__")
	bn_name = strings.ReplaceAll(bn_name, "<", "_")
	bn_name = strings.ReplaceAll(bn_name, ">", "")

	return
}

func format_symbol_entry(entry *symfile.Entry, out io.Writer) {
	outentry := *entry

	if outentry.Name[0] == '_' && outentry.Name[1] != 'Z' {
		outentry.Name = outentry.Name[1:]
	}
	bn_name, dm_name, _, err := demangle_symbol_name(outentry.Name)
	if err == nil {
		outentry.Name = bn_name
		outentry.Comment = dm_name
		// if outentry.DataType == "" {
		// 	outentry.DataType = dm_type
		// }
	}
	out.Write([]byte(outentry.String()))
	out.Write([]byte("\n"))
}

func format_symbols(in io.Reader, out io.Writer) {
	scanner := bufio.NewScanner(in)
	for scanner.Scan() {
		var entry symfile.Entry
		if err := entry.Parse(scanner.Text()); err != nil {
			fmt.Println(err)
			os.Exit(1)
		}
		format_symbol_entry(&entry, out)
	}
}

func format_symbols_func(cmd *cobra.Command, args []string) {
	format_symbols(os.Stdin, os.Stdout)
}

var format_symbols_cmd = &cobra.Command{
	Use:   "format-symbols",
	Short: "format symbols from stdin",
	Run:   format_symbols_func,
}
