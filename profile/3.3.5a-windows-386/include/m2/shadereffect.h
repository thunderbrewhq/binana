#ifndef M2_SHADER_EFFECT
#define M2_SHADER_EFFECT

DECLARE_STRUCT(CShaderEffect);
DECLARE_STRUCT(CShaderEffect_LocalLights);

#include "storm/hash.h"
#include "gx/shader.h"

STORM_TS_HASH(CShaderEffect, HASHKEY_STRI);

struct CShaderEffect_LocalLights {
  float float0[44];
};

// class CShaderEffect : public TSHashObject<CShaderEffect, HASHKEY_STRI>
struct CShaderEffect {
  TSHashObject_CShaderEffect_HASHKEY_STRI b_base;
  uint32_t dword18;
  uint32_t dword1C;
  uint32_t dword20;
  uint32_t dword24;
  uint32_t dword28;
  CGxShader* vertexShaders[90];
  CGxShader* pixelShaders[16];
};

#endif