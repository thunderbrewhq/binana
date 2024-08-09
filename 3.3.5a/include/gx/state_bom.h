#ifndef GX_STATE_BOM_H
#define GX_STATE_BOM_H

#include "system/types.h"
#include "storm/array.h"

typedef struct CGxStateBom CGxStateBom;

struct CGxStateBom {
  union {
    int32_t i[3];
    uint32_t u[3];
    float f[3];
    void* p;
  } m_data;

  int32_t filler;
};
STORM_TS_FIXED_ARRAY(CGxStateBom);

#endif