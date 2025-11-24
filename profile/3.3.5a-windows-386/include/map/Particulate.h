#ifndef PARTICULATE_H
#define PARTICULATE_H

DECLARE_STRUCT(Particulate);
DECLARE_STRUCT(LiquidParticle);

#include "system/types.h"
#include "tempest/vector.h"
#include "texture/texture.h"

struct LiquidParticle
{
    C3Vector position;
    float size;
};

struct Particulate
{
    LiquidParticle particles[4000];
    uint32_t maxParticles;
    C3Vector prevCameraPos;
    CTexture* texture;
    uint8_t unk_byte;
    uint8_t padding[3];
    float particleSize;
    float spawnAreaSize;
    float unk_float1;
    uint32_t unkValue; //liquid type of particle type
    C3Vector direction;
    float speed;
    float timer;
    float rotationSpeed;
};


#endif