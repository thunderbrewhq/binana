#ifndef STORM_REGION_REGION_H
#define STORM_REGION_REGION_H

#include "common/handle.h"
#include "storm/hash.h"
#include "storm/region/source.h"
#include "storm/region/rect.h"
#include "storm/region/found_param.h"

DECLARE_HANDLE(HSRGN);
DECLARE_HANDLE(HLOCKEDRGN);

DECLARE_STRUCT(RGN);
DECLARE_STRUCT(CSRgn);

STORM_TS_HASH(RGN, HASHKEY_NONE);
struct RGN {
  TSHashObject_RGN_HASHKEY_NONE b_base;
  TSGrowableArray_SOURCE source;
  TSGrowableArray_RECTF combined;
  TSGrowableArray_FOUNDPARAM foundparams;
  RECTF foundparamsrect;
  int32_t sequence;
  int32_t dirty;
};

struct CSRgn {
  HSRGN m_handle;
};

#endif