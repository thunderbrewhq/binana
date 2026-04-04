#ifndef BC_FILE_FILESYSTEM_H
#define BC_FILE_FILESYSTEM_H

#include "system/detect.h"

DECLARE_STRUCT(Blizzard__File__Filesystem);
DECLARE_STRUCT(Blizzard__File__Functions);

typedef uintptr_t offset_in_Blizzard__File__Functions_to_System_File__Stacked__FileFunc;

#include "bc/system_file/stacked/filefunc.h"
#include "bc/util/offset.h"

struct Blizzard__File__Functions {
    System_File__Stacked__FileFunc cd;
    System_File__Stacked__FileFunc close;
    System_File__Stacked__FileFunc create;
    System_File__Stacked__FileFunc cwd;
    System_File__Stacked__FileFunc dirwalk;
    System_File__Stacked__FileFunc exists;
    System_File__Stacked__FileFunc flush;
    System_File__Stacked__FileFunc getfileinfo;
    System_File__Stacked__FileFunc getfreespace;
    System_File__Stacked__FileFunc getpos;
    System_File__Stacked__FileFunc getrootchars;
    System_File__Stacked__FileFunc isabspath;
    System_File__Stacked__FileFunc isreadonly;
    System_File__Stacked__FileFunc makeabspath;
    System_File__Stacked__FileFunc mkdir;
    System_File__Stacked__FileFunc move;
    System_File__Stacked__FileFunc copy;
    System_File__Stacked__FileFunc open;
    System_File__Stacked__FileFunc read;
    System_File__Stacked__FileFunc readp;
    System_File__Stacked__FileFunc rmdir;
    System_File__Stacked__FileFunc setcachemode;
    System_File__Stacked__FileFunc seteof;
    System_File__Stacked__FileFunc setfileinfo;
    System_File__Stacked__FileFunc setpos;
    System_File__Stacked__FileFunc unlink;
    System_File__Stacked__FileFunc write;
    System_File__Stacked__FileFunc writep;
    System_File__Stacked__FileFunc shutdown;
};
BC_OFFSET_INTO(Blizzard__File__Functions, System_File__Stacked__FileFunc);

// 0x7C bytes = 4 + 4 + (29 * 4)
//
struct Blizzard__File__Filesystem {
    Blizzard__File__Filesystem* original;
    Blizzard__File__Filesystem* next;
    Blizzard__File__Functions   verbs;
};

#endif
