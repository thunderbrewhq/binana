-- #include "cmapstaticentity.lua"

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