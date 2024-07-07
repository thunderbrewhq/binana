#ifndef TEMPEST_RANGE_H
#define TEMPEST_RANGE_H

#include <stdint.h>

typedef struct CRange CRange;
typedef struct CiRange CiRange;

struct CRange {
  float l;
  float h;
};

struct CiRange {
  int32_t l;
  int32_t h;
};

#endif