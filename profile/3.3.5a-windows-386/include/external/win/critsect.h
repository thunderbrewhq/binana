#ifndef WIN_CRITSECT_H
#define WIN_CRITSECT_H

DECLARE_STRUCT(CRITICAL_SECTION);

struct CRITICAL_SECTION {
    uint32_t opaque_data[6];
};

#endif
