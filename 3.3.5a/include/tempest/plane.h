#ifndef TEMPEST_PLANE_H
#define TEMPEST_PLANE_H

#include "tempest/vector.h"

typedef struct C4Plane C4Plane;

struct C4Plane {
  C3Vector n;
  float d;
};

#endif