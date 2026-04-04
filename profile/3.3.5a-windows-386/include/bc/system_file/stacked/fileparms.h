#ifndef BC_SYSTEM_FILE_STACKED_FILE_PARMS_H
#define BC_SYSTEM_FILE_STACKED_FILE_PARMS_H

DECLARE_STRUCT(System_File__Stacked__FileParms);

#include "bc/file/fileinfo.h"
#include "bc/file/filesystem.h"
#include "bc/file/infomask.h"
#include "bc/file/mode.h"
#include "bc/file/processdir.h"
#include "bc/file/stream.h"
#include "system/types.h"

struct System_File__Stacked__FileParms {
    // the offset of the file operation
    // inside Blizzard::File::Filesystem
    offset_in_Blizzard__File__Functions_to_System_File__Stacked__FileFunc verb; // 0x0
    //
    char*                              path;    // 0x4 name/path to a file or directory
    char*                              newpath; // 0x8
    Blizzard__File__Stream             stream;  // 0xC
    Blizzard__File__FileInfo*          info;
    uint32_t                           extra;
    Blizzard__File__FileInfo           info_;
    Blizzard__File__FileInfoMask       has;
    Blizzard__File__FileInfoMask       want;
    int32_t                            mode;   // 0x58
    void*                              buffer; //
    int32_t                            amount;
    int64_t                            pos;
    int32_t                            posMode;
    char*                              cwdbuf;
    int32_t                            cwdbuflen;
    bool                               recursive;
    bool                               makeCanonical;
    void*                              cookie;
    Blizzard__File__ProcessDirCallback dircallback;
    bool sorted; // set to false by Blizzard::File::ProcessDirFast (i suppose it's fast because it doesn't request sorting, though there's
                 // no underlying code that does this)
    bool overwrite;
    bool grantEveryone; // something that causes a security descriptor to be generated
    bool zeroFillAll;
    bool supportsSparseFiles; // extopt not plausible here
};

#endif
