#ifndef UI_SIMPLE_MODEL_H
#define UI_SIMPLE_MODEL_H

#include "tempest/box.h"
#include "tempest/vector.h"
#include "framescript/object.h"
#include "m2/scene.h"
#include "m2/model.h"
#include "ui/simpleframe.h"

DECLARE_STRUCT(CSimpleModel);

// class CSimpleModel : CSimpleFrame
struct CSimpleModel {
  CSimpleFrame b_base;
  CM2Scene* m_scene;
  CM2Model* m_model;
  CCamera* m_camera;
  uint32_t m_pendingCameraIndex;
  uint32_t m_pendingCameraId;
  CM2Light m_light;
  C3Vector m_position;
  float m_facing;
  float m_scale;
  uint32_t m_flags;
  CImVector m_fogColor;
  float m_fogNear;
  float m_fogFar;
  CAaBox m_bounds;
  FrameScript_Object__ScriptIx m_onUpdateModel;
  FrameScript_Object__ScriptIx m_onAnimFinished;
};

#endif