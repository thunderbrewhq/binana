#ifndef CONSOLE_HARDWARE_H
#define CONSOLE_HARDWARE_H

#include "db/records.h"

DECLARE_STRUCT(CpuHardware);
DECLARE_STRUCT(SoundHardware);
DECLARE_STRUCT(Hardware__Device);
DECLARE_STRUCT(Hardware);

struct CpuHardware {
  uint32_t farclipIdx;
  uint32_t animatingDoodadIdx;
  uint32_t waterLODIdx;
  uint32_t particleDensityIdx;
  uint32_t smallCullDistIdx;
  uint32_t unitDrawDistIdx;
};

// struct __declspec(align(4)) SoundHardware
struct SoundHardware {
  uint32_t numChannels;
  bool fivePointOne;
};

// struct Hardware::Device
struct Hardware__Device {
  uint16_t vendorID;
  uint16_t deviceID;
  uint32_t driverVersionHi;
  uint32_t driverVersionLo;
};

struct Hardware {
  Hardware__Device videoDevice;
  Hardware__Device soundDevice;
  uint32_t cpuIdx;
  uint32_t videoID;
  uint32_t soundIdx;
  uint32_t memIdx;
  VideoHardwareRec* videoHw;
  CpuHardware* cpuHw;
  SoundHardware* soundHw;
};

#endif