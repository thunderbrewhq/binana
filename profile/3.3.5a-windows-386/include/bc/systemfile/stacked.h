#ifndef BC_SYSTEM_FILE_STACKED_H
#define BC_SYSTEM_FILE_STACKED_H

#include "system/types.h"
#include "bc/file/stream.h"
#include "bc/file/info.h"
#include "bc/file/processdir.h"
#include "bc/file/mode.h"

DECLARE_STRUCT(System_File__Stacked__FileParms);

struct System_File__Stacked__FileParms {
  // the offset of the file operation
  // inside Blizzard::File::Filesystem
  uint32_t op; //0x0
  // name/path to a file or directory
  char* name; //0x4
  char* newname; // 0x8
  Blizzard__File__StreamRecord* file; // 0xC
  Blizzard__File__FileInfo* info;
  uint32_t extra;
  Blizzard__File__FileInfo noinfo;
  uint32_t setinfo;
    // something to do with file info
  // used by:
  //   Blizzard::File::GetFileInfo
  //   set to -1
  uint32_t getinfo;
  Blizzard__File__Mode mode; // 0x58
  void* data; // 
  uint32_t count;
  int64_t offset;
  int32_t whence;
  char* buffer;
  int32_t buffersize;
  bool recurse;
  // something to do with MakeAbsolutePath? (normalize? resolve? resolvesymlinks?)
  bool canonicalize; 
  void* dirwalkparam;
  Blizzard__File__ProcessDirCallback dirwalkcallback;
  // set to false by Blizzard::File::ProcessDirFast
  bool unk88;
  bool overwrite;
  bool set_acl; // something that causes a security descriptor to be generated in mkdir() (takeownership? chown? )
  uint32_t unk8C;
};

#endif
