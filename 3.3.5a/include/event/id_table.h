#ifndef EVENT_ID_TABLE_H
#define EVENT_ID_TABLE_H

#include "storm/array.h"
#include "storm/array/uint32_t.h"
#include "event/timer.h"

DECLARE_STRUCT(EvtIdTable_pointer_to_EvtTimer);

struct EvtIdTable_pointer_to_EvtTimer {
  TSGrowableArray_pointer_to_EvtTimer m_allocArray;
  TSGrowableArray_uint32_t m_freeArray;
};

#endif