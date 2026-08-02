#ifndef DS_3D_LISTENER_H
#define DS_3D_LISTENER_H

DECLARE_STRUCT(DS3DLISTENER);

typedef DS3DLISTENER*       LPDS3DLISTENER;
typedef const DS3DLISTENER* LPCDS3DLISTENER;

#include "external/d3d9/vector.h"

struct DS3DLISTENER {
    uint32_t  dwSize;
    D3DVECTOR vPosition;
    D3DVECTOR vVelocity;
    D3DVECTOR vOrientFront;
    D3DVECTOR vOrientTop;
    D3DVALUE  flDistanceFactor;
    D3DVALUE  flRolloffFactor;
    D3DVALUE  flDopplerFactor;
};

#endif
