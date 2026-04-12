#ifndef XML_XML_H
#define XML_XML_H

DECLARE_STRUCT(XMLNode);
DECLARE_STRUCT(XMLAttribute);

#include "common/rcstring.h"
#include "storm/array.h"

struct XMLAttribute {
    // Member variables
    RCString m_name;
    RCString m_value;
};
STORM_TS_GROWABLE_ARRAY(XMLAttribute);

struct XMLNode {
    // Member variables
    void*                        m_userData;
    XMLNode*                     m_parent;
    XMLNode*                     m_child;
    RCString                     m_name;
    char*                        m_body;
    uint32_t                     m_bodyLen;
    TSGrowableArray_XMLAttribute m_attributes;
    uint32_t                     m_offset;
    XMLNode*                     m_next;
};

#endif
