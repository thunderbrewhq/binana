#ifndef M2_LIGHTING_H
#define M2_LIGHTING_H

DECLARE_STRUCT(CM2Lighting);

#include "m2/scene.h"
#include "tempest/vector.h"
#include "tempest/sphere.h"
#include "tempest/plane.h"

struct CM2Lighting {
  CM2Scene* m_scene;
  CAaSphere sphere4;
  uint32_t m_flags;
  C3Vector vector18;
  C3Vector vector24;
  C3Vector vector30;
  C3Vector vector3C;
  C3Vector vector48;
  C3Vector m_sunAmbient;
  C3Vector m_sunDiffuse;
  C3Vector m_sunSpecular;
  C3Vector m_sunDir;
  CM2Light* m_lights[4];
  uint32_t m_lightCount;
  float m_fogStart;
  float m_fogEnd;
  float m_fogScale;
  float m_fogDensity;
  C3Vector m_fogColor;
  C4Plane m_liquidPlane;
};

#endif