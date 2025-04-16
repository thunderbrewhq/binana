#ifndef COMMON_INSTANCE_H
#define COMMON_INSTANCE_H

#include "system/types.h"

#include "storm/list.h"
#include "storm/thread.h"

// TSList<T>
// TSLinkedNode<T>
// TInstanceId<T>
// TSingletonInstanceId<T>
#define COMMON_INSTANCE_ID(T) \
STORM_TS_LIST(T); \
typedef struct TInstanceId_##T##__v_table TInstanceId_##T##__v_table; \
typedef struct TInstanceId_##T TInstanceId_##T; \
typedef struct TSingletonInstanceId_##T TSingletonInstanceId_##T; \
struct TInstanceId_##T##__v_table { \
  void* v_fn_00_scalar_deleting_destructor; \
}; \
struct TInstanceId_##T { \
  TInstanceId_##T##__v_table* v_table; \
  TSLinkedNode_##T b_base; \
  uint32_t m_id; \
}; \
struct TSingletonInstanceId_##T { \
  TInstanceId_##T b_base; \
};

#define COMMON_INSTANCE_ID_TABLE(T) \
STORM_TS_LIST(T); \
typedef struct TInstanceIdTable_##T TInstanceIdTable_##T; \
struct TInstanceIdTable_##T { \
  SCritSect m_idCritSect; \
  uint32_t m_id; \
  int32_t m_idWrapped; \
  CSRWLock m_idLock[8]; \
  TSList_##T m_idList[8]; \
};

// template <class T>
// class TExtraInstanceRecyclable
typedef struct TExtraInstanceRecyclable TExtraInstanceRecyclable;
struct TExtraInstanceRecyclable {
  uint32_t m_recycleBytes;
};

#endif