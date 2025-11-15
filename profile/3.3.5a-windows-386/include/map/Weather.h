#ifndef WEATHER_H
#define WEATHER_H

DECLARE_STRUCT(Weather);

#include "system/types.h"
#include "tempest/vector.h"

struct Weather
{
    float intensity;
    float lastIntensity;
    float currStormItensity;
    float targetSkyDark;
    float startSkyDark;
    float currSkyDark;
    uint32_t weatherStartMs;
    uint32_t weatherStartMs2;
    uint32_t weatherType;
    uint32_t abrupt;

    float transitionSkyBox;
    float transitionSkyBoxNotAbrupt;
    float transitionSkyBoxNoWeather;

    CImVector color;
    
    char texturePath[260];
    
    void* RainPtr;
    void* SnowPtr;
    void* SandPtr;
    
    void* unkObject;

    int32_t unk_14C;
    
    void* unk_ptr_150;
    void* unk_ptr_154;
    
    int32_t unk_158;

    void* unk_ptr_15C;
    void* unk_ptr_160;
    
    C3Vector velocity;
    C3Vector unkVec;
    C3Vector playerPos;
    int32_t unk_188;
    float facingAngle;
    float moveSpeed;
    int32_t unk_194;
};

#endif