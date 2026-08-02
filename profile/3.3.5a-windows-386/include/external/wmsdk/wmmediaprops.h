#ifndef WM_SDK_WM_MEDIA_PROPS_H
#define WM_SDK_WM_MEDIA_PROPS_H

DECLARE_STRUCT(IWMMediaProps);
DECLARE_STRUCT(IWMMediaProps__v_table);

#include "external/win/guid.h"
#include "external/win/hresult.h"
#include "external/wmsdk/wmmediatype.h"

#define INTERFACE IWMMediaProps
struct IWMMediaProps__v_table {
    // IUnknown methods
    COM_P_METHOD(HRESULT, _00_QueryInterface, REFIID riid, void** ppvObject);
    COM_E_METHOD(uint32_t, _01_AddRef);
    COM_E_METHOD(uint32_t, _02_Release);
    // IWMMediaProps methods
    COM_P_METHOD(HRESULT, _03_GetType, GUID* pguidType);
    COM_P_METHOD(HRESULT, _04_GetMediaType, WM_MEDIA_TYPE* pType, uint32_t* pcbType);
    COM_P_METHOD(HRESULT, _05_SetMediaType, WM_MEDIA_TYPE* pType);
};
#undef INTERFACE

struct IWMMediaProps {
    IWMMediaProps__v_table* v_table;
};

#endif
