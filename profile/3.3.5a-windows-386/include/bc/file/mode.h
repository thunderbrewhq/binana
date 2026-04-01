#ifndef BC_FILE_MODE_H
#define BC_FILE_MODE_H

DECLARE_ENUM(Blizzard__File__Mode);

enum Blizzard__File__Mode {
    read       = 0x0001,
    write      = 0x0002,
    shareread  = 0x0004,
    sharewrite = 0x0008,
    async      = 0x0020, // confirmed
    nocache    = 0x0040, // confirmed
    temp       = 0x0080, // confirmed
    truncate   = 0x0100, // confirmed
    append     = 0x0200, // confirmed
    recreate   = 0x0400, // confirmed
    cantexist  = 0x0800,
    mustexist  = 0x1000
};

#endif
