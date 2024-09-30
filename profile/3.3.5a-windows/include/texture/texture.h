#ifndef TEXTURE_TEXTURE_H
#define TEXTURE_TEXTURE_H

#include "common/handle.h"
#include "common/status.h"
#include "gx/types.h"
#include "gx/texture.h"
#include "async/object.h"

DECLARE_STRUCT(CTexture);

// struct CTexture : CHandleObject
struct CTexture {
  CHandleObject b_base;
  uint32_t dword8[6];
  CGxTexFlags unkTexFlags1;
  uint32_t dword10;
  uint16_t flags;
  int8_t bestMip;
  int8_t alphaBits;
  CStatus loadStatus;
  CAsyncObject* asyncObject;
  CGxTex* gxTex;
  int32_t gxTexTarget;
  uint16_t gxWidth;
  uint16_t gxHeight;
  EGxTexFormat gxTexFormat;
  EGxTexFormat dataFormat;
  CGxTexFlags gxTexFlags;
  void* atlas;
  uint32_t atlasBlockIndex;
  uint32_t dword50[2];
  char filename[260];
};

#endif