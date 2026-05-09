#ifndef STORM_THREAD_H
#define STORM_THREAD_H

DECLARE_STRUCT(SCritSect);
DECLARE_STRUCT(SSyncObject);
DECLARE_STRUCT(SEvent);
DECLARE_STRUCT(SThread);
DECLARE_STRUCT(SSemaphore);

#include "system/types.h"

typedef struct CSRWLock CSRWLock;

struct SCritSect {
    uint8_t m_critsect[40];
};

struct CSRWLock {
    uint8_t m_opaqueData[12];
};

struct SSyncObject {
    // HANDLE
    void* m_opaqueData;
};

struct SEvent {
    SSyncObject _;
};

struct SThread {
    SSyncObject _;
};

struct SSemaphore {
    SSyncObject _;
};

#endif
