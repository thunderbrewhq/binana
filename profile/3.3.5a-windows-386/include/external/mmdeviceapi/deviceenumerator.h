#ifndef MM_DEVICE_API_DEVICE_ENUMERATOR_H
#define MM_DEVICE_API_DEVICE_ENUMERATOR_H

DECLARE_STRUCT(IMMDeviceEnumerator);
DECLARE_STRUCT(IMMDeviceEnumerator__v_table);

#include "external/mmdeviceapi/dataflow.h"
#include "external/mmdeviceapi/device.h"
#include "external/mmdeviceapi/devicecollection.h"
#include "external/mmdeviceapi/notificationclient.h"
#include "external/mmdeviceapi/role.h"
#include "external/win/guid.h"
#include "external/win/hresult.h"

#define INTERFACE IMMDeviceEnumerator
struct IMMDeviceEnumerator__v_table {
    // IUnknown methods
    COM_P_METHOD(HRESULT, _00_QueryInterface, REFIID riid, void** ppvObject);
    COM_E_METHOD(uint32_t, _01_AddRef);
    COM_E_METHOD(uint32_t, _02_Release);
    // IMMDeviceEnumerator methods
    COM_P_METHOD(
        HRESULT,
        _03_EnumAudioEndpoints,
        EDataFlow             dataFlow,
        uint32_t              dwStateMask,
        IMMDeviceCollection** ppDevices);
    COM_P_METHOD(
        HRESULT,
        _04_GetDefaultAudioEndpoint,
        EDataFlow   dataFlow,
        ERole       role,
        IMMDevice** ppEndpoint);
    COM_P_METHOD(HRESULT, _05_GetDevice, const uint16_t* pwstrId, IMMDevice** ppDevice);
    COM_P_METHOD(HRESULT, _06_RegisterEndpointNotificationCallback, IMMNotificationClient* pClient);
    COM_P_METHOD(
        HRESULT,
        _07_UnregisterEndpointNotificationCallback,
        IMMNotificationClient* pClient);
};
#undef INTERFACE

struct IMMDeviceEnumerator {
    IMMDeviceEnumerator__v_table* v_table;
};

#endif
