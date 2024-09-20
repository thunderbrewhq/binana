#ifndef SCREEN_LAYER_H
#define SCREEN_LAYER_H

#include "storm/list.h"
#include "common/handle.h"
#include "storm/region/rect.h"

DECLARE_HANDLE(HLAYER);

DECLARE_STRUCT(CILayer);

STORM_TS_LIST(CILayer);
struct CILayer {
  CHandleObject b_base;
  RECTF rect;
  RECTF visible;
  float zorder;
  uint32_t flags;
  void* param;
  void (*paintfunc)(void*, RECTF*, RECTF*, float);
  TSLink_CILayer zorderlink;
};

#endif
