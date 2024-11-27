#ifndef TEXTURE_BLP_H
#define TEXTURE_BLP_H

#include "system/types.h"

#include "storm/file.h"

#include "gx/types.h"

DECLARE_HANDLE(HCOLORMAP);

DECLARE_ENUM(MipMapAlgorithm);

DECLARE_STRUCT(CBLPFile);
DECLARE_STRUCT(BlpPalPixel);
DECLARE_STRUCT(BLPHeader);
DECLARE_STRUCT(BLPJPEGHeader);

enum MipMapAlgorithm {
  MMA_BOX = 0x0,
  MMA_CUBIC = 0x1,
  MMA_FULLDFT = 0x2,
  MMA_KAISER = 0x3,
  MMA_LINEARLIGHTKAISER = 0x4
};

struct BlpPalPixel {
  uint8_t b;
  uint8_t g;
  uint8_t r;
  uint8_t pad;
};

struct BLPJPEGHeader {
  uint32_t headerSize;
  uint8_t headerData[1020];
};

struct BLPHeader {
  uint32_t magic;
  uint32_t formatVersion;
  uint8_t colorEncoding;
  uint8_t alphaSize;
  uint8_t preferredFormat;
  uint8_t hasMips;
  uint32_t width;
  uint32_t height;
  uint32_t mipOffsets[16];
  uint32_t mipSizes[16];

  union {
    BlpPalPixel palette[256];

    BLPJPEGHeader jpeg;
  } extended;
};

struct CBLPFile {
  MipBits* m_images;
  BLPHeader m_header;
  void* m_inMemoryImage;
  int32_t m_inMemoryNeedsFree;
  uint32_t m_numLevels;
  uint32_t m_quality;
  HCOLORMAP m_colorMapping;
  MipMapAlgorithm m_mipMapAlgorithm;
  uint8_t* m_lockDecompMem;
};

#endif
