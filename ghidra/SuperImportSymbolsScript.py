#Extended Binana symbols importer script
# @runtime Jython
# @category Binana
# @author Thunderbrew 
# @menupath 
# @toolbar logo.png

import re
import string

from ghidra.app.cmd.function import ApplyFunctionSignatureCmd
from ghidra.app.util.parser import FunctionSignatureParser
from ghidra.util.data import DataTypeParser
from ghidra.program.model.symbol import SourceType
from ghidra.program.model.listing import Function, ParameterImpl, VariableStorage

def find_storage_parameter(str):
    match = re.search(r'@<(\w+)?>', str)
    
    if match:
        return match.group(1)
    return None

def strip_storage_parameter(str):
    pattern = r'@<[^>]+>'

    # Use re.sub to replace the match with an empty string
    return re.sub(pattern, '', str)

def split_function_parameters(str):
    SCAN_FUNC = 1
    SCAN_PARAMETER = 2
    SCAN_ESCAPE_PAREN = 3

    current_word = ''
    parameters = []
    state = SCAN_FUNC
    paren_level = 0
    i = 0
    while i < len(str):
        c = str[i]

        if state == SCAN_FUNC:
            if c == '(':
                state = SCAN_PARAMETER
        elif state == SCAN_PARAMETER:
            if c == '(':
                state = SCAN_ESCAPE_PAREN
                paren_level = 1
                current_word = current_word + c
            elif c == ',':
                parameters.append(current_word.strip())
                current_word = ''
            elif c == ')':
                parameters.append(current_word.strip())
                current_word = ''
                break
            else:
                current_word = current_word + c
        elif state == SCAN_ESCAPE_PAREN:
            current_word = current_word + c
            if c == '(':
                paren_level = paren_level + 1
            elif c == ')':
                paren_level = paren_level - 1

            if paren_level == 0:
                state = SCAN_PARAMETER

        i = i + 1

    if current_word != '':
        parameters.append(current_word.strip())
    return parameters

# return: <calling convention> <optional, this ptr type> <stripped type string>, <map of parameter index numbers to register names> 
def strip_function_type(str):
    # str = int32_t __stdcall func@<eax>(int32_t x@<edi>)

    parameter_storage = {}

    this_ptr_type = ''

    # [ 'int32_t', '__stdcall', 'func@<eax>(int32_t x@<edi>)' ]
    str_parts = str.split(' ') 
    # int32_t
    return_type = str_parts[0]

    # default
    call_conv = '__stdcall'

    i = 0
    last_spec = -1
    func_start = -1
    while i < len(str_parts):
        if str_parts[i].startswith('__'):
            if str_parts[i].endswith('call'):
                call_conv = str_parts[i]
            last_spec = i
        elif str_parts[i].startswith('func'):
            func_start = i
            break
        i = i + 1

    function_call = ' '.join(str_parts[func_start:])

    # [ 'func@<eax>', 'int32_t x@<edi>)' ]
    func_before_after_paren = function_call.split('(', 1)
    # func@<eax>
    func_id = func_before_after_paren[0]
    # [ 'int32_t x@<edi>' ]
    func_parameters = split_function_parameters(function_call) 

    return_parameter_storage = find_storage_parameter(func_id)
    if return_parameter_storage is not None:
        parameter_storage[0] = return_parameter_storage
        func_id = strip_storage_parameter(func_id)

    # start building stripped function type
    stripped_type = return_type
    stripped_type += " "
    stripped_type += func_id

    stripped_type += '('
        
    n = 1
    first = True 
    for argument_parameter in func_parameters:
        if '__return_ptr' in argument_parameter:
            argument_parameter = argument_parameter.replace('__return_ptr ', '')

        if n == 1 and call_conv == '__thiscall':
            # in Ghidra, a this pointer is always added to the signature 
            # we need only record the the type for later
            this_ptr_type = argument_parameter.split(' ', 1)[0]
            # n = n + 1
            # continue
            # 
            # commented out: let's see if this fixed it

        if not first:
            stripped_type += ', '
        else:
            first = False
        argument_parameter_storage = find_storage_parameter(argument_parameter)
        if argument_parameter_storage is not None:
           parameter_storage[n] = argument_parameter_storage
           argument_parameter = strip_storage_parameter(argument_parameter)
        stripped_type += argument_parameter
        n = n + 1
    stripped_type += ')'
    # todo strip parameters
    return call_conv, this_ptr_type, stripped_type, parameter_storage

