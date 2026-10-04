local CE = {
    vtByte   = 0,
    vtWord   = 1,
    vtDword  = 2,
    vtQword  = 3,
    vtSingle = 4,
    vtDouble = 5,
    vtString = 6,
    vtGrouped = 14,
}

local Types = {
    -- Unsigned integers
    uint8   = { ce = CE.vtByte,   size = 1 },
    uint16  = { ce = CE.vtWord,   size = 2 },
    uint32  = { ce = CE.vtDword,  size = 4 },
    uint64  = { ce = CE.vtQword,  size = 8 },
    
    -- Signed integers
    int8    = { ce = CE.vtByte,   size = 1 },
    int16   = { ce = CE.vtWord,   size = 2 },
    int32   = { ce = CE.vtDword,  size = 4 },
    int64   = { ce = CE.vtQword,  size = 8 },
    
    -- Floating point
    float   = { ce = CE.vtSingle, size = 4 },
    double  = { ce = CE.vtDouble, size = 8 },
    
    -- Pointers
    ptr     = { ce = CE.vtDword,  size = 4 },
    ptr32   = { ce = CE.vtDword,  size = 4 },
    ptr64   = { ce = CE.vtQword,  size = 8 },
    
    -- Aliases
    bool    = { ce = CE.vtByte,   size = 1 },
    bool32  = { ce = CE.vtDword,  size = 4 },
    char    = { ce = CE.vtByte,   size = 1 },
    byte    = { ce = CE.vtByte,   size = 1 },
    word    = { ce = CE.vtWord,   size = 2 },
    dword   = { ce = CE.vtDword,  size = 4 },
    qword   = { ce = CE.vtQword,  size = 8 },
}

local StructRegistry = {}

function SetPointerSize(bits)
    if bits == 64 then
        Types.ptr = { ce = CE.vtQword, size = 8 }
    else
        Types.ptr = { ce = CE.vtDword, size = 4 }
    end
end

local StructDef = {}
StructDef.__index = StructDef

-- @param name
-- @param parent
function StructDef.new(name, parent)
    local self = setmetatable({}, StructDef)
    self.name = name
    self.parent = parent
    self.ownFields = {}
    self.embeddings = {}

    if parent then
        self._offset = parent:totalSize()
    else
        self._offset = 0
    end

    if name then
        StructRegistry[name] = self
    end

    return self
end

-- @param name
-- @param typeName  (uint32, float, ptr etc)
-- @param opts      {hex=bool, color=number}
function StructDef:field(name, typeName, opts)
    opts = opts or {}

    local typeInfo = Types[typeName]
    if not typeInfo then
        error(string.format("Unknown type '%s' for field '%s'", typeName, name))
    end

    table.insert(self.ownFields, {
        fieldOffset = self._offset,
        name        = name,
        type        = typeInfo.ce,
        size        = typeInfo.size,
        color       = opts.color,
        hex         = opts.hex,
    })

    self._offset = self._offset + typeInfo.size
    return self
end

StructDef.f = StructDef.field

--- Add hex-field
function StructDef:hex(name, typeName, opts)
    opts = opts or {}
    opts.hex = true
    return self:field(name, typeName, opts)
end

function StructDef:flag8(name, opts)
    opts = opts or {}
    opts.hex = true
    return self:field(name, "uint8", opts)
end

function StructDef:flag16(name, opts)
    opts = opts or {}
    opts.hex = true
    return self:field(name, "uint16", opts)
end

function StructDef:flag32(name, opts)
    opts = opts or {}
    opts.hex = true
    return self:field(name, "uint32", opts)
end

function StructDef:flag64(name, opts)
    opts = opts or {}
    opts.hex = true
    return self:field(name, "uint64", opts)
end

--- Add string
function StructDef:string(name, size, opts)
    opts = opts or {}

    table.insert(self.ownFields, {
        fieldOffset = self._offset,
        name        = name,
        type        = CE.vtString,
        string_size = size,
        size        = size,
        color       = opts.color,
    })

    self._offset = self._offset + size
    return self
end

--- Add array
function StructDef:array(name, typeName, count, opts)
    opts = opts or {}

    local typeInfo = Types[typeName]
    if not typeInfo then
        error(string.format("Unknown type '%s' for array '%s'", typeName, name))
    end

    for i = 0, count - 1 do
        table.insert(self.ownFields, {
            fieldOffset = self._offset + i * typeInfo.size,
            name        = string.format("%s[%d]", name, i),
            type        = typeInfo.ce,
            size        = typeInfo.size,
            color       = opts.color,
            hex         = opts.hex,
        })
    end

    self._offset = self._offset + count * typeInfo.size
    return self
end

--- skip to X bytes
function StructDef:paddingTo(targetOffset, opts)
    local size = targetOffset - self._offset
    if size <= 0 then
        return self
    end

    opts = opts or {}
    local remaining = size

    while remaining >= 4 do
        local name = string.format("unk_%04X", self._offset)
        self:field(name, "uint32", opts)
        remaining = remaining - 4
    end

    while remaining >= 1 do
        local name = string.format("unk_%04X", self._offset)
        self:field(name, "uint8", opts)
        remaining = remaining - 1
    end

    return self
end

--- skip N bytes
function StructDef:padding(size, opts)
    opts = opts or {}
    local remaining = size

    while remaining >= 4 do
        local name = string.format("unk_%04X", self._offset)
        self:field(name, "uint32", opts)
        remaining = remaining - 4
    end

    while remaining >= 1 do
        local name = string.format("unk_%04X", self._offset)
        self:field(name, "uint8", opts)
        remaining = remaining - 1
    end
    
    return self
end

