#ifndef STORM_CMD_H
#define STORM_CMD_H

DECLARE_STRUCT(ARGLIST);
DECLARE_STRUCT(CMDPARAMS);
DECLARE_STRUCT(CMDDEF);
STORM_TS_LIST(CMDDEF);
DECLARE_STRUCT(CMDERROR);
DECLARE_STRUCT(PROCESSING);

#include "storm/list.h"

// Callback types
typedef int32_t (*CMDEXTRACALLBACK)(const char*);
typedef int32_t (*CMDERRORCALLBACK)(CMDERROR*);
typedef int32_t (*CMDPARAMSCALLBACK)(CMDPARAMS*, const char*);

// Details a command line argument
// class ARGLIST
struct ARGLIST {
  uint32_t          flags;
  uint32_t          id;
  const char*       name;
  CMDPARAMSCALLBACK callback;
};

// Parameters passed to argument callback
// class CMDPARAMS
struct CMDPARAMS {
  uint32_t      flags;
  uint32_t      id;
  const char*   name;
  void*         variable;
  uint32_t      setvalue;
  uint32_t      setmask;
  union {
    int32_t     boolvalue;
    int32_t     signedvalue;
    uint32_t    unsignedvalue;
    const char* stringvalue;
  };
};

// Command definitions
// class CMDDEF : public TSLinkedNode<CMDDEF>
struct CMDDEF {
  TSLinkedNode_CMDDEF b_base;
  uint32_t            flags;
  uint32_t            id;
  char                name[16];
  int32_t             namelength;
  uint32_t            setvalue;
  uint32_t            setmask;
  void*               variableptr;
  uint32_t            variablebytes;
  CMDPARAMSCALLBACK   callback;
  int32_t             found;
  union {
    uint32_t          currvalue;
    char*             currvaluestr;
  };
};

// class CMDERROR
struct CMDERROR {
  uint32_t    errorcode;
  const char* itemstr;
  const char* errorstr;
};

// class PROCESSING 
struct PROCESSING {
  CMDDEF* ptr;
  char    name[16];
  int32_t namelength;
};

#endif