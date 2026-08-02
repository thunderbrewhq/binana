
#ifndef WM_SDK_WM_STREAM_CONFIG_H
#define WM_SDK_WM_STREAM_CONFIG_H

DECLARE_STRUCT(IWMStreamConfig);
DECLARE_STRUCT(IWMStreamConfig__v_table);

#include "external/win/guid.h"
#include "external/win/hresult.h"

#define INTERFACE IWMStreamConfig
struct IWMStreamConfig__v_table {
    // IUnknown methods
    COM_P_METHOD(HRESULT, _00_QueryInterface, REFIID riid, void** ppvObject);
    COM_E_METHOD(uint32_t, _01_AddRef);
    COM_E_METHOD(uint32_t, _02_Release);
    // IWMStreamConfig methods
    COM_P_METHOD(HRESULT, _03_GetStreamType, GUID* pguidStreamType);
    COM_P_METHOD(HRESULT, _04_GetStreamNumber, uint16_t* pwStreamNum);
    COM_P_METHOD(HRESULT, _05_SetStreamNumber, uint16_t wStreamNum);
    COM_P_METHOD(HRESULT, _06_GetStreamName, uint16_t* pwszStreamName, uint16_t* pcchStreamName);
    COM_P_METHOD(HRESULT, _07_SetStreamName, const uint16_t* pwszStreamName);
    COM_P_METHOD(HRESULT, _08_GetConnectionName, uint16_t* pwszInputName, uint16_t* pcchInputName);
    COM_P_METHOD(HRESULT, _09_SetConnectionName, const uint16_t* pwszInputName);
    COM_P_METHOD(HRESULT, _10_GetBitrate, uint32_t* pdwBitrate);
    COM_P_METHOD(HRESULT, _11_SetBitrate, uint32_t pdwBitrate);
    COM_P_METHOD(HRESULT, _12_GetBufferWindow, uint32_t* pmsBufferWindow);
    COM_P_METHOD(HRESULT, _13_SetBufferWindow, uint32_t msBufferWindow);
};
#undef INTERFACE

struct IWMStreamConfig {
    IWMStreamConfig__v_table* v_vtable;
};

#endif
