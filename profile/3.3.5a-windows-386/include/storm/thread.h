#ifndef STORM_THREAD_H
#define STORM_THREAD_H

#include "system/types.h"

DECLARE_STRUCT(SCritSect);
typedef struct CSRWLock CSRWLock;

struct SCritSect {
  uint8_t m_critsect[24];
};

struct CSRWLock {
  uint8_t m_opaqueData[12];
};

#endif