package profile

import (
	"fmt"
	"os"
	"path/filepath"
	"strconv"

	"github.com/thunderbrewhq/binana/go/symfile"
)

func (profile *Profile) generate_symbols_idc() (err error) {

	var (
		output_file *os.File
	)
	output_file, err = os.Create(filepath.Join(profile.Directory, "ida", "import.idc"))
	if err != nil {
		return
	}

	fmt.Fprintf(output_file, "#include <idc.idc>\n")
	fmt.Fprintf(output_file, "\n")
	fmt.Fprintf(output_file, "static main() {\n")
	fmt.Fprintf(output_file, "  // Make names\n")

	for _, symbol := range profile.SymbolTable.Entries {
		quoted_name := strconv.Quote(symbol.Name)
		address := fmt.Sprintf("0x%08X", symbol.StartAddress)
		fmt.Fprintf(output_file, "  set_name(%s, %s);\n", address, quoted_name)
	}

	fmt.Fprintf(output_file, "  // Make functions\n")

	for _, function_symbol := range profile.SymbolTable.Entries {
		if function_symbol.Kind == symfile.Function {
			address := fmt.Sprintf("0x%08X", function_symbol.StartAddress)
			fmt.Fprintf(output_file, "  set_func_start(%s, %s);\n", address, address)
			if function_symbol.EndAddress != 0 {
				end_address := fmt.Sprintf("0x%08X", function_symbol.EndAddress)
				fmt.Fprintf(output_file, "  set_func_end(%s, %s);\n", address, end_address)
			}
		}
	}

	fmt.Fprintf(output_file, "}\n")

	output_file.Close()
	return
}

func (profile *Profile) CreateIDAFiles() (err error) {
	err = profile.generate_symbols_idc()
	return
}