function StructDef:skip(size)
    self._offset = self._offset + size
    return self
end

function StructDef:unk(size, opts)
    opts = opts or {}
    local name = string.format("unk_%04X", self._offset)

    if size == 1 then
        return self:field(name, "uint8", opts)
    elseif size == 2 then
        return self:field(name, "uint16", opts)
    elseif size == 4 then
        return self:field(name, "uint32", opts)
    elseif size == 8 then
        return self:field(name, "uint64", opts)
    else
        return self:array(name, "uint8", size, opts)
    end
end

function StructDef:alignTo(alignment)
    local rem = self._offset % alignment
    if rem ~= 0 then
        self._offset = self._offset + (alignment - rem)
    end
    return self
end

function StructDef:at(offset)
    self._offset = offset
    return self
end

function StructDef:currentOffset()
    return self._offset
end

-- @param name
-- @param otherStruct
-- @param opts {expand=bool}
function StructDef:embed(name, otherStruct, opts)
    opts = opts or {}
    local baseOffset = self._offset

    table.insert(self.embeddings, {
        type = "embed",
        name = name,
        struct = otherStruct,
        offset = baseOffset,
        size = otherStruct:totalSize(),
        expand = opts.expand or false,
    })

    for _, f in ipairs(otherStruct:getAllFields()) do
        local newField = {}
        for k, v in pairs(f) do
            newField[k] = v
        end
        newField.fieldOffset = baseOffset + f.fieldOffset
        newField.name = name .. "." .. f.name
        newField.structName = nil
        newField._embeddedIn = name
        table.insert(self.ownFields, newField)
    end

    self._offset = self._offset + otherStruct:totalSize()
    return self
end

-- @param name
-- @param otherStruct
-- @param count
-- @param opts {expand=bool}
function StructDef:structArray(name, otherStruct, count, opts)
    opts = opts or {}
    local structSize = otherStruct:totalSize()
    local baseOffset = self._offset

    table.insert(self.embeddings, {
        type = "structArray",
        name = name,
        struct = otherStruct,
        offset = baseOffset,
        count = count,
        size = count * structSize,
        elemSize = structSize,
        expand = opts.expand or false,
    })

    for i = 0, count - 1 do
        local elemOffset = self._offset + i * structSize

        for _, f in ipairs(otherStruct:getAllFields()) do
            local newField = {}
            for k, v in pairs(f) do
                newField[k] = v
            end
            newField.fieldOffset = elemOffset + f.fieldOffset
            newField.name = string.format("%s[%d].%s", name, i, f.name)
            newField._embeddedIn = name
            newField._arrayIndex = i
            table.insert(self.ownFields, newField)
        end
    end

    self._offset = self._offset + count * structSize
    return self
end

--   :ptrArray("fieldName", count)                    -- void*[]
--   :ptrArray("fieldName", count, opts)              -- void*[] with opts
--   :ptrArray("TypeName", "fieldName", count)        -- TypeName*[]
--   :ptrArray("TypeName", "fieldName", count, opts)  -- TypeName*[] with opts
function StructDef:ptrArray(arg1, arg2, arg3, arg4)
    local typeName, fieldName, count, opts

    if type(arg2) == "number" then
        -- ptrArray("fieldName", count) or ptrArray("fieldName", count, opts)
        typeName = nil
        fieldName = arg1
        count = arg2
        opts = arg3 or {}
    elseif type(arg2) == "string" then
        -- ptrArray("TypeName", "fieldName", count) or ptrArray("TypeName", "fieldName", count, opts)
        typeName = arg1
        fieldName = arg2
        count = arg3
        opts = arg4 or {}
    else
        error("Invalid arguments for ptrArray()")
    end

    local typeInfo = Types.ptr

    for i = 0, count - 1 do
        table.insert(self.ownFields, {
            fieldOffset   = self._offset + i * typeInfo.size,
            name          = string.format("%s[%d]", fieldName, i),
            type          = typeInfo.ce,
            size          = typeInfo.size,
            color         = opts.color,
            hex           = true,
            isPointer     = true,
            ptrType       = typeName,
            _ptrArrayBase = fieldName,
        })
    end

    self._offset = self._offset + count * typeInfo.size
    return self
end

function StructDef:ptr(arg1, arg2, arg3)
    local typeName, fieldName, opts

    if arg2 == nil then
        -- ptr("fieldName")
        typeName = nil
        fieldName = arg1
        opts = {}
    elseif type(arg2) == "table" then
        -- ptr("fieldName", opts)
        typeName = nil
        fieldName = arg1
        opts = arg2
    elseif type(arg2) == "string" then
        -- ptr("TypeName", "fieldName") or ptr("TypeName", "fieldName", opts)
        typeName = arg1
        fieldName = arg2
        opts = arg3 or {}
    else
        error("Invalid arguments for ptr()")
    end

    local typeInfo = Types.ptr

    table.insert(self.ownFields, {
        fieldOffset = self._offset,
        name        = fieldName,
        type        = typeInfo.ce,
        size        = typeInfo.size,
        color       = opts.color,
        hex         = true,
        isPointer   = true,
        ptrType     = typeName,
    })

    self._offset = self._offset + typeInfo.size
    return self
end

