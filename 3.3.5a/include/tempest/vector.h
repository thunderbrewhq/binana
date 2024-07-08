#ifndef TEMPEST_VECTOR_H
#define TEMPEST_VECTOR_H

#include <stdint.h>

typedef struct C2Vector C2Vector;
typedef struct C2iVector C2iVector;
typedef struct C3Vector C3Vector;
typedef struct C4Vector C4Vector;
typedef struct CImVector CImVector;

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