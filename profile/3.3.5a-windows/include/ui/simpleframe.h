#ifndef UI_SIMPLE_FRAME_H
#define UI_SIMPLE_FRAME_H

#include "storm/list.h"
#include "tempest/rect.h"
#include "tempest/vector.h"

DECLARE_STRUCT(CSimpleFrame);
DECLARE_STRUCT(SIMPLEFRAMENODE);

STORM_TS_LIST(SIMPLEFRAMENODE);

#include "ui/scriptregion.h"
#include "ui/backdropgenerator.h"
#include "ui/renderbatch.h"

DECLARE_STRUCT(CBackdropGenerator);

// struct CSimpleFrame : CScriptRegion {
struct CSimpleFrame {
  CScriptRegion b_base;
  void* m_top;
  CSimpleFrame* m_tooltip;
  CScriptRegion* m_titleRegion;
  int32_t m_intAC;
  int32_t m_id;
  uint32_t m_flags;
  float m_frameScale;
  uint32_t dwordBC;
  uint32_t dwordC0;
  float m_floatC4;
  float m_floatC8;
  uint32_t dwordCC;
  int32_t m_strata;
  int32_t m_level;
  uint32_t m_eventmask;
  int32_t m_shown;
  int32_t m_visible;
  CRect m_hitRect;
  CRect m_hitOffset;
  uint32_t simpleframe_unk9[4];
  int32_t m_highlightLocked;
  uint32_t m_lookForDrag;
  int32_t m_mouseDown;
  int32_t m_dragging;
  int32_t m_dragButton;
  C2Vector m_clickPoint;
  int32_t m_loading;
  FrameScript_Object__ScriptIx m_onLoad;
  FrameScript_Object__ScriptIx m_onSizeChanged;
  FrameScript_Object__ScriptIx m_onUpdate;
  FrameScript_Object__ScriptIx m_onShow;
  FrameScript_Object__ScriptIx m_onHide;
  FrameScript_Object__ScriptIx m_onEnter;
  FrameScript_Object__ScriptIx m_onLeave;
  FrameScript_Object__ScriptIx m_onMouseDown;
  FrameScript_Object__ScriptIx m_onMouseUp;
  FrameScript_Object__ScriptIx m_onMouseWheel;
  FrameScript_Object__ScriptIx m_onDragStart;
  FrameScript_Object__ScriptIx m_onDragStop;
  FrameScript_Object__ScriptIx m_onReceiveDrag;
  FrameScript_Object__ScriptIx m_onChar;
  FrameScript_Object__ScriptIx m_onKeyDown;
  FrameScript_Object__ScriptIx m_onKeyUp;
  FrameScript_Object__ScriptIx m_onAttributeChange;
  FrameScript_Object__ScriptIx m_onEnable;
  FrameScript_Object__ScriptIx m_onDisable;
  uint32_t m_attributes[10];
  int32_t m_drawenabled[5];
  CBackdropGenerator* m_backdrop;
  uint32_t m_regions[3];
  uint32_t m_drawlayers[15];
  uint32_t m_batchDirty;
  void* m_batch[5];
  TSExplicitList_CRenderBatch m_renderList;
  uint32_t m_children[3];
  uint32_t m_framesLink[2];
  uint32_t m_destroyedLink[2];
  uint32_t m_strataLink[2];
};
STORM_TS_LIST(CSimpleFrame);

// struct SIMPLEFRAMENODE : TSLinkedNode<SIMPLEFRAMENODE> 
struct SIMPLEFRAMENODE {
  TSLinkedNode_SIMPLEFRAMENODE b_base;
  CSimpleFrame* frame;
};

#endif