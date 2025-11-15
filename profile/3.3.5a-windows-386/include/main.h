// Defines

#include "system/detect.h"

// Types (include all files to expose them in the disassembler)

// external types (c-ified)
#include "external/d3d9/d3d9.h"
#include "external/lua/lua.h"

#include "async/object.h"
#include "async/queue.h"

#include "bc/main.h"

#include "camera/camera.h"

#include "cmd/option.h"

#include "common/array.h"
#include "common/handle.h"
#include "common/instance.h"
#include "common/datarecycler.h"
#include "common/datastore.h"
#include "common/status.h"
#include "common/refcount.h"
#include "common/rcstring.h"

#include "console/hardware.h"
#include "console/default_settings.h"
#include "console/command.h"
#include "console/line.h"
#include "console/var.h"
#include "console/types.h"

#include "cursor/types.h"

#include "event/types.h"
#include "event/context.h"
#include "event/handler.h"
#include "event/id_table.h"
#include "event/keydown.h"
#include "event/message.h"
#include "event/timer.h"
#include "event/thread.h"

#include "framescript/object.h"
#include "framescript/event_object.h"

#include "gx/batch.h"
#include "gx/blit.h"
#include "gx/buffer.h"
#include "gx/caps.h"
#include "gx/device.h"
#include "gx/format.h"
#include "gx/light.h"
#include "gx/matrix_stack.h"
#include "gx/monitor_mode.h"
#include "gx/opengl.h"
#include "gx/shader.h"
#include "gx/state_bom.h"
#include "gx/string.h"
#include "gx/stringbatch.h"
#include "gx/texture.h"
#include "gx/types.h"
#include "gx/batch.h"
#include "gx/d3d9.h"
#include "gx/query.h"

#include "m2/cache.h"
#include "m2/data.h"
#include "m2/light.h"
#include "m2/lighting.h"
#include "m2/model.h"
#include "m2/ribbon.h"
#include "m2/scene.h"
#include "m2/shadereffect.h"
#include "m2/shared.h"
#include "m2/types.h"

#include "map/CMapBaseObj.h"
#include "map/ADTchunks.h"
#include "map/CMapArea.h"
#include "map/WMOchunks.h"
#include "map/CMapObj.h"
#include "map/CChunkLiquid.h"
#include "map/CDetailDoodadInst.h"
#include "map/CMapRenderChunk.h"
#include "map/CMapObjDef.h"
#include "map/CMapStaticEntity.h"
#include "map/CMapDoodadDef.h"
#include "map/CMapEntity.h"
#include "map/CMapBaseObjLink.h"
#include "map/Weather.h"

#include "character/CCharacterComponent.h"

#include "net/message.h"

#include "nvapi/nvapi.h"

#include "object/object.h"

#include "os/processorfeatures.h"
#include "os/timemanager.h"

#include "screen/layer.h"

#include "storm/array.h"
#include "storm/big.h"
#include "storm/cmd.h"
#include "storm/list.h"
#include "storm/hash.h"
#include "storm/queue.h"
#include "storm/region.h"
#include "storm/thread.h"
#include "storm/log.h"
#include "storm/options.h"

#include "tempest/box.h"
#include "tempest/matrix.h"
#include "tempest/plane.h"
#include "tempest/quaternion.h"
#include "tempest/range.h"
#include "tempest/rect.h"
#include "tempest/sphere.h"
#include "tempest/vector.h"

#include "text/font.h"

#include "texture/blp.h"
#include "texture/texture.h"
#include "texture/tga.h"

#include "ui/backdropgenerator.h"
#include "ui/framestrata.h"
#include "ui/layoutframe.h"
#include "ui/renderbatch.h"
#include "ui/scriptobject.h"
#include "ui/scriptregion.h"
#include "ui/simplebatchedmesh.h"
#include "ui/simpleframe.h"
#include "ui/simpleregion.h"
#include "ui/simpletexture.h"
#include "ui/simpletop.h"

// include files that define the use of template classes for standard library types
// template classes for whoa types should be entered immediately after where the type is

#include "storm/array/pointer_to_void.h"
#include "storm/array/uint8_t.h"
#include "storm/array/uint32_t.h"
#include "storm/array/float.h"
#include "storm/array/c2ivector.h"

#include "storm/queue/timer_priority_uint32_t.h"

// template types that are defined in our headers, should be declared immediately after the base type
// and not used anywhere else

