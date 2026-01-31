-- #include "StructDef.lua"

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