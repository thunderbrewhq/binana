#ifndef UI_LAYOUT_FRAME_H
#define UI_LAYOUT_FRAME_H

#include "tempest/rect.h"
#include "storm/list.h"

DECLARE_STRUCT(CLayoutFrame__FRAMENODE);
DECLARE_STRUCT(CLayoutFrame_vtable);
DECLARE_STRUCT(CLayoutFrame);

STORM_TS_LIST(CLayoutFrame__FRAMENODE);

struct CLayoutFrame__FRAMENODE {
  TSLinkedNode_CLayoutFrame__FRAMENODE b_base;
  CLayoutFrame* frame;
  uint32_t dep;
};

struct CLayoutFrame_vtable {
  void* v_fn_00;
  void* v_fn_01;
  void* v_fn_02;
  void* v_fn_03;
  void* v_fn_04;
  void* v_fn_05;
  void* v_fn_06;
  void* v_fn_07;
  void* v_fn_08;
  void* v_fn_09;
  void* v_fn_10;
  void* v_fn_11;
  void* v_fn_12;
  void* v_fn_13;
  void* v_fn_14;
  void* v_fn_15;
  void* v_fn_16;
  void* v_fn_17;
  void* v_fn_18;
};

struct CLayoutFrame {
  CLayoutFrame_vtable* v_vtable;
  uint32_t resizeLink[2];
  void* m_points[9];
  TSList_CLayoutFrame__FRAMENODE m_resizeList;
  uint32_t m_guard;
  uint32_t m_flags;
  CRect m_rect;
  float m_width;
  float m_height;
  float m_layoutScale;
  float m_layoutDepth;
  float float64;
  float float68;
  float float6C;
  float float70;
};

#endif