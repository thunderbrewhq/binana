-- #include "cgobject.lua"

local Vector3 = Struct("Vector3")
    :field("x", "float")
    :field("y", "float")
    :field("z", "float")

local ObjectFields = Struct("ObjectFields")
    :hex("GUID", "uint64")
    :field("type", "uint32")
    :field("unk", "uint32")
    :field("scale", "float")
    :field("pad", "uint32")

local CorpseFields = Struct("CorpseFields")
    :hex("Owner", "uint64")
    :hex("Party", "uint64")
    :field("DisplayId", "int32")
    :array("Item", "int32", 19)
    :hex("Bytes1", "uint32")
    :hex("Bytes2", "uint32")
    :field("Guild", "int32")
    :field("Flags", "int32")
    :field("DynamicFlags", "int32")
    :field("Pad", "int32")

local CGCorpse = Struct("CGCorpse", CGObject)
    :paddingTo(0xE8)
    :embed("Position", Vector3) -- 0x0E8
    :paddingTo(0xF8)
    :field("FacingAngle", "float") -- 0x0F8
    :paddingTo(0x274)
    :embed("Scale", Vector3) -- 0x274
    :paddingTo(0x290)
    :embed("ObjectFields", ObjectFields) -- 0x290
    :embed("CorpseFields", CorpseFields) -- 0x2A8
    :paddingTo(0x338)

-- #include "load_mouseover_corpse.lua"