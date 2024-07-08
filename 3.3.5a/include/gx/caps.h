#ifndef GX_CAPS_H
#define GX_CAPS_H

#include "gx/types.h"
#include <stdint.h>

typedef struct CGxCaps CGxCaps;

struct CGxCaps {
  int32_t m_numTmus;
  int32_t m_pixelCenterOnEdge;
  int32_t m_texelCenterOnEdge;
  int32_t m_numStreams;
  int32_t int10;
  EGxColorFormat m_colorFormat;
  uint32_t m_maxIndex;
  int32_t m_generateMipMaps;
  int32_t m_texFmt[GxTexFormats_Last];
  int32_t m_texTarget[GxTexTargets_Last];
  uint32_t m_texMaxSize[GxTexTargets_Last];
  int32_t m_shaderTargets[GxShTargets_Last];
  int32_t m_texFilterTrilinear;
  int32_t m_texFilterAnisotropic;
  uint32_t m_maxTexAnisotropy;
  int32_t m_depthBias;
  int32_t int130;
  int32_t int134;
  int32_t int138;
};

#endif
