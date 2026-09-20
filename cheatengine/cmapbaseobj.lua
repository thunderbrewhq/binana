-- #include "StructDef.lua"

local CImVector = Struct("CImVector")
    :uint8("r")
    :uint8("g")
    :uint8("b")
    :uint8("a")

local C3Vector = Struct("C3Vector")
    :float("x")
    :float("y")
    :float("z")

local C2iVector = Struct("C2iVector")
    :int32("x")
    :int32("y")

local CAaBox = Struct("CAaBox")
    :C3Vector("top")
    :C3Vector("bottom")

local CAaSphere = Struct("CAaSphere")
    :C3Vector("center")
    :float("d")

local C44Matrix = Struct("C44Matrix")
    :float_array("m", 16)

local TSGrowableArray = Struct("TSGrowableArray")
    :uint32('m_alloc')
    :uint32('m_count')
    :ptr('data')
    :uint32('m_chunk')

local TSLink = Struct("TSLink")
    :TSLink_ptr("m_prevlink")
    :ptr("m_next")

local TSList = Struct("TSList") -- also TSExplicitList
    :int32("m_linkoffset")
    :TSLink("m_terminator")

local CMapBaseObj = Struct("CMapBaseObj")
    :ptr("void*", "vtable")
    :uint32("objectIndex")
    :uint16("type")
    :uint16("refCount")
    :uint32("unk_C")
    :TSLink("m_link")
    :TSList("m_objLink")