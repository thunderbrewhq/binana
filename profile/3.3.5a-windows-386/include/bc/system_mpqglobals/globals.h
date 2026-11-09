#ifndef BC_SYSTEM_MPQ_GLOBALS_GLOBALS_H
#define BC_SYSTEM_MPQ_GLOBALS_GLOBALS_H

DECLARE_STRUCT(System_MPQGlobals__Globals);
DECLARE_STRUCT(Blizzard__Lock__ConstructOnce_System_MPQGlobals__Globals);
DECLARE_STRUCT(std__multiset_SystemFile__ARCHIVEREC);
DECLARE_STRUCT(System_MPQGlobals__MopaqGlobals);
DECLARE_STRUCT(System_MPQGlobals__WorkerPool);
DECLARE_STRUCT(System_MPQGlobals__Worker);
DECLARE_STRUCT(std__vector_System_MPQGlobals__Worker);

#include "bc/lock/construct_once.h"
#include "bc/lock/mutex.h"
#include <stdint.h>

struct std__multiset_SystemFile__ARCHIVEREC {
    uint32_t base;
    void*    _Myhead;
    uint32_t _Mysize;
};

struct std__vector_System_MPQGlobals__Worker {
    System_MPQGlobals__Worker* _Myfirst;
    System_MPQGlobals__Worker* _Mylast;
    System_MPQGlobals__Worker* _Myend;
};

struct System_MPQGlobals__MopaqGlobals {
    uint32_t m_directAccess;                                  // 0x000
    char     m_basePath[260];                                 // 0x004
    void (*m_openCallback)(const char* name, void* param);    // 0x108
    void*    m_openCallbackParam;                             // 0x10C
    uint32_t m_md5Mode;                                       // 0x110
    bool (*m_md5Callback)(void* context, const uint8_t* md5); // 0x114
};

struct System_MPQGlobals__WorkerPool {
    Blizzard__Lock__RMutex                m_mutex;
    std__vector_System_MPQGlobals__Worker m_workers;
};

struct System_MPQGlobals__Globals {
    std__multiset_SystemFile__ARCHIVEREC m_archives;    // 0x000
    Blizzard__Lock__RMutex               m_archiveLock; // 0x00C
    System_MPQGlobals__MopaqGlobals      m_mopaq;       // 0x024
    Blizzard__Lock__RMutex               m_mopaqLock;   // 0x13C
    System_MPQGlobals__WorkerPool        m_workerPool;  // 0x154
};
BC_LOCK_CONSTRUCT_ONCE(System_MPQGlobals__Globals);

#endif
