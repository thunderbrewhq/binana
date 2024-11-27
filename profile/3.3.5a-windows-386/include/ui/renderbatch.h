#ifndef UI_RENDER_BATCH_H
#define UI_RENDER_BATCH_H

#include "system/types.h"
#include "ui/simplebatchedmesh.h"
#include "gx/stringbatch.h"

DECLARE_STRUCT(CRenderBatch);
DECLARE_STRUCT(RENDERCALLBACKNODE);

STORM_TS_LIST(RENDERCALLBACKNODE);
STORM_TS_LIST(CRenderBatch);

// struct RENDERCALLBACKNODE : TSLinkedNode<RENDERCALLBACKNODE> 
struct RENDERCALLBACKNODE {
  void* callback;
  void* param;
};

struct CRenderBatch {
  uint32_t m_count;
  TSGrowableArray_CSimpleBatchedMesh m_texturelist;
  CGxStringBatch* m_stringbatch;
  TSList_RENDERCALLBACKNODE m_callbacks;
  TSLink_CRenderBatch renderLink;
};

#endif
