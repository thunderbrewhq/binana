from ghidra.program.model.symbol.SourceType import *

functionManager = currentProgram.getFunctionManager()

file_location = askFile("Choose a file to write to", "Go baby go!")

listing = currentProgram.getListing()

def export_function_symbols(file):
  monitor.setMessage("Exporting function symbols...")

  for f in functionManager.getFunctionsNoStubs(1):
    monitor.checkCanceled() # throws exception if canceled

    if f.isExternal() or f.isThunk():
      continue

    func_name = f.getName()

    if func_name.startswith("FUN_"):
      continue

    func_start_address = f.getBody().getMinAddress().getOffset()
    func_end_address = f.getBody().getMaxAddress().getOffset() + 1
    
    line_template = "{name} {start_address:08X} f end={end_address:08X}\n"

    func_line = line_template.format(name = func_name, start_address = func_start_address, end_address = func_end_address)

    file.write(func_line)

  return
  
with open(file_location.absolutePath, "w") as file:
  export_function_symbols(file)
  file.close()