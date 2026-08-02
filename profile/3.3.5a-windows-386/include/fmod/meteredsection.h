#ifndef FMOD_METERED_SECTION_H
#define FMOD_METERED_SECTION_H

DECLARE_STRUCT(METSECT_SHARED_INFO);
DECLARE_STRUCT(METERED_SECTION);

#include "external/win/critsect.h"
#include "external/win/handle.h"

typedef METSECT_SHARED_INFO* LPMETSECT_SHARED_INFO;
typedef METERED_SECTION*     LPMETERED_SECTION;

struct METSECT_SHARED_INFO {
    int32_t fInitialized; // Is the metered section initialized?
    int32_t lSpinLock;
    int32_t lThreadsWaiting; // Count of threads waiting
    int32_t lAvailableCount; // Available resource count
    int32_t lMaximumCount;   // Maximum resource count
};

// The opaque Metered Section data structure
// size = 0xC
struct METERED_SECTION {
    // HANDLE                hEvent; // Handle to a kernel event object
    // METSECT_SHARED_INFO   SharedInfo;
    // CRITICAL_SECTION      hCrit;
    // LPMETSECT_SHARED_INFO lpSharedInfo;
    HANDLE                hEvent;
    HANDLE                hFileMap;
    LPMETSECT_SHARED_INFO lpSharedInfo;
};

#endif
