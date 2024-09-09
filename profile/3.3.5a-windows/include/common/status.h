#ifndef COMMON_STATUS_H
#define COMMON_STATUS_H

#include "storm/list.h"

DECLARE_ENUM(STATUS_TYPE);
DECLARE_STRUCT(CStatus);
DECLARE_STRUCT(CStatus__STATUSENTRY);

enum STATUS_TYPE {
  STATUS_INFO = 0x0,
  STATUS_WARNING = 0x1,
  STATUS_ERROR = 0x2,
  STATUS_FATAL = 0x3,
  STATUS_NUMTYPES = 0x4
};

STORM_TS_LIST(CStatus__STATUSENTRY);

struct CStatus__STATUSENTRY {
  char* text;
  STATUS_TYPE severity;
  TSLink_CStatus__STATUSENTRY link;
};

struct CStatus {
  TSExplicitList_CStatus__STATUSENTRY statusList;
};

// class CWOWClientStatus : public CStatus {
//     public:
//         HSLOG m_logFile = nullptr;
// };


#endif