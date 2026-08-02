#ifndef MM_DEVICE_API_AUDIO_CAPTURE_CLIENT_H
#define MM_DEVICE_API_AUDIO_CAPTURE_CLIENT_H

DECLARE_STRUCT(IAudioCaptureClient);
DECLARE_STRUCT(IAudioCaptureClient__v_table);

#include "external/win/guid.h"
#include "external/win/hresult.h"

#define INTERFACE IAudioCaptureClient
struct IAudioCaptureClient__v_table {
    // IUnknown methods
    COM_P_METHOD(HRESULT, _00_QueryInterface, REFIID riid, void** ppvObject);
    COM_E_METHOD(uint32_t, _01_AddRef);
    COM_E_METHOD(uint32_t, _02_Release);
    // IAudioCaptureClient methods
    COM_P_METHOD(
        HRESULT,
        _03_GetBuffer,
        uint8_t*  ppData,
        uint32_t* pNumFramesToRead,
        uint32_t* pdwFlags,
        uint64_t* pu64DevicePosition,
        uint64_t* pu64QPCPosition);
    COM_P_METHOD(HRESULT, _04_ReleaseBuffer, uint32_t NumFramesRead);
    COM_P_METHOD(HRESULT, _05_GetNextPacketSize, uint32_t* pNumFramesInNextPacket);
};
#undef INTERFACE

struct IAudioCaptureClient {
    IAudioCaptureClient__v_table* v_table;
};

#endif
