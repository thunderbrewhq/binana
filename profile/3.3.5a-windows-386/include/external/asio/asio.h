#ifndef ASIO_ASIO_H
#define ASIO_ASIO_H

DECLARE_STRUCT(ASIOBufferInfo);
DECLARE_STRUCT(ASIOCallbacks);
DECLARE_STRUCT(ASIOChannelInfo);
DECLARE_STRUCT(ASIOClockSource);
DECLARE_STRUCT(ASIODRVSTRUCT);
DECLARE_STRUCT(ASIOTime);
DECLARE_STRUCT(ASIOTimeCode);
DECLARE_STRUCT(AsioDriverList);
DECLARE_STRUCT(AsioDrivers);
DECLARE_STRUCT(AsioTimeInfo);
DECLARE_STRUCT(IASIO);
DECLARE_STRUCT(IASIO__v_table);
DECLARE_STRUCT(ASIODriverInfo);

typedef int32_t ASIOBool;
typedef int32_t ASIOError;
typedef int32_t ASIOSampleType;

typedef double  ASIOSampleRate;
typedef int64_t ASIOSamples;
typedef int64_t ASIOTimeStamp;

typedef ASIODRVSTRUCT*  LPASIODRVSTRUCT;
typedef AsioDriverList* LPASIODRIVERLIST;

#include "external/win/guid.h"
#include "external/win/hresult.h"

struct ASIOClockSource {
    int32_t  index;
    int32_t  associatedChannel;
    int32_t  associatedGroup;
    ASIOBool isCurrentSource;
    char     name[32];
};

struct ASIOChannelInfo {
    int32_t        channel;
    ASIOBool       isInput;
    ASIOBool       isActive;
    int32_t        channelGroup;
    ASIOSampleType type;
    char           name[32];
};

struct ASIOBufferInfo {
    ASIOBool isInput;
    int32_t  channelNum;
    void*    buffers[2];
};

struct AsioTimeInfo {
    double         speed;
    ASIOTimeStamp  systemTime;
    ASIOSamples    samplePosition;
    ASIOSampleRate sampleRate;
    uint32_t       flags;
    char           reserved[12];
};

struct ASIOTimeCode {
    double      speed;
    ASIOSamples timeCodeSamples;
    uint32_t    flags;
    char        future[64];
};

struct ASIOTime {
    int32_t      reserved[4];
    AsioTimeInfo timeInfo;
    ASIOTimeCode timeCode;
};

struct ASIOCallbacks {
    void (*bufferSwitch)(int32_t doubleBufferIndex, ASIOBool directProcess);
    void (*sampleRateDidChange)(ASIOSampleRate sRate);
    int32_t (*asioMessage)(int32_t selector, int32_t value, void* message, double* opt);
    ASIOTime* (
        *bufferSwitchTimeInfo)(ASIOTime* params, int32_t doubleBufferIndex, ASIOBool directProcess);
};

struct ASIODRVSTRUCT {
    int32_t        drvID;
    CLSID          clsid;
    char           dllpath[512];
    char           drvname[128];
    void*          asiodrv;
    ASIODRVSTRUCT* next;
};

struct AsioDriverList {
    LPASIODRVSTRUCT lpdrvlist;
    int32_t         numdrv;
};

struct AsioDrivers {
    AsioDriverList _;
    uint32_t       connID;
    int32_t        curIndex;
};

struct ASIODriverInfo {
    int32_t asioVersion;
    int32_t driverVersion;
    char    name[32];
    char    errorMessage[124];
    void*   sysRef;
};

#define INTERFACE IASIO
struct IASIO__v_table {
    // IUnknown methods
    COM_P_METHOD(HRESULT, _00_QueryInterface, REFIID riid, void** ppvObject);
    COM_E_METHOD(uint32_t, _01_AddRef);
    COM_E_METHOD(uint32_t, _02_Release);
    // IASIO methods
    P_METHOD(ASIOBool, _03_init, void* sysHandle);
    P_METHOD(void, _04_getDriverName, char* name);
    E_METHOD(int32_t, _05_getDriverVersion);
    P_METHOD(void, _06_getErrorMessage, char* string);
    E_METHOD(ASIOError, _07_start);
    E_METHOD(ASIOError, _08_stop);
    P_METHOD(ASIOError, _09_getChannels, int32_t* numInputChannels, int32_t* numOutputChannels);
    P_METHOD(ASIOError, _10_getLatencies, int32_t* inputLatency, int32_t* outputLatency);
    P_METHOD(
        ASIOError,
        _11_getBufferSize,
        int32_t* minSize,
        int32_t* maxSize,
        int32_t* preferredSize,
        int32_t* granularity);
    P_METHOD(ASIOError, _12_canSampleRate, ASIOSampleRate sampleRate);
    P_METHOD(ASIOError, _13_getSampleRate, ASIOSampleRate* sampleRate);
    P_METHOD(ASIOError, _14_setSampleRate, ASIOSampleRate sampleRate);
    P_METHOD(ASIOError, _15_getClockSources, ASIOClockSource* clocks, int32_t* numSources);
    P_METHOD(ASIOError, _16_setClockSource, int32_t reference);
    P_METHOD(ASIOError, _17_getSamplePosition, ASIOSamples* sPos, ASIOTimeStamp* tStamp);
    P_METHOD(ASIOError, _18_getChannelInfo, ASIOChannelInfo* info);
    P_METHOD(
        ASIOError,
        _19_createBuffers,
        ASIOBufferInfo* bufferInfos,
        int32_t         numChannels,
        int32_t         bufferSize,
        ASIOCallbacks*  callbacks);
    E_METHOD(ASIOError, _20_disposeBuffers);
    E_METHOD(ASIOError, _21_controlPanel);
    P_METHOD(ASIOError, _22_future, int32_t selector, void* opt);
    E_METHOD(ASIOError, _23_outputReady);
};
#undef INTERFACE

struct IASIO {
    IASIO__v_table* v_table;
};

#endif
