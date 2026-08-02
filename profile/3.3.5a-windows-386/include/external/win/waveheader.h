#ifndef WIN_WAVE_HEADER_H
#define WIN_WAVE_HEADER_H

DECLARE_STRUCT(WAVEHDR);

struct WAVEHDR {
    char*     lpData;          // 0x00
    uint32_t  dwBufferLength;  // 0x04
    uint32_t  dwBytesRecorded; // 0x08
    uintptr_t dwUser;          // 0x0C
    uint32_t  dwFlags;         // 0x10
    uint32_t  dwLoops;         // 0x14
    WAVEHDR*  lpNext;          // 0x18
    uintptr_t reserved;        // 0x1C
};

#endif
