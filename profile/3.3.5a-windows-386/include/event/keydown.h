#ifndef EVENT_KEY_DOWN_H
#define EVENT_KEY_DOWN_H

#include "storm/list.h"
#include "event/types.h"

typedef struct EvtKeyDown EvtKeyDown;

STORM_TS_LIST(EvtKeyDown);

struct EvtKeyDown {
  TSLink_EvtKeyDown link;
  KEY key;
};

#endif