#ifndef UI_SCRIPT_OBJECT_H
#define UI_SCRIPT_OBJECT_H

#include "common/rcstring.h"
#include "framescript/object.h"

DECLARE_STRUCT(CScriptObject);

// struct CScriptObject : FrameScript_Object {
struct CScriptObject {
  FrameScript_Object b_base;
  RCString m_name;
};

#endif