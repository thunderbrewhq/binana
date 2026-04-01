#Copy the current function as a Binana symbol entry to your clipboard
# @runtime Jython
# @category Binana
# @author Thunderbrew 
# @keybinding Shift-F
# @menupath 
# @toolbar logo.png

from ghidra.program.model.symbol import SymbolType
from java.awt import Toolkit
from java.awt.datatransfer import StringSelection
from ghidra.app.decompiler import DecompInterface
from ghidra.util.task import ConsoleTaskMonitor

def yank_to_clipboard(text):
    selection = StringSelection(text)
    clipboard = Toolkit.getDefaultToolkit().getSystemClipboard()
    clipboard.setContents(selection, None)

def get_high_function_signature(func):
    """Uses the Decompiler to get the refined signature."""
    if func is None:
        return ""
        
    iface = DecompInterface()
    iface.openProgram(currentProgram)
    
    results = iface.decompileFunction(func, 30, ConsoleTaskMonitor())
    high_func = results.getHighFunction()
    
    if high_func is None:
        return 

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
    
    full_signature = get_high_function_signature(func)

    output = "{} {} f end={} type=\"{}\"".format(
        name, 
        entry_addr, 
        end_addr, 
        full_signature
    ) 
    return output

def yank_current_function_symbol():
    listing = currentProgram.getListing()
    func = listing.getFunctionContaining(currentAddress)

    if func is None:
        print("No function found at the current cursor position.")
        return
    output = get_symbol_entry_for_function(func)
    yank_to_clipboard(output)
    print("Copied to clipboard: {}".format(output))

yank_current_function_symbol()