function StructDef:toCStruct(options)
    options = options or {}
    local indent = options.indent or "    "
    local collapsePadding = options.collapsePadding ~= false
    local flattenInheritance = options.flattenInheritance or false
    local lines = {}

    local ceToC = {
        [CE.vtByte]   = "uint8_t",
        [CE.vtWord]   = "uint16_t",
        [CE.vtDword]  = "uint32_t",
        [CE.vtQword]  = "uint64_t",
        [CE.vtSingle] = "float",
        [CE.vtDouble] = "double",
        [CE.vtString] = "char",
    }

    local function getPtrTypeName(field)
        return field.ptrType or "void"
    end

    local function sanitizeName(name)
        return name:gsub("%.", "_"):gsub("%[", "_"):gsub("%]", "")
    end

    local function isUnkField(name)
        return name:match("^unk_[%dA-Fa-f]+$") ~= nil
    end

    local function isUnkArray(name)
        return name:match("^unk_[%dA-Fa-f]+%[%d+%]$") ~= nil
    end

    local function isAnyUnk(name)
        return isUnkField(name) or isUnkArray(name)
    end

    local fields
    local embeddingMap = {}

    if flattenInheritance then
        fields = self:getAllFields()
        for _, emb in ipairs(self:getAllEmbeddings()) do
            embeddingMap[emb.offset] = emb
        end
    else
        fields = self.ownFields
        for _, emb in ipairs(self.embeddings) do
            embeddingMap[emb.offset] = emb
        end
    end

    if flattenInheritance and self.parent then
        table.insert(lines, string.format("// Inherits from: %s (size: 0x%X)", self.parent.name, self.parent:totalSize()))
    end

    table.insert(lines, string.format("struct %s {", self.name))

    if not flattenInheritance and self.parent then
        table.insert(lines, string.format("%s%s base; // 0x%04X", indent, self.parent.name, 0))
    end

    local i = 1
    local processedEmbeddings = {}

    while i <= #fields do
        local field = fields[i]
        local cType = ceToC[field.type] or "uint8_t"

        local emb = embeddingMap[field.fieldOffset]

        if emb and not processedEmbeddings[emb.name] then
            processedEmbeddings[emb.name] = true

            if emb.type == "embed" then
                if emb.expand then
                    table.insert(lines, string.format("%sstruct { // %s::%s", indent, emb.struct.name, emb.name))

                    for _, sf in ipairs(emb.struct:getAllFields()) do
                        local subType = ceToC[sf.type] or "uint8_t"
                        if sf.type == CE.vtString and sf.string_size then
                            table.insert(lines, string.format("%s%schar %s[%d]; // +0x%02X", indent, indent, sanitizeName(sf.name), sf.string_size, sf.fieldOffset))
                        elseif sf.isPointer then
                            table.insert(lines, string.format("%s%s%s* %s; // +0x%02X", indent, indent, getPtrTypeName(sf), sanitizeName(sf.name), sf.fieldOffset))
                        else
                            table.insert(lines, string.format("%s%s%s %s; // +0x%02X", indent, indent, subType, sanitizeName(sf.name), sf.fieldOffset))
                        end
                    end

                    table.insert(lines, string.format("%s} %s; // 0x%04X", 
                        indent, emb.name, emb.offset))
                else
                    table.insert(lines, string.format("%s%s %s; // 0x%04X",
                        indent, emb.struct.name, emb.name, emb.offset))
                end

                while i <= #fields and fields[i]._embeddedIn == emb.name do
                    i = i + 1
                end

            elseif emb.type == "structArray" then
                if emb.expand then
                    table.insert(lines, string.format("%sstruct { // %s element", indent, emb.struct.name))

                    for _, sf in ipairs(emb.struct:getAllFields()) do
                        local subType = ceToC[sf.type] or "uint8_t"
                        if sf.isPointer then
                            table.insert(lines, string.format("%s%s%s* %s; // +0x%02X", indent, indent, getPtrTypeName(sf), sanitizeName(sf.name), sf.fieldOffset))
                        else
                            table.insert(lines, string.format("%s%s%s %s; // +0x%02X", indent, indent, subType, sanitizeName(sf.name), sf.fieldOffset))
                        end
                    end

                    table.insert(lines, string.format("%s} %s[%d]; // 0x%04X (0x%X bytes)", indent, emb.name, emb.count, emb.offset, emb.size))
                else
                    table.insert(lines, string.format("%s%s %s[%d]; // 0x%04X (0x%X bytes)", indent, emb.struct.name, emb.name, emb.count, emb.offset, emb.size))
                end

                while i <= #fields and fields[i]._embeddedIn == emb.name do
                    i = i + 1
                end
            end

        elseif collapsePadding and isAnyUnk(field.name) then
            local startOffset = field.fieldOffset
            local totalSize = 0
            local j = i

            while j <= #fields do
                local f = fields[j]
                local expectedOffset = startOffset + totalSize

                if isAnyUnk(f.name) and f.fieldOffset == expectedOffset then
                    totalSize = totalSize + f.size
                    j = j + 1
                else
                    break
                end
            end

            if totalSize > 0 then
                table.insert(lines, string.format("%suint8_t pad_%04X[0x%X]; // 0x%04X", indent, startOffset, totalSize, startOffset))
            end

            i = j

        elseif field.isPointer and field._ptrArrayBase and field.name:match("%[0%]$") then
            local baseName = field._ptrArrayBase
            local j = i + 1
            local count = 1

            while j <= #fields do
                if fields[j]._ptrArrayBase == baseName then
                    count = count + 1
                    j = j + 1
                else
                    break
                end
            end

            table.insert(lines, string.format("%s%s* %s[%d]; // 0x%04X", indent, getPtrTypeName(field), baseName, count, field.fieldOffset))
            i = j

        elseif field.name:match("%[0%]$") and not field.name:find("%.") then
            local baseName = field.name:match("^([^%[]+)")
            local j = i + 1
            local count = 1

            while j <= #fields do
                local bn, ci = fields[j].name:match("^([^%[%.]+)%[(%d+)%]$")
                if bn == baseName and tonumber(ci) == count then
                    count = count + 1
                    j = j + 1
                else
                    break
                end
            end

            table.insert(lines, string.format("%s%s %s[%d]; // 0x%04X", indent, cType, baseName, count, field.fieldOffset))
            i = j

        elseif field.type == CE.vtString and field.string_size then
            table.insert(lines, string.format("%schar %s[%d]; // 0x%04X", indent, sanitizeName(field.name), field.string_size, field.fieldOffset))
            i = i + 1

        elseif field.isPointer then
            table.insert(lines, string.format("%s%s* %s; // 0x%04X", indent, getPtrTypeName(field), sanitizeName(field.name), field.fieldOffset))
            i = i + 1

        else
            table.insert(lines, string.format("%s%s %s; // 0x%04X", indent, cType, sanitizeName(field.name), field.fieldOffset))
            i = i + 1
        end
    end

    table.insert(lines, string.format("}; // sizeof: 0x%X (%d bytes)", self:totalSize(), self:totalSize()))

    return table.concat(lines, "\n")
