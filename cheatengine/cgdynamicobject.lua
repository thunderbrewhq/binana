-- #include "cgobject.lua"

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

local DynamicObjectFields = Struct("DynamicObjectFields")
    :WOWGUID("caster")
    :uint32("bytes")
    :uint32("spellId")
    :float("radius")
    :uint32("castTime")

local CGDynamicObject_C = Struct("CGDynamicObject_C", CGObject)
    :DynamicObjectFields_ptr("m_dynamicObjectFields")
    :paddingTo(0x0D8)
    :CPassenger("m_passenger") -- 0x0D8–0x107
    :TSList_array("lists", 6) -- 0x108–0x14F
    :flag32("m_flags") -- 0x150
    :float("m_scale") -- 0x154 = 1.0
    :ptr("m_spellVisual") -- 0x158
    :uint32("unk_15C") -- 0x15C
    :uint32("unk_160") -- 0x160
    :ptr("unk_SoundVtbl_ptr") -- 0x164 -- ptr to 0x0087bdfc
    :uint32("unk_168") -- 0x168
    :uint32("unk_16C") -- 0x16C

function findAllAddresses()
    local scan = AOBScan("20 30 A3 00")
    if scan then
        for i = 0, scan.Count - 1 do
            local addr = getAddress(scan[i])
            if not inModule(addr) then
                loadStructToTable(CGDynamicObject_C, addr)
            end
        end
        scan.destroy()
    end
end

findAllAddresses()