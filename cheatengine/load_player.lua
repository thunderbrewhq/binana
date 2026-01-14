local addr, typ = GetCGObjectAddr(readQword(0xC79D10)) -- local player GUID from game connection class
if addr then
    if typ == "player" then
        loadStructToTable(CGPlayer, addr)
    end
end