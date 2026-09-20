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
    :int32("m_linkoffset")
    :TSLink("m_terminator")

local TSLinkedNode = Struct("TSLinkedNode")
    :TSLink("m_link")

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
    :uint32("m_slotmask", {hex = true}) -- 000x24

local Vector2 = Struct("Vector2")
    :float("x")
    :float("y")

local Vector3 = Struct("Vector3")
    :float("x")
    :float("y")
    :float("z")

local UnitFields = Struct("UnitFields")
    :WOWGUID("Charm") -- 0x1970
    :WOWGUID("Summon") -- 0x1978
    :WOWGUID("Critter") -- 0x1980
    :WOWGUID("CharmedBy") -- 0x1988
    :WOWGUID("SummonedBy") -- 0x1990
    :WOWGUID("CreatedBy") -- 0x1998
    :WOWGUID("Target") -- 0x19A0
    :WOWGUID("ChannelSpellTarget") -- 0x19A8
    :int32("ChannelSpellId") -- 0x19B0
    :uint8("Race") -- 0x19B4
    :uint8("Class") -- 0x19B5
    :uint8("Gender") -- 0x19B6
    :uint8("DisplayPower") -- 0x19B7
    :int32("Health") -- 0x19B8
    :int32("Mana") -- 0x19BC
    :int32("Rage") -- 0x19C0
    :int32("Focus") -- 0x19C4
    :int32("Energy") -- 0x19C8
    :int32("UnkResource1") -- 0x19CC
    :int32("UnkResource2") -- 0x19D0
    :int32("RunePower") -- 0x19D4
    :int32("MaxHealth") -- 0x19D8
    :int32("MaxMana") -- 0x19DC
    :int32("MaxRage") -- 0x19E0
    :int32("MaxFocus") -- 0x19E4
    :int32("MaxEnergy") -- 0x19E8
    :int32("UnkMaxResource1") -- 0x19EC
    :int32("UnkMaxResource2") -- 0x19F0
    :int32("MaxRunePower") -- 0x19F4
    :float("ManaRegenFlatMod") -- 0x19F8
    :float("RageRegenFlatMod") -- 0x19FC
    :float("FocusRegenFlatMod") -- 0x1A00
    :float("EnergyFlatMod") -- 0x1A04
    :float("UnkRegenFlatMod") -- 0x1A08
    :float("UnkRegenFlatMod") -- 0x1A0C
    :float("RunePowerRegenFlatMod") -- 0x1A10
    :float("ManaRegenInterruptedFlatMod") -- 0x1A14
    :float("RageRegenInterruptedFlatMod") -- 0x1A18
    :float("FocusRegenInterruptedFlatMod") -- 0x1A1C
    :float("EnergyRegenInterruptedFlatMod") -- 0x1A20
    :float("UnkRegenInterruptedFlatMod") -- 0x1A24
    :float("UnkRegenInterruptedFlatMod") -- 0x1A28
    :float("RunePowerRegenInterruptedFlatMod") -- 0x1A2C
    :int32("Level") -- 0x1A30
    :int32("FieldFactiontemplate") -- 0x1A34
    :int32("VirtualItemSlotIdMainHand") -- 0x1A38
    :int32("VirtualItemSlotIdOffHand") -- 0x1A3C
    :int32("VirtualItemSlotIdRanged") -- 0x1A40
    :flag32("Flag1") -- 0x1A44
    :flag32("Flag2") -- 0x1A48
    :int32("AuraState") -- 0x1A4C
    :int32("BaseAttackTimeMainHand") -- 0x1A50
    :int32("BaseAttackTimeOffHand") -- 0x1A54
    :int32("RangedAttackTime") -- 0x1A58
    :float("BoundingRadius") -- 0x1A5C
    :float("CombatReach") -- 0x1A60
    :int32("DisplayId") -- 0x1A64
    :int32("NativedisplayId") -- 0x1A68
    :int32("MountdisplayId") -- 0x1A6C
    :float("MinMainHandDamage") -- 0x1A70
    :float("MaxMainHandDamage") -- 0x1A74
    :int32("MinOffHandDamage") -- 0x1A78
    :int32("MaxOffHandDamage") -- 0x1A7C
    :int32("SitState") -- 0x1A80
    :int32("PetNumber") -- 0x1A84
    :int32("PetNameTamestamp") -- 0x1A88
    :int32("PetXP") -- 0x1A8C
    :int32("PetNextLevelXP") -- 0x1A90
    :int32("DynFlags") -- 0x1A94
    :float("ModCastSpeed") -- 0x1A98
    :int32("CreatedBySpell") -- 0x1A9C
    :int32("NPCFlags") -- 0x1AA0
    :int32("NPCEmoteState") -- 0x1AA4
    :int32("StatStrengthBase") -- 0x1AA8
    :int32("StatAgilityBase") -- 0x1AAC
    :int32("StatStaminaBase") -- 0x1AB0
    :int32("StatIntellectBase") -- 0x1AB4
    :int32("StatSpiritBase") -- 0x1AB8
    :int32("StatStrengthPositive") -- 0x1ABC
    :int32("StatAgilityPositive") -- 0x1AC0
    :int32("StatStaminaPositive") -- 0x1AC4
    :int32("StatIntellectPositive") -- 0x1AC8
    :int32("StatSpiritPositive") -- 0x1ACC
    :int32("StatStrengthNegative") -- 0x1AD0
    :int32("StatAgilityNegative") -- 0x1AD4
    :int32("StatStaminaNegative") -- 0x1AD8
    :int32("StatIntellectNegative") -- 0x1ADC
    :int32("StatSpiritNegative") -- 0x1AE0
    :int32("StatArmor") -- 0x1AE4
    :int32("ResistHoly") -- 0x1AE8
    :int32("ResistFire") -- 0x1AEC
    :int32("ResistNature") -- 0x1AF0
    :int32("ResistFrost") -- 0x1AF4
    :int32("ResistShadow") -- 0x1AF8
    :int32("ResistArcane") -- 0x1AFC
    :int32("UnkResist") -- 0x1B00
    :int32("ResistPositiveHoly") -- 0x1B04
    :int32("ResistPositiveFire") -- 0x1B08
    :int32("ResistPovisitveNature") -- 0x1B0C
    :int32("ResistPositiveFrost") -- 0x1B10
    :int32("ResistPositiveShadow") -- 0x1B14
    :int32("ResistPositiveArcane") -- 0x1B18
    :int32("UnkResist") -- 0x1B1C
    :int32("ResistNegativeHoly") -- 0x1B20
    :int32("ResistNegativeFire") -- 0x1B24
    :int32("ResistNegativeNature") -- 0x1B28
    :int32("ResistNegativeFrost") -- 0x1B2C
    :int32("ResistNegativeShadow") -- 0x1B30
    :int32("ResistNegativeArcane") -- 0x1B34
    :int32("UnkBaseMana") -- 0x1B38
    :int32("BaseHealth") -- 0x1B3C
    :int32("WeaponStandType") -- 0x1B40
    :int32("AttackPowerMelee") -- 0x1B44
    :int32("AttackPowerMeleeMod") -- 0x1B48
    :float("AttackPowerMeleeMulti") -- 0x1B4C
    :int32("AttackPowerRange") -- 0x1B50
    :int32("AttackPowerRangedMod") -- 0x1B54
    :float("AttackPowerRangedMulti") -- 0x1B58
    :float("MinRangedDamage") -- 0x1B5C
    :float("MaxRangedDamage") -- 0x1B60
    :int32_array("PowerCostModifier", 7) -- 0x1B64
    :float_array("PowerCostMultiplier", 7) -- 0x1B80
    :int32("MaxHealthMod") -- 0x1B9C
    :float("HoverHeight") -- 0x1BA0
    :int32("Pad") -- 0x1BA4

