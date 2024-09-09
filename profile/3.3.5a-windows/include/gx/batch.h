#ifndef GX_BATCH_H
#define GX_BATCH_H

#include "gx/types.h"

typedef struct CGxBatch CGxBatch;

struct CGxBatch {
  // Member variables
  EGxPrim m_primType;
  uint32_t m_start;
  uint32_t m_count;
  uint16_t m_minIndex;
  uint16_t m_maxIndex;
};

#endif