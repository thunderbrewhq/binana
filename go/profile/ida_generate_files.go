package profile

import (
	"fmt"
	"os"
	"path/filepath"
	"strconv"

	"github.com/thunderbrewhq/binana/go/symfile"
)

type idac_import_batch struct {
	tab int
	fd  *os.File
}

// Include/import
func (b *idac_import_batch) I(global bool, filename string) (err error) {
	var (
		hq_global = [2]rune{'<', '>'}
		hq_local  = [2]rune{'"', '"'}
	)
	hq := hq_local
	if global {
		hq = hq_global
	}
	_, err = fmt.Fprintf(b.fd, "#include %c%s%c\n", hq[0], filename, hq[1])
	return
}

func (b *idac_import_batch) T(tabs int) {
	b.tab = tabs
}

// Print
func (b *idac_import_batch) P(f string, list ...any) (err error) {
	for range b.tab {
		if _, err = fmt.Fprint(b.fd, "\t"); err != nil {
			return
		}
	}
	_, err = fmt.Fprintf(b.fd, f, list...)
	if err != nil {
		return
	}
	_, err = fmt.Fprint(b.fd, "\n")
	return
}

// Newline n times
func (b *idac_import_batch) N(n int) (err error) {
	for range n {
		if _, err = fmt.Fprint(b.fd, "\n"); err != nil {
			return
		}
	}

	return
}

func (b *idac_import_batch) Close() (err error) {
	err = b.fd.Close()
	return
}

func (profile *Profile) create_idac_import_batch(name string) (b *idac_import_batch, err error) {
	b = new(idac_import_batch)
	b.fd, err = os.Create(filepath.Join(profile.Directory, "ida", "batch", name+".idc"))
	if err != nil {
		return
	}

	return
}

func (profile *Profile) generate_symbols_idc() (err error) {
	// symbols
	var b *idac_import_batch
	b, err = profile.create_idac_import_batch("import_symbols")
	if err != nil {
		return
	}
	b.I(true, "idc.idc")
	b.N(1)
	b.P("static import_symbols() {")
	b.T(1)
	b.P("// Set/create names")

	name_instances := make(map[string]int)

	for _, symbol := range profile.SymbolTable.Entries {
		name := symbol.Name
		instances := name_instances[name]
		name_instances[name] = instances + 1

		if instances != 0 {
			name = fmt.Sprintf("%s@%d", name, instances+1)
		}

		quoted_name := strconv.Quote(name)
		address := fmt.Sprintf("0x%08X", symbol.StartAddress)
		b.P("set_name(%s, %s);", address, quoted_name)
	}
	b.T(0)
	b.P("}")

	b.Close()

	// data label types
	b, err = profile.create_idac_import_batch("import_data_types")
	if err != nil {
		return
	}

	b.I(true, "idc.idc")
	b.N(1)
	b.P("static import_data_types() {")
	b.T(1)
	b.P("// Give types to data labels")
	for _, symbol := range profile.SymbolTable.Entries {
		if symbol.DataType != "" {
			quoted_data_type := strconv.Quote(symbol.DataType)
			address := fmt.Sprintf("0x%08X", symbol.StartAddress)
			b.P("apply_type(%s, %s);", address, quoted_data_type)
		}
	}
	b.T(0)
	b.P("}")

	b.Close()

	// functions
	b, err = profile.create_idac_import_batch("import_functions")
	if err != nil {
		return
	}

	b.I(true, "idc.idc")
	b.N(1)
	b.P("static import_functions() {")
	b.T(1)
	b.P("// Import function addresses and comments")
	b.P(`msg("Importing function addresses and comments");`)
	for _, function_symbol := range profile.SymbolTable.Entries {
		if function_symbol.Kind == symfile.Function {
			address := fmt.Sprintf("0x%08X", function_symbol.StartAddress)
			// b.P("set_func_start(%s, %s);", address, address)
			// if function_symbol.EndAddress != 0 {
			// 	end_address := fmt.Sprintf("0x%08X", function_symbol.EndAddress)
			// 	b.P("set_func_end(%s, %s);", address, end_address)
			// }
			if function_symbol.Comment != "" {
				b.P("set_func_cmt(%s, %s, 0);", address, strconv.Quote(function_symbol.Comment))
			}
		}
	}
	b.T(0)
	b.P("}")

	b.Close()

	return
}

func (profile *Profile) CreateIDAFiles() (err error) {
	err = profile.generate_symbols_idc()
	return
}