end

function StructDef:getDependencies()
    local deps = {}
    local seen = {}

    local function collect(struct)
        if seen[struct.name] then return end
        seen[struct.name] = true

        if struct.parent then
            collect(struct.parent)
        end

        for _, emb in ipairs(struct.embeddings) do
            collect(emb.struct)
        end

        table.insert(deps, struct)
    end

    collect(self)
    return deps
end

function StructDef:toCStructWithDeps(options)
    local deps = self:getDependencies()
    local parts = {}

    for _, struct in ipairs(deps) do
        table.insert(parts, struct:toCStruct(options))
    end

    return table.concat(parts, "\n\n")
end

function StructDef:getAllEmbeddings()
    local result = {}

    if self.parent then
        for _, e in ipairs(self.parent:getAllEmbeddings()) do
            table.insert(result, e)
        end
    end

    for _, e in ipairs(self.embeddings) do
        table.insert(result, e)
    end

    return result
end

function StructDef:totalSize()
    return self._offset
end

function StructDef:getOwnFields()
    return self.ownFields
end

function StructDef:getAllFields()
    local fields = {}

    if self.parent then
        for _, f in ipairs(self.parent:getAllFields()) do
            table.insert(fields, f)
        end
    end

    for _, f in ipairs(self.ownFields) do
        local newField = {}
        for k, v in pairs(f) do
            newField[k] = v
        end
        newField.structName = self.name
        table.insert(fields, newField)
    end

    return fields
end

-- @param struct
-- @param baseAddress
-- @param options
function loadStructToTable(struct, baseAddress, options)
    options = options or {}
    local showStructName = options.showStructName ~= false
    local parentRecord = options.parentRecord

    local fields = struct:getAllFields()

    for _, field in ipairs(fields) do
        local memrec = AddressList.createMemoryRecord()

        if type(baseAddress) == "string" then
            memrec.Address = string.format("%s+0x%X", baseAddress, field.fieldOffset)
        else
            memrec.Address = string.format("0x%X", field.fieldOffset + baseAddress)
        end

        if showStructName and field.structName then
            memrec.Description = string.format("0x%03X   %s::%s", field.fieldOffset, field.structName, field.name)
        else
            memrec.Description = string.format("0x%03X   %s", field.fieldOffset, field.name)
        end

        memrec.Type = field.type

        if field.string_size then
            memrec.String.Size = field.string_size
        end
        if field.color then
            memrec.Color = field.color
        end
        if field.hex then
            memrec.ShowAsHex = true
        end

        if parentRecord then
            memrec.appendToEntry(parentRecord)
        end
    end
end

function Struct(name, parent)
    return StructDef.new(name, parent)
end

function GetCGObjectAddr(guidValue)
    if type(guidValue) == "string" then
        guidValue = tonumber(guidValue, 16)
    end
    if not guidValue or guidValue == 0 then
        return nil
    end

    local VTABLE_TYPES = {
        [0xA34D90] = "unit",
        [0xA326C8] = "player",
        [0xA33428] = "item",
        [0xA332D0] = "container",
        [0xA331C8] = "corpse",
        [0xA34640] = "gameobject"
    }

    local memScan   = createMemScan()
    local foundList = createFoundList(memScan)

    local function cleanup()
        foundList.destroy()
        memScan.destroy()
    end

    memScan.firstScan(
        soExactValue, vtQword, rtRounded,
        string.format("%016X", guidValue),
        nil, 0x0, 0x7FFFFFFFFFFFFFFF,
        "", fsmNotAligned, nil,
        true, false, false, false
    )

    memScan.waitTillDone()
    foundList.initialize()

    for i = 0, foundList.Count - 1 do
        local addr = tonumber(foundList.Address[i], 16)
        if addr then
            local base = addr - 0x30
            local objType = VTABLE_TYPES[readInteger(base)]
            if objType then
                cleanup()
                return base, objType
            end
        end
    end

    cleanup()
    return nil
end

