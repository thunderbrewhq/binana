#ifndef D3D9_SOUND_3D_LISTENER_H
#define D3D9_SOUND_3D_LISTENER_H

DECLARE_STRUCT(IDirectSound3DListener);
DECLARE_STRUCT(IDirectSound3DListener__v_table);

#include "external/d3d9/ds3dlistener.h"
#include "external/d3d9/value.h"
#include "external/d3d9/vector.h"
#include "external/win/guid.h"
#include "external/win/hresult.h"

#define INTERFACE IDirectSound3DListener
struct IDirectSound3DListener__v_table {
    /*** IUnknown methods ***/
    COM_P_METHOD(HRESULT, _00_QueryInterface, REFIID riid, void** ppvObject);
    COM_E_METHOD(uint32_t, _01_AddRef);
    COM_E_METHOD(uint32_t, _02_Release);
    /*** IDirectSound3DListener methods ***/
    COM_P_METHOD(HRESULT, _03_GetAllParameters, LPDS3DLISTENER lpListener);
    COM_P_METHOD(HRESULT, _04_GetDistanceFactor, LPD3DVALUE lpflDistanceFactor);
    COM_P_METHOD(HRESULT, _05_GetDopplerFactor, LPD3DVALUE lpflDopplerFactor);
    COM_P_METHOD(HRESULT, _06_GetOrientation, LPD3DVECTOR lpvOrientFront, LPD3DVECTOR lpvOrientTop);
    COM_P_METHOD(HRESULT, _07_GetPosition, LPD3DVECTOR lpvPosition);
    COM_P_METHOD(HRESULT, _08_GetRolloffFactor, LPD3DVALUE lpflRolloffFactor);
    COM_P_METHOD(HRESULT, _09_GetVelocity, LPD3DVECTOR lpvVelocity);
    COM_P_METHOD(HRESULT, _10_SetAllParameters, LPCDS3DLISTENER lpcListener, uint32_t dwApply);
    COM_P_METHOD(HRESULT, _11_SetDistanceFactor, D3DVALUE flDistanceFactor, uint32_t dwApply);
    COM_P_METHOD(HRESULT, _12_SetDopplerFactor, D3DVALUE flDopplerFactor, uint32_t dwApply);
    COM_P_METHOD(
        HRESULT,
        _13_SetOrientation,
        D3DVALUE xFront,
        D3DVALUE yFront,
        D3DVALUE zFront,
        D3DVALUE xTop,
        D3DVALUE yTop,
        D3DVALUE zTop,
        uint32_t dwApply);
    COM_P_METHOD(HRESULT, _14_SetPosition, D3DVALUE x, D3DVALUE y, D3DVALUE z, uint32_t dwApply);
    COM_P_METHOD(HRESULT, _15_SetRolloffFactor, D3DVALUE flRolloffFactor, uint32_t dwApply);
    COM_P_METHOD(HRESULT, _16_SetVelocity, D3DVALUE x, D3DVALUE y, D3DVALUE z, uint32_t dwApply);
    COM_E_METHOD(HRESULT, _17_CommitDeferredSettings);
};

struct IDirectSound3DListener {
    IDirectSound3DListener__v_table* v_table;
};

#endif
