#ifndef D3D9_SOUND_BUFFER_H
#define D3D9_SOUND_BUFFER_H

DECLARE_STRUCT(IDirectSoundBuffer);
DECLARE_STRUCT(IDirectSoundBuffer__v_table);
DECLARE_STRUCT(IDirectSoundBuffer8);
DECLARE_STRUCT(IDirectSoundBuffer8__v_table);

typedef IDirectSoundBuffer*  LPDIRECTSOUNDBUFFER;
typedef LPDIRECTSOUNDBUFFER* LPLPDIRECTSOUNDBUFFER;

typedef IDirectSoundBuffer8*  LPDIRECTSOUNDBUFFER8;
typedef LPDIRECTSOUNDBUFFER8* LPLPDIRECTSOUNDBUFFER8;

#include "external/win/guid.h"
#include "external/win/hresult.h"

#include "external/d3d9/dsbcaps.h"
#include "external/d3d9/dsbufferdesc.h"
#include "external/d3d9/dseffectdesc.h"
#include "external/d3d9/sound.h"

#define INTERFACE IDirectSoundBuffer
struct IDirectSoundBuffer__v_table {
    /*** IUnknown methods ***/
    COM_P_METHOD(_HRESULT, _00_QueryInterface, _REFIID riid, void** ppvObject);
    COM_E_METHOD(uint32_t, _01_AddRef);
    COM_E_METHOD(uint32_t, _02_Release);
    /*** IDirectSoundBuffer methods ***/
    COM_P_METHOD(_HRESULT, _03_GetCaps, LPDSBCAPS lpDSBufferCaps);
    COM_P_METHOD(
        _HRESULT,
        _04_GetCurrentPosition,
        uint32_t* lpdwCurrentPlayCursor,
        uint32_t* lpdwCurrentWriteCursor);
    COM_P_METHOD(
        _HRESULT,
        _05_GetFormat,
        LPWAVEFORMATEX lpwfxFormat,
        uint32_t       dwSizeAllocated,
        uint32_t*      lpdwSizeWritten);
    COM_P_METHOD(_HRESULT, _06_GetVolume, int32_t* lplVolume);
    COM_P_METHOD(_HRESULT, _07_GetPan, int32_t* lplpan);
    COM_P_METHOD(_HRESULT, _08_GetFrequency, uint32_t* lpdwFrequency);
    COM_P_METHOD(_HRESULT, _09_GetStatus, uint32_t* lpdwStatus);
    COM_P_METHOD(
        _HRESULT,
        _10_Initialize,
        LPDIRECTSOUND   lpDirectSound,
        LPCDSBUFFERDESC lpcDSBufferDesc);
    COM_P_METHOD(
        _HRESULT,
        _11_Lock,
        uint32_t  dwOffset,
        uint32_t  dwBytes,
        void**    ppvAudioPtr1,
        uint32_t* pdwAudioBytes1,
        void**    ppvAudioPtr2,
        uint32_t* pdwAudioBytes2,
        uint32_t  dwFlags);
    COM_P_METHOD(_HRESULT, _12_Play, uint32_t dwReserved1, uint32_t dwReserved2, uint32_t dwFlags);
    COM_P_METHOD(_HRESULT, _13_SetCurrentPosition, uint32_t dwNewPosition);
    COM_P_METHOD(_HRESULT, _14_SetFormat, LPCWAVEFORMATEX lpcfxFormat);
    COM_P_METHOD(_HRESULT, _15_SetVolume, int32_t lVolume);
    COM_P_METHOD(_HRESULT, _16_SetPan, int32_t lPan);
    COM_P_METHOD(_HRESULT, _17_SetFrequency, uint32_t dwFrequency);
    COM_E_METHOD(_HRESULT, _18_Stop);
    COM_P_METHOD(
        _HRESULT,
        _19_Unlock,
        void*    pvAudioPtr1,
        uint32_t dwAudioBytes1,
        void*    pvAudioPtr2,
        uint32_t dwAudioPtr2);
    COM_E_METHOD(_HRESULT, _20_Restore);
};
#undef INTERFACE

