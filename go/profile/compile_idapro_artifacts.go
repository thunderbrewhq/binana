package profile

import (
	_ "embed"
	"fmt"
	"os"
	"path/filepath"
	"strconv"

	"github.com/thunderbrewhq/binana/go/symbols"
)

var (
	//go:embed ida/import_all.idc
	import_all_script []byte

	//go:embed ida/import_data_types.idc
	import_data_types_script []byte

	//go:embed ida/import_functions.idc
	import_functions_script []byte

	//go:embed ida/import_symbols.idc
	import_symbols_script []byte
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
	batch_path := filepath.Join(profile.ArtifactsDirectory, "ida", "batch")
	if err = os.MkdirAll(batch_path, 0755); err != nil {
		return
	}
	b = new(idac_import_batch)
	b.fd, err = os.Create(filepath.Join(batch_path, name+".idc"))
	if err != nil {
		return
	}

	return
}

func compile_idapro_artifacts(profile *Profile, params *CompileArtifactsParams) (err error) {
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

	for symbol := range profile.Symbols.Entries() {
		name := symbol.Symbol.Name
		instances := name_instances[name]
		name_instances[name] = instances + 1

		if instances != 0 {
			name = fmt.Sprintf("%s@%d", name, instances+1)
		}

		quoted_name := strconv.Quote(name)
		address := fmt.Sprintf("0x%08X", symbol.Symbol.StartAddress)
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
	for symbol := range profile.Symbols.Entries() {
		if symbol.Symbol.DataType != "" {
			quoted_data_type := strconv.Quote(symbol.Symbol.DataType)
			address := fmt.Sprintf("0x%08X", symbol.Symbol.StartAddress)
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
	for function_symbol := range profile.Symbols.Entries() {
		if function_symbol.Symbol.Kind == symbols.Function {
			address := fmt.Sprintf("0x%08X", function_symbol.Symbol.StartAddress)
			// b.P("set_func_start(%s, %s);", address, address)
			// if function_symbol.EndAddress != 0 {
			// 	end_address := fmt.Sprintf("0x%08X", function_symbol.EndAddress)
			// 	b.P("set_func_end(%s, %s);", address, end_address)
			// }
			if function_symbol.Symbol.Comment != "" {
				b.P("set_func_cmt(%s, %s, 0);", address, strconv.Quote(function_symbol.Symbol.Comment))
			}
		}
	}
	b.T(0)
	b.P("}")

	b.Close()

	// include stock scripts
	ida_path := filepath.Join(profile.ArtifactsDirectory, "ida")
	if err = os.MkdirAll(ida_path, 0755); err != nil {
		return
	}
	if err = os.WriteFile(filepath.Join(ida_path, "import_all.idc"), import_all_script, 0755); err != nil {
		return
	}
	if err = os.WriteFile(filepath.Join(ida_path, "import_data_types.idc"), import_data_types_script, 0755); err != nil {
		return
	}
	if err = os.WriteFile(filepath.Join(ida_path, "import_functions.idc"), import_functions_script, 0755); err != nil {
		return
	}
	if err = os.WriteFile(filepath.Join(ida_path, "import_symbols.idc"), import_symbols_script, 0755); err != nil {
		return
	}

	return
}
