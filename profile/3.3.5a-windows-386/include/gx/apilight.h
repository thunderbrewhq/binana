#ifndef GX_API_LIGHT_H
#define GX_API_LIGHT_H

DECLARE_STRUCT(CGxApiLight);

#include "tempest/vector.h"

struct CGxApiLight {
  C4Vector m_dir;
  C3Vector m_ambColor;
  C3Vector m_dirColor;
  C3Vector m_specColor;
  float m_constantAttenuation;
  float m_linearAttenuation;
  float m_quadraticAttenuation;
  int32_t m_enable;
  uint32_t flags;
};

#endif