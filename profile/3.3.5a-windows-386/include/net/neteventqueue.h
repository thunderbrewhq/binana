#ifndef NET_NET_EVENT_QUEUE_H
#define NET_NET_EVENT_QUEUE_H

DECLARE_STRUCT(NETEVENTQUEUENODE);
DECLARE_STRUCT(NETEVENTQUEUE);

#include "event/types.h"
#include "net/netclient.h"
#include "storm/list.h"
#include "storm/thread.h"

// class NETEVENTQUEUENODE : public TSLinkedNode<NETEVENTQUEUENODE>
STORM_TS_LIST(NETEVENTQUEUENODE);
struct NETEVENTQUEUENODE {
    EVENTID  m_eventId;
    uint32_t m_timeReceived;
    void*    m_data;
    uint32_t m_dataSize;
};

// class NETEVENTQUEUE
struct NETEVENTQUEUE {
    NetClient*               m_client;
    SCritSect                m_critSect;
    TSList_NETEVENTQUEUENODE m_eventQueue;
};

#endif
