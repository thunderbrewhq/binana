#ifndef TEMPEST_BOX_H
#define TEMPEST_BOX_H

#include "tempest/vector.h"
#include "tempest/range.h"

DECLARE_STRUCT(CAaBox);
DECLARE_STRUCT(CBoundingBox);

struct CAaBox {
  C3Vector b;
  C3Vector t;
};

struct CBoundingBox {
  CRange x;
  CRange y;
  CRange z;
};

#endif