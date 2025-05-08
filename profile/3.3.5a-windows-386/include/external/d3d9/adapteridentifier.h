
#ifndef D3D9_ADAPTERIDENTIFIER_H
#define D3D9_ADAPTERIDENTIFIER_H

DECLARE_STRUCT(D3DADAPTER_IDENTIFIER9);

#include "external/win/guid.h"
#include "external/win/largeinteger.h"

struct D3DADAPTER_IDENTIFIER9 {
  char Driver[512];
  char Description[512];
  char DeviceName[32];
  LARGE_INTEGER DriverVersion;

  uint32_t VendorId;
  uint32_t DeviceId;
  uint32_t SubSysId;
  uint32_t Revision;

  GUID DeviceIdentifier;

  uint32_t WHQLLevel;
};

#endif