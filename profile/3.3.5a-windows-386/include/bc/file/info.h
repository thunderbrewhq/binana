#ifndef BC_FILE_INFO_H
#define BC_FILE_INFO_H

#include "bc/time/timestamp.h"

DECLARE_STRUCT(Blizzard__File__FileInfo);

struct Blizzard__File__FileInfo {
  char* name;
  uint32_t unk04;
  // uint32_t unk08;
  // uint32_t unk0C;
  uint64_t size; // 08
  uint32_t attributes; 
  Blizzard__Time__Timestamp creationTime;
  Blizzard__Time__Timestamp lastWriteTime;
  Blizzard__Time__Timestamp lastAccessTime; 
  int32_t exists; 
  int32_t normal; 
};

#endif