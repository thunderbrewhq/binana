#ifndef BC_SYSTEM_FILE_FILE_FUNC_H
#define BC_SYSTEM_FILE_FILE_FUNC_H

DECLARE_STRUCT(Blizzard__File__Filesystem);
DECLARE_STRUCT(System_File__Stacked__FileParms);

typedef bool (*System_File__Stacked__FileFunc)(
    Blizzard__File__Filesystem*      fs,
    System_File__Stacked__FileParms* parms);

#include "bc/file/filesystem.h"
#include "bc/system_file/stacked/fileparms.h"

#endif
