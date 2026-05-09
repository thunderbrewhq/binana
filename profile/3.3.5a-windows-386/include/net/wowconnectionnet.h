#ifndef NET_WOW_CONNECTION_NET_H
#define NET_WOW_CONNECTION_NET_H

DECLARE_STRUCT(WowConnectionNet);
DECLARE_STRUCT(WowConnectionNet__Worker);

#include "net/wowconnection.h"
#include "storm/thread.h"

struct WowConnectionNet__Worker {
    WowConnectionNet* owner;
    SThread           thread;
    int32_t           id;
    WowConnection*    serviceConn;
    SEvent            event;
    int8_t            quit;
    SCritSect         lock;
};

struct WowConnectionNet {
    SThread                  m_thread;
    SEvent                   m_stopEvent;
    uint8_t                  m_stop;
    int32_t                  m_numWorkers;
    WowConnectionNet__Worker m_workers[32];
    SCritSect                m_connectionsLock;
    // STORM_EXPLICIT_LIST(WowConnection, m_netlink) m_connections;
    TSExplicitList_WowConnection m_connections;
    SSemaphore                   m_workerSem;
    void (*m_threadinit)();
    void* event8E8;
};

#endif
