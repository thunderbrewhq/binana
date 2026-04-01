#ifndef BC_FILE_STREAMING_INFO_H
#define BC_FILE_STREAMING_INFO_H

DECLARE_STRUCT(Blizzard__File__StreamingInfo);

#include "bc/file/fileinfo.h"
#include "bc/file/inode.h"
#include "bc/storage/storageunithandle.h"

struct Blizzard__File__StreamingInfo {
    Blizzard__Storage__StorageUnitHandle storagehandle;
    Blizzard__File__INODE                inode;
    uint32_t                             streamRefCount;
    Blizzard__File__FileInfo             streaminginfo;
};

#endif
