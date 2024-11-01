#ifndef M2_LIGHT_H
#define M2_LIGHT_H

DECLARE_STRUCT(CM2Light);

#include "m2/scene.h"

struct CM2Light {
  CM2Scene* m_scene;
  uint32_t dword4;
  uint32_t m_type;
  C3Vector m_pos;
  float float10;
  float float14;
  float float18;
  C3Vector m_dir;
  C3Vector m_ambColor;
  C3Vector m_dirColor;
  C3Vector m_specColor;
  float m_constantAttenuation;
  float m_linearAttenuation;
  float m_quadraticAttenuation;
  uint32_t m_visible;
  CM2Light** m_lightPrev;
  CM2Light* m_lightNext;
};

#endif