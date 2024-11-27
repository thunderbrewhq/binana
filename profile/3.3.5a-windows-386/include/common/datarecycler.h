#ifndef COMMON_DATA_RECYCLER_H
#define COMMON_DATA_RECYCLER_H

#include "system/types.h"

DECLARE_STRUCT(CDataRecycler);
DECLARE_STRUCT(CDataRecycler__vtable);
DECLARE_STRUCT(CDataRecycler__NodeBlock);
DECLARE_STRUCT(CDataRecycler__Node);

struct CDataRecycler__vtable {
  void* v_fn_00;
  void* v_fn_01;
  void* v_fn_02;
  void* v_fn_03;
  void* v_fn_04;
};

struct CDataRecycler__Node {
  CDataRecycler__Node* m_next;
  void* m_data;
  uint32_t m_bytes;
};

struct CDataRecycler__NodeBlock {
  CDataRecycler__NodeBlock* m_next;
  CDataRecycler__Node m_nodes[1];
};

struct CDataRecycler {
  CDataRecycler__vtable* v_vtable;
  int32_t m_nodesRecyclable;
  uint32_t m_nodesPerBlock;
  CDataRecycler__NodeBlock* m_nodeBlockList;
  CDataRecycler__Node* m_nodeFullList;
  CDataRecycler__Node* m_nodeEmptyList;
};

#endif
