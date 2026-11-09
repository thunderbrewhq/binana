#ifndef BC_LOCK_CONSTRUCT_ONCE_H
#define BC_LOCK_CONSTRUCT_ONCE_H

#include "bc/lock/do_once.h"

#define BC_LOCK_CONSTRUCT_ONCE(T)                                                                  \
    struct Blizzard__Lock__ConstructOnce_##T {                                                     \
        Blizzard__Lock__DoOnceData doOnceData;                                                     \
        T                          object;                                                         \
    };

#endif
