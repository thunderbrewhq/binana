#ifndef WM_SDK_WM_MEDIA_TYPE_H
#define WM_SDK_WM_MEDIA_TYPE_H

DECLARE_STRUCT(WM_MEDIA_TYPE);

#include "external/win/guid.h"
#include "external/win/iunknown.h"

struct WM_MEDIA_TYPE {
    __GUID    majortype;
    __GUID    subtype;
    int32_t   bFixedSizeSamples;
    int32_t   bTemporalCompression;
    uint32_t  lSampleSize;
    __GUID    formattype;
    IUnknown* pUnk;
    uint32_t  cbFormat;
    uint8_t*  pbFormat;
};

#endif
