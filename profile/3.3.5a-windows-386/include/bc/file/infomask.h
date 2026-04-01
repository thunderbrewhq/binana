#ifndef BC_FILE_INFO_MASK_H
#define BC_FILE_INFO_MASK_H

#if defined(BITFIELDS_SUPPORTED)

DECLARE_UNION(Blizzard__File__FileInfoMask);

union Blizzard__File__FileInfoMask {
    struct {
        uint32_t path : 1;
        uint32_t size : 1;
        uint32_t attributes : 1;
        uint32_t createTime : 1;
        uint32_t modTime : 1;
        uint32_t accessTime : 1;
        uint32_t existence : 1;
        uint32_t regularFile : 1;
        uint32_t pad : 24;
    };
    uint32_t all;
};

#else

DECLARE_STRUCT(Blizzard__File__FileInfoMask);

struct Blizzard__File__FileInfoMask {
    uint32_t all;
};

#endif

#endif
