#ifndef UI_SIMPLE_TOP_H
#define UI_SIMPLE_TOP_H

#include "event/types.h"
#include "ui/layoutframe.h"
#include "ui/simpleframe.h"
#include "tempest/vector.h"
#include "common/array.h"

DECLARE_ENUM(FRAMEPOINT);

DECLARE_STRUCT(FRAMEPRIORITY);
DECLARE_STRUCT(CSimpleTop);
DECLARE_STRUCT(CSimpleTop__frame_layout);

enum FRAMEPOINT {
  FRAMEPOINT_TOPLEFT = 0x0,
  FRAMEPOINT_TOP = 0x1,
  FRAMEPOINT_TOPRIGHT = 0x2,
  FRAMEPOINT_LEFT = 0x3,
  FRAMEPOINT_CENTER = 0x4,
  FRAMEPOINT_RIGHT = 0x5,
  FRAMEPOINT_BOTTOMLEFT = 0x6,
  FRAMEPOINT_BOTTOM = 0x7,
  FRAMEPOINT_BOTTOMRIGHT = 0x8,
  FRAMEPOINT_NUMPOINTS = 0x9
};

struct CSimpleTop__frame_layout {
  int32_t enabled;
  CSimpleFrame* frame;
  FRAMEPOINT anchor;
  C2Vector last;
  float float14;
};

struct FRAMEPRIORITY {
  CSimpleFrame* frame;
  uint32_t priority;
};
typedef FRAMEPRIORITY* pointer_to_FRAMEPRIORITY;
COMMON_SIMPLE_SORTED_ARRAY(pointer_to_FRAMEPRIORITY);

struct CSimpleTop {
  CLayoutFrame b_base;
  void* m_screenLayer;
  CSimpleFrame* m_mouseFocus;
  CSimpleFrame* m_mouseCapture;
  uint32_t m_keydownCapture[787];
  TSList_SIMPLEFRAMENODE m_frames;
  uint32_t m_destroyed[3];
  void* m_strata[9];
  CSimpleTop__frame_layout m_layout;
  CSimpleSortedArray_pointer_to_FRAMEPRIORITY m_eventqueue[5][9];
  int32_t m_checkFocus;
  EVENT_DATA_MOUSE m_mousePosition;
  uint32_t dword1234;
  void* m_mouseButtonCallback;
  void* m_mouseMoveCallback;
  void* m_displaySizeCallback;
  uint32_t dword1244;
  void* m_keyEventCallback;
  uint32_t dword124C;
  uint32_t dword1250;
  uint32_t dword1254;
};

#endif