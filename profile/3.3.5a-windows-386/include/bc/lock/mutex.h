#ifndef BC_LOCK_MUTEX_H
#define BC_LOCK_MUTEX_H

DECLARE_STRUCT(Blizzard__Lock__Mutex);

#include "external/win/critsect.h"

struct Blizzard__Lock__Mutex {
    CRITICAL_SECTION critsect;
};

#endif
