#ifndef BC_FILE_STREAM_H
#define BC_FILE_STREAM_H

#include "bc/file/info.h"

DECLARE_STRUCT(Blizzard__File__StreamRecord);

struct Blizzard__File__StreamRecord {
  void* filehandle;
  int32_t mode;
  bool haveinfo;
  uint32_t unk0C;
  Blizzard__File__FileInfo info;
  // GetFileInfo only gets a size if this is null or points to a zero value
  int32_t* unk48;
  char* name; // name is a pointer to &filehandle (0x00) + sizeof(StreamRecord)
  // extra buffer that holds the actual data of name
};

#endif