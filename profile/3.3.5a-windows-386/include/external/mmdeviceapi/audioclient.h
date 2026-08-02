#ifndef MM_DEVICE_API_AUDIO_CLIENT_H
#define MM_DEVICE_API_AUDIO_CLIENT_H

DECLARE_STRUCT(IAudioClient);
DECLARE_STRUCT(IAudioClient__v_table);

DECLARE_ENUM(AUDCLNT_SHAREMODE);

typedef int64_t REFERENCE_TIME;

#include "external/win/guid.h"
#include "external/win/handle.h"
#include "external/win/hresult.h"
#include "external/win/waveformatex.h"

enum AUDCLNT_SHAREMODE {
    AUDCLNT_SHAREMODE_SHARED,
    AUDCLNT_SHAREMODE_EXCLUSIVE,
};

#define INTERFACE IAudioClient
struct IAudioClient__v_table {
    // IUnknown methods
    COM_P_METHOD(HRESULT, _00_QueryInterface, REFIID riid, void** ppvObject);
    COM_E_METHOD(uint32_t, _01_AddRef);
    COM_E_METHOD(uint32_t, _02_Release);
    // IAudioClient methods
    COM_P_METHOD(
        HRESULT,
        _03_Initialize,
        AUDCLNT_SHAREMODE   ShareMode,
        uint32_t            StreamFlags,
        REFERENCE_TIME      hnsBufferDuration,
        REFERENCE_TIME      hnsPeriodicity,
        const WAVEFORMATEX* pFormat,
        LPCGUID             AudioSessionGuid);
    COM_P_METHOD(HRESULT, _04_GetBufferSize, uint32_t* pNumBufferFrames);
    COM_P_METHOD(HRESULT, _05_GetStreamLatency, REFERENCE_TIME* phnsLatency);
    COM_P_METHOD(HRESULT, _06_GetCurrentPadding, uint32_t* pNumPaddingFrames);
    COM_P_METHOD(
        HRESULT,
        _07_IsFormatSupported,
        AUDCLNT_SHAREMODE   ShareMode,
        const WAVEFORMATEX* pFormat,
        WAVEFORMATEX**      ppClosestMatch);
    COM_P_METHOD(HRESULT, _08_GetMixFormat, WAVEFORMATEX** ppDeviceFormat);
    COM_P_METHOD(
        HRESULT,
        _09_GetDevicePeriod,
        REFERENCE_TIME* phnsDefaultDevicePeriod,
        REFERENCE_TIME* phnsMinimumDevicePeriod);
    COM_E_METHOD(HRESULT, _10_Start);
    COM_E_METHOD(HRESULT, _11_Stop);
    COM_E_METHOD(HRESULT, _12_Reset);
    COM_P_METHOD(HRESULT, _13_SetEventHandle, HANDLE eventHandle);
    COM_P_METHOD(HRESULT, _14_GetService, REFIID riid, void** ppv);
};
#undef INTERFACE

struct IAudioClient {
    IAudioClient__v_table* v_table;
};

#endif
