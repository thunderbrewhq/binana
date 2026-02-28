#include <idc.idc>
#include "batch/import_symbols.idc"
#include "batch/import_data_types.idc"
#include "batch/import_functions.idc"

static main() {
	// Import all
	import_symbols();
	import_data_types();
	import_functions();
	// Wait for auto-analysis to be finished
	auto_wait();
}
