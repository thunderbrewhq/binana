#ifndef GX_FONT_H
#define GX_FONT_H

#include "system/types.h"
#include "tempest/rect.h"
#include "storm/list.h"
#include "storm/hash.h"
#include "gx/string.h"

DECLARE_HANDLE(HFACE);

DECLARE_STRUCT(CGxFont);
DECLARE_STRUCT(GLYPHBITMAPDATA);
DECLARE_STRUCT(CHARCODEDESC);

DECLARE_STRUCT(KERNNODE);
DECLARE_STRUCT(KERNINGHASHKEY);

DECLARE_STRUCT(TEXTURECACHE);
DECLARE_STRUCT(TEXTURECACHEROW);

STORM_TS_LIST(CGxFont);
STORM_TS_LIST(CHARCODEDESC);

STORM_TS_HASH(CHARCODEDESC, HASHKEY_NONE);

struct GLYPHBITMAPDATA {
  void* m_data;
  uint32_t m_dataSize;
  uint32_t m_glyphWidth;
  uint32_t m_glyphHeight;
  uint32_t m_glyphCellWidth;
  float m_glyphAdvance;
  float m_glyphBearing;
  uint32_t m_glyphPitch;
  int32_t m_yOffset;
  int32_t m_yStart;
  CRect m_textureCoords;
};

// struct CHARCODEDESC : TSHashObject<CHARCODEDESC,HASHKEY_NONE>
struct CHARCODEDESC {
  TSHashObject_CHARCODEDESC_HASHKEY_NONE b_base;
  TSLink_CHARCODEDESC textureRowLink;
  TSLink_CHARCODEDESC fontGlyphLink;
  uint32_t textureNumber;
  uint32_t rowNumber;
  uint32_t glyphStartPixel;
  uint32_t glyphEndPixel;
  GLYPHBITMAPDATA bitmapData;
};

// 
// struct KERNNODE : TSHashObject<KERNNODE,KERNINGHASHKEY>
struct KERNNODE {
  uint32_t flags;
  float proporportionalSpacing;
  float fixedWidthSpacing;
};

struct KERNINGHASHKEY {
  uint32_t code;
};

struct TEXTURECACHEROW {
  uint32_t widestFreeSlot;
  TSExplicitList_CHARCODEDESC glyphList;
};
STORM_TS_FIXED_ARRAY(TEXTURECACHEROW);

struct TEXTURECACHE {
  void* m_texture;
  CGxFont* m_theFace;
  uint8_t m_anyDirtyGlyphs;
  uint8_t pad[3];
  TSFixedArray_TEXTURECACHEROW m_textureRows;
};

STORM_TS_HASH(KERNNODE, KERNINGHASHKEY);

// struct CGxFont : TSLinkedNode<CGxFont>
struct CGxFont {
  TSLinkedNode_CGxFont b_base;
  TSExplicitList_CGxString m_strings;
  TSHashTable_CHARCODEDESC_HASHKEY_NONE m_activeCharacters;
  TSHashTable_KERNNODE_KERNINGHASHKEY m_kernInfo;
  TSExplicitList_CHARCODEDESC m_activeCharacterCache;
  HFACE m_faceHandle;
  char m_fontName[260];
  uint32_t m_cellHeight;
  uint32_t m_baseline;
  uint32_t m_flags;
  float float184;
  float m_pixelsPerUnit;
  TEXTURECACHE m_textureCache[8];
  uint32_t m_pixelSize;
};

#endif
