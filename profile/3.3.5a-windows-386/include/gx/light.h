#ifndef GX_LIGHT_H
#define GX_LIGHT_H

#include "tempest/vector.h"

DECLARE_STRUCT(CGxLight);

struct CGxLight {
  // int32_t m_enabled : 1;
  // int32_t m_isOmni : 1;
  int32_t f_flags;
  C3Vector m_dir;
  C3Vector m_ambColor;
  C3Vector m_dirColor;
  C3Vector m_specColor;
  float m_constantAttenuation;
  float m_linearAttenuation;
  float m_quadraticAttenuation;
};

#endif