def parse_attributes(str):
    attributes = {}
    current_key = ''
    current_value = ''
    
    SCAN_ATTRIBUTES = 0
    SCAN_KEY = 1
    SCAN_VALUE = 2

    i = 0
    state = SCAN_ATTRIBUTES
    quote = False
    while i < len(str):
        c = str[i]
        i = i + 1
        if state == SCAN_ATTRIBUTES:
            if c != ' ':
                current_key = c
                state = SCAN_KEY
        elif state == SCAN_KEY:
            if c == ' ':
                # the key terminated early with a space
                # this is valid and means it is a boolean attribute
                state = SCAN_ATTRIBUTES
                attributes[current_key] = True
                current_key = ''
            elif c == '=':
                state = SCAN_VALUE
            else:
                current_key = current_key + c
        elif state == SCAN_VALUE:
            if quote:
                if c == '"':
                    attributes[current_key] = current_value
                    current_key = ''
                    current_value = ''
                    state = SCAN_ATTRIBUTES
                else:
                    current_value = current_value + c 
            else:
                if c == '"':
                    quote = True
                elif c == ' ':
                    attributes[current_key] = current_value
                    current_key = ''
                    current_value = ''
                    state = SCAN_ATTRIBUTES
                else:
                    current_value = current_value + c
    # the line terminated in the middle of scanning a key
    # that means it's a boolean attribute
    if state == SCAN_KEY:
        attributes[current_key] = True

    return attributes

def parse_symbol_entry(line):
    pieces = line.split(' ', 3)
    print(len(pieces))
    if len(pieces) < 3:
        return None

    entry = {}
    entry['label'] = pieces[0]
    entry['address'] = pieces[1]
    entry['kind'] = pieces[2]
    entry['comment'] = ''
    entry['attributes'] = {}

    if len(pieces) > 3:
        et_cetera = pieces[3]
        attributes = et_cetera
        index_of_comment_separator = et_cetera.find(';')
        if index_of_comment_separator != -1:
            entry['comment'] = et_cetera[index_of_comment_separator+1:].lstrip(' ')
            attributes = et_cetera[:index_of_comment_separator]
            attributes = attributes.rstrip(' ')
        entry['attributes'] = parse_attributes(attributes)        

    return entry

def parse_datatype_string(dt_string):
    # Get the current program's data type manager
    dtm = currentProgram.getDataTypeManager()
    
    # Initialize the parser using the program's context
    # Allowed forms: HIDDEN, READ_ONLY, or FULL (updates DTM)
    parser = DataTypeParser(dtm, dtm, None, DataTypeParser.AllowedDataTypes.ALL)
    
    try:
        # Parse the string into a DataType object
        parsed_dt = parser.parse(dt_string)
        print("Successfully parsed: {} as {}".format(dt_string, parsed_dt.getName()))
        return parsed_dt
    except Exception as e:
        print("Error parsing '{}': {}".format(dt_string, e))
        return None

functionManager = currentProgram.getFunctionManager()

f = askFile("Navigate to the Binana all.sym file", "Go")

