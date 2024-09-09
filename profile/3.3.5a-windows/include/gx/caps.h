#ifndef GX_CAPS_H
#define GX_CAPS_H

#include "system/types.h"

#include "gx/types.h"

typedef struct CGxCaps CGxCaps;

struct CGxCaps {
  int32_t m_numTmus;
  int32_t m_pixelCenterOnEdge;
  int32_t m_texelCenterOnEdge;
  int32_t m_numStreams;
  int32_t int10;
  EGxColorFormat m_colorFormat;
  uint32_t unk18;
  uint32_t m_maxIndex;
  int32_t m_generateMipMaps;
  // int32_t m_texFmt[GxTexFormats_Last];
  int32_t m_texFmt[13];
  // int32_t m_texTarget[GxTexTargets_Last];
  int32_t m_texTarget[4];
  uint32_t unk68;
  // uint32_t m_texMaxSize[GxTexTargets_Last];
  uint32_t m_texMaxSize[4];
  uint32_t unk7C;
  uint32_t unk80;
  uint32_t unk84;
  uint32_t unk88;
  uint32_t unk8C;
  uint32_t unk90;
  uint32_t unk94;
  uint32_t unk98;
  uint32_t unk9C;
  uint32_t unkA0;
  uint32_t unkA4;
  uint32_t unkA8;
  int32_t hwPcf;
  uint32_t unkB0;
  // int32_t m_shaderTargets[GxShTargets_Last];
  int32_t m_shaderTargets[6];
  // Evidence for this: go to 0x00684CD8
  uint32_t m_shaderConstants[6];
  int32_t m_texFilterTrilinear;
  int32_t m_texFilterAnisotropic;
  uint32_t m_maxTexAnisotropy;
  int32_t m_depthBias;
  uint32_t unkF4;
  int32_t m_maxClipPlanes;
  // CGxDeviceD3d::ISetCaps
  int32_t m_hardwareCursor;
  uint32_t unk100[5];
  uint32_t unk114[6];
  int32_t m_stereoAvailable;
  int32_t int130;
  int32_t int134;
  int32_t int138;
};

#endif
