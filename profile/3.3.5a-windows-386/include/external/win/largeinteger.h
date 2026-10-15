#ifndef WIN_LARGEINTEGER_H
#define WIN_LARGEINTEGER_H

DECLARE_STRUCT(__LARGE_INTEGER);
DECLARE_STRUCT(__ULARGE_INTEGER);

struct __LARGE_INTEGER {
    int64_t QuadPart;
};

struct __ULARGE_INTEGER {
    uint64_t QuadPart;
};

#endif
