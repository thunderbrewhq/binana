#ifndef MAP_PARTICULATE_H
#define MAP_PARTICULATE_H

DECLARE_STRUCT(Particulate);

#include "map/liquidparticle.h"
#include "texture/texture.h"

struct Particulate {
    LiquidParticle particles[4000];
    uint32_t       maxParticles;
    C3Vector       prevCameraPos;
    CTexture*      texture;
    uint8_t        unk_byte;
    uint8_t        padding[3];
    float          particleSize;
    float          spawnAreaSize;
    float          unk_float1;
    uint32_t       unkValue; // liquid type of particle type
    C3Vector       direction;
    float          speed;
    float          timer;
    float          rotationSpeed;
};

#endif
