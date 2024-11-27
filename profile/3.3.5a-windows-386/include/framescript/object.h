#ifndef FRAMESCRIPT_OBJECT_H
#define FRAMESCRIPT_OBJECT_H

#include "system/types.h"

DECLARE_STRUCT(FrameScript_Object);
DECLARE_STRUCT(FrameScript_Object__ScriptIx);

struct FrameScript_Object {
  void** v_vtable;
  int32_t lua_registered;
  int32_t lua_objectRef;
  int32_t m_onEvent;
};

// struct FrameScript_Object::ScriptIx
struct FrameScript_Object__ScriptIx {
  int32_t luaRef;
  int8_t* unk;
};

// struct FrameScript_Object::ScriptData
struct FrameScript_Object__ScriptData {
  char* wrapper;
};

// struct FrameScript_Object::ScriptFunction {
struct FrameScript_Object__ScriptFunction {
  int32_t luaRef;
};

#endif
