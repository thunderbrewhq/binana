#ifndef MM_DEVICE_API_AUDIO_RENDER_CLIENT_H
#define MM_DEVICE_API_AUDIO_RENDER_CLIENT_H

DECLARE_STRUCT(IAudioRenderClient);
DECLARE_STRUCT(IAudioRenderClient__v_table);

#include "external/win/guid.h"
#include "external/win/hresult.h"

#define INTERFACE IAudioRenderClient
struct IAudioRenderClient__v_table {
    // IUnknown methods
    COM_P_METHOD(HRESULT, _00_QueryInterface, REFIID riid, void** ppvObject);
    COM_E_METHOD(uint32_t, _01_AddRef);
    COM_E_METHOD(uint32_t, _02_Release);
    // IAudioRenderClient methods
    COM_P_METHOD(HRESULT, _03_GetBuffer, uint32_t NumFramesRequested, uint8_t** ppData);
    COM_P_METHOD(HRESULT, _04_ReleaseBuffer, uint32_t NumFramesWritten, uint32_t dwFlags);
};
#undef INTERFACE

struct IAudioRenderClient {
    IAudioRenderClient__v_table* v_table;
};

#endif
