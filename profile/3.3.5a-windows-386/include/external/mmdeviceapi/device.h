#ifndef MM_DEVICE_API_DEVICE_H
#define MM_DEVICE_API_DEVICE_H

DECLARE_STRUCT(IMMDevice);
DECLARE_STRUCT(IMMDevice__v_table);

#include "external/win/guid.h"
#include "external/win/hresult.h"
#include "external/win/ipropertystore.h"
#include "external/win/propvariant.h"

#define INTERFACE IMMDevice
struct IMMDevice__v_table {
    // IUnknown methods
    COM_P_METHOD(HRESULT, _00_QueryInterface, REFIID riid, void** ppvObject);
    COM_E_METHOD(uint32_t, _01_AddRef);
    COM_E_METHOD(uint32_t, _02_Release);
    // IMMDevice methods
    COM_P_METHOD(
        HRESULT,
        _03_Activate,
        REFIID       iid,
        uint32_t     dwClsCtx,
        PROPVARIANT* pActivationParams,
        void**       ppInterface);
    COM_P_METHOD(
        HRESULT,
        _04_OpenPropertyStore,
        uint32_t         stgmAccess,
        IPropertyStore** ppProperties);
    COM_P_METHOD(HRESULT, _05_GetId, uint16_t* ppstrId);
    COM_P_METHOD(HRESULT, _06_GetState, uint32_t* pdwState);
};
#undef INTERFACE

struct IMMDevice {
    IMMDevice__v_table* v_table;
};

#endif