setmetatable(StructDef, {
    __index = function(t, key)
        if Types[key] then
            local typeName = key
            local fn = function(self, name, opts)
                return self:field(name, typeName, opts)
            end
            rawset(t, key, fn)
            return fn
        end

        local baseArray, suffixArray = key:match("^(.*)_(array)$")
        if suffixArray == "array" then
            if Types[baseArray] then
                local fn = function(self, name, count, opts)
                    return self:array(name, baseArray, count, opts)
                end
                rawset(t, key, fn)
                return fn
            elseif StructRegistry[baseArray] then
                local struct = StructRegistry[baseArray]
                local fn = function(self, name, count, opts)
                    return self:structArray(name, struct, count, opts)
                end
                rawset(t, key, fn)
                return fn
            end
        end

        local baseArrayPtr, suffixArrayPtr = key:match("^(.*)_(arrayPtr)$")
        if suffixArrayPtr == "arrayPtr" then
            local fn = function(self, name, count, opts)
                return self:ptrArray(baseArrayPtr, name, count, opts)
            end
            rawset(t, key, fn)
            return fn
        end

        local basePtr, suffixPtr = key:match("^(.*)_(ptr)$")
        if suffixPtr == "ptr" then
            local fn = function(self, name, opts)
                return self:ptr(basePtr, name, opts)
            end
            rawset(t, key, fn)
            return fn
        end

        local userStruct = StructRegistry[key]
        if userStruct then
            local fn = function(self, name, opts)
                return self:embed(name, userStruct, opts)
            end
            rawset(t, key, fn)
            return fn
        end

        return nil
    end
})
local WoWGUID = Struct("WOWGUID")
    :hex("guid", "uint64")

local TSLink = Struct("TSLink")
    :TSLink_ptr("m_prevlink")
    :ptr("m_next")

local TSList = Struct("TSList") -- also TSExplicitList
    :uint32("m_linkoffset", {hex = true})
    :TSLink("m_terminator")

local TSLinkedNode = Struct("TSLinkedNode")
    :TSLink("m_link")

local TSFixedArray = Struct("TSFixedArray")
    :uint32("m_alloc") -- 0x0
    :uint32("m_count") -- 0x4
    :ptr("m_data") -- 0x8

local TSGrowableArray = Struct("TSGrowableArray", TSFixedArray)
    :uint32("m_chunk") -- 0xC

local TSHashTable = Struct("TSHashTable")
    :ptr("void*", "v_table") -- 0x0000
    :TSList("m_fulllist")
    :uint32("m_fullnessIndicator") -- 0x0010
    :TSGrowableArray("m_slotlistarray") -- 000x14
    :flag32("m_slotmask") -- 000x24

local HASHKEY_STRI = Struct("HASHKEY_STRI")
    :int8_ptr("m_str")

local C2Vector = Struct("C2Vector")
    :float("x")
    :float("y")

local C2iVector = Struct("C2iVector")
    :int32("x")
    :int32("y")

local C3Vector = Struct("C3Vector")
    :float("x")
    :float("y")
    :float("z")

local CImVector = Struct("CImVector")
    :uint8("r")
    :uint8("g")
    :uint8("b")
    :uint8("a")

local CAaBox = Struct("CAaBox")
    :C3Vector("top")
    :C3Vector("bottom")

local CAaSphere = Struct("CAaSphere")
    :C3Vector("center")
    :float("d")

local C44Matrix = Struct("C44Matrix")
    :float_array("m", 16)

local RCString = Struct("RCString")
    :ptr("void*", "vtbl")
    :uint32("m_refCnt")
    :int8_ptr("m_str")

local CPassenger = Struct("CPassenger")
    :TSLink("m_passangerLink")
    :WOWGUID("m_transportGUID") -- 0x08
    :C3Vector("m_position") -- 0x10
    :ptr("unkPtr") -- 0x1C
    :float("m_facing") -- 0x20
    :uint32("unk_24") -- 0x24
    :ptr("m_data") -- 0x28: CGObject.dataBeginPtr; for aoe spells ptr to DynamicObjectFields
    :flag8("unkFlag") -- 0x2C
    :paddingTo(0x30)

local ObjectFields = Struct("ObjectFields")
    :WOWGUID("ObjectGUID")
    :uint32("type")
    :uint32("unk")
    :float("scale")
    :uint32("pad")

local CGObject = Struct("CGObject")
    :ptr("void*", "VtablePtr") -- 0x0000
    :unk(4) -- 0x0004
    :ptr("dataBeginPtr") -- 0x0008
    :ptr("dataEndPtr") -- 0x000C
    :uint32("unkFlag", {hex = true}) -- 0x0010
    :int32("TypeID") -- 0x0014
    :uint32("low_GUID", {hex = true}) -- 0x0018
    :paddingTo(0x30)
    :WOWGUID("ObjectGuid") -- 0x0030
    :paddingTo(0x44)
    :TSList_array("m_list", 6)
    :paddingTo(0x98)
    :float("m_objectSacle1") -- 0x0098
    :float("m_objectSacle2") -- 0x009C
    :int32("m_objectScalingEndMS") -- 0x00A0
    :float("m_objectLastScale") -- 0x00A4
    :ptr("specialEffectPtr") -- 0x00A8
    :float("objectHeight") -- 0x00AC
    :ptr("unkPlayerNamePtr") -- 0x00B0
    :ptr("CM2Model", "m_model") -- 0x00B4
    :ptr("CMapEntityPtr") -- 0x00B8
    :int32("unkMovementFlags", {hex = true}) -- 0x00BC
    :int32("unk_00C0") -- 0x00C0
    :int32("unk_00C4") -- 0x00C4
    :uint8("m_alpha") -- 0x00C8
    :uint8("m_startAlpha") -- 0x00C9
    :uint8("m_endAlpha") -- 0x00CA
    :uint8("m_maxAlpha") -- 0x00CB
    :ptr("effectManagerPtr") -- 0x00CC

local GameObjectFields = Struct("GameObjectFields")
    :WOWGUID("createdBy")        -- 0x000
    :uint32("displayId")        -- 0x008
    :flag32("flags")   -- 0x00C
    :float_array("parentRotation", 4) -- 0x010
    :uint32("dynamic") -- 0x020
    :uint32("faction") -- 0x024
    :uint32("level")   -- 0x028
    :uint8("state")  -- 0x02C
    :uint8("type")  -- 0x02D
    :uint8("artKit")  -- 0x02E
    :uint8("animProgress")  -- 0x02F

