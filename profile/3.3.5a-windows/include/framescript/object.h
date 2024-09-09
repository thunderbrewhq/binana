#ifndef FRAMESCRIPT_OBJECT_H
#define FRAMESCRIPT_OBJECT_H

#include "system/types.h"

DECLARE_STRUCT(FrameScript_Object);

struct FrameScript_Object {
  void** v_vtable;
  int32_t lua_registered;
  int32_t lua_objectRef;
  int32_t m_onEvent;
};

#endif
