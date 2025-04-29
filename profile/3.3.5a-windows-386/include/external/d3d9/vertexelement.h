#ifndef D3D9_VERTEXELEMENT_H
#define D3D9_VERTEXELEMENT_H

DECLARE_STRUCT(D3DVERTEXELEMENT9);

struct D3DVERTEXELEMENT9 {
  uint16_t Stream;
  uint16_t Offset;
  uint8_t Type;
  uint8_t Method;
  uint8_t Usage;
  uint8_t UsageIndex;
};

#endif