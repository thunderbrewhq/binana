#ifndef GX_STRING_H
#define GX_STRING_H

#include "tempest/vector.h"

DECLARE_STRUCT(CGxString);

STORM_TS_LIST(CGxString);

// struct CGxString : TSLinkedNode<CGxString>
struct CGxString {
  TSLinkedNode_CGxString b_base;
  TSLink_CGxString m_fontStringLink;
  TSLink_CGxString m_batchedStringLink;
  float m_requestedFontHeight;
  float m_currentFontHeight;
  C3Vector m_position;
  CImVector m_fontColor;
  CImVector m_shadowColor;
  C2Vector m_shadowOffset;
  float m_blockWidth;
  float m_blockHeight;
  void* m_currentFace;
  char* m_text;
  int32_t m_textLen;
  int32_t m_vertJust;
  int32_t m_horzJust;
  float m_spacing;
  uint32_t m_flags;
  uint32_t m_texturePagesUsed;
  int32_t m_textureEvicted;
  uint32_t m_lastGradientStart;
  uint32_t m_lastGradientLength;
  C3Vector m_viewTranslation;
  float m_scale;
  uint32_t m_hyperlinkInfo[4];
  uint32_t dword90;
  uint32_t dword94;
  uint32_t dword98;
  uint32_t dword9C;
  uint32_t dwordA0;
  uint32_t dwordA4;
  uint32_t dwordA8;
  uint32_t dwordAC;
  int32_t m_intB0;
  void* m_textLines[8];
  int32_t m_intD4;
};

#endif