local CGGameObject_C = Struct("CGGameObject_C", CGObject)
    :GameObjectFields_ptr("m_gameObjectFields") -- 0x00D0
    :ptr("unk_00D4") -- 0x00D4
    :paddingTo(0xE8)
    :C3Vector("m_position") -- 0x0E8
    :flag32("unkFlag") -- 0x0F4
    :uint32("unkCounter") -- 0x00F8
    :int32("unk_00FC") -- 0x00FC
    :ptr("unkPtr")     -- 0x0100
    :flag8("m_flags")  -- 0x0104 ( |= 2 )
    :paddingTo(0x108)  -- 0x0105..0x0107
    :TSList_array("m_typeLists", 12) -- 0x0108 (12 * 0x0C = 0x90)
    :int32("unk_0198") -- 0x0198
    :int32("unk_019C") -- 0x019C
    :ptr("CGGameObject_C_Type", "m_typeSpecific") -- 0x01A0
    :ptr("CGameObjectDef", "m_gameObjDef") -- 0x01A4
    :C44Matrix("m_mtx")
    :CAaBox("m_bbox")
    :uint32("m_transportTimeDelta") -- 0x0200
    :int32("m_typeByte")    -- 0x0204 (m_gameObjectFields->type)
    :int32("unk_0208") -- 0x0208
    :int32("unk_020C") -- 0x020C
    :int32("unk_0210") -- 0x0210
    :int32("unk_0214") -- 0x0214
-- sizeof = 0x218

local vtbl2TypeName = {
    --[0xA33790] = "CGGameObject_C_Type_WorldObj",
    --[0xA33E60] = "CGGameObject_C_Type_TransportBase",
    --[0xA34750] = "CGGameObject_C_Type_TrapDoor",
    [0xA336E0] = "CGGameObject_C_Type_Binder",
    [0xA33848] = "CGGameObject_C_Type_Chair",
    [0xA33900] = "CGGameObject_C_Type_BarberChair",
    [0xA33B80] = "CGGameObject_C_Type_Door",
    [0xA33CF0] = "CGGameObject_C_Type_QuestGiver",
    [0xA33DA8] = "CGGameObject_C_Type_Generic",
    [0xA34368] = "CGGameObject_C_Type_DuelArbiter",
    [0xA33F18] = "CGGameObject_C_Type_Text",
    [0xA33FD0] = "CGGameObject_C_Type_FishingNode",
    [0xA34088] = "CGGameObject_C_Type_Ritual",
    [0xA34140] = "CGGameObject_C_Type_Mailbox",
    [0xA341F8] = "CGGameObject_C_Type_MeetingStone",
    [0xA342B0] = "CGGameObject_C_Type_CapturePoint",
    [0xA34420] = "CGGameObject_C_Type_DungeonDifficulty",
    [0xA344D0] = "CGGameObject_C_Type_DestructibleBuilding",
    [0xA34588] = "CGGameObject_C_Type_GuildBank",
    --[0xA34808] = "CGGameObject_C_Type_Transport",
    --[0xA348C0] = "CGGameObject_C_Type_MapObjTransport",
}

local CGGameObject_C_Type = Struct("CGGameObject_C_Type")
    :ptr("void*", "vtbl") -- 0x00
    :CGGameObject_C_ptr("m_owner") -- 0x04
    :uint32("TypeID") -- 0x08
    :float("Scale") -- 0x0C

local CGGameObject_C_TypeAnimated = Struct("CGGameObject_C_TypeAnimated", CGGameObject_C_Type)
    :int32("m_animationState") -- 0x010
    :int32("m_previousAnimState") -- 0x014
    :uint32("m_sequenceTime") -- 0x018
    :uint32("unkSoundHanle") -- 0x01C
    :paddingTo(0x24)
    :ptr("unk_SoundPtr")
    :paddingTo(0x30) -- 0x10..0x2F

local CGGameObject_C_Type_Chair = Struct("CGGameObject_C_Type_Chair", CGGameObject_C_Type)
    :C3Vector("m_position")
    :int32("unk_1C")   -- 0x1C
    :int32("unk_20")   -- 0x20
    :int32("unk_24")   -- 0x24
    :int32("unk_28")   -- 0x28
    :int32("unk_2C")   -- 0x2C
    :int32("unk_30")   -- 0x30
    :int32("unk_34")   -- 0x34
    :int32("unk_38")   -- 0x38
    :int32("unk_3C")   -- 0x3C
    :int32("unk_40")   -- 0x40
    :int32("unk_44")   -- 0x44
    :int32("unk_48")   -- 0x48

local CGGameObject_C_Type_BarberChair = Struct("CGGameObject_C_Type_BarberChair", CGGameObject_C_Type)
    :C3Vector("m_position")
    :int32("unk_1C")   -- 0x1C
    :int32("unk_20")   -- 0x20
    :int32("unk_24")   -- 0x24
    :int32("unk_28")   -- 0x28
    :int32("unk_2C")   -- 0x2C
    :int32("unk_30")   -- 0x30
    :int32("unk_34")   -- 0x34
    :int32("unk_38")   -- 0x38
    :int32("unk_3C")   -- 0x3C
    :int32("unk_40")   -- 0x40
    :int32("unk_44")   -- 0x44
    :int32("unk_48")   -- 0x48

