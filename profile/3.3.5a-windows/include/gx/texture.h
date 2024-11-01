#ifndef GX_TEXTURE_H
#define GX_TEXTURE_H

#include "tempest/rect.h"
#include "common/handle.h"

#include "storm/array.h"

typedef HOBJECT HTEXTURE;
STORM_TS_GROWABLE_ARRAY(HTEXTURE);

typedef struct CGxTexFlags CGxTexFlags;
typedef struct CGxTex CGxTex;

struct CGxTexFlags {
  // unsigned __int32 m_filter : 3;
  // unsigned __int32 m_wrapU : 1;
  // unsigned __int32 m_wrapV : 1;
  // unsigned __int32 m_forceMipTracking : 1;
  // unsigned __int32 m_generateMipMaps : 1;
  // unsigned __int32 m_renderTarget : 1;
  // unsigned __int32 m_maxAnisotropy : 5;
  uint32_t f_flags;
};

struct CGxTex {
  CiRect m_updateRect;
  int16_t m_updatePlaneMin;
  int16_t m_updatePlaneMax;
  uint32_t m_width;
  uint32_t m_height;
  uint32_t m_depth;
  uint32_t m_target;
  uint32_t m_format;
  uint32_t m_dataFormat;
  CGxTexFlags m_flags;
  void* m_userArg;
  void* m_userFunc;
  void* m_apiSpecificData;
  void* m_apiSpecificData2;
  uint32_t unk40;
  uint32_t unk44;
  uint32_t unk48;
  uint32_t unk4C;
  uint32_t unk50;
  uint32_t unk54;
  int8_t char58;
  int8_t char59;
  int8_t m_needsUpdate;
  int8_t m_needsCreation;
  int8_t m_needsFlagUpdate;
  int8_t char5D;
  uint16_t m_pad;
};

#endif