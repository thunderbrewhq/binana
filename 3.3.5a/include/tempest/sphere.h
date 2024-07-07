#ifndef TEMPEST_SPHERE_H
#define TEMPEST_SPHERE_H

#include "tempest/vector.h"

typedef struct CAaSphere CAaSphere;

struct CAaSphere {
  C3Vector n;
  float d;
};

#endif