#ifndef MM_DEVICE_API_DEVICE_COLLECTION_H
#define MM_DEVICE_API_DEVICE_COLLECTION_H

DECLARE_STRUCT(IMMDeviceCollection);
DECLARE_STRUCT(IMMDeviceCollection__v_table);

#include "external/mmdeviceapi/device.h"
#include "external/win/guid.h"
#include "external/win/hresult.h"

#define INTERFACE IMMDeviceCollection
struct IMMDeviceCollection__v_table {
    // IUnknown methods
    COM_P_METHOD(HRESULT, _00_QueryInterface, REFIID riid, void** ppvObject);
    COM_E_METHOD(uint32_t, _01_AddRef);
    COM_E_METHOD(uint32_t, _02_Release);
    // IMMDeviceCollection methods
    COM_P_METHOD(HRESULT, _03_GetCount, uint32_t* pcDevices);
    COM_P_METHOD(HRESULT, _04_Item, uint32_t nDevice, IMMDevice** ppDevice);
};
#undef INTERFACE

struct IMMDeviceCollection {
    IMMDeviceCollection__v_table* v_table;
};

#endif
