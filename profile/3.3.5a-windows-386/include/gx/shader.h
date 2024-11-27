#ifndef GX_SHADER_H
#define GX_SHADER_H

#include "storm/hash.h"
#include "storm/array/uint8_t.h"

DECLARE_STRUCT(CGxShader);

STORM_TS_HASH(CGxShader, HASHKEY_STRI);

// class CGxShader : public TSHashObject<CGxShader, HASHKEY_STRI>
struct CGxShader {
  TSHashObject_CGxShader_HASHKEY_STRI b_base;
  void* v_table;
  uint32_t refCount;
  void* apiSpecific;
  int32_t target;
  int32_t int28;
  int32_t valid;
  int32_t loaded;
  int32_t int34;
  int32_t patched;
  int32_t int3C;
  int32_t int40;
  int16_t int44;
  int16_t int46;
  TSGrowableArray_uint8_t code;
  // bool IsEnabled();
};

#endif

