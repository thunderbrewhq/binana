#ifndef CONSOLE_COMMAND_H
#define CONSOLE_COMMAND_H

DECLARE_STRUCT(CONSOLECOMMAND);

#include "console/types.h"
#include "storm/hash.h"

STORM_TS_HASH(CONSOLECOMMAND, HASHKEY_STRI);

typedef int32_t (*COMMANDHANDLER_interface)(const char*, const char*);
typedef COMMANDHANDLER_interface COMMANDHANDLER;

// class CONSOLECOMMAND : public TSHashObject<CONSOLECOMMAND, HASHKEY_STRI>
struct CONSOLECOMMAND {
    TSHashObject_CONSOLECOMMAND_HASHKEY_STRI _;
    COMMANDHANDLER                           m_handler;
    const char*                              m_helpText;
    CATEGORY                                 m_category;
};

#endif
