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
  int32_t attributes; 
  Blizzard__Time__Timestamp createtime;
  Blizzard__Time__Timestamp lastwritetime;
  Blizzard__Time__Timestamp lastaccesstime; 
  int32_t filetype; 
  int32_t normal; 
};

#endif