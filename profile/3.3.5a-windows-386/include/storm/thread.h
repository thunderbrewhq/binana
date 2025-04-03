#ifndef STORM_THREAD_H
#define STORM_THREAD_H

DECLARE_STRUCT(SCritSect);
DECLARE_STRUCT(SSyncObject);
DECLARE_STRUCT(SEvent);
DECLARE_STRUCT(SThread);

#include "system/types.h"

typedef struct CSRWLock CSRWLock;

struct SCritSect {
  uint8_t m_critsect[24];
};

struct CSRWLock {
  uint8_t m_opaqueData[12];
};

struct SSyncObject {
  // HANDLE
  void* m_opaqueData;
};

struct SEvent {
  SSyncObject b_base;
};

struct SThread {
  SSyncObject b_base;
};

#endif