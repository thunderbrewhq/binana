#ifndef EVENT_CONTEXT_H
#define EVENT_CONTEXT_H

#include "storm/thread.h"

#include "common/instance.h"
#include "storm/queue/timer_priority_uint32_t.h"

#include "event/message.h"
#include "event/handler.h"
#include "event/keydown.h"
#include "event/types.h"
#include "event/timer.h"
#include "event/id_table.h"

DECLARE_ENUM(SCHEDSTATE);
DECLARE_STRUCT(EvtContext);
DECLARE_STRUCT(EvtTimer);
DECLARE_HANDLE(HPROPCONTEXT);
DECLARE_HANDLE(HEVENTCONTEXT);

// EvtContext::SCHEDSTATE
enum SCHEDSTATE {
  SCHEDSTATE_ACTIVE = 0x0,
  SCHEDSTATE_CLOSED = 0x1,
  SCHEDSTATE_DESTROYED = 0x2,
  _UNIQUE_SYMBOL_SCHEDSTATE_96 = 0xFFFFFFFF
};

COMMON_INSTANCE_ID(EvtContext);

// class EvtContext : public TSingletonInstanceId<EvtContext, offsetof(TInstanceId<EvtContext>, m_id)> 
struct EvtContext {
  TSingletonInstanceId_EvtContext b_base;
  uint32_t unkA;
  // Member variables
  SCritSect m_critsect;
  uint32_t m_currTime;
  SCHEDSTATE m_schedState;
  TSTimerPriority_uint32_t m_schedNextWakeTime;
  uint32_t m_schedLastIdle;
  uint32_t m_schedFlags;
  uint32_t m_schedIdleTime;
  uint32_t m_schedInitialIdleTime;
  uint32_t m_schedWeight;
  uint32_t m_schedSmoothWeight;
  int32_t m_schedRebalance;
  int32_t unkXX;
  int32_t unkXY;
  int32_t unkXZ;
  int32_t unkYY;
  int32_t unkYZ;
  // TSExplicitList<EvtHandler, offsetof(EvtHandler, link)> m_queueHandlerList[EVENTIDS];
  TSExplicitList_EvtHandler m_queueHandlerList[36];
  // TSExplicitList<EvtMessage, offsetof(EvtMessage, link)> m_queueMessageList;
  TSExplicitList_EvtMessage m_queueMessageList;
  uint32_t m_queueSyncButtonState;
  // TSExplicitList<EvtKeyDown, offsetof(EvtKeyDown, link)> m_queueSyncKeyDownList;
  TSExplicitList_EvtKeyDown m_queueSyncKeyDownList;
  EvtIdTable_pointer_to_EvtTimer m_timerIdTable;
  EvtTimerQueue m_timerQueue;
  HPROPCONTEXT m_propContext;
  void* m_callContext;
  uint32_t m_startWatchdog;
};

#endif