local UnitAura = Struct("Aura")
    :WOWGUID("caster") -- 0x0C50
    :int32("buffId") -- 0x0C58
    :int32("unk") -- 0x0C5C
    :int32("maxDuration") -- 0x0C60
    :ptr("buffPtr") -- 0x0C64

local UnitBuff = Struct("Buff")
    :int32("index")
    :int32("buffId")

local CMovementData = Struct("CMovementData")
    :int32("unk_0788") -- 0x0788
    :int32("unk_078C") -- 0x078C
    :WOWGUID("Transport") -- 0x0790
    :Vector3("Position")
    :uint32("unkFlag", {hex = true}) -- 0x07A4
    :float("Facing") -- 0x07A8
    :float("Pitch") -- 0x07AC
    :ptr("dataPtr") -- 0x07B0
    :uint32("unkFlag2", {hex = true}) -- 0x07B4
    :int32("unk_07B8") -- 0x07B8
    :int32("unk_07BC") -- 0x07BC
    :Vector3("GroundNormal")
    :flag32("moveFlag1") -- 0x07CC
    :flag32("moveFlag2") -- 0x07D0
    :Vector3("Anchor")
    :float("AnchorFacing") -- 0x07E0
    :float("AnchorPitch") -- 0x07E4
    :int32("unk_07E8") -- 0x07E8
    :Vector3("Direction")
    :Vector2("Direction2d")
    :float("cosAnchorPitch") -- 0x0800
    :float("sinAnchorPitch") -- 0x0804
    :int32("FallTime") -- 0x0808
    :float("StartFallHeight") -- 0x080C
    :float("unkFloat") -- 0x0810
    :float("MoveSpeed") -- 0x0814
    :float("WalkSpeed") -- 0x0818
    :float("RunSpeed") -- 0x081C
    :float("BackSpeed") -- 0x0820
    :float("SwimSpeed") -- 0x0824
    :float("BackSwimSpeed") -- 0x0828
    :float("FlyMountSpeed") -- 0x082C
    :float("FlyMountBackSpeed") -- 0x0830
    :float("TurnSpeed") -- 0x0834
    :float("FlyMountUnkUpDownRotation1") -- 0x0838
    :float("FlyMountUnkUpDownRotation2") -- 0x083C
    :float("FallSpeed") -- 0x0840
    :ptr("CGMoveSplinePtr") -- 0x0844
    :int32("PerfCount") -- 0x0848
    :flag32("unkFlag3") -- 0x084C
    :float("CollisonBoxHalfWidth") -- 0x0850
    :float("CollisionBoxHeight") -- 0x0854
    :float("ObjectScale") -- 0x0858
    :int32("unk_085C") -- 0x085C
    :int32("unk_0860") -- 0x0860
    :int32("unk_0864") -- 0x0864
    :int32("unk_0868") -- 0x0868
    :int32("unk_086C") -- 0x086C
    :flag32("unkFlags_00") -- 0x0870
    :flag32("unkFlags_01") -- 0x0874
    :flag32("unkFlags_02") -- 0x0878
    :flag32("unkFlags_03") -- 0x087C
    :flag32("unkFlags_04") -- 0x0880
    :flag32("unkFlags_05") -- 0x0884
    :flag32("unkFlags_06") -- 0x0888
    :flag32("unkFlags_07") -- 0x088C
    :flag32("unkFlags_08") -- 0x0890
    :flag32("unkFlags_09") -- 0x0894
    :flag32("unkFlags_10") -- 0x0898
    :flag32("unkFlags_11") -- 0x089C
    :flag32("unkFlags_12") -- 0x08A0
    :flag32("unkFlags_13") -- 0x08A4
    :flag32("unkFlags_14") -- 0x08A8
    :flag32("unkFlags_15") -- 0x08AC
    :int32("unk_08B0") -- 0x08B0
    :int32("unk_08B4") -- 0x08B4
    :int32("unk_08B8") -- 0x08B8
    :int32("unk_08BC") -- 0x08BC
    :int32("unk_08C0") -- 0x08C0
    :TSLink("m_link") -- 0x08C4
    :ptr("CGObject_C", "objectPtr") -- 0x08CC

