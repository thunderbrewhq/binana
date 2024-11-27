#ifndef STORM_QUEUE_H
#define STORM_QUEUE_H

#include "system/types.h"

#include "storm/array/pointer_to_void.h"

DECLARE_STRUCT(CSBasePriorityQueue);
DECLARE_STRUCT(CSBasePriority);

struct CSBasePriorityQueue {
  TSGrowableArray_pointer_to_void b_base;
  uint32_t m_linkOffset;
};

struct CSBasePriority {
  CSBasePriorityQueue* m_queue;
  uint32_t m_index;
};

#define STORM_TS_TIMER_PRIORITY(T) \
typedef struct TSTimerPriority_##T TSTimerPriority_##T; \
struct TSTimerPriority_##T { \
  CSBasePriority b_base; \
  T m_val; \
}

#define STORM_TS_PRIORITY_QUEUE(T) \
typedef CSBasePriorityQueue TSPriorityQueue_##T

#endif