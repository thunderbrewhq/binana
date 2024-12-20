#ifndef CMD_OPTION_H
#define CMD_OPTION_H

DECLARE_ENUM(CMDOPT);

enum CMDOPT {
  CMD_D3D           = 0,
  CMD_D3D9EX        = 1,
  CMD_DATA_DIR      = 2,
  CMD_NO_LAG_FIX    = 3,
  CMD_LOADFILE      = 4,
  CMD_GAMETYPE      = 5,
  CMD_OPENGL        = 6,
  CMD_SW_TNL        = 7,
  CMD_TIMEDEMO      = 8,
  CMD_DEMOREZ       = 9,
  CMD_DEMODEPTH     = 10,
  CMD_DEMODETAIL    = 11,
  CMD_DEMOSOUND     = 12,
  CMD_FULL_SCREEN   = 13,
  CMD_22050HZ       = 14,
  CMD_NO_WARNINGS   = 15,
  // CMDOPTS = 16,
  // NOTE: these extensions are NOT canonically part of the CMDOPT enum, but may be USED as CMDOPT values.
  CMD_RES_800x600   = 16,
  CMD_RES_1024x768  = 17,
  CMD_RES_1280x960  = 18,
  CMD_RES_1280x1024 = 19,
  CMD_RES_1600x1200 = 20,
  CMD_UP_TO_DATE    = 21,
  CMD_16_BIT        = 22,
  CMD_NO_FIX_LAG    = 24,
  CMD_NO_SOUND      = 26,
  CMD_SOUND_CHAOS   = 27,
  CMD_DEPTH_16      = 29,
  CMD_DEPTH_24      = 30,
  CMD_DEPTH_32      = 31,
  CMD_WINDOWED      = 32,
  CMD_CONSOLE       = 35,
  CMD_HW_DETECT     = 36,
  CMD_GX_OVERRIDE   = 39
};

#endif