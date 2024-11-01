#ifndef M2_RIBBON_H
#define M2_RIBBON_H

#include "system/types.h"
#include "gx/types.h"
#include "gx/texture.h"
#include "storm/array.h"
#include "storm/array/uint32_t.h"
#include "tempest/vector.h"

DECLARE_STRUCT(CRibbonMat);
DECLARE_STRUCT(CRibbonEmitter);

struct CRibbonMat {
  // int32 enableLighting : 1;
  // int32 enableFog : 1;
  // int32 enableDepthTest : 1;
  // int32 enableDepthWrite : 1;
  // int32 enableCulling : 1;
  uint32_t f_flags;
  EGxBlend alpha;
};
STORM_TS_GROWABLE_ARRAY(CRibbonMat);

struct CRibbonEmitter {
  uint32_t m_refCount;
  uint32_t dword4;
  uint32_t dword8;
  uint32_t dwordC;
  uint32_t dword10;
  uint32_t dword14;
  uint32_t dword18;
  uint32_t dword1C;
  uint32_t dword20;
  uint32_t dword24;
  uint32_t dword28;
  uint32_t dword2C;
  uint32_t dword30;
  uint32_t dword34;
  uint32_t dword38;
  uint32_t dword3C;
  uint32_t dword40;
  uint32_t dword44;
  uint32_t dword48;
  uint32_t dword4C;
  uint32_t dword50;
  uint32_t dword54;
  float m_ooLifeSpan;
  float m_tmpDU;
  float m_tmpDV;
  float m_ooTmpDU;
  float m_ooTmpDV;
  uint32_t dword6C;
  uint32_t dword70;
  uint32_t dword74;
  uint32_t dword78;
  uint32_t dword7C;
  uint32_t dword80;
  uint32_t dword84;
  uint32_t dword88;
  uint32_t dword8C;
  uint32_t dword90;
  uint32_t dword94;
  uint32_t dword98;
  uint32_t dword9C;
  uint32_t dwordA0;
  uint32_t dwordA4;
  uint32_t dwordA8;
  uint32_t dwordAC;
  uint32_t dwordB0;
  uint32_t dwordB4;
  uint32_t dwordB8;
  uint32_t dwordBC;
  uint32_t dwordC0;
  uint32_t dwordC4;
  uint32_t dwordC8;
  uint32_t dwordCC;
  uint32_t dwordD0;
  uint32_t dwordD4;
  uint32_t dwordD8;
  uint32_t dwordDC;
  uint32_t dwordE0;
  uint32_t dwordE4;
  uint32_t dwordE8;
  uint32_t dwordEC;
  uint32_t dwordF0;
  uint32_t dwordF4;
  uint32_t dwordF8;
  uint32_t dwordFC;
  uint32_t dword100;
  uint32_t dword104;
  uint32_t dword108;
  uint32_t dword10C;
  float m_edgeLifeSpan;
  TSGrowableArray_CRibbonMat m_materials;
  TSGrowableArray_HTEXTURE m_textures;
  TSGrowableArray_uint32_t m_replaces;
  CImVector m_diffuseClr;
  uint32_t dword148;
  uint32_t dword14C;
  uint32_t dword150;
  uint32_t dword154;
  uint32_t dword158;
  uint32_t dword15C;
  uint32_t dword160;
  uint32_t dword164;
  uint32_t dword168;
  uint32_t dword16C;
  uint32_t m_texSlot;
  float m_above;
  float m_below;
  float m_gravity;
};

#endif