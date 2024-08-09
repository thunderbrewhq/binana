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
		f *os.File
	)
	f, err = os.Create(filepath.Join(profile.Directory, "ida", "import_symbols.idc"))
	if err != nil {
		return
	}

	fmt.Fprintf(f, "#include <idc.idc>\n")
	fmt.Fprintf(f, "\n")
	fmt.Fprintf(f, "#include \"import_data_types.idc\"\n")
	fmt.Fprintf(f, "static main() {\n")
	fmt.Fprintf(f, "  // Make names\n")

	for _, symbol := range profile.SymbolTable.Entries {
		quoted_name := strconv.Quote(symbol.Name)
		address := fmt.Sprintf("0x%08X", symbol.StartAddress)
		fmt.Fprintf(f, "  set_name(%s, %s);\n", address, quoted_name)
	}

	fmt.Fprintf(f, "  // Make functions\n")

	for _, function_symbol := range profile.SymbolTable.Entries {
		if function_symbol.Kind == symfile.Function {
			address := fmt.Sprintf("0x%08X", function_symbol.StartAddress)
			fmt.Fprintf(f, "  set_func_start(%s, %s);\n", address, address)
			if function_symbol.EndAddress != 0 {
				end_address := fmt.Sprintf("0x%08X", function_symbol.EndAddress)
				fmt.Fprintf(f, "  set_func_end(%s, %s);\n", address, end_address)
			}
		}
	}
	fmt.Fprintf(f, "  // Apply data types\n")
	fmt.Fprintf(f, "  import_data_types();\n")
	fmt.Fprintf(f, "}\n")

	f.Close()

	f, err = os.Create(filepath.Join(profile.Directory, "ida", "import_data_types.idc"))
	if err != nil {
		return
	}

	fmt.Fprintf(f, "#include <idc.idc>\n")
	fmt.Fprintf(f, "\n")
	fmt.Fprintf(f, "static import_data_types() {\n")

	for _, symbol := range profile.SymbolTable.Entries {
		if symbol.DataType != "" {
			quoted_data_type := strconv.Quote(symbol.DataType)
			address := fmt.Sprintf("0x%08X", symbol.StartAddress)
			fmt.Fprintf(f, "  apply_type(%s, %s);\n", address, quoted_data_type)
		}
	}

	fmt.Fprintf(f, "}\n")

	return
}

func (profile *Profile) CreateIDAFiles() (err error) {
	err = profile.generate_symbols_idc()
	return
}
