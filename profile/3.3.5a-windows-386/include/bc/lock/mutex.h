#ifndef BC_LOCK_MUTEX_H
#define BC_LOCK_MUTEX_H

DECLARE_STRUCT(Blizzard__Lock__Mutex);
DECLARE_STRUCT(Blizzard__Lock__RMutex);

#include "external/win/critsect.h"

struct Blizzard__Lock__Mutex {
    CRITICAL_SECTION critsect;
};

// class RMutex : public Mutex
struct Blizzard__Lock__RMutex {
    Blizzard__Lock__Mutex _;
};

#endif
