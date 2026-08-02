#ifndef WM_SDK_WM_SYNC_READER_H
#define WM_SDK_WM_SYNC_READER_H

DECLARE_STRUCT(IWMSyncReader);
DECLARE_STRUCT(IWMSyncReader__v_table);

#include "external/win/guid.h"
#include "external/win/hresult.h"
#include "external/win/stream.h"
#include "external/wmsdk/nssbuffer.h"
#include "external/wmsdk/wmoutputmediaprops.h"
#include "external/wmsdk/wmtattrdatatype.h"
#include "external/wmsdk/wmtstreamselection.h"

#define INTERFACE IWMSyncReader
struct IWMSyncReader__v_table {
    // IUnknown methods
    COM_P_METHOD(HRESULT, _00_QueryInterface, REFIID riid, void** ppvObject);
    COM_E_METHOD(uint32_t, _01_AddRef);
    COM_E_METHOD(uint32_t, _02_Release);
    // IWMSyncReader methods
    COM_P_METHOD(HRESULT, _03_Open, const uint16_t* pwszFilename);
    COM_E_METHOD(HRESULT, _04_Close);
    COM_P_METHOD(HRESULT, _05_SetRange, uint64_t cnsStartTime, int64_t cnsDuration);
    COM_P_METHOD(
        HRESULT,
        _06_SetRangeByFrame,
        uint16_t wStreamNum,
        uint64_t qwFrameNumber,
        int64_t  cFramesToRead);
    COM_P_METHOD(
        HRESULT,
        _07_GetNextSample,
        uint16_t     wStreamNum,
        INSSBuffer** ppSample,
        uint64_t*    pcnsSampleTime,
        uint64_t*    pcnsDuration,
        uint32_t*    pdwFlags,
        uint32_t*    pdwOutputNum,
        uint16_t*    pwStreamNum);
    COM_P_METHOD(
        HRESULT,
        _08_SetStreamsSelected,
        uint16_t              cStreamCount,
        uint16_t*             pwStreamNumbers,
        WMT_STREAM_SELECTION* pSelections);
    COM_P_METHOD(
        HRESULT,
        _09_GetStreamSelected,
        uint16_t              wStreamNum,
        WMT_STREAM_SELECTION* pSelection);
    COM_P_METHOD(HRESULT, _10_SetReadStreamSamples, uint16_t wStreamNum, int32_t fCompressed);
    COM_P_METHOD(HRESULT, _11_GetReadStreamSamples, uint16_t wStreamNum, int32_t* pfCompressed);
    COM_P_METHOD(
        HRESULT,
        _12_GetOutputSetting,
        uint32_t           dwOutputNum,
        const uint16_t*    pszName,
        WMT_ATTR_DATATYPE* pType,
        uint8_t*           pValue,
        uint16_t*          pcbLength);
    COM_P_METHOD(
        HRESULT,
        _13_SetOutputSetting,
        uint32_t          dwOutputNum,
        const uint16_t*   pszName,
        WMT_ATTR_DATATYPE Type,
        const uint8_t*    pValue,
        uint16_t          cbLength);
    COM_P_METHOD(HRESULT, _14_GetOutputCount, uint32_t* pcOutputs);
    COM_P_METHOD(HRESULT, _15_GetOutputProps, uint32_t dwOutputNum, IWMOutputMediaProps** ppOutput);
    COM_P_METHOD(HRESULT, _16_SetOutputProps, uint32_t dwOutputNum, IWMOutputMediaProps* pOutput);
    COM_P_METHOD(HRESULT, _17_GetOutputFormatCount, uint32_t dwOutputNum, uint32_t* pcFormats);
    COM_P_METHOD(
        HRESULT,
        _18_GetOutputFormat,
        uint32_t              dwOutputNum,
        uint32_t              dwFormatNum,
        IWMOutputMediaProps** ppProps);
    COM_P_METHOD(
        HRESULT,
        _19_GetOutputNumberForStream,
        uint16_t  wStreamNum,
        uint32_t* pdwOutputNum);
    COM_P_METHOD(
        HRESULT,
        _20_GetStreamNumberForOutput,
        uint32_t  dwOutputNum,
        uint16_t* pwStreamNum);
    COM_P_METHOD(HRESULT, _21_GetMaxOutputSampleSize, uint32_t dwOutput, uint32_t* pcbMax);
    COM_P_METHOD(HRESULT, _22_GetMaxStreamSampleSize, uint16_t wStream, uint32_t* pcbMax);
    COM_P_METHOD(HRESULT, _23_OpenStream, IStream* pStream);
};
#undef INTERFACE

struct IWMSyncReader {
    IWMSyncReader__v_table* v_table;
};

#endif
