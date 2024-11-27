#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

#include "system/types.h"

#include "storm/list.h"

DECLARE_STRUCT(EvtHandler);

STORM_TS_LIST(EvtHandler);

struct EvtHandler {
  TSLink_EvtHandler link;
  int32_t (*func)(const void*, void*);
  void* param;
  float priority;
  int32_t marker;
};

#endif