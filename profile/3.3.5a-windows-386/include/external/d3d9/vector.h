#ifndef D3D9_VECTOR_H
#define D3D9_VECTOR_H

DECLARE_STRUCT(D3DVECTOR);

typedef D3DVECTOR* LPD3DVECTOR;

#include "external/d3d9/value.h"

struct D3DVECTOR {
    D3DVALUE x;
    D3DVALUE y;
    D3DVALUE z;
};

#endif
