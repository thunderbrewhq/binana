#ifndef WEATHER_H
#define WEATHER_H

DECLARE_STRUCT(Weather);
DECLARE_STRUCT(Mists);
DECLARE_STRUCT(Rain);
DECLARE_STRUCT(Snow);
DECLARE_STRUCT(Sand);

DECLARE_STRUCT(PacketList_Packet_RainDrop);
DECLARE_STRUCT(Packet_RainDrop);
DECLARE_STRUCT(RainDropParticle);
DECLARE_STRUCT(RainParticleBuffer);

DECLARE_STRUCT(PacketList_Packet_RainPatter);
DECLARE_STRUCT(Packet_RainPatter);
DECLARE_STRUCT(RainPatterParticle);
DECLARE_STRUCT(RainPatterParticleBuffer);

DECLARE_STRUCT(PacketList_Packet_SnowFlake);
DECLARE_STRUCT(Packet_SnowFlake);
DECLARE_STRUCT(SnowFlakeParticle);
DECLARE_STRUCT(SnowFlakeParticleBuffer);

DECLARE_STRUCT(PacketList_Packet_SandGrain);
DECLARE_STRUCT(Packet_SandGrain);
DECLARE_STRUCT(SandGrainParticle);
DECLARE_STRUCT(SandGrainParticleBuffer);

#include "tempest/box.h"
#include "system/types.h"
#include "tempest/vector.h"
#include "texture/texture.h"
#include "gx/shader.h"
#include "gx/buffer.h"

struct Mists
{
    void** vtable;
    C3Vector position;
    uint32_t unk_10;
    uint32_t unk_14;
    uint32_t unk_18;
    float scale;
    uint32_t unk_20;
    float rotationSpeed;
    float fadeSpeed;
    uint32_t unk_2C;
    float opacity;
    float lifeTime;
    float spawnRate;
    uint8_t unk_3C;
    uint8_t padding[3];
    CTexture* mistTexture;
    uint32_t particleCount;
    uint32_t unk_48;
    uint32_t unk_4C;
    uint32_t unk_50;
};

struct SandGrainParticle
{
    C3Vector position;
    C3Vector velocity;
    float lifetime;
    float size;
};

struct SandGrainParticleBuffer
{
    uint32_t particleCount;
    SandGrainParticle particles[6144];
};

struct Packet_SandGrain
{
    Packet_SandGrain* prev;
    Packet_SandGrain* next;

    SandGrainParticleBuffer particlesBuffer;

    uint32_t currParticle;
    uint32_t packetStartTick;
    uint32_t packetEndTick;
    float packetBuildTime;

    uint32_t field_C007;
    uint32_t field_C008;
    uint32_t field_C009;

    CGxPool* gxPool;
    CGxBuf* vertexBufHandle;
};

struct PacketList_Packet_SandGrain
{
    int32_t unk_00;
    Packet_SandGrain* prev;
    Packet_SandGrain* next;
    int32_t activePacketsCount;
    int32_t freePacketsCount;
    int32_t unk_14;
    Packet_SandGrain* unk_18;
    Packet_SandGrain* unk_1C;
};

struct Sand
{
    int32_t useWeatherShaders;
    CAaBox bbox;
    Mists mists;

    PacketList_Packet_SandGrain sandGrainPacketList;

    Packet_SandGrain* sandGrainPacketPtr;
    float unk_94;
    CGxShader* shader;
    float unk_9C;
};

struct SnowFlakeParticle
{
    C3Vector position;
    C3Vector velocity;
    float lifetime;
    float size;
};

struct SnowFlakeParticleBuffer
{
    uint32_t particleCount;
    SnowFlakeParticle particles[6144];
};

struct Packet_SnowFlake
{
    Packet_SnowFlake* prev;
    Packet_SnowFlake* next;

    SnowFlakeParticleBuffer particlesBuffer;

    uint32_t currParticle;
    uint32_t packetStartTick;
    uint32_t packetEndTick;
    float packetBuildTime;

