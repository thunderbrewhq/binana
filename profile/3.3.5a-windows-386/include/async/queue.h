#ifndef ASYNC_QUEUE_H
#define ASYNC_QUEUE_H

DECLARE_STRUCT(CAsyncQueue);
STORM_TS_LIST(CAsyncQueue);

#include "system/types.h"
#include "storm/list.h"

#include "async/object.h"

struct CAsyncQueue {
  TSLink_CAsyncQueue link;
  TSExplicitList_CAsyncObject readList;
  TSExplicitList_CAsyncObject unkList;
  int32_t int20;
};

#endif