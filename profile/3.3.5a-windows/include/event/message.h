#ifndef EVENT_MESSAGE_H
#define EVENT_MESSAGE_H

#include "system/types.h"

#include "common/instance.h"
#include "storm/list.h"

#include "event/types.h"

typedef struct EvtMessage EvtMessage;

STORM_TS_LIST(EvtMessage);

// class EvtMessage : public TExtraInstanceRecyclable<EvtMessage>
struct EvtMessage {
  TExtraInstanceRecyclable b_base;
  TSLink_EvtMessage link;
  EVENTID id;
  char data[4];
};

#endif