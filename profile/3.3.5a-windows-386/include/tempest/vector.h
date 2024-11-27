#ifndef TEMPEST_VECTOR_H
#define TEMPEST_VECTOR_H

#include "system/types.h"

DECLARE_STRUCT(C2Vector);
DECLARE_STRUCT(C2iVector);
DECLARE_STRUCT(C3Vector);
DECLARE_STRUCT(C4Vector);
DECLARE_STRUCT(CImVector);

struct C2Vector {
  float x;
  float y;
};

struct C2iVector {
  int32_t x;
  int32_t y;
};

struct C3Vector {
  float x;
  float y;
  float z;
};

struct C4Vector {
  float x;
  float y;
  float z;
  float w;
};

struct CImVector {
  uint8_t b;
  uint8_t g;
  uint8_t r;
  uint8_t a;
};


#endif