#ifndef D3D9_LIGHT_H
#define D3D9_LIGHT_H

DECLARE_STRUCT(D3DLIGHT9);

#include "external/d3d9/lighttype.h"
#include "external/d3d9/colorvalue.h"
#include "external/d3d9/vector.h"

struct D3DLIGHT9 {
  D3DLIGHTTYPE    Type;
  D3DCOLORVALUE   Diffuse;
  D3DCOLORVALUE   Specular;
  D3DCOLORVALUE   Ambient;
  D3DVECTOR       Position;
  D3DVECTOR       Direction;
  float           Range;
  float           Falloff;
  float           Attenuation0;
  float           Attenuation1;
  float           Attenuation2;
  float           Theta;
  float           Phi;
};

#endif