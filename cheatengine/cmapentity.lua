-- #include "cmapstaticentity.lua"

local WoWGUID = Struct("WOWGUID")
    :hex("guid", "uint64")

local CMapEntity = Struct("CMapEntity", CMapStaticEntity)
    :paddingTo(0x98)
    :WOWGUID("GUID")
    :paddingTo(0xC0)
    :CImVector("ambientTarget", CImVector)
    :float("dirLightScaleTarget", "float")
    :paddingTo(0xD0)

local addr, typ = GetCGObjectAddr(readQword(0x00bd07b0)) -- target guid
if addr then
    if typ == "unit" or typ == "player" then
        local cmapentityOffset = 0xB8
        loadStructToTable(CMapEntity, readPointer(addr + cmapentityOffset))
    end
end