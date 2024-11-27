#ifndef TEXTURE_TGA_H
#define TEXTURE_TGA_H

#include "system/types.h"

#include "storm/file.h"

DECLARE_STRUCT(TGAFooter);
DECLARE_STRUCT(TGAHeader);
DECLARE_STRUCT(TGA32Pixel);
DECLARE_STRUCT(TGAImageDesc);
DECLARE_STRUCT(CTgaFile);

struct TGAFooter {
  uint32_t dwExtensionOffset;
  uint32_t dwDeveloperOffset;
  uint8_t szSigniture[18];
};

#pragma pack(push, 1)

struct TGAImageDesc {
  uint8_t bAlphaChannelBits : 4;
  uint8_t bLeftRightOrder : 1;
  uint8_t bTopBottomOrder : 1;
  uint8_t bReserved : 2;
};

struct TGAHeader {
  uint8_t bIDLength;
  uint8_t bColorMapType;
  uint8_t bImageType;
  // byte packed
  uint16_t wColorMapStartIndex;
  uint16_t wColorMapEntries;
  uint8_t bColorMapEntrySize;
  uint16_t wXOrigin;
  uint16_t wYOrigin;
  uint16_t wWidth;
  uint16_t wHeight;
  uint8_t bPixelDepth;
  union {
    uint8_t bImageDescriptor;
    TGAImageDesc desc;
  };
};
#pragma pack(pop)

struct TGA32Pixel {
  uint8_t b;
  uint8_t g;
  uint8_t r;
  uint8_t a;
};

struct CTgaFile {
  SFile* m_file;
  uint8_t* m_image;
  TGAHeader m_header;
  uint8_t* m_addlHeaderData;
  TGAFooter m_footer;
  uint32_t m_imageBytes;
  uint8_t* m_colorMap;
};

#endif
