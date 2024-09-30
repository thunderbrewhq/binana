#ifndef UI_SCRIPT_REGION_H
#define UI_SCRIPT_REGION_H

#include "ui/simpleframe.h"
#include "ui/scriptobject.h"
#include "ui/layoutframe.h"

DECLARE_STRUCT(CScriptRegion);
// forward declare to avoid problems
DECLARE_STRUCT(CSimpleFrame);

// struct CScriptRegion : CScriptObject, CLayoutFrame  {
struct CScriptRegion {
  CScriptObject b_base_01;
  CLayoutFrame b_base_02;
  CSimpleFrame* m_parent;
  void* m_animGroups;
  uint32_t scriptregion_dword8;
};

#endif