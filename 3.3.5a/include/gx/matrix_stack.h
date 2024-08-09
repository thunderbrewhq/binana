#ifndef GX_MATRIX_STACK_H
#define GX_MATRIX_STACK_H

#include "system/types.h"

#include "tempest/matrix.h"

typedef enum CGxMatrixStack__EMatrixFlags CGxMatrixStack__EMatrixFlags;
typedef struct CGxMatrixStack CGxMatrixStack;

enum CGxMatrixStack__EMatrixFlags {
  F_Identity = 0x1
};

struct CGxMatrixStack {
  uint32_t m_level;
  int8_t m_dirty;
  C44Matrix m_mtx[4];
  uint32_t m_flags[4];
};

#endif