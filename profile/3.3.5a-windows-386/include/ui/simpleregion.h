#ifndef UI_SIMPLE_REGION_H
#define UI_SIMPLE_REGION_H

#include "ui/scriptregion.h"

DECLARE_STRUCT(CSimpleRegion);

// struct CSimpleRegion : CScriptRegion
struct CSimpleRegion {
  CScriptRegion b_base;
  int32_t m_numAlpha;
  uint8_t m_alpha[4];
  int32_t m_numColor;
  CImVector m_color[4];
  uint32_t m_regionLink[2];
  uint32_t m_drawLink[2];
  uint16_t m_regionFlags;
  uint16_t padding;
};

#endif