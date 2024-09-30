#ifndef UI_BACKDROP_GENERATOR_H
#define UI_BACKDROP_GENERATOR_H

#include "tempest/vector.h"
#include "ui/simpletexture.h"

struct CBackdropGenerator {
  CSimpleTexture* m_backgroundTexture;
  CSimpleTexture* m_leftTexture;
  CSimpleTexture* m_rightTexture;
  CSimpleTexture* m_topTexture;
  CSimpleTexture* m_bottomTexture;
  CSimpleTexture* m_topLeftTexture;
  CSimpleTexture* m_topRightTexture;
  CSimpleTexture* m_bottomLeftTexture;
  CSimpleTexture* m_bottomRightTexture;
  uint32_t dword24;
  uint32_t dword28;
  uint32_t dword2C;
  uint32_t dword30;
  uint32_t dword34;
  uint32_t dword38;
  uint32_t dword3C;
  uint32_t dword40;
  uint32_t dword44;
  uint32_t dword48;
  uint32_t dword4C;
  uint32_t dword50;
  uint32_t dword54;
  uint32_t dword58;
  uint32_t dword5C;
  uint32_t dword60;
  CImVector m_borderColor;
  uint32_t dword68;
};

#endif