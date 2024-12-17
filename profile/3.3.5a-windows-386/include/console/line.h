#ifndef CONSOLE_LINE_H
#define CONSOLE_LINE_H

DECLARE_STRUCT(CONSOLELINE);

#include "storm/list.h"
#include "console/types.h"
#include "gx/string.h"

STORM_TS_LIST(CONSOLELINE);

// struct CONSOLELINE : TSLinkedNode<CONSOLELINE>
struct CONSOLELINE {
  TSLinkedNode_CONSOLELINE b_base;
  uint8_t* buffer;
  uint32_t chars;
  uint32_t charsalloc;
  uint32_t inputpos;
  uint32_t inputstart;
  COLOR_T colorType;
  CGxString* fontPointer;
};

#endif