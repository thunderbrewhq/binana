#ifndef MM_DEVICE_API_AUDIO_CLOCK_H
#define MM_DEVICE_API_AUDIO_CLOCK_H

DECLARE_STRUCT(IAudioClock);
DECLARE_STRUCT(IAudioClock__v_table);

#include "external/win/guid.h"
#include "external/win/hresult.h"

// interface IAudioClock : IUnknown
// {
//     HRESULT GetFrequency(
//         [out] UINT64 *pu64Frequency
//     );
//     HRESULT GetPosition(
//         [out] UINT64 *pu64Position,
//         [out,unique] UINT64 *pu64QPCPosition
//     );
//     HRESULT GetCharacteristics(
//         [out] DWORD *pdwCharacteristics
//     );
// }

#define INTERFACE IAudioClock
struct IAudioClock__v_table {
    // IUnknown methods
    COM_P_METHOD(HRESULT, _00_QueryInterface, REFIID riid, void** ppvObject);
    COM_E_METHOD(uint32_t, _01_AddRef);
    COM_E_METHOD(uint32_t, _02_Release);
    // IAudioClock methods
    COM_P_METHOD(HRESULT, _03_GetFrequency, uint64_t* pu64Frequency);
    COM_P_METHOD(HRESULT, _04_GetPosition, uint64_t* pu64Position, uint64_t* pu64QPCPosition);
    COM_P_METHOD(HRESULT, _05_GetCharacteristics, uint32_t* pdwCharacteristics);
};
#undef INTERFACE

struct IAudioClock {
    IAudioClock__v_table* v_table;
};

#endif
