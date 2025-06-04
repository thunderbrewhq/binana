#ifndef D3D9_MATERIAL_H
#define D3D9_MATERIAL_H

DECLARE_STRUCT(D3DMATERIAL9);

#include "external/d3d9/colorvalue.h"

struct D3DMATERIAL9 {
  D3DCOLORVALUE   Diffuse;
  D3DCOLORVALUE   Ambient;
  D3DCOLORVALUE   Specular;
  D3DCOLORVALUE   Emissive;
  float           Power;
};

#endif