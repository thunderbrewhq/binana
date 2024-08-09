#ifndef GX_BUFFER_H
#define GX_BUFFER_H

#include "system/types.h"

#include "storm/list.h"
#include "tempest/vector.h"

typedef enum EGxPoolHintBits EGxPoolHintBits;
typedef enum EGxPoolTarget EGxPoolTarget;
typedef enum EGxPoolUsage EGxPoolUsage;
typedef enum EGxVertexAttrib EGxVertexAttrib;
typedef enum EGxVertexBufferFormat EGxVertexBufferFormat;
typedef struct ubyte4 ubyte4;
typedef struct CGxVertexAttrib CGxVertexAttrib;
typedef struct CGxVertexPBNT2 CGxVertexPBNT2;
typedef struct CGxVertexPCT CGxVertexPCT;
typedef struct CGxPool CGxPool;
typedef struct CGxBuf CGxBuf;

enum EGxPoolHintBits {
  GxPoolHintBit_Unk0 = 0,
  GxPoolHintBit_Unk1 = 1,
  GxPoolHintBit_Unk2 = 2,
  GxPoolHintBit_Unk3 = 3
};

enum EGxPoolTarget {
  GxPoolTarget_Vertex = 0,
  GxPoolTarget_Index = 1,
  GxPoolTargets_Last = 2
};

enum EGxPoolUsage {
  GxPoolUsage_Static = 0,
  GxPoolUsage_Dynamic = 1,
  GxPoolUsage_Stream = 2,
  GxPoolUsages_Last = 3
};

enum EGxVertexAttrib {
  GxVA_Position = 0,
  GxVA_BlendWeight = 1,
  GxVA_BlendIndices = 2,
  GxVA_Normal = 3,
  GxVA_Color0 = 4,
  GxVA_Color1 = 5,
  GxVA_TexCoord0 = 6,
  GxVA_TexCoord1 = 7,
  GxVA_TexCoord2 = 8,
  GxVA_TexCoord3 = 9,
  GxVA_TexCoord4 = 10,
  GxVA_TexCoord5 = 11,
  GxVA_TexCoord6 = 12,
  GxVA_TexCoord7 = 13,
  GxVAs_Last = 14
};

enum EGxVertexBufferFormat {
  GxVBF_P = 0,
  GxVBF_PN = 1,
  GxVBF_PNC = 2,
  GxVBF_PNT = 3,
  GxVBF_PNCT = 4,
  GxVBF_PNT2 = 5,
  GxVBF_PNCT2 = 6,
  GxVBF_PC = 7,
  GxVBF_PCT = 8,
  GxVBF_PCT2 = 9,
  GxVBF_PT = 10,
  GxVBF_PT2 = 11,
  GxVBF_PBNT2 = 12,
  GxVBF_PNC2T2 = 13,
  GxVertexBufferFormats_Last = 14
};

struct ubyte4 {
  union {
    uint8_t b[4];
    uint32_t u;
  };
};

struct CGxVertexAttrib {
  EGxVertexAttrib attrib;
  uint32_t type;
  uint32_t offset;
  uint32_t bufSize;
};

struct CGxVertexPBNT2 {
  C3Vector p;
  ubyte4 bw;
  ubyte4 bi;
  C3Vector n;
  C2Vector tc[2];
};

struct CGxVertexPCT {
  C3Vector p;
  CImVector c;
  C2Vector tc[1];
};

STORM_TS_LIST(CGxBuf);
STORM_TS_LIST(CGxPool);

// class CGxPool : public TSLinkedNode<CGxPool>
struct CGxPool {
  TSLinkedNode_CGxPool b_base;
  EGxPoolTarget m_target;
  EGxPoolUsage m_usage;
  int32_t m_size;
  void* m_apiSpecific;
  void* m_mem;
  int32_t unk1C; // TODO
  TSList_CGxBuf m_bufList;
  EGxPoolHintBits m_hint;
  const char* m_name;
};

// class CGxBuf : public TSLinkedNode<CGxBuf>
struct CGxBuf {
  TSLinkedNode_CGxBuf b_base;
  CGxPool* m_pool;
  uint32_t m_itemSize;
  uint32_t m_itemCount;
  uint32_t m_size;
  uint32_t m_index;
  uint8_t unk1C; // TODO
  uint8_t unk1D; // TODO
  uint8_t unk1E; // TODO
  uint8_t unk1F; // TODO
};

#endif