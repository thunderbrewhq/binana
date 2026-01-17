local addr, typ = GetCGObjectAddr(readQword(0xC79D10)) -- local player GUID from game connection class
if addr then
    if typ == "player" then
        local bagpackOffset = 0x1F20
        for i = 0, 15, 1 do
            local addr, typ = GetCGObjectAddr(readQword(addr + bagpackOffset + i * 8))
            if addr ~= 0 and typ == "item" then
                loadStructToTable(CGItem, addr)
            end
        end
    end
end