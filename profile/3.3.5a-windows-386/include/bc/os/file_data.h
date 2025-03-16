#ifndef BC_OS_FILE_DATA_H
#define BC_OS_FILE_DATA_H

DECLARE_STRUCT(OS_FILE_DATA);
DECLARE_STRUCT(FileListParms);

struct OS_FILE_DATA {
  uint32_t size;
  uint32_t flags;
  char fileName[260];
};

struct OsFileList__Internal__FileListParms {
  void* callback;
  void* param;
  uint32_t flags;
  char* pattern;
};

#endif