local CGGameObject_C_Type_GuildBank = Struct("CGGameObject_C_Type_GuildBank", CGGameObject_C_TypeAnimated)
local CGGameObject_C_Type_Mailbox = Struct("CGGameObject_C_Type_Mailbox", CGGameObject_C_TypeAnimated)
local CGGameObject_C_Type_MeetingStone = Struct("CGGameObject_C_Type_MeetingStone", CGGameObject_C_TypeAnimated)
local CGGameObject_C_Type_CapturePoint = Struct("CGGameObject_C_Type_CapturePoint", CGGameObject_C_TypeAnimated)
local CGGameObject_C_Type_Door = Struct("CGGameObject_C_Type_Door", CGGameObject_C_TypeAnimated)
local CGGameObject_C_Type_FishingNode = Struct("CGGameObject_C_Type_FishingNode", CGGameObject_C_TypeAnimated)
local CGGameObject_C_Type_Button = Struct("CGGameObject_C_Type_Button", CGGameObject_C_TypeAnimated)
local CGGameObject_C_Type_Chest = Struct("CGGameObject_C_Type_Chest", CGGameObject_C_TypeAnimated)
local CGGameObject_C_Type_Trap = Struct("CGGameObject_C_Type_Trap", CGGameObject_C_TypeAnimated)
local CGGameObject_C_Type_AreaDamage = Struct("CGGameObject_C_Type_AreaDamage", CGGameObject_C_TypeAnimated)

local DestructibleStateInfo = Struct("DestructibleStateInfo")
    :ptr("char", "m_modelName")      -- 0x00 GameObjectDisplayInfo.ModelName
    :uint32("m_displayId")           -- 0x04 GameObjectDisplayInfo ID
    :ptr("CMapObjDef", "m_mapObj")   -- 0x08
    :uint8("m_loadPending")          -- 0x0C 1 = wait World__ObjectIsLoaded
    :uint8("m_playRebuildAnim")      -- 0x0D 1 for state 0 / 3
    :uint8("pad_0E")                 -- 0x0E
    :uint8("pad_0F")                 -- 0x0F

local CGGameObject_C_Type_DestructibleBuilding = Struct("CGGameObject_C_Type_DestructibleBuilding", CGGameObject_C_Type)
    :ptr("CMapObjDef", "m_mapObjPtr") -- 0x10
    :DestructibleStateInfo_array("m_states", 4)
    :int32("m_lastStateIndex")  -- 0x54 = 0xFFFFFFFF
    :float("m_baseZ")   -- 0x58
    :uint32("m_animStartMs")   -- 0x5C
    :int32("m_animDurationMs")   -- 0x60
    :int32("unk_64")   -- 0x64
    :ptr("CMapObjDef", "m_mapObjPtr") -- 0x68
    :float("m_currentHeight")   -- 0x6C
    :int32("unk_70")   -- 0x70
    :int32("unkSoundHandler")   -- 0x74
    :int32("unk_78")   -- 0x78
    :int32("unk_7C")   -- 0x7C
    :int32("unk_80")   -- 0x80
    :int32("unk_84")   -- 0x84
    :int32("unk_88")   -- 0x88
    :int32("unk_8C")   -- 0x8C
    :int32("unk_90")   -- 0x90
    :C3Vector("unk_vec3") -- 0x94
    :float("unk_Float")   -- 0xA0
    :int32("unk_A4")   -- 0xA4
    :ptr("DestructibleModelData", "m_dbcRec")   -- 0xA8
    :uint8("unk_waitBoolFlag")   -- 0xAC = 1
    :uint8("unk_AD")   -- 0xAD
    :uint8("unk_AE")   -- 0xAE
    :uint8("unk_AF")   -- 0xAF
-- sizeof = 0xB0

-- waypoint/spawn point for various purposes: a ship (transport) spawn point, event spawn point, ore node etc
local CGGameObject_C_Type_Binder = Struct("CGGameObject_C_Type_Binder", CGGameObject_C_Type)

-- fireplace, torchlight too
local CGGameObject_C_Type_DuelArbiter = Struct("CGGameObject_C_Type_DuelArbiter", CGGameObject_C_TypeAnimated)

-- readable openworld book
local CGGameObject_C_Type_Text = Struct("CGGameObject_C_Type_Text", CGGameObject_C_TypeAnimated)

-- for testing (horde) .go xyz -3708 -2532 70 1
local CGGameObject_C_Type_QuestGiver = Struct("CGGameObject_C_Type_QuestGiver", CGGameObject_C_TypeAnimated)

-- road sign
local CGGameObject_C_Type_Generic = Struct("CGGameObject_C_Type_Generic", CGGameObject_C_TypeAnimated)

-- warlock's healthstone-summoning portal 
local CGGameObject_C_Type_Ritual = Struct("CGGameObject_C_Type_Ritual", CGGameObject_C_TypeAnimated)

-- dungeon/raid diffuculty entrance skull
local CGGameObject_C_Type_DungeonDifficulty = Struct("CGGameObject_C_Type_DungeonDifficulty", CGGameObject_C_Type)
    :int32("unk_10")   -- 0x10
    :int32("unk_14")   -- 0x14
    :int32("unk_18")   -- 0x18
    :int32("unk_1C")   -- 0x1C
    :int32("unk_20")   -- 0x20

local CGGameObject_C_Type_TransportBase = Struct("CGGameObject_C_Type_TransportBase", CGGameObject_C_Type)
    :ptr("CMapObjDef", "m_mapObjDefPtr") -- 0x10
    :TSList("m_passengerList") -- 0x14
    :C3Vector("m_pos") -- 0x20
    :float("m_speed")   -- 0x2C
    :uint32("m_currentTime")   -- 0x30
    :int32("m_loaded")   -- 0x34
    :int32("m_lastSequence")  -- 0x38
    :uint32("m_transportUpdateTime")   -- 0x3C


