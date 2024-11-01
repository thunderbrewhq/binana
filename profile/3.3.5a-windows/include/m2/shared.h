#ifndef M2_SHARED_H
#define M2_SHARED_H

DECLARE_STRUCT(CM2Shared);

#include "tempest/box.h"
#include "async/object.h"
#include "m2/cache.h"
#include "m2/model.h"
#include "m2/shadereffect.h"

struct CM2Shared {
  uint32_t m_refCount;
  CM2Cache* m_cache;
  uint32_t m_flags;
  CAsyncObject* asyncObject;
  CM2Model* m_callbackList;
  CM2Model** m_callbackTail;
  uint32_t dword18;
  uint32_t dword1C;
  uint32_t dword20;
  uint32_t numLowPrioritySequences;
  void* lowPrioritySequences;
  uint32_t dword2C;
  CM2Shared** m_freePrev;
  CM2Shared* m_freeNext;
  uint32_t dword38;
  uint8_t m_filePath[260];
  uint8_t* ext;
  uint32_t dword144;
  uint32_t dword148;
  uint32_t dword14C;
  M2Data* data;
  CAaBox aaBox154;
  uint32_t size;
  M2SkinProfile* skinProfile;
  HTEXTURE* textures;
  CGxPool* m_indexPool;
  CGxBuf* m_indexBuf;
  CGxPool* m_vertexPool;
  CGxBuf* m_vertexBuf;
  CShaderEffect** m_batchShaders;
  M2SkinSection* m_skinSections;
  uint32_t uint190;
  uint32_t uint194;
  uint32_t dword198;
  uint32_t dword19C;
  uint32_t dword1A0;
  uint32_t dword1A4;
};

#endif