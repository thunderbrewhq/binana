local address = 0x51f838 -- at CGGameUI__HandleObjectTrackChange
debugger_onBreakpoint = nil
function onBreakpoint()
    local addr, typ = GetCGObjectAddr(readQword(0x00bd07a0)) -- mouseover guid
    if addr then
        if typ == "corpse" then
            loadStructToTable(CGCorpse, addr)
        end
    end
    debugger_onBreakpoint = nil
    debug_removeBreakpoint(address)
    debug_continueFromBreakpoint(co_run)
    return 1
end

debug_setBreakpoint(address)
debugger_onBreakpoint = onBreakpoint
