#ifndef WM_SDK_NSS_BUFFER_H
#define WM_SDK_NSS_BUFFER_H

DECLARE_STRUCT(INSSBuffer);
DECLARE_STRUCT(INSSBuffer__v_table);

#include "external/win/guid.h"
#include "external/win/hresult.h"

#define INTERFACE INSSBuffer
struct INSSBuffer__v_table {
    // IUnknown methods
    COM_P_METHOD(HRESULT, _00_QueryInterface, REFIID riid, void** ppvObject);
    COM_E_METHOD(uint32_t, _01_AddRef);
    COM_E_METHOD(uint32_t, _02_Release);
    // INSSBuffer methods
    COM_P_METHOD(HRESULT, _03_GetLength, uint32_t* pdwLength);
    COM_P_METHOD(HRESULT, _04_SetLength, uint32_t dwLength);
    COM_P_METHOD(HRESULT, _05_GetMaxLength, uint32_t* pdwLength);
    COM_P_METHOD(HRESULT, _06_GetBuffer, uint8_t** ppdwBuffer);
    COM_P_METHOD(HRESULT, _07_GetBufferAndLength, uint8_t** ppdwBuffer, uint32_t* pdwLength);
};
#undef INTERFACE

struct INSSBuffer {
    INSSBuffer__v_table* v_table;
};

#endif
