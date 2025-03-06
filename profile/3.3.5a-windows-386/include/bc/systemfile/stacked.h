#ifndef BC_SYSTEM_FILE_STACKED_H
#define BC_SYSTEM_FILE_STACKED_H

#include "system/types.h"
#include "bc/file/stream.h"
#include "bc/file/info.h"
#include "bc/file/processdir.h"

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
  uint32_t extra[17]; // 0x10
  uint32_t flags;
  void* data; // 
  uint32_t count;
  int64_t offset;
  uint32_t unk__;
  char* buffer;
  int32_t buffersize;
  bool unkbool1;
  bool unkbool2;
  void* dirwalkparam;
  Blizzard__File__ProcessDirCallback dirwalkcallback;
  uint32_t extra3[2];
};

#endif
