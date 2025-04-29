#ifndef UI_FRAME_STRATA_H
#define UI_FRAME_STRATA_H

DECLARE_STRUCT(CFrameStrataNode);
DECLARE_STRUCT(CFrameStrata);

#include "storm/array.h"
#include "storm/list.h"

#include "ui/simpleframe.h"

// class CFrameStrataNode
struct CFrameStrataNode {
  TSExplicitList_CSimpleFrame pendingFrames;
  TSExplicitList_CSimpleFrame frames;
  CSimpleFrame* pendingFrame;
  CRenderBatch batches[5];
  int32_t batchDirty;
  TSExplicitList_CRenderBatch renderList;
};
typedef CFrameStrataNode* pointer_to_CFrameStrataNode;
STORM_TS_FIXED_ARRAY(pointer_to_CFrameStrataNode);

struct CFrameStrata {
  int32_t batchDirty;
  int32_t levelsDirty;
  uint32_t topLevel;
  TSFixedArray_pointer_to_CFrameStrataNode levels;
};

#endif