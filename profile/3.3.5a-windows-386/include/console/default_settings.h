#ifndef CONSOLE_DEFAULT_SETTINGS_H
#define CONSOLE_DEFAULT_SETTINGS_H

DECLARE_STRUCT(DefaultSettings);

#include "gx/format.h"

struct DefaultSettings {
  float farClip;
  // float terrainLODDist;
  uint32_t terrainShadowLOD;
  uint32_t detailDoodadDensity;
  uint32_t detailDoodadAlpha;
  bool animatingDoodads;
  bool trilinear;
  uint32_t numLights;
  bool specularity;
  bool unk19;
  bool unk1A;
  uint32_t waterLOD;
  float particleDensity;
  float unitDrawDist;
  float smallCull;
  float distCull;
  CGxFormat* format;
  uint32_t baseMipLevel;
  uint32_t numChannels;
  bool fivePointOne;
};

#endif