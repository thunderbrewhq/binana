#Export all functions in the database to a Binana symbol file
# @runtime Jython
# @category Binana
# @author Thunderbrew 
# @keybinding Shift-E
# @menupath 
# @toolbar logo.png

from ghidra.program.model.symbol import SymbolType
from java.awt import Toolkit
from java.awt.datatransfer import StringSelection
from ghidra.app.decompiler import DecompInterface
from ghidra.util.task import ConsoleTaskMonitor
from ghidra.program.model.symbol.SourceType import *

functionManager = currentProgram.getFunctionManager()

file_location = askFile("Choose a file to save your Binana symbols ot", "Go")

listing = currentProgram.getListing()

decomp_interface = DecompInterface()
decomp_interface.openProgram(currentProgram)

def get_function_type(func):
    """Uses the Decompiler to get the refined signature."""
    if func is None:
        return ""
        
    results = decomp_interface.decompileFunction(func, 30, ConsoleTaskMonitor())
    high_func = results.getHighFunction()
    
    if high_func is None:
        return "" 

    ret_type = high_func.getFunctionPrototype().getReturnType().getName().replace(" *", "*")

    call_conv = high_func.getFunctionPrototype().getModelName()

    params = []
    num_params = high_func.getFunctionPrototype().getNumParams()
    for i in range(num_params):
        p = high_func.getFunctionPrototype().getParam(i)
        params.append("{} {}".format(p.getDataType().getName().replace(" *", "*"), p.getName()))
    
    param_str = "(" + (", ".join(params)) + ")"
    return ret_type + " " + call_conv + " func" + param_str

def get_symbol_entry_for_function(func):
    name = func.getName()
    
    entry_addr = func.getEntryPoint().toString().upper()[-8:]
    body = func.getBody()
    end_addr = (body.getMaxAddress().add(1)).toString().upper()[-8:]
    
    func_type = get_function_type(func)

    if func_type == "":
        output = "{} {} f end={}".format(name, entry_addr, end_addr)
    else:
        output = "{} {} f end={} type=\"{}\"".format(
            name, 
            entry_addr, 
            end_addr, 
            func_type 
        ) 
    return output

def export_function_symbols(file):
  monitor.setMessage("Exporting function symbols...")

  for f in functionManager.getFunctionsNoStubs(1):
    monitor.checkCanceled() # throws exception if canceled

    if f.isExternal() or f.isThunk():
      continue

    func_line = get_symbol_entry_for_function(f)
    monitor.setMessage(func_line)

    file.write(func_line + "\n")

  return
  
with open(file_location.absolutePath, "w") as file:
  export_function_symbols(file)
  file.close()
