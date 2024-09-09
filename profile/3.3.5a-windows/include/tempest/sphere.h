#ifndef TEMPEST_SPHERE_H
#define TEMPEST_SPHERE_H

#include "tempest/vector.h"

DECLARE_STRUCT(CAaSphere);

struct CAaSphere {
  C3Vector n;
  float d;
};

#endif