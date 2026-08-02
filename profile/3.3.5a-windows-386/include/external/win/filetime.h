#ifndef WIN_FILETIME_H
#define WIN_FILETIME_H

DECLARE_STRUCT(FILETIME);

struct FILETIME {
    uint32_t dwLowDateTime;
    uint32_t dwHighDateTime;
};

#endif
