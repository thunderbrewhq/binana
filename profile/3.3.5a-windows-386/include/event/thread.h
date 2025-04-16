#ifndef EVENT_THREAD_H
#define EVENT_THREAD_H

DECLARE_STRUCT(EvtThread);

#include "storm/thread.h"
#include "storm/list.h"
#include "storm/queue.h"

STORM_TS_LIST(EvtThread);

// class EvtThread : public TSLinkedNode<EvtThread>
struct EvtThread {
  TSLinkedNode_EvtThread b_base;
  uint32_t m_threadSlot;
  uint32_t m_threadCount;
  uint32_t m_weightTotal;
  uint32_t m_weightAvg;
  uint32_t m_contextCount;
  uint32_t m_rebalance;
  SEvent m_wakeEvent;
  EvtContextQueue m_contextQueue;
};

#endif