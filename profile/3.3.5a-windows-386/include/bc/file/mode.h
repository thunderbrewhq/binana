#ifndef BC_FILE_MODE_H
#define BC_FILE_MODE_H

DECLARE_ENUM(Blizzard__File__Mode);

enum Blizzard__File__Mode {
  read         = 0x0001,
  write        = 0x0002,
  shareread    = 0x0004,
  sharewrite   = 0x0008,
  nocache      = 0x0040,
  temporary    = 0x0080,
  truncate     = 0x0100,
  append       = 0x0200,
  create       = 0x0400,
  mustnotexist = 0x0800,
  mustexist    = 0x1000
};

#endif
