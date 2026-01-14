local addr, typ = GetCGObjectAddr(readQword(0x00bd07b0)) -- target guid
if addr then
    if typ == "unit" then
        loadStructToTable(CGUnit, addr)
    end
end