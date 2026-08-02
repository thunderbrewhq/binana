#ifndef D3D9_DS_3D_BUFFER_H
#define D3D9_DS_3D_BUFFER_H

DECLARE_STRUCT(DS3DBUFFER);

typedef DS3DBUFFER*       LPDS3DBUFFER;
typedef const DS3DBUFFER* LPCDS3DBUFFER;

#include "external/d3d9/vector.h"

struct DS3DBUFFER {
    uint32_t  dwSize;
    D3DVECTOR vPosition;
    D3DVECTOR vVelocity;
    uint32_t  dwInsideConeAngle;
    uint32_t  dwOutsideConeAngle;
    D3DVECTOR vConeOrientation;
    int32_t   lConeOutsideVolume;
    D3DVALUE  flMinDistance;
    D3DVALUE  flMaxDistance;
    uint32_t  dwMode;
};

#endif
