#ifndef EVENT_TIMER_H
#define EVENT_TIMER_H

#include "system/types.h"

#include "storm/queue/timer_priority_uint32_t.h"

DECLARE_STRUCT(EvtTimer);
DECLARE_STRUCT(EvtTimerQueue);

// class EvtTimer 
struct EvtTimer {
  // Member variables
  uint32_t id;
  TSTimerPriority_uint32_t targetTime;
  float timeout;
  int32_t (*handler)(const void*, void*);
  void* param;
  int32_t (*guidHandler)(const void*, uint64_t, void*);
  uint64_t guidParam;
  void* guidParam2;
};

STORM_TS_PRIORITY_QUEUE(EvtTimer);
STORM_TS_GROWABLE_ARRAY_POINTER_TO(EvtTimer);

// class EvtTimerQueue : public TSPriorityQueue<EvtTimer>
struct EvtTimerQueue {
  TSPriorityQueue_EvtTimer b_base;
};

#endif