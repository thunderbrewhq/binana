#ifndef WM_SDK_WM_PROFILE_H
#define WM_SDK_WM_PROFILE_H

DECLARE_STRUCT(IWMProfile);
DECLARE_STRUCT(IWMProfile__v_table);

#include "external/win/guid.h"
#include "external/win/hresult.h"
#include "external/wmsdk/wmmutualexclusion.h"
#include "external/wmsdk/wmstreamconfig.h"
#include "external/wmsdk/wmtversion.h"

#define INTERFACE IWMProfile
struct IWMProfile__v_table {
    // IUnknown methods
    COM_P_METHOD(_HRESULT, _00_QueryInterface, _REFIID riid, void** ppvObject);
    COM_E_METHOD(uint32_t, _01_AddRef);
    COM_E_METHOD(uint32_t, _02_Release);
    // IWMProfile methods
    COM_P_METHOD(_HRESULT, _03_GetVersion, WMT_VERSION* pdwVersion);
    COM_P_METHOD(_HRESULT, _04_GetName, uint16_t* pwszName, uint32_t* pcchName);
    COM_P_METHOD(_HRESULT, _05_SetName, const uint16_t* pwszName);
    COM_P_METHOD(
        _HRESULT,
        _06_GetDescription,
        uint16_t* pwszDescription,
        uint32_t* pcchDescription);
    COM_P_METHOD(_HRESULT, _07_SetDescription, const uint16_t* pwszDescription);
    COM_P_METHOD(_HRESULT, _08_GetStreamCount, uint32_t* pcStreams);
    COM_P_METHOD(_HRESULT, _09_GetStream, uint32_t dwStreamIndex, IWMStreamConfig** ppConfig);
    COM_P_METHOD(_HRESULT, _10_GetStreamByNumber, uint16_t wStreamNum, IWMStreamConfig** ppConfig);
    COM_P_METHOD(_HRESULT, _11_RemoveStream, IWMStreamConfig* pConfig);
    COM_P_METHOD(_HRESULT, _12_RemoveStreamByNumber, uint16_t wStreamNum);
    COM_P_METHOD(_HRESULT, _13_AddStream, IWMStreamConfig* pConfig);
    COM_P_METHOD(_HRESULT, _14_ReconfigStream, IWMStreamConfig* pConfig);
    COM_P_METHOD(
        _HRESULT,
        _15_CreateNewStream,
        _REFGUID          guidStreamType,
        IWMStreamConfig** ppConfig);
    COM_P_METHOD(_HRESULT, _16_GetMutualExclusionCount, uint32_t* pcME);
    COM_P_METHOD(_HRESULT, _17_GetMutualExclusion, uint32_t dwMEIndex, IWMMutualExclusion** ppME);
    COM_P_METHOD(_HRESULT, _18_RemoveMutualExclusion, IWMMutualExclusion* pME);
    COM_P_METHOD(_HRESULT, _19_AddMutualExclusion, IWMMutualExclusion* pME);
    COM_P_METHOD(_HRESULT, _20_CreateNewMutualExclusion, IWMMutualExclusion** ppME);
};
#undef INTERFACE

struct IWMProfile {
    IWMProfile__v_table* v_table;
};

#endif