    uint32_t field_C007;
    uint32_t field_C008;
    uint32_t field_C009;

    CGxPool* gxPool;
    CGxBuf* vertexBufHandle;
};

struct PacketList_Packet_SnowFlake
{
    int32_t unk_00;
    Packet_SnowFlake* prev;
    Packet_SnowFlake* next;
    int32_t activePacketsCount;
    int32_t freePacketsCount;
    int32_t unk_14;
    Packet_SnowFlake* unk_18;
    Packet_SnowFlake* unk_1C;
};

struct Snow
{
    int32_t useWeatherShaders;
    CAaBox bbox;    
    Mists mists;

    //PacketList_Packet_SnowFlake snowFlakePacketList;
    int32_t unk_70;
    void* unk_74;
    void* unk_78;
    int32_t activePacketsCount;
    int32_t freePacketsCount;
    int32_t unk_84;
    void* unk_88;
    void* unk_8C;
    //end

    Packet_SnowFlake* snowFlakePacketPtr;
    float unk_94;
    CTexture* snowFlakeTex;
    CGxShader* shaderPtr;
    int32_t unk_A0;
    int32_t unk_A4;
};

struct RainPatterParticle
{
    C3Vector position;
    float lifetime;
    float size;
    float unk;
};

struct RainPatterParticleBuffer
{
    uint32_t particleCount;
    RainPatterParticle particles[6144];
};

struct Packet_RainPatter
{
    Packet_RainPatter* prev;
    Packet_RainPatter* next;

    RainPatterParticleBuffer particlesBuffer;

    uint32_t currParticle;
    uint32_t packetStartTick;
    uint32_t packetEndTick;
    float packetBuildTime;

    uint32_t field_9007;
    uint32_t field_9008;
    uint32_t field_9009;

    CGxPool* gxPool;
    CGxBuf* vertexBufHandle;
};

struct PacketList_Packet_RainPatter
{
    int32_t unk_00;
    Packet_RainPatter* prev;
    Packet_RainPatter* next;
    int32_t activePacketsCount;
    int32_t freePacketsCount;
    int32_t unk_14;
    Packet_RainPatter* unk_18;
    Packet_RainPatter* unk_1C;
};

struct RainDropParticle
{
    C3Vector position;
    C3Vector velocity;
    CImVector color;
    float size;
    float unk;
};

struct RainParticleBuffer
{
    uint32_t particleCount;
    RainDropParticle particles[6144];
};

struct Packet_RainDrop
{
    Packet_RainDrop* prev;
    Packet_RainDrop* next;
    
    RainParticleBuffer particlesBuffer;

    uint32_t currParticle;
    uint32_t packetStartTick;
    uint32_t packetEndTick;
    float packetBuildTime;

    uint32_t field_D807;
    uint32_t field_D808;
    uint32_t field_D809;

    CGxPool* gxPool;
    CGxBuf* vertexBufHandle;
};

struct PacketList_Packet_RainDrop
{
    int32_t unk_00;
    Packet_RainDrop* prev;
    Packet_RainDrop* next;
    int32_t activePacketsCount;
    int32_t freePacketsCount;
    int32_t unk_14;
    Packet_RainDrop* unk_18;
    Packet_RainDrop* unk_1C;
};

struct Rain
{
    int32_t useWeatherShaders;
    CAaBox bbox;
    Mists mists;

    PacketList_Packet_RainDrop rainDropPacketList;
    PacketList_Packet_RainPatter rainPatterPacketList;

    Packet_RainDrop* rainDropPacketPtr;
    float unk_B4; // particle lifetime?
    Packet_RainPatter* rainPatterPacketPtr;

    CTexture* rainDropTex;
    CGxShader* shaderRain;
    CTexture* rainDropSplashTex;
    CGxShader* shaderPatter;
    
    float particlesPerFrame;
    float intensity;
};

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
    
    Rain* rain;
    Snow* snow;
    Sand* sand;
    
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