def apply_function_symbol(entry):
    name = entry['label']
    address = toAddr(entry['address'])

    func = functionManager.getFunctionAt(address)

    if func is not None:
        old_name = func.getName()
        func.setName(name, SourceType.USER_DEFINED)
        print("Renamed function {} to {} at address {}".format(old_name, name, address))
    else:
        func = createFunction(address, name)
        print("Created function {} at address {}".format(name, address))
    
    func_type = entry['attributes'].get('type')
    if func_type is not None:
        calling_convention, this_ptr_type, stripped_func_type, parameter_storage = strip_function_type(func_type)

        # 4. Initialize the parser
        # We pass 'None' for the DataTypeManagerService as it's not strictly required here
        parser = FunctionSignatureParser(currentProgram.getDataTypeManager(), None)

        print('applying signature: {}'.format(stripped_func_type))

        func_signature = parser.parse(None, stripped_func_type)
        if calling_convention == '__usercall':
            calling_convention = '__stdcall'

        # if calling_convention == '__thiscall':
        #     this_ptr_datatype = findDataType(this_ptr_type)
        #     func_signature.replaceArgument(0, 'this', this_ptr_datatype, '', SourceType.USER_DEFINED)

        # apply this information to the function
        func_signature.setCallingConvention(calling_convention)
        cmd = ApplyFunctionSignatureCmd(address, func_signature, SourceType.USER_DEFINED)

        if cmd.applyTo(currentProgram):
            print("Success! Applied signature '{}' to {}".format(entry['label'], entry['address']))
        else:
            print("Failed to apply signature. Reason: {}".format(cmd.getStatusMsg()))

        # if the function is a class method, the storage has to be modified
        # or if the function passes certain arguments by register, in violation of standard calling convention
        if len(parameter_storage) != 0 or calling_convention == '__thiscall':
            # because we have to do this, everything is now manual
            func.setCustomVariableStorage(True)
            
            parameters = func.getParameters()
            # check if changing return storage is needed
            if parameter_storage.get(0) is not None:
                return_register_storage = currentProgram.getRegister(parameter_storage[0].upper())
                return_storage = VariableStorage(currentProgram, return_register_storage)
                func.setReturn(func_signature.getReturnType(), return_storage, SourceType.USER_DEFINED)

            # TODO: adjust this for different architectures
            # only __usercall and __stdcall can pass arguments through stack by default
            stack_offset = 4 
            stack_alignment = 4

            parameter_index = 0
            # fix this ptr storage
            if calling_convention == '__thiscall':
                this_ptr_datatype = parse_datatype_string(this_ptr_type)
                # TODO: fix for other architectures
                # this_parameter_register = currentProgram.getRegister('ECX')
                # this_parameter_storage = VariableStorage(currentProgram, this_parameter_register)
                # parameters[0] = ParameterImpl(parameters[0].getName(), this_ptr_datatype, this_parameter_storage, currentProgram)
                parameters[0] = ParameterImpl(parameters[0].getName(), this_ptr_datatype, parameters[0].getVariableStorage(), currentProgram)
                parameter_index = 1
            # fix storage of main parameters
            while parameter_index < len(parameters):
                if parameter_storage.get(1+parameter_index) is not None:
                    # this parameter wants to be stored in a register
                    parameter_register = currentProgram.getRegister(parameter_storage[1+parameter_index].upper())
                    parameter_variable_storage = VariableStorage(currentProgram, parameter_register)
                    parameters[parameter_index] = ParameterImpl(parameters[parameter_index].getName(), parameters[parameter_index].getDataType(), parameter_variable_storage, currentProgram)
                else:
                    # this parameter wants to be passed in the stack
                    parameter_data_type = parameters[parameter_index].getDataType()
                    parameter_size = parameter_data_type.getLength()
                    parameter_variable_storage = VariableStorage(currentProgram, stack_offset, parameter_size) 
                    parameters[parameter_index] = ParameterImpl(parameters[parameter_index].getName(), parameters[parameter_index].getDataType(), parameter_variable_storage, currentProgram)
                    if parameter_size % stack_alignment != 0:
                        stack_offset = stack_offset + (parameter_size + (parameter_size - (parameter_size % stack_alignment)))
                    else:
                        stack_offset = stack_offset + parameter_size
                parameter_index = parameter_index + 1

            func.replaceParameters(Function.FunctionUpdateType.CUSTOM_STORAGE, True, SourceType.USER_DEFINED, parameters)

def apply_data_symbol(entry):
    address = toAddr(entry['address'])

    # st = currentProgram.getSymbolTable()
    # existing_symbols = st.getSymbols(address)
    # for symbol in existing_symbols:
    #     st.removeSymbolSpecial(symbol)
    #     print("Removed existing label: {}".format(symbol.getName()))

    print("Created label {} at address {}".format(entry['label'], entry['address']))
    createLabel(address, entry['label'], True)
    
    if entry['attributes'].get('type') is not None:
        data_type = parse_datatype_string(entry['attributes']['type'])
        data_type_size = data_type.getLength()
        if data_type is not None:
            # remove existing defined data at address
            clearListing(address, address.add(data_type_size - 1))
            createData(address, data_type)
            print("applied data type {} to label {}".format(entry['attributes']['type'], entry['label']))
        

for line in file(f.absolutePath):  # note, cannot use open(), since that is in GhidraScript
    entry = parse_symbol_entry(line)
    if entry is not None:
        if entry['kind'] == 'f':
            apply_function_symbol(entry)
        elif entry['kind'] == 'l':
            apply_data_symbol(entry)
