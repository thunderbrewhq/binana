#ifndef BC_FILE_FILESYSTEM_H
#define BC_FILE_FILESYSTEM_H

#include "bc/systemfile/stacked.h"

DECLARE_ENUM(Blizzard__File__Operation);

DECLARE_STRUCT(Blizzard__File__Filesystem);

// invented enum
enum Blizzard__File__Operation {
  cd,
  close,
  create,
  cwd,
  dirwalk,
  exists,
  flush,
  getfileinfo,
  getfreespace,
  getpos,
  getrootchars,
  isabspath,
  isreadonly,
  makeabspath,
  mkdir,
  move,
  copy,
  open,
  read,
  readp,
  rmdir,
  setcachemode,
  seteof,
  setfileinfo,
  setpos,
  unlink,
  write,
  writep,
  shutdown,
  num_operations
};

#define FS_OP(N) bool (*f_##N)(Blizzard__File__Filesystem* fs, System_File__Stacked__FileParms* parms)

// 0x7C bytes = 4 + 4 + (29 * 4)
struct Blizzard__File__Filesystem {
  Blizzard__File__Filesystem* base;
  Blizzard__File__Filesystem* next;

  FS_OP(cd);
  FS_OP(close);
  FS_OP(create);
  FS_OP(cwd);
  FS_OP(dirwalk);
  FS_OP(exists);
  FS_OP(flush);
  FS_OP(getfileinfo);
  FS_OP(getfreespace);
  FS_OP(getpos);
  FS_OP(getrootchars);
  FS_OP(isabspath);
  FS_OP(isreadonly);
  FS_OP(makeabspath);
  FS_OP(mkdir);
  FS_OP(move);
  FS_OP(copy);
  FS_OP(open);
  FS_OP(read);
  FS_OP(readp);
  FS_OP(rmdir);
  FS_OP(setcachemode);
  FS_OP(seteof);
  FS_OP(setfileinfo);
  FS_OP(setpos);
  FS_OP(unlink);
  FS_OP(write);
  FS_OP(writep);
  FS_OP(shutdown);
};

#endif