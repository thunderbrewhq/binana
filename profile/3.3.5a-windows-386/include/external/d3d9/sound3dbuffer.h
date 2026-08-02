#ifndef D3D9_SOUND_3D_BUFFER_H
#define D3D9_SOUND_3D_BUFFER_H

DECLARE_STRUCT(IDirectSound3DBuffer);
DECLARE_STRUCT(IDirectSound3DBuffer__v_table);

#include "external/d3d9/ds3dbuffer.h"
#include "external/d3d9/value.h"
#include "external/d3d9/vector.h"
#include "external/win/guid.h"
#include "external/win/hresult.h"

#define INTERFACE IDirectSound3DBuffer
struct IDirectSound3DBuffer__v_table {
    /*** IUnknown methods ***/
    COM_P_METHOD(HRESULT, _00_QueryInterface, REFIID riid, void** ppvObject);
    COM_E_METHOD(uint32_t, _01_AddRef);
    COM_E_METHOD(uint32_t, _02_Release);
    /*** IDirectSound3DBuffer methods ***/
    COM_P_METHOD(HRESULT, _03_GetAllParameters, LPDS3DBUFFER lpDs3dBuffer);
    COM_P_METHOD(
        HRESULT,
        _04_GetConeAngles,
        uint32_t* lpdwInsideConeAngle,
        uint32_t* lpdwOutsideConeAngle);
    COM_P_METHOD(HRESULT, _05_GetConeOrientation, LPD3DVECTOR lpvOrientation);
    COM_P_METHOD(HRESULT, _06_GetConeOutsideVolume, int32_t* lplConeOutsideVolume);
    COM_P_METHOD(HRESULT, _07_GetMaxDistance, LPD3DVALUE lpflMaxDistance);
    COM_P_METHOD(HRESULT, _08_GetMinDistance, LPD3DVALUE lpflMinDistance);
    COM_P_METHOD(HRESULT, _09_GetMode, uint32_t* lpwdMode);
    COM_P_METHOD(HRESULT, _10_GetPosition, LPD3DVECTOR lpvPosition);
    COM_P_METHOD(HRESULT, _11_GetVelocity, LPD3DVECTOR lpvVelocity);
    COM_P_METHOD(HRESULT, _12_SetAllParameters, LPCDS3DBUFFER lpcDs3dBuffer, uint32_t dwApply);
    COM_P_METHOD(
        HRESULT,
        _13_SetConeAngles,
        uint32_t dwInsideConeAngle,
        uint32_t dwOutsideConeAngle,
        uint32_t dwApply);
    COM_P_METHOD(
        HRESULT,
        _14_SetConeOrientation,
        D3DVALUE x,
        D3DVALUE y,
        D3DVALUE z,
        uint32_t dwApply);
    COM_P_METHOD(HRESULT, _15_SetConeOutsideVolume, int32_t lConeOutsideVolume, uint32_t dwApply);
    COM_P_METHOD(HRESULT, _16_SetMaxDistance, D3DVALUE flMaxDistance, uint32_t dwApply);
    COM_P_METHOD(HRESULT, _17_SetMinDistance, D3DVALUE flMinDistance, uint32_t dwApply);
    COM_P_METHOD(HRESULT, _18_SetMode, uint32_t dwMode, uint32_t dwApply);
    COM_P_METHOD(HRESULT, _19_SetPosition, D3DVALUE x, D3DVALUE y, D3DVALUE z, uint32_t dwApply);
    COM_P_METHOD(HRESULT, _20_SetVelocity, D3DVALUE x, D3DVALUE y, D3DVALUE z, uint32_t dwApply);
};

struct IDirectSound3DBuffer {
    IDirectSound3DBuffer__v_table* v_table;
};

#endif
