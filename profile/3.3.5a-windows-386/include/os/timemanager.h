#ifndef OS_TIME_MANAGER_H
#define OS_TIME_MANAGER_H

#include "storm/thread.h"

DECLARE_ENUM(TimingMethod);
DECLARE_STRUCT(OsTimeManager);

enum TimingMethod {
  BestAvailable =  0,
  // GetTickCount (Windows), mach_absolute_time (MacOS)
  SystemMethod1 =  1,
  // QueryPerformanceCounter (Windows), Carbon Microseconds (MacOS)
  SystemMethod2 =  2,
  NotSet        =  0xFFFFFFFF,
};

struct OsTimeManager {
  double scaleToMs;
  TimingMethod timingMethod;
  uint32_t timingTestError;
  int64_t performanceFrequency;
  double timeBegin;
};

#endif