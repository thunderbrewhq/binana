#ifndef GX_STRING_BATCH_H
#define GX_STRING_BATCH_H

#include "storm/list.h"
#include "storm/hash.h"
#include "gx/font.h"

DECLARE_STRUCT(CGxStringBatch);
DECLARE_STRUCT(BATCHEDRENDERFONTDESC);

STORM_TS_HASH(BATCHEDRENDERFONTDESC, HASHKEY_PTR);

STORM_TS_LIST(CGxStringBatch);

// struct BATCHEDRENDERFONTDESC : TSHashObject<BATCHEDRENDERFONTDESC, HASHKEY_PTR>
struct BATCHEDRENDERFONTDESC {
  TSHashObject_BATCHEDRENDERFONTDESC_HASHKEY_PTR b_base;
  CGxFont* m_face;
  // STORM_EXPLICIT_LIST(CGxString, m_batchedStringLink) m_strings;
  TSExplicitList_CGxString m_strings;
};

// CGxStringBatch : TSLinkedNode<CGxStringBatch>
struct CGxStringBatch {
  TSLinkedNode_CGxStringBatch b_base;
  TSHashTable_BATCHEDRENDERFONTDESC_HASHKEY_PTR m_fontBatch;
  uint32_t m_flags;
};

#endif