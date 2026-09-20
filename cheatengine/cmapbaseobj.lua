-- #include "StructDef.lua"
-- #include "stdlib.lua"

local CMapBaseObj = Struct("CMapBaseObj")
    :ptr("void*", "vtable")
    :uint32("objectIndex")
    :uint16("type")
    :uint16("refCount")
    :uint32("unk_C")
    :TSLink("m_link")
    :TSList("m_objLink")