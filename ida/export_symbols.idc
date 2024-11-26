#include <idc.idc>

static bna_format_address(ea) {
  return sprintf("%08X", ea);
}

static bna_save_function_symbols(fd) {
  auto func_address;
  auto func_name;
  auto func_start;
  auto func_end;
  auto func_line;

  while ((func_address = get_next_func(func_address)) != -1) {
    func_name = get_func_name(func_address);
    
    if (func_name) {
      func_start = get_func_attr(func_address, FUNCATTR_START);
      func_end = get_func_attr(func_address, FUNCATTR_END);

      func_line = sprintf(
        "%s %s f end=%s ; %08X",
        func_name, bna_format_address(func_start), bna_format_address(func_end), get_func_attr(func_address, FUNCATTR_FLAGS));

      if (fprintf(fd, "%s\n", func_line) != 0) {
        error("bna_save_function_symbols: failed to write line break to file");
        return 0;
      }
    }
  }

  return 1;
}

static bna_save_label_symbols(fd) {
  return 1;
} 

static main() {
  // Ask use for output file
  auto output_filename;
  auto output_file;

  output_filename = ask_file(1, "all.sym", "Enter a path to export your symbols");
  if (output_filename == 0) {
    error("No output file specified. Doing NOTHING.");
    return 1;
  }

  output_file = fopen(output_filename, "w");

  if (!output_file) {
    error("Failed to open output file '%s' for writing", output_filename);
    return 0;
  }

  if (!bna_save_function_symbols(output_file)) {
    return 0;
  }

  if (!bna_save_label_symbols(output_file)) {
    return 0;
  }

  fclose(output_file);

  warning("Successfully exported to %s", output_filename);

  return 1;
}