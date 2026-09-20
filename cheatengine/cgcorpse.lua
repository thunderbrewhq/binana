-- #include "cgobject.lua"

local CorpseFields = Struct("CorpseFields")
    :WOWGUID("Owner")
    :WOWGUID("Party")
    :int32("DisplayId")
    :int32_array("Item")
    :flag32("Bytes1")
    :flag32("Bytes2")
    :int32("Guild", "int32")
    :flag32("Flags")
    :flag32("DynamicFlags")
    :int32("Pad")

local CGCorpse = Struct("CGCorpse", CGObject)
    :paddingTo(0xE8)
    :C3Vector("m_position") -- 0x0E8
    :paddingTo(0xF8)
    :float("m_facingAngle") -- 0x0F8
    :paddingTo(0x274)
    :C3Vector("m_scale") -- 0x274
    :paddingTo(0x290)
    :ObjectFields("m_objectFields") -- 0x290
    :CorpseFields("m_corpseFields") -- 0x2A8
    :paddingTo(0x338)

-- #include "load_mouseover_corpse.lua"