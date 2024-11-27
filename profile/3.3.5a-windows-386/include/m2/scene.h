#ifndef M2_SCENE_H
#define M2_SCENE_H

DECLARE_STRUCT(CM2Scene);

#include "m2/cache.h"
#include "m2/types.h"
#include "m2/model.h"
#include "m2/light.h"
#include "storm/array/uint32_t.h"
#include "tempest/matrix.h"

struct CM2Scene {
  uint32_t dword0;
  CM2Cache* m_cache;
  CM2Model* m_modelList;
  uint32_t m_time;
  uint32_t uint10;
  uint32_t uint14;
  uint32_t dword18;
  uint32_t m_flags;
  CM2Light* m_lightList;
  uint32_t dword24;
  CM2Model* m_animateList;
  CM2Model* m_drawList;
  uint32_t dword30;
  TSGrowableArray_M2Element m_elements;
  TSGrowableArray_uint32_t array44;
  TSGrowableArray_uint32_t array54[3];
  C44Matrix m_view;
  C44Matrix m_viewInv;
  uint32_t uint104;
  uint32_t dword108;
  uint32_t dword10C;
  uint32_t dword110;
  uint32_t dword114;
  uint32_t dword118;
  uint32_t dword11C;
  uint32_t dword120;
  uint32_t dword124;
  uint32_t m_hitList;
  uint32_t dword12C;
  uint32_t dword130;
  uint32_t dword134;
  uint32_t dword138;
  uint32_t dword13C;
  uint32_t dword140;
  uint32_t dword144;
};

#endif