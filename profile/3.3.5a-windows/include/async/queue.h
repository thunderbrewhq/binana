#ifndef ASYNC_QUEUE_H
#define ASYNC_QUEUE_H

#include "system/types.h"
#include "storm/list.h"

DECLARE_STRUCT(TSLink_CAsyncQueue);
DECLARE_STRUCT(TSExplicitList_CAsyncObject);

DECLARE_STRUCT(CAsyncQueue);
STORM_TS_LIST(CAsyncQueue);

struct CAsyncQueue {
  TSLink_CAsyncQueue link;
  TSExplicitList_CAsyncObject readList;
  TSExplicitList_CAsyncObject unkList;
  int32_t int20;
};

#endif