local ShipPath__Segment = Struct("ShipPath__Segment")
    :uint32("m_startTime") -- 0x00
    :float("m_distance") -- 0x04
    :uint32("m_duration") -- 0x08
-- sizeof = 0x0C

local ShipPath__TimeEvent = Struct("ShipPath__TimeEvent")
    :uint32("m_time") -- 0x00
    :uint32("m_event") -- 0x04
-- sizeof = 0x08

local ShipPath__Leg = Struct("ShipPath__Leg")
    :int32("m_mapId") -- 0x000
    :ptr("m_loadingScreenFuncPtr") -- 0x004
    :float("m_splineLength") -- 0x008
    :C3Vector_array("m_vectors", 25)
    -- TSFixedArray<C3Vector>
    :TSFixedArray("m_vec3Array")
    :int32("unk_144") -- 0x144
    :int32("unk_0148")
    :float_array("m_floats", 25)
    :TSFixedArray("m_unkArray")
    :int32("unk_1BC") -- 0x1BC
    :int32("unk_1C0")
    :int32("unk_1C4")
    :int32("unk_1C8")
    :int32("unk_1CC")
    :int32("unk_1D0")
    -- TSFixedArray<ShipPath__Segment>
    :TSFixedArray("m_segments")
    :int32("unk_1E0") -- 0x1E0
-- sizeof = 0x1E4

local ShipPathParams = Struct("ShipPathParams")
    :int32("m_unkIndex")
    :float_array("m_unkValues", 10)
-- sizeof = 0x2C

local ShipPath = Struct("ShipPath")
    :ShipPathParams_ptr("unk_paramsPtr")
    :int32("m_pathId") -- 0x04
    -- TSFixedArray<ShipPath::Leg>
    :uint32("m_alloc") -- 0x08
    :uint32("m_count") -- 0x0C
    :ptr("ShipPath__Leg", "m_data") -- 0x10
    :int32("unk_014") -- 0x14
    -- TSFixedArray<ShipPath::TimeEvent>
    :uint32("m_alloc") -- 0x18
    :uint32("m_count") -- 0x1C
    :ptr("ShipPath__TimeEvent", "m_data") -- 0x20
    :int32("unk_024") -- 0x24
    :float("m_speed") -- 0x28
    :uint32("m_totalPathTimeMS") -- 0x2C
    :float("m_totalDistance") -- 0x30
    :uint32("m_pausePathTimeMS") -- 0x34
    :uint32("m_timeOffsetMS") -- 0x38
    :uint8("m_waitAtPausePoint") -- 0x3C
    :uint8("m_isPaused") -- 0x3D
    :uint8("unk_3E") -- 0x3E
    :uint8("unk_3F") -- 0x3F
    :paddingTo(0x40)

-- zeppelin between orgri and thunder bluff, battleships in icecrown, etc
local CGGameObject_C_Type_MapObjTransport = Struct("CGGameObject_C_Type_MapObjTransport", CGGameObject_C_Type_TransportBase)
    :ShipPath("m_shipPath")
    :int32("unk_80")   -- 0x80
-- sizeof = 0x84

-- thunder bluff elevator
local CGGameObject_C_Type_Transport = Struct("CGGameObject_C_Type_Transport", CGGameObject_C_Type_TransportBase)
    :ptr("unk_movementSequencePtr")   -- 0x40
    :uint32("m_movementCount") -- 0x44
    :uint32("m_movementIndex") -- 0x48
    :ptr("unk_rotationPtr")   -- 0x4C
    :uint32("m_rotationKeyCount")     -- 0x50
    :uint32("m_rotationKeyIndex")     -- 0x54
    :int32("m_currentSequence")  -- 0x58
    :int32("m_stateChangeTime")   -- 0x5C
    :int32("unk_60")   -- 0x60
-- sizeof = 0x64



local address = 0x51f838 -- at CGGameUI__HandleObjectTrackChange
debugger_onBreakpoint = nil
function onBreakpoint()    
    local addr, objectType = GetCGObjectAddr(readQword(0x00bd07a0)) -- mouseover guid
    if addr and objectType == "gameobject" then
        loadStructToTable(CGGameObject_C, addr)

        local gameObjectClassName = vtbl2TypeName[readPointer(readPointer(addr + 0x1A0))]
        if gameObjectClassName then
            loadStructToTable(StructRegistry[gameObjectClassName], readPointer(addr + 0x1A0))
        end

        debugger_onBreakpoint = nil
        debug_removeBreakpoint(address)
        debug_continueFromBreakpoint(co_run)
        return 1
    end

    local playerAddr, _ = GetCGObjectAddr(readQword(0xC79D10)) -- local player GUID from game connection class
    local playerTransportGUIDoffset = 0x790
    local addr, objectType = GetCGObjectAddr(readQword(playerAddr + playerTransportGUIDoffset))
    if addr and objectType == "gameobject" then
        loadStructToTable(CGGameObject_C, addr)
        local transportVtblAddr = readPointer(readPointer(addr + 0x1A0))
        if transportVtblAddr == 0xA34808 then
            loadStructToTable(CGGameObject_C_Type_Transport, readPointer(addr + 0x1A0))
        end
        if transportVtblAddr == 0xA348C0 then
            loadStructToTable(CGGameObject_C_Type_MapObjTransport, readPointer(addr + 0x1A0))
        end
    end

    debugger_onBreakpoint = nil
    debug_removeBreakpoint(address)
    debug_continueFromBreakpoint(co_run)
    return 1
end

debug_setBreakpoint(address)
debugger_onBreakpoint = onBreakpoint

