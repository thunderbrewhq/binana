#ifndef OBJECT_OBJECT_MANAGER_H
#define OBJECT_OBJECT_MANAGER_H

DECLARE_STRUCT(ClntObjMgr);

#include "net/clientconnection.h"
#include "object/object.h"
#include "object/player.h"

struct ClntObjMgr {
    // Member variables
    TSHashTable_CGObject_C_CHashKeyGUID m_objects;
    TSHashTable_CGObject_C_CHashKeyGUID m_lazyCleanupObjects;
    // STORM_EXPLICIT_LIST(CGObject_C, m_link) m_lazyCleanupFifo[NUM_CLIENT_OBJECT_TYPES - 1];
    TSList_CGObject_C m_lazyCleanupFifo[7];
    TSList_CGObject_C m_visibleObjects;
    TSList_CGObject_C m_reenabledObjects;
    // TODO
    WOWGUID           m_activePlayer;
    PLAYER_TYPE       m_type;
    uint32_t          m_mapID;
    ClientConnection* m_net;
};

#endif
