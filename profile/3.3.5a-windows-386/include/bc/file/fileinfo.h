#ifndef BC_FILE_FILE_INFO_H
#define BC_FILE_FILE_INFO_H

#include "bc/time/types.h"

DECLARE_STRUCT(Blizzard__File__FileInfo);

struct Blizzard__File__FileInfo {
    char*                     path;
    uint32_t                  unk04;
    int64_t                   size; // 08
    int32_t                   attributes;
    Blizzard__Time__Timestamp createTime;
    Blizzard__Time__Timestamp modTime;
    Blizzard__Time__Timestamp accessTime;
    int32_t                   existence;
    int32_t                   regularFile;
};

#endif
