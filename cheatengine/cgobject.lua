-- #include "StructDef.lua"
-- #include "stdlib.lua"

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