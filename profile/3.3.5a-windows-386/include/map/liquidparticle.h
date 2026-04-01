#ifndef MAP_LIQUID_PARTICLE_H
#define MAP_LIQUID_PARTICLE_H

DECLARE_STRUCT(LiquidParticle);

#include "tempest/vector.h"

struct LiquidParticle {
    C3Vector position;
    float    size;
};

#endif
