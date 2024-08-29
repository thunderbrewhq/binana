// Defines

#include "system/detect.h"

// Types

#include "common/handle.h"
#include "common/instance.h"
#include "common/datarecycler.h"
#include "common/status.h"

#include "cursor/types.h"

#include "d3d9/caps.h"
#include "d3d9/device.h"

#include "event/types.h"
#include "event/context.h"
#include "event/handler.h"
#include "event/id_table.h"
#include "event/keydown.h"
#include "event/message.h"
#include "event/timer.h"

#include "framescript/object.h"
#include "framescript/event_object.h"

#include "gx/buffer.h"
#include "gx/caps.h"
#include "gx/device.h"
#include "gx/format.h"
#include "gx/matrix_stack.h"
#include "gx/shader.h"
#include "gx/state_bom.h"
#include "gx/types.h"
#include "gx/batch.h"
#include "gx/d3d9.h"

#include "storm/array.h"
#include "storm/list.h"
#include "storm/hash.h"

#include "tempest/box.h"
#include "tempest/matrix.h"
#include "tempest/plane.h"
#include "tempest/quaternion.h"
#include "tempest/range.h"
#include "tempest/rect.h"
#include "tempest/sphere.h"
#include "tempest/vector.h"

#include "texture/blp.h"
#include "texture/tga.h"

#include "ui/simpleframe.h"

// include files that define the use of template classes for standard library types
// template classes for whoa types should be entered immediately after where the type is

#include "storm/array/pointer_to_void.h"
#include "storm/array/uint8_t.h"
#include "storm/array/uint32_t.h"

#include "storm/queue/timer_priority_uint32_t.h"

// template types that are defined in our headers, should be declared immediately after the base type
// and not used anywhere else

