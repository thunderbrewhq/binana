#ifndef TEMPEST_RECT_H
#define TEMPEST_RECT_H

#include <stdint.h>

struct CRect {
  float minY; // t
  float minX; // l
  float maxY; // b
  float maxX; // r
};

struct CiRect {
  int32_t minY;
  int32_t minX;
  int32_t maxY;
  int32_t maxX;
};

#endif