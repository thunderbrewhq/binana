#ifndef D3D9_SOUND_CAPTURE_BUFFER_H
#define D3D9_SOUND_CAPTURE_BUFFER_H

DECLARE_STRUCT(IDirectSoundCaptureBuffer);
DECLARE_STRUCT(IDirectSoundCaptureBuffer__v_table);
DECLARE_STRUCT(IDirectSoundCaptureBuffer8);
DECLARE_STRUCT(IDirectSoundCaptureBuffer8__v_table);

typedef IDirectSoundCaptureBuffer*   LPDIRECTSOUNDCAPTUREBUFFER;
typedef LPDIRECTSOUNDCAPTUREBUFFER*  LPLPDIRECTSOUNDCAPTUREBUFFER;
typedef IDirectSoundCaptureBuffer8*  LPDIRECTSOUNDCAPTUREBUFFER8;
typedef LPDIRECTSOUNDCAPTUREBUFFER8* LPLPDIRECTSOUNDCAPTUREBUFFER8;

#include "external/d3d9/dscbcaps.h"
#include "external/d3d9/dscbufferdesc.h"
#include "external/d3d9/soundcapture.h"
#include "external/win/guid.h"
#include "external/win/hresult.h"
#include "external/win/waveformatex.h"

#define INTERFACE IDirectSoundCaptureBuffer
struct IDirectSoundCaptureBuffer__v_table {
    /*** IUnknown methods ***/
    COM_P_METHOD(HRESULT, _00_QueryInterface, REFIID riid, void** ppvObject);
    COM_E_METHOD(uint32_t, _01_AddRef);
    COM_E_METHOD(uint32_t, _02_Release);
    /*** IDirectSoundCaptureBuffer methods ***/
    COM_P_METHOD(HRESULT, _03_GetCaps, LPDSCBCAPS lpDSCBCaps);
    COM_P_METHOD(
        HRESULT,
        _04_GetCurrentPosition,
        uint32_t* lpdwCapturePosition,
        uint32_t* lpdwReadPosition);
    COM_P_METHOD(
        HRESULT,
        _05_GetFormat,
        LPWAVEFORMATEX lpwfxFormat,
        uint32_t       dwSizeAllocated,
        uint32_t       lpdwSizeWritten);
    COM_P_METHOD(HRESULT, _06_GetStatus, uint32_t* lpdwStatus);
    COM_P_METHOD(HRESULT, _07_Initialize, LPDIRECTSOUNDCAPTURE lpDSC, LPCDSCBUFFERDESC lpcDSCBDesc);
    COM_P_METHOD(
        HRESULT,
        _08_Lock,
        uint32_t  dwReadCusor,
        uint32_t  dwReadBytes,
        void**    lplpvAudioPtr1,
        uint32_t* lpdwAudioBytes1,
        void**    lplpvAudioPtr2,
        uint32_t* lpdwAudioBytes2,
        uint32_t  dwFlags);
    COM_P_METHOD(HRESULT, _09_Start, uint32_t dwFlags);
    COM_E_METHOD(HRESULT, _10_Stop);
    COM_P_METHOD(
        HRESULT,
        _11_Unlock,
        void*    lpvAudioPtr1,
        uint32_t dwAudioBytes1,
        void*    lpvAudioPtr2,
        uint32_t dwAudioBytes2);
};
#undef INTERFACE

struct IDirectSoundCaptureBuffer {
    IDirectSoundCaptureBuffer__v_table* v_table;
};

#define INTERFACE IDirectSoundCaptureBuffer8
struct IDirectSoundCaptureBuffer8__v_table {
    /*** IUnknown methods ***/
    COM_P_METHOD(HRESULT, _00_QueryInterface, REFIID riid, void** ppvObject);
    COM_E_METHOD(uint32_t, _01_AddRef);
    COM_E_METHOD(uint32_t, _02_Release);
    /*** IDirectSoundCaptureBuffer methods ***/
    COM_P_METHOD(HRESULT, _03_GetCaps, LPDSCBCAPS lpDSCBCaps);
    COM_P_METHOD(
        HRESULT,
        _04_GetCurrentPosition,
        uint32_t* lpdwCapturePosition,
        uint32_t* lpdwReadPosition);
    COM_P_METHOD(
        HRESULT,
        _05_GetFormat,
        LPWAVEFORMATEX lpwfxFormat,
        uint32_t       dwSizeAllocated,
        uint32_t       lpdwSizeWritten);
    COM_P_METHOD(HRESULT, _06_GetStatus, uint32_t* lpdwStatus);
    COM_P_METHOD(HRESULT, _07_Initialize, LPDIRECTSOUNDCAPTURE lpDSC, LPCDSCBUFFERDESC lpcDSCBDesc);
    COM_P_METHOD(
        HRESULT,
        _08_Lock,
        uint32_t  dwReadCusor,
        uint32_t  dwReadBytes,
        void**    lplpvAudioPtr1,
        uint32_t* lpdwAudioBytes1,
        void**    lplpvAudioPtr2,
        uint32_t* lpdwAudioBytes2,
        uint32_t  dwFlags);
    COM_P_METHOD(HRESULT, _09_Start, uint32_t dwFlags);
    COM_E_METHOD(HRESULT, _10_Stop);
    COM_P_METHOD(
        HRESULT,
        _11_Unlock,
        void*    lpvAudioPtr1,
        uint32_t dwAudioBytes1,
        void*    lpvAudioPtr2,
        uint32_t dwAudioBytes2);
    /*** IDirectSoundCaptureBuffer8 methods ***/
    COM_P_METHOD(
        HRESULT,
        _12_GetObjectInPath,
        REFGUID  rguidObject,
        uint32_t dwIndex,
        REFGUID  rguidInterface,
        void**   ppObject);
    COM_P_METHOD(HRESULT, _13_GetFXStatus, uint32_t dwFXCount, uint32_t* pdwFXStatus);
};
#undef INTERFACE

struct IDirectSoundCaptureBuffer8 {
    IDirectSoundCaptureBuffer8__v_table* v_table;
};

#endif
