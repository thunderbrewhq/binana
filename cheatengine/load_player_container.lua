local addr, typ = GetCGObjectAddr(readQword(0xC79D10)) -- local player GUID from game connection class
if addr then
    if typ == "player" then
        local bagsOffset = 0x1F00
        for i = 0, 4, 1 do
            local addr, typ = GetCGObjectAddr(readQword(addr + bagsOffset + i * 8))
            if addr ~= 0 and typ == "container" then
                loadStructToTable(CGContainer, addr)
            end
        end
    end
end