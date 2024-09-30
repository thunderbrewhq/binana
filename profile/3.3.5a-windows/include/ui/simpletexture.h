#ifndef UI_SIMPLE_TEXTURE_H
#define UI_SIMPLE_TEXTURE_H

#include "ui/simpleregion.h"
#include "texture/texture.h"

DECLARE_STRUCT(CSimpleTexture);

// struct CSimpleTexture : CSimpleRegion {
struct CSimpleTexture {
  CSimpleRegion b_base;
  uint32_t dwordD0;
  CTexture* m_texture;
  uint32_t m_alphaMode;
  void* m_shader;
  C3Vector m_position[4];
  C3Vector m_position2[4];
  C2Vector m_texCoord[4];
  uint32_t dword160;
};

#endif
