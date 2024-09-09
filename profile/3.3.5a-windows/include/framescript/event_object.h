#ifndef FRAMESCRIPT_EVENT_OBJECT_H
#define FRAMESCRIPT_EVENT_OBJECT_H

#include "storm/hash.h"

#include "framescript/object.h"

#include "ui/simpleframe.h"

DECLARE_STRUCT(FrameScript_EventObject);
DECLARE_STRUCT(SIMPLEFRAMENODE);
DECLARE_STRUCT(EVENTLISTENERNODE);

STORM_TS_LIST(SIMPLEFRAMENODE);
STORM_TS_LIST(EVENTLISTENERNODE);

// struct SIMPLEFRAMENODE : TSLinkedNode<SIMPLEFRAMENODE> 
struct SIMPLEFRAMENODE {
  TSLinkedNode_SIMPLEFRAMENODE b_base;
  CSimpleFrame* frame;
};

// struct EVENTLISTENERNODE : TSLinkedNode<EVENTLISTENERNODE> {
struct EVENTLISTENERNODE {
  TSLinkedNode_EVENTLISTENERNODE b_base;
  FrameScript_Object* listener;
};

STORM_TS_HASH(FrameScript_EventObject, HASHKEY_STRI)

struct FrameScript_EventObject {
  TSHashObject_FrameScript_EventObject_HASHKEY_STRI b_base;
};

#endif