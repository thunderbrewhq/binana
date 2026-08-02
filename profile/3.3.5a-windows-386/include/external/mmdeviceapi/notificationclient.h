#ifndef MM_DEVICE_API_NOTIFICATION_CLIENT_H
#define MM_DEVICE_API_NOTIFICATION_CLIENT_H

DECLARE_STRUCT(IMMNotificationClient);
DECLARE_STRUCT(IMMNotificationClient__v_table);

#include "external/mmdeviceapi/dataflow.h"
#include "external/mmdeviceapi/role.h"
#include "external/win/guid.h"
#include "external/win/hresult.h"

#define INTERFACE IMMNotificationClient
struct IMMNotificationClient__v_table {
    // IUnknown methods
    COM_P_METHOD(HRESULT, _00_QueryInterface, REFIID riid, void** ppvObject);
    COM_E_METHOD(uint32_t, _01_AddRef);
    COM_E_METHOD(uint32_t, _02_Release);
    // IMMNotificationClient methods
    COM_P_METHOD(
        HRESULT,
        _03_OnDeviceStateChanged,
        const uint16_t* pwstrDeviceId,
        uint32_t        dwNewState);
    COM_P_METHOD(HRESULT, _04_OnDeviceAdded, const uint16_t* pwstrDeviceId);
    COM_P_METHOD(HRESULT, _05_OnDeviceRemoved, const uint16_t* pwdstrDeviceId);
    COM_P_METHOD(
        HRESULT,
        _06_OnDefaultDeviceChanged,
        EDataFlow       flow,
        ERole           role,
        const uint16_t* pwstrDefaultDeviceId);
};
#undef INTERFACE

struct IMMNotificationClient {
    IMMNotificationClient__v_table* v_table;
};

#endif