local CGUnit = Struct("CGUnit", CGObject)
    :ptr("unitDataPtr") -- 0x00D0
    :ptr("unk_00D4") -- 0x00D4
    :CMovementData_ptr("m_moveData") -- 0x00D8

    --mirror handlers
    :TSList_array("m_lists", 142)
    :paddingTo(0x788)

    :CMovementData("m_movementData") -- 0x0788

    :float("m_facingAngle") -- 0x08D0
    :field("unk_08D4", "int32") -- 0x08D4
    :field("unk_08D8", "int32") -- 0x08D8
    :float("m_facingAngle") -- 0x08DC
    :field("unk_08E0", "int32") -- 0x08E0
    :field("unk_08E4", "int32") -- 0x08E4
    :field("unk_08E8", "int32") -- 0x08E8
    :field("unk_08EC", "int32") -- 0x08EC
    :field("unk_08F0", "int32") -- 0x08F0
    :field("unk_08F4", "int32") -- 0x08F4
    :field("unk_08F8", "int32") -- 0x08F8
    :field("unk_08FC", "int32") -- 0x08FC
    :field("unk_0900", "int32") -- 0x0900
    :field("unk_0904", "int32") -- 0x0904
    :field("unk_0908", "int32") -- 0x0908
    :field("unk_090C", "int32") -- 0x090C
    :field("unk_0910", "int32") -- 0x0910
    :field("unk_0914", "int32") -- 0x0914
    :field("unk_0918", "int32") -- 0x0918
    :field("unk_091C", "int32") -- 0x091C
    :field("unk_0920", "int32") -- 0x0920
    :field("unk_0924", "int32") -- 0x0924
    :field("unk_0928", "int32") -- 0x0928
    :field("unk_092C", "int32") -- 0x092C
    :field("unk_0930", "int32") -- 0x0930
    :field("unk_0934", "int32") -- 0x0934
    :field("unk_0938", "int32") -- 0x0938
    :field("unk_093C", "int32") -- 0x093C
    :field("unk_0940", "int32") -- 0x0940
    :field("unk_0944", "int32") -- 0x0944
    :field("unk_0948", "int32") -- 0x0948
    :field("unk_094C", "int32") -- 0x094C
    :field("unk_0950", "int32") -- 0x0950
    :field("unk_0954", "int32") -- 0x0954
    :ptr("unk_0958") -- 0x0958
    :ptr("unk_095C") -- 0x095C
    :field("unk_0960", "int32") -- 0x0960
    :ptr("unkCreatureStatsPtr") -- 0x0964
    :ptr("CreatureDisplayInfoPtr") -- 0x0968
    :ptr("CreatureDisplayInfoExtraPtr") -- 0x096C
    :ptr("CreatureModelDataPtr") -- 0x0970
    :ptr("CreatureSoundDataPtr") -- 0x0974
    :ptr("mountedCreatureSoundDataPtr") -- 0x0978
    :ptr("unkBloodPoolPtr") -- 0x097C
    :field("unk_0980", "int32") -- 0x0980
    :field("unk_0984", "int32") -- 0x0984
    :field("unk_0988", "int32") -- 0x0988
    :ptr("m_mountM2modelPtr") -- 0x098C
    :float("m_mountScale") -- 0x0990
    :ptr("unk_0994") -- 0x0994
    :field("unk_0998", "int32") -- 0x0998
    :field("unk_099C", "int32") -- 0x099C
    :field("unk_09A0", "int32") -- 0x09A0
    :field("unk_09A4", "int32") -- 0x09A4
    :field("unk_09A8", "int32") -- 0x09A8
    :field("unk_09AC", "int32") -- 0x09AC
    :field("unk_09B0", "int32") -- 0x09B0
    :field("unk_09B4", "int32") -- 0x09B4
    :field("unk_09B8", "int32") -- 0x09B8
    :int32("objectNextUpdateMillisec") -- 0x09BC
    :int32("mountModelId") -- 0x09C0
    :field("unk_09C4", "int32") -- 0x09C4
    :field("unk_09C8", "int32") -- 0x09C8
    :field("unk_09CC", "int32") -- 0x09CC
    :field("unk_09D0", "int32") -- 0x09D0
    :field("unk_09D4", "int32") -- 0x09D4
    :Vector3("GroundNormal")
    :field("unk_09E4", "int32") -- 0x09E4
    :field("unk_09E8", "int32") -- 0x09E8
    :field("unk_09EC", "int32") -- 0x09EC
    :field("unk_09F0", "int32") -- 0x09F0
    :ptr("unk_09F4") -- 0x09F4
    :field("unk_09F8", "int32") -- 0x09F8
    :field("unk_09FC", "int32") -- 0x09FC
    :ptr("unk_0A00") -- 0x0A00
    :field("unk_0A04", "int32") -- 0x0A04
    :field("unk_0A08", "int32") -- 0x0A08
    :field("unk_0A0C", "int32") -- 0x0A0C
    :field("unk_0A10", "int32") -- 0x0A10
    :field("unk_0A14", "int32") -- 0x0A14
    :field("unk_0A18", "int32") -- 0x0A18
    :field("unk_0A1C", "int32") -- 0x0A1C
    :WOWGUID("unkGUID") -- 0x0A20
    :field("unk_0A28", "int32") -- 0x0A28
    :field("unk_0A2C", "int32") -- 0x0A2C
    :flag32("unkJumpFlags") -- 0x0A30
    :field("unk_0A34", "int32") -- 0x0A34
    :flag32("unk_0A38") -- 0x0A38
    :int32("m_footprintTexId") -- 0x0A3C
    :int32("m_terrain") -- 0x0A40
    :Vector2("m_footPrintSize")
    :float("m_footPrintScale") -- 0x0A4C
    :float("m_facingAngle") -- 0x0A50
    :float("m_pitchAngle") -- 0x0A54
    :ptr("unk_0A58") -- 0x0A58
    :int32("UnkSpellCounter") -- 0x0A5C
    :int32("m_channelSpellId") -- 0x0A60
    :field("unk_0A64", "int32") -- 0x0A64
    :field("unk_0A68", "int32") -- 0x0A68
    :int32("m_channelSpellId") -- 0x0A6C
    :flag32("unkCastSchoolImmunFlag") -- 0x0A70
    :flag32("unkCastImmunFlag") -- 0x0A74
    :int32("m_spellCastStartMS") -- 0x0A78
    :int32("m_spellCastEndMS") -- 0x0A7C
    :field("unk_0A80", "int32") -- 0x0A80
    :field("unk_0A84", "int32") -- 0x0A84
    :field("unk_0A88", "int32") -- 0x0A88
    :field("unk_0A8C", "int32") -- 0x0A8C
    :field("unk_0A90", "int32") -- 0x0A90
    :float("m_facingAngle") -- 0x0A94
    :float("unkAnimValue") -- 0x0A98
    :float("unkAnimValue") -- 0x0A9C
    :float("m_HeadFacingAngle") -- 0x0AA0
    :field("unk_0AA4", "int32") -- 0x0AA4
    :field("unk_0AA8", "int32") -- 0x0AA8
    :Vector3("SmoothFacing")
    :ptr("unk_0AB8") -- 0x0AB8
    :int32("objectUpdateMillisec") -- 0x0ABC
    :field("unk_0AC0", "int32") -- 0x0AC0
    :field("unk_0AC4", "int32") -- 0x0AC4
    :field("unk_0AC8", "int32") -- 0x0AC8
    :ptr("unkSoundPtr") -- 0x0ACC
    :field("unk_0AD0", "int32") -- 0x0AD0
    :field("unk_0AD4", "int32") -- 0x0AD4
    :int32("m_mountFootprintTexId") -- 0x0AD8
    :Vector2("m_mountFootprintSize")
    :ptr("unk_0AE4", "int32") -- 0x0AE4
    :ptr("unk_0AE8", "int32") -- 0x0AE8
    :ptr("unk_0AEC", "int32") -- 0x0AEC
    :field("unk_0AF0", "int32") -- 0x0AF0
    :field("unk_0AF4", "int32") -- 0x0AF4
    :field("unk_0AF8", "int32") -- 0x0AF8
    :field("unk_0AFC", "int32") -- 0x0AFC
    :field("unk_0B00", "int32") -- 0x0B00
    :field("unk_0B04", "int32") -- 0x0B04
    :field("unk_0B08", "int32") -- 0x0B08
    :float("m_selectionRadius") -- 0x0B0C
    :field("unk_0B10", "int32") -- 0x0B10
    :field("unk_0B14", "int32") -- 0x0B14
    :field("unkFloatValue", "float") -- 0x0B18
    :field("unk_0B1C", "int32") -- 0x0B1C
    :field("unk_0B20", "int32") -- 0x0B20
    :field("unk_0B24", "int32") -- 0x0B24
    :field("unk_0B28", "int32") -- 0x0B28
    :field("unk_0B2C", "int32") -- 0x0B2C
    :field("unk_0B30", "int32") -- 0x0B30
    :field("unk_0B34", "int32") -- 0x0B34
    :field("unk_0B38", "int32") -- 0x0B38
    :float("m_unitScale") -- 0x0B3C
    :ptr("unkDisplayModeIdRangedPtr") -- 0x0B40
    :field("unk_0B44", "int32") -- 0x0B44
    :field("unk_0B48", "int32") -- 0x0B48
    :ptr("CCharacterComponentPtr") -- 0x0B4C
    :ptr("unkEquipedMainHandModelPtr") -- 0x0B50
    :field("unk_0B54", "int32") -- 0x0B54
    :flag32("unkObjectWeaponLastStandValue") -- 0x0B58
    :flag32("unkObjectWeaponCurrentStandFlag") -- 0x0B5C
    :field("unk_0B60", "int32") -- 0x0B60
    :field("unk_0B64", "int32") -- 0x0B64
    :field("unk_0B68", "int32") -- 0x0B68
    :field("unk_0B6C", "int32") -- 0x0B6C
    :field("unk_0B70", "int32") -- 0x0B70
    :field("unk_0B74", "int32") -- 0x0B74
    :field("unk_0B78", "int32") -- 0x0B78
    :field("unk_0B7C", "int32") -- 0x0B7C
    :field("unk_0B80", "int32") -- 0x0B80
    :field("unk_0B84", "int32") -- 0x0B84
    :hex("unk_0B88", "uint32") -- 0x0B88
    :hex("unk_0B8C", "uint32") -- 0x0B8C
    :hex("unk_0B90", "uint32") -- 0x0B90
    :field("unk_0B94", "int32") -- 0x0B94
    :field("unk_0B98", "int32") -- 0x0B98
    :field("unk_0B9C", "int32") -- 0x0B9C
    :field("unk_0BA0", "int32") -- 0x0BA0
    :field("unk_0BA4", "int32") -- 0x0BA4
    :field("unk_0BA8", "int32") -- 0x0BA8
    :field("unk_0BAC", "int32") -- 0x0BAC
    :field("unk_0BB0", "int32") -- 0x0BB0
    :field("unk_0BB4", "int32") -- 0x0BB4
    :field("unk_0BB8", "int32") -- 0x0BB8
    :field("unk_0BBC", "int32") -- 0x0BBC
    :field("unk_0BC0", "int32") -- 0x0BC0
    :field("unk_0BC4", "int32") -- 0x0BC4
    :field("unk_0BC8", "int32") -- 0x0BC8
    :field("unkFloatValue", "float") -- 0x0BCC
    :field("unk_0BD0", "int32") -- 0x0BD0
    :field("unk_0BD4", "int32") -- 0x0BD4
    :field("unk_0BD8", "int32") -- 0x0BD8
    :field("unk_0BDC", "int32") -- 0x0BDC
    :field("unk_0BE0", "int32") -- 0x0BE0
    :field("unk_0BE4", "int32") -- 0x0BE4
    :field("unk_0BE8", "int32") -- 0x0BE8
    :flag32("UnkCombatFlag") -- 0x0BEC
    :field("unk_0BF0", "int32") -- 0x0BF0
    :field("unk_0BF4", "int32") -- 0x0BF4
    :field("unk_0BF8", "int32") -- 0x0BF8
    :field("unk_0BFC", "int32") -- 0x0BFC
    :field("unk_0C00", "int32") -- 0x0C00
    :field("unk_0C04", "int32") -- 0x0C04
    :field("unk_0C08", "int32") -- 0x0C08
    :field("unk_0C0C", "int32") -- 0x0C0C
    :field("unk_0C10", "int32") -- 0x0C10
    :field("unk_0C14", "int32") -- 0x0C14
    :field("unk_0C18", "int32") -- 0x0C18
    :field("unk_0C1C", "int32") -- 0x0C1C
    :field("unk_0C20", "int32") -- 0x0C20
    :field("unk_0C24", "int32") -- 0x0C24
    :field("unk_0C28", "int32") -- 0x0C28
    :field("unk_0C2C", "int32") -- 0x0C2C
    :field("unk_0C30", "int32") -- 0x0C30
    :field("unk_0C34", "int32") -- 0x0C34
    :ptr("CGNamePlateFramePtr") -- 0x0C38
    :field("unk_0C3C", "int32") -- 0x0C3C
    :field("unk_0C40", "int32") -- 0x0C40
    :field("unk_0C44", "int32") -- 0x0C44
    :field("unk_0C48", "int32") -- 0x0C48
    :field("unk_0C4C", "int32") -- 0x0C4C

    :Aura_array("m_aura", 16)

    :int32("m_auraCount") -- 0x0DD0
    :Buff_array("m_unitBuff", 16)

    :int32("m_auraCountSorted") -- 0x0E54
    :Buff_array("m_unitBuffSorted", 16)

    :paddingTo(0xFB0)

    :int32("UnitHealthPredicted") -- 0x0FB0
    :int32("UnitManaPredicted") -- 0x0FB4
    :int32("UnitRagePredicted") -- 0x0FB8
    :int32("UnitFocusPredicted") -- 0x0FBC
    :int32("UnitEnergyPredicted") -- 0x0FC0
    :int32("UnkPowerPredicted") -- 0x0FC4
    :int32("UnkPowerPredicted") -- 0x0FC8
    :int32("UnitRunePowerPredicted") -- 0x0FCC
    :int32("UnkPowerPredictionTimer") -- 0x0FD0
    :field("unk_0FD4", "int32") -- 0x0FD4
    :field("unk_0FD8", "int32") -- 0x0FD8
    :field("unk_0FDC", "int32") -- 0x0FDC
    :TSHashTable("TSHashTable__UnitThreat") -- 0x0FE0    
    :ptr("playerBeginPtr") -- 0x1008 --if not a player then 8 byte GUID
    :ptr("playerEndPtr") -- 0x100C
    :field("unk_1010", "int32") -- 0x1010
    :paddingTo(0x1068)
    :field("Health", "uint32") -- 0x1068
    :field("Mana", "uint32") -- 0x106C
    :paddingTo(0x1088)
    :field("MaxHealth", "uint32") -- 0x1088
    :field("MaxMana", "uint32") -- 0x108C
    :paddingTo(0x1110)
    :field("maxInteractDistance", "float") -- 0x1100
    :padding(0x33C)

local addr, typ = GetCGObjectAddr(readQword(0x00bd07b0)) -- target guid
if addr then
    if typ == "unit" then
        loadStructToTable(CGUnit, addr)
    end
end
