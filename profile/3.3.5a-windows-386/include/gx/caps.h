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
  // Always set to 1 in CGxDeviceOpenGl
  // Set to 1 if D3d9 Caps2 & 0x1
  // this could be an undocumented flag
  // CGxDeviceD3d::Draw skips a calculation if 1
  // could also be a bug: maybe they meant to check
  // D3DDEVCAPS2_STREAMOFFSET in DevCaps2
  // but mistakenly checked Caps2
  // in which case this could be called m_streamOffset
  int32_t int10;
  EGxColorFormat m_colorFormat;
  // set to zero in CGxDeviceOpenGl::CGxDeviceOpenGl
  uint32_t unk18;
  uint32_t m_maxIndex;
  int32_t m_generateMipMaps;
  // int32_t m_texFmt[GxTexFormats_Last];
  int32_t m_texFmt[13];
  // int32_t m_texTarget[GxTexTargets_Last];
  int32_t m_texTarget[4];
  uint32_t m_texNonPow2;
  // uint32_t m_texMaxSize[GxTexTargets_Last];
  uint32_t m_texMaxSize[4];
  int32_t m_rttFormat[13];
  uint32_t unkB0;
  // int32_t m_shaderTargets[GxShTargets_Last];
  int32_t m_shaderTargets[6];
  // Evidence for this: go to 0x00684CD8
  uint32_t m_shaderConstants[6];
  int32_t m_texFilterTrilinear;
  int32_t m_texFilterAnisotropic;
  uint32_t m_maxTexAnisotropy;
  int32_t m_depthBias;
  int32_t m_colorWrite;
  int32_t m_maxClipPlanes;
  // CGxDeviceD3d::ISetCaps
  int32_t m_hwCursor;
  int32_t m_occlusionQuery;
  // GxOverride_Unk8
  int32_t m_pointParameters;
  float m_pointScaleMax;
  int32_t m_pointSprite;
  uint32_t m_blendFactor;
  // in CGxDeviceOpenGl:
  //   members are initialized to zero
  // in CGxDeviceD3d:
  //  members are initialized to zero
  uint32_t unk114[5];
  // Used by RTAlphaSupported
  int32_t m_oglRtAlpha;
  int32_t m_stereoAvailable;
  // in CGxDeviceOpenGl:
  //   always true
  // in CGxDeviceD3d:
  //   always true
  int32_t int130;
  // in CGxDeviceOpenGl:
  //   always true
  // in CGxDeviceD3d:
  //   true if this->b_base.m_caps.m_shaderTargets[4 (GxSh_Pixel)] != 4 (GxShPS_ps_3_0);
  int32_t int134;
  // in CGxDeviceOpenGl:
  //   true if this->b_base.m_caps.m_shaderTargets[4 (GxSh_Pixel)] != 12 (GxShPS_arbfp1);
  // in CGxDeviceD3d:
  //   true if this->b_base.m_caps.m_shaderTargets[4 (GxSh_Pixel)] != 4 (GxShPS_ps_3_0);
  int32_t int138;
};

#endif
