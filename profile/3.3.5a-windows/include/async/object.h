#ifndef ASYNC_OBJECT_H
#define ASYNC_OBJECT_H

#include "system/types.h"
#include "storm/list.h"
#include "async/queue.h"

DECLARE_STRUCT(CAsyncObject);
DECLARE_STRUCT(TSLink_CAsyncObject);

STORM_TS_LIST(CAsyncObject);

struct CAsyncObject {
  void* file;
  void* buffer;
  uint32_t size;
  void* userArg;
  void* userPostloadCallback;
  void* userPostUnloadCallback;
  CAsyncQueue* queue;
  void* ptr1c;
  int8_t priority;
  int8_t isProcessed;
  int8_t isRead;
  int8_t isCurrent;
  int8_t char24;
  int8_t char25;
  uint16_t padding;
  TSLink_CAsyncObject link;
};

#endif