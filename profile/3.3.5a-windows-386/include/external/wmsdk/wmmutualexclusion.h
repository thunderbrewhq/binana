#ifndef WM_SDK_WM_MUTUAL_EXCLUSION_H
#define WM_SDK_WM_MUTUAL_EXCLUSION_H

DECLARE_STRUCT(IWMMutualExclusion);
DECLARE_STRUCT(IWMMutualExclusion__v_table);

#include "external/win/guid.h"
#include "external/win/hresult.h"

#define INTERFACE IWMMutualExclusion
struct IWMMutualExclusion__v_table {
    // IUnknown methods
    COM_P_METHOD(HRESULT, _00_QueryInterface, REFIID riid, void** ppvObject);
    COM_E_METHOD(uint32_t, _01_AddRef);
    COM_E_METHOD(uint32_t, _02_Release);
    // IWMStreamList methods
    COM_P_METHOD(HRESULT, _03_GetStreams, uint16_t* pwStreamNumArray, uint16_t* pcStreams);
    COM_P_METHOD(HRESULT, _04_AddStream, uint16_t wStreamNum);
    COM_P_METHOD(HRESULT, _05_RemoveStream, uint16_t wStreamNum);
    // IWMMutualExclusion methods
    COM_P_METHOD(HRESULT, _06_GetType, GUID* pguidType);
    COM_P_METHOD(HRESULT, _07_SetType, REFGUID guidType);
};
#undef INTERFACE

struct IWMMutualExclusion {
    IWMMutualExclusion__v_table* v_table;
};

#endif
