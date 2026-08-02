#ifndef D3D9_SOUND_CAPTURE_H
#define D3D9_SOUND_CAPTURE_H

DECLARE_STRUCT(IDirectSoundCapture);
DECLARE_STRUCT(IDirectSoundCapture8);
DECLARE_STRUCT(IDirectSoundCapture__v_table);
DECLARE_STRUCT(IDirectSoundCapture8__v_table);

typedef IDirectSoundCapture*  LPDIRECTSOUNDCAPTURE;
typedef IDirectSoundCapture8* LPDIRECTSOUNDCAPTURE8;

#include "external/win/guid.h"
#include "external/win/hresult.h"
#include "external/win/iunknown.h"

#include "external/d3d9/dscbufferdesc.h"
#include "external/d3d9/dsccaps.h"
#include "external/d3d9/soundcapturebuffer.h"

#define INTERFACE IDirectSoundCapture
struct IDirectSoundCapture__v_table {
    /*** IUnknown methods ***/
    COM_P_METHOD(HRESULT, _00_QueryInterface, REFIID riid, void** ppvObject);
    COM_E_METHOD(uint32_t, _01_AddRef);
    COM_E_METHOD(uint32_t, _02_Release);
    /*** IDirectSoundCapture methods ***/
    COM_P_METHOD(
        HRESULT,
        _03_CreateCaptureBuffer,
        LPCDSCBUFFERDESC            lpcDSCBufferDesc,
        LPDIRECTSOUNDCAPTUREBUFFER* lplpDSCaptureBuffer,
        LPUNKNOWN                   pUnk);
    COM_P_METHOD(HRESULT, _04_GetCaps, LPDSCCAPS lpDSCCaps);
    COM_P_METHOD(HRESULT, _05_Initialize, LPCGUID lpcGUID);
};
#undef INTERFACE

#define INTERFACE IDirectSoundCapture8
struct IDirectSoundCapture8__v_table {
    /*** IUnknown methods ***/
    COM_P_METHOD(HRESULT, _00_QueryInterface, REFIID riid, void** ppvObject);
    COM_E_METHOD(uint32_t, _01_AddRef);
    COM_E_METHOD(uint32_t, _02_Release);
    /*** IDirectSoundCapture methods ***/
    COM_P_METHOD(
        HRESULT,
        _03_CreateCaptureBuffer,
        LPCDSCBUFFERDESC            lpcDSCBufferDesc,
        LPDIRECTSOUNDCAPTUREBUFFER* lplpDSCaptureBuffer,
        LPUNKNOWN                   pUnk);
    COM_P_METHOD(HRESULT, _04_GetCaps, LPDSCCAPS lpDSCCaps);
    COM_P_METHOD(HRESULT, _05_Initialize, LPCGUID lpcGUID);
};
#undef INTERFACE

struct IDirectSoundCapture {
    IDirectSoundCapture__v_table* v_table;
};

struct IDirectSoundCapture8 {
    IDirectSoundCapture8__v_table* v_table;
};

#endif
