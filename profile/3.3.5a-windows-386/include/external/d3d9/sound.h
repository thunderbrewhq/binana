#ifndef D3D9_SOUND_H
#define D3D9_SOUND_H

DECLARE_STRUCT(IDirectSound);
DECLARE_STRUCT(IDirectSound__v_table);
DECLARE_STRUCT(IDirectSound8);
DECLARE_STRUCT(IDirectSound8__v_table);

typedef IDirectSound*  LPDIRECTSOUND;
typedef IDirectSound8* LPDIRECTSOUND8;

#include "external/win/guid.h"
#include "external/win/handle.h"
#include "external/win/hresult.h"
#include "external/win/iunknown.h"

#include "external/d3d9/dsbufferdesc.h"
#include "external/d3d9/dscaps.h"
#include "external/d3d9/soundbuffer.h"

#define INTERFACE IDirectSound
struct IDirectSound__v_table {
    /*** IUnknown methods ***/
    COM_P_METHOD(HRESULT, _00_QueryInterface, REFIID riid, void** ppvObject);
    COM_E_METHOD(uint32_t, _01_AddRef);
    COM_E_METHOD(uint32_t, _02_Release);
    /*** IDirectSound methods ***/
    COM_P_METHOD(
        HRESULT,
        _03_CreateSoundBuffer,
        LPCDSBUFFERDESC       lpcDSBufferDesc,
        LPLPDIRECTSOUNDBUFFER lplpDirectSoundBuffer,
        IUnknown*             pUnkOuter);
    COM_P_METHOD(HRESULT, _04_GetCaps, LPDSCAPS lpDSCaps);
    COM_P_METHOD(
        HRESULT,
        _05_DuplicateSoundBuffer,
        LPDIRECTSOUNDBUFFER   lpDsbOriginal,
        LPLPDIRECTSOUNDBUFFER lplpDsbDuplicate);
    COM_P_METHOD(HRESULT, _06_SetCooperativeLevel, HWND hwnd, uint32_t dwLevel);
    COM_E_METHOD(HRESULT, _07_Compact);
    COM_P_METHOD(HRESULT, _08_GetSpeakerConfig, uint32_t* lpdwSpeakerConfig);
    COM_P_METHOD(HRESULT, _09_SetSpeakerConfig, uint32_t dwSpeakerConfig);
    COM_P_METHOD(HRESULT, _10_Initialize, LPCGUID lpcGuid);
};
#undef INTERFACE

struct IDirectSound {
    IDirectSound__v_table* v_table;
};

#define INTERFACE IDirectSound8
struct IDirectSound8__v_table {
    /*** IUnknown methods ***/
    COM_P_METHOD(HRESULT, _00_QueryInterface, REFIID riid, void** ppvObject);
    COM_E_METHOD(uint32_t, _01_AddRef);
    COM_E_METHOD(uint32_t, _02_Release);
    /*** IDirectSound8 methods ***/
    COM_P_METHOD(
        HRESULT,
        _03_CreateSoundBuffer,
        LPCDSBUFFERDESC       lpcDSBufferDesc,
        LPLPDIRECTSOUNDBUFFER lplpDirectSoundBuffer,
        IUnknown*             pUnkOuter);
    COM_P_METHOD(HRESULT, _04_GetCaps, LPDSCAPS lpDSCaps);
    COM_P_METHOD(
        HRESULT,
        _05_DuplicateSoundBuffer,
        LPDIRECTSOUNDBUFFER   lpDsbOriginal,
        LPLPDIRECTSOUNDBUFFER lplpDsbDuplicate);
    COM_P_METHOD(HRESULT, _06_SetCooperativeLevel, HWND hwnd, uint32_t dwLevel);
    COM_E_METHOD(HRESULT, _07_Compact);
    COM_P_METHOD(HRESULT, _08_GetSpeakerConfig, uint32_t* lpdwSpeakerConfig);
    COM_P_METHOD(HRESULT, _09_SetSpeakerConfig, uint32_t dwSpeakerConfig);
    COM_P_METHOD(HRESULT, _10_Initialize, LPCGUID lpcGuid);
    COM_P_METHOD(HRESULT, _11_VerifyCertification, uint32_t* pdwCertified);
};
#undef INTERFACE

struct IDirectSound8 {
    IDirectSound8__v_table* v_table;
};

#endif