struct IDirectSoundBuffer {
    IDirectSoundBuffer__v_table* v_table;
};

#define INTERFACE IDirectSoundBuffer8
struct IDirectSoundBuffer8__v_table {
    /*** IUnknown methods ***/
    /*** IUnknown methods ***/
    COM_P_METHOD(_HRESULT, _00_QueryInterface, _REFIID riid, void** ppvObject);
    COM_E_METHOD(uint32_t, _01_AddRef);
    COM_E_METHOD(uint32_t, _02_Release);
    /*** IDirectSoundBuffer methods ***/

    COM_P_METHOD(_HRESULT, _03_GetCaps, LPDSBCAPS lpDSBufferCaps);
    COM_P_METHOD(
        _HRESULT,
        _04_GetCurrentPosition,
        uint32_t* lpdwCurrentPlayCursor,
        uint32_t* lpdwCurrentWriteCursor);
    COM_P_METHOD(
        _HRESULT,
        _05_GetFormat,
        LPWAVEFORMATEX lpwfxFormat,
        uint32_t       dwSizeAllocated,
        uint32_t*      lpdwSizeWritten);
    COM_P_METHOD(_HRESULT, _06_GetVolume, int32_t* lplVolume);
    COM_P_METHOD(_HRESULT, _07_GetPan, int32_t* lplpan);
    COM_P_METHOD(_HRESULT, _08_GetFrequency, uint32_t* lpdwFrequency);
    COM_P_METHOD(_HRESULT, _09_GetStatus, uint32_t* lpdwStatus);
    COM_P_METHOD(
        _HRESULT,
        _10_Initialize,
        LPDIRECTSOUND   lpDirectSound,
        LPCDSBUFFERDESC lpcDSBufferDesc);
    COM_P_METHOD(
        _HRESULT,
        _11_Lock,
        uint32_t  dwOffset,
        uint32_t  dwBytes,
        void**    ppvAudioPtr1,
        uint32_t* pdwAudioBytes1,
        void**    ppvAudioPtr2,
        uint32_t* pdwAudioBytes2,
        uint32_t  dwFlags);
    COM_P_METHOD(_HRESULT, _12_Play, uint32_t dwReserved1, uint32_t dwReserved2, uint32_t dwFlags);
    COM_P_METHOD(_HRESULT, _13_SetCurrentPosition, uint32_t dwNewPosition);
    COM_P_METHOD(_HRESULT, _14_SetFormat, LPCWAVEFORMATEX lpcfxFormat);
    COM_P_METHOD(_HRESULT, _15_SetVolume, int32_t lVolume);
    COM_P_METHOD(_HRESULT, _16_SetPan, int32_t lPan);
    COM_P_METHOD(_HRESULT, _17_SetFrequency, uint32_t dwFrequency);
    COM_E_METHOD(_HRESULT, _18_Stop);
    COM_P_METHOD(
        _HRESULT,
        _19_Unlock,
        void*    pvAudioPtr1,
        uint32_t dwAudioBytes1,
        void*    pvAudioPtr2,
        uint32_t dwAudioPtr2);
    COM_E_METHOD(_HRESULT, _20_Restore);
    COM_P_METHOD(
        _HRESULT,
        _21_SetFX,
        uint32_t       dwEffectsCount,
        LPDSEFFECTDESC pDSFXDesc,
        uint32_t*      pdwResultCodes);
    COM_P_METHOD(
        _HRESULT,
        _22_AcquireResources,
        uint32_t  dwFlags,
        uint32_t  dwEffectsCount,
        uint32_t* pdwResultCodes);
    COM_P_METHOD(
        _HRESULT,
        _23_GetObjectInPath,
        _REFGUID rguidObject,
        uint32_t dwIndex,
        _REFGUID rguidInterface,
        void**   ppObject);
};
#undef INTERFACE

struct IDirectSoundBuffer8 {
    IDirectSoundBuffer8__v_table* v_table;
};

#endif
