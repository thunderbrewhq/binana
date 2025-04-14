#ifndef STORM_LOG_H
#define STORM_LOG_H

#include "common/handle.h"

DECLARE_HANDLE(HSLOG);
DECLARE_STRUCT(LOG);

struct LOG {
  HSLOG log;
  LOG* next;
  char filename[260];
  void* file;
  uint32_t flags;
  size_t bufferused;
  size_t pendpoint;
  int32_t indent;
  int32_t timeStamp;
  char buffer[0x10000];
};

#endif