-- #include "cmapstaticentity.lua"

local CMapDoodadDef = Struct("CMapDoodadDef", CMapStaticEntity)
    :uint32("unkFlags_090", { hex = true })             -- 0x090
    :TSLink("m_link")                                   -- 0x094
    :TSLink("m_mapDoodadDefLink")                       -- 0x09C
    :int32("unk_0A4")                                   -- 0x0A4
    :int32("unk_0A8")                                   -- 0x0A8
    :int32("unk_0AC")                                   -- 0x0AC
    :uint32("unkCounter")                               -- 0x0B0
    :int32("unk_0B4")                                   -- 0x0B4
    :int32("unk_0B8")                                   -- 0x0B8
    :int32("unk_0BC")                                   -- 0x0BC
    :CAaBox("bboxDoodadDef")                            -- 0x0C0
    :C44Matrix("mat")                                   -- 0x0D8
    :C44Matrix("identity")                              -- 0x118
    :int32("unk_158")                                   -- 0x158
    :int32("unk_15C")                                   -- 0x15C
    :ptr("unkSoundObjVtblptr")                          -- 0x160
    :int32("unk_164")                                   -- 0x164
    :int32("unk_168")                                   -- 0x168
    :int32("unk_16C")                                   -- 0x16C
-- sizeof: 0x170

local ADDR_PLAYER_X = 0xADF4E4
local ADDR_PLAYER_Y = 0xADF4E8
local ADDR_PLAYER_Z = 0xADF4EC

function getObjectPos(this)
  local mat = this + 0xD8
  return
    readFloat(mat + 0x30), -- X
    readFloat(mat + 0x34), -- Y
    readFloat(mat + 0x38)  -- Z
end

function getObjectBBox(this)
  local bbox = this + 0xC0
  return
    readFloat(bbox + 0x00), -- minX
    readFloat(bbox + 0x04), -- minY
    readFloat(bbox + 0x08), -- minZ
    readFloat(bbox + 0x0C), -- maxX
    readFloat(bbox + 0x10), -- maxY
    readFloat(bbox + 0x14)  -- maxZ
end

function isObjectNearPlayer(this, radius)
  radius = radius or 10.0

  local px = readFloat(ADDR_PLAYER_X)
  local py = readFloat(ADDR_PLAYER_Y)
  local pz = readFloat(ADDR_PLAYER_Z)

  if px ~= px or py ~= py or pz ~= pz then
    return false
  end

  local ox, oy, oz = getObjectPos(this)

  if ox ~= ox or oy ~= oy or oz ~= oz then
    return false
  end

  local dx = ox - px
  local dy = oy - py
  local dz = oz - pz

  local dist = math.sqrt(dx * dx + dy * dy + dz * dz)

  if dist <= radius then
    return true
  end

  return false
end

function findAllAddresses(radius)
  local objects = {}

  local scan = AOBScan("18 03 A4 00")
  if scan then
    for i = 0, scan.Count - 1 do
      local addr = getAddress(scan[i])

      if addr ~= 0 and not inModule(addr) then
        if isObjectNearPlayer(addr, radius or 10.0) then
          loadStructToTable(CMapDoodadDef, addr)
        end
      end
    end

    scan.destroy()
  end

  return objects
end

findAllAddresses(5.0)