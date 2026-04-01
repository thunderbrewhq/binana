#ifndef BC_STORAGE_STORAGE_UNIT_HANDLE_H
#define BC_STORAGE_STORAGE_UNIT_HANDLE_H

DECLARE_STRUCT(Blizzard__Storage__StorageUnitHandle);

#include "bc/file/inode.h"
#include "bc/storage/storageunit.h"

struct Blizzard__Storage__StorageUnitHandle {
    Blizzard__File__INODE           mNode;
    Blizzard__Storage__StorageUnit* mUnit;
};

#endif
