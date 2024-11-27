#ifndef UI_SIMPLE_BATCHED_MESH_H
#define UI_SIMPLE_BATCHED_MESH_H

#include "texture/texture.h"
#include "gx/texture.h"
#include "gx/shader.h"
#include "tempest/vector.h"

DECLARE_STRUCT(CSimpleBatchedMesh);

struct CSimpleBatchedMesh {
  CTexture* texture;
  CGxTex* textureID;
  EGxBlend alphaMode;
  CGxShader* shader;
  int32_t posCount;
  C3Vector* position;
  C2Vector* texCoord;
  CImVector* color;
  int32_t colorCount;
  uint16_t* indices;
  int32_t idxCount;
  int32_t onAtlas;
  float atlasScale;
  C2Vector atlasOffset;
};
STORM_TS_GROWABLE_ARRAY(CSimpleBatchedMesh);

#endif