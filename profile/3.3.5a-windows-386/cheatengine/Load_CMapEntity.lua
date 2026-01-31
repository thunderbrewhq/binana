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

local CImVector = Struct("CImVector")
    :field("r", "uint8")
    :field("g", "uint8")
    :field("b", "uint8")
    :field("a", "uint8")

local C3Vector = Struct("C3Vector")
    :field("x", "float")
    :field("y", "float")
    :field("z", "float")

local C2iVector = Struct("C2iVector")
    :field("x", "int32")
    :field("y", "int32")

local CAaBox = Struct("CAaBox")
    :embed("top", C3Vector)
    :embed("bottom", C3Vector)

local CAaSphere = Struct("CAaSphere")
    :embed("center", C3Vector)
    :field("d", "float")

local C44Matrix = Struct("C44Matrix")
    :array('m', 'float', 16)

local TSGrowableArray = Struct("TSGrowableArray")
    :field('m_alloc', 'uint32')
    :field('m_count', 'uint32')
    :ptr('data')
    :field('m_chunk', 'uint32')

local TSExplicitList = Struct("TSExplicitList")
    :field("m_linkOffset", "uint32")
    :ptr("ptr1")
    :ptr("ptr2")

local CMapBaseObj = Struct("CMapBaseObj")
    :ptr("void*", "vtable")
    :field("objectIndex", "uint32")
    :field("type", "uint16")
    :field("refCount", "uint16")
    :field("unk_C", "int32")
    :ptr("prev")
    :ptr("next")
    :embed("objLink", TSExplicitList)

local CMapStaticEntity = Struct("CMapStaticEntity", CMapBaseObj)
    :paddingTo(0x28)
    :field("unkFlags", "uint32")
    :field("unkCounter", "int32")
    :field("unk_030", "float")
    :ptr("CM2Model", "model")
    :embed("sphere", CAaSphere)
    :embed("bbox", CAaBox)
    :embed("vec2", C3Vector)
    :embed("position", C3Vector)
    :field("scale", "float")
    :paddingTo(0x84)
    :embed("m2AmbietColor", CImVector)
    :embed("m2DiffuseColor", CImVector)
    :field("unk_08C", "float")

local CMapEntity = Struct("CMapEntity", CMapStaticEntity)
    :paddingTo(0x98)
    :hex("GUID", "uint64")
    :paddingTo(0xC0)
    :embed("ambientTarget", CImVector)
    :field("dirLightScaleTarget", "float")
    :paddingTo(0xD0)

local addr, typ = GetCGObjectAddr(readQword(0x00bd07b0)) -- target guid
if addr then
    if typ == "unit" or typ == "player" then
        local cmapentityOffset = 0xB8
        loadStructToTable(CMapEntity, readPointer(addr + cmapentityOffset))
    end
end
