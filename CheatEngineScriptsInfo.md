#### How to execute the script
- Click *'Table'* then *'Show Cheat Table Lua Script'* or press Ctrl+Alt+L

#### CGObject_C hierarchy
| Name | What to do | What to load |
|---|---|---|
| CGUnit_C | Select a target unit (it must be of type **Unit**). | [Load_CGUnit.lua](https://github.com/thunderbrewhq/binana/blob/master/profile/3.3.5a-windows-386/cheatengine/Load_CGUnit.lua) |
| CGPlayer_C (your character) | — | [Load_CGPlayer.lua](https://github.com/thunderbrewhq/binana/blob/master/profile/3.3.5a-windows-386/cheatengine/Load_CGPlayer.lua) |
| CGCorpse_C | After the script exec hover your mouse cursor over the corpse. | [Load_CGCorpse.lua](https://github.com/thunderbrewhq/binana/blob/master/profile/3.3.5a-windows-386/cheatengine/Load_CGCorpse.lua) |
| CGItem_C (items in the main 16-slot backpack) | — | [Load_CGItem.lua](https://github.com/thunderbrewhq/binana/blob/master/profile/3.3.5a-windows-386/cheatengine/Load_CGItem.lua) |
| CGContainers_C (only for equipped bags) | — | [Load_CGContainer.lua](https://github.com/thunderbrewhq/binana/blob/master/profile/3.3.5a-windows-386/cheatengine/Load_CGContainer.lua) |

#### Map/World
| Name | What to do | What to load |
|---|---|---|
| CMapArea (ADT) | — | [Load_CMapArea.lua](https://github.com/thunderbrewhq/binana/blob/master/profile/3.3.5a-windows-386/cheatengine/Load_CMapArea.lua) |
| CMapChunk | — | [Load_CMapChunk.lua](https://github.com/thunderbrewhq/binana/blob/master/profile/3.3.5a-windows-386/cheatengine/Load_CMapChunk.lua) |
| CMapEntity | Select a target (unit or player). | [Load_CMapEntity.lua](https://github.com/thunderbrewhq/binana/blob/master/profile/3.3.5a-windows-386/cheatengine/Load_CMapEntity.lua) |
| CMapDoodadDef | Stand near the object and exec the script. | [Load_CMapDoodadDef.lua](https://github.com/thunderbrewhq/binana/blob/master/profile/3.3.5a-windows-386/cheatengine/Load_CMapDoodadDef.lua) |
| CMapObjDef (WMO) | Run inside a WMO object (tower, cave, barracks etc) and exec the script. | [Load_CMapObjDef.lua](https://github.com/thunderbrewhq/binana/blob/master/profile/3.3.5a-windows-386/cheatengine/Load_CMapObjDef.lua) |
| CMapObjDefGroup | Run inside a WMO object (tower, cave, barracks etc) and exec the script. | [Load_CMapObjDefGroup.lua](https://github.com/thunderbrewhq/binana/blob/master/profile/3.3.5a-windows-386/cheatengine/Load_CMapObjDefGroup.lua) |
| CMapObj | Run inside a WMO object (tower, cave, barracks etc) and exec the script. | [Load_CMapObj.lua](https://github.com/thunderbrewhq/binana/blob/master/profile/3.3.5a-windows-386/cheatengine/Load_CMapObj.lua) |
| CMapObjGroup | Run inside a WMO object (tower, cave, barracks etc) and exec the script. | [Load_CMapObjGroup.lua](https://github.com/thunderbrewhq/binana/blob/master/profile/3.3.5a-windows-386/cheatengine/Load_CMapObjGroup.lua) |
| CDetailDoodadInst (flower/grass on the ground) | Stand on the grass and exec the script. | [Load_CDetailDoodadInst.lua](https://github.com/thunderbrewhq/binana/blob/master/profile/3.3.5a-windows-386/cheatengine/Load_CDetailDoodadInst.lua) |
| CChunkLiquid | Run inside water (not a WMO water) and exec the script. | [Load_CChunkLiquid.lua](https://github.com/thunderbrewhq/binana/blob/master/profile/3.3.5a-windows-386/cheatengine/Load_CChunkLiquid.lua) |