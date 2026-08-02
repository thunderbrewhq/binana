#ifndef WIN_WAVE_FORMAT_EX_H
#define WIN_WAVE_FORMAT_EX_H

DECLARE_STRUCT(WAVEFORMATEX);

typedef WAVEFORMATEX*       LPWAVEFORMATEX;
typedef const WAVEFORMATEX* LPCWAVEFORMATEX;

struct WAVEFORMATEX {
    uint16_t wFormatTag;
    uint16_t nChannels;
    uint32_t nSamplesPerSec;
    uint32_t nAvgBytesPerSec;
    uint16_t nBlockAlign;
    uint16_t wBitsPerSample;
    uint16_t cbSize;
};

#endif
