#ifndef EXPAT_EXPAT_H
#define EXPAT_EXPAT_H

// struct declarations
DECLARE_STRUCT(ATTRIBUTE);
DECLARE_STRUCT(ATTRIBUTE_ID);
DECLARE_STRUCT(BINDING);
DECLARE_STRUCT(BLOCK);
DECLARE_STRUCT(CONTENT_SCAFFOLD);
DECLARE_STRUCT(DEFAULT_ATTRIBUTE);
DECLARE_STRUCT(DTD);
DECLARE_STRUCT(ELEMENT_TYPE);
DECLARE_STRUCT(ENCODING);
DECLARE_STRUCT(ENTITY);
DECLARE_STRUCT(HASH_TABLE);
DECLARE_STRUCT(HASH_TABLE_ITER);
DECLARE_STRUCT(INIT_ENCODING);
DECLARE_STRUCT(NAMED);
DECLARE_STRUCT(OPEN_INTERNAL_ENTITY);
DECLARE_STRUCT(POSITION);
DECLARE_STRUCT(PREFIX);
DECLARE_STRUCT(PROLOG_STATE);
DECLARE_STRUCT(STRING_POOL);
DECLARE_STRUCT(TAG);
DECLARE_STRUCT(TAG_NAME);
DECLARE_STRUCT(XML_Content);
DECLARE_STRUCT(XML_Encoding);
DECLARE_STRUCT(XML_Memory_Handling_Suite);
DECLARE_STRUCT(XML_ParserStruct);
DECLARE_STRUCT(normal_encoding);
DECLARE_STRUCT(unknown_encoding);

// enum declarations
DECLARE_ENUM(XML_Content_Quant);
DECLARE_ENUM(XML_Content_Type);
DECLARE_ENUM(XML_Error);
DECLARE_ENUM(XML_ParamEntityParsing);
DECLARE_ENUM(XML_Status);

// integral types
typedef char     XML_Char;
typedef char     XML_LChar;
typedef int64_t  XML_Index;
typedef uint64_t XML_Size;
typedef uint8_t  XML_Bool;

// type aliases)
typedef XML_ParserStruct* XML_Parser;
typedef const XML_Char*   __expat__KEY; // in conflict with WoW KEY

// enums
enum XML_Content_Type {
    XML_CTYPE_EMPTY = 1,
    XML_CTYPE_ANY,
    XML_CTYPE_MIXED,
    XML_CTYPE_NAME,
    XML_CTYPE_CHOICE,
    XML_CTYPE_SEQ
};

enum XML_Content_Quant {
    XML_CQUANT_NONE,
    XML_CQUANT_OPT,
    XML_CQUANT_REP,
    XML_CQUANT_PLUS
};

enum XML_Error {
    XML_ERROR_NONE,
    XML_ERROR_NO_MEMORY,
    XML_ERROR_SYNTAX,
    XML_ERROR_NO_ELEMENTS,
    XML_ERROR_INVALID_TOKEN,
    XML_ERROR_UNCLOSED_TOKEN,
    XML_ERROR_PARTIAL_CHAR,
    XML_ERROR_TAG_MISMATCH,
    XML_ERROR_DUPLICATE_ATTRIBUTE,
    XML_ERROR_JUNK_AFTER_DOC_ELEMENT,
    XML_ERROR_PARAM_ENTITY_REF,
    XML_ERROR_UNDEFINED_ENTITY,
    XML_ERROR_RECURSIVE_ENTITY_REF,
    XML_ERROR_ASYNC_ENTITY,
    XML_ERROR_BAD_CHAR_REF,
    XML_ERROR_BINARY_ENTITY_REF,
    XML_ERROR_ATTRIBUTE_EXTERNAL_ENTITY_REF,
    XML_ERROR_MISPLACED_XML_PI,
    XML_ERROR_UNKNOWN_ENCODING,
    XML_ERROR_INCORRECT_ENCODING,
    XML_ERROR_UNCLOSED_CDATA_SECTION,
    XML_ERROR_EXTERNAL_ENTITY_HANDLING,
    XML_ERROR_NOT_STANDALONE,
    XML_ERROR_UNEXPECTED_STATE,
    XML_ERROR_ENTITY_DECLARED_IN_PE,
    XML_ERROR_FEATURE_REQUIRES_XML_DTD,
    XML_ERROR_CANT_CHANGE_FEATURE_ONCE_PARSING
};

enum XML_ParamEntityParsing {
    XML_PARAM_ENTITY_PARSING_NEVER,
    XML_PARAM_ENTITY_PARSING_UNLESS_STANDALONE,
    XML_PARAM_ENTITY_PARSING_ALWAYS
};

enum XML_Status {
    XML_STATUS_ERROR = 0,
    XML_STATUS_OK    = 1
};

// callbacks

DECLARE_CALLBACK(
    void,
    XML_StartElementHandler,
    void*            userData,
    const XML_Char*  name,
    const XML_Char** atts);
DECLARE_CALLBACK(void, XML_EndElementHandler, void* userData, const XML_Char* name);
DECLARE_CALLBACK(void, XML_CharacterDataHandler, void* userData, const XML_Char* s, int32_t len);
DECLARE_CALLBACK(
    void,
    XML_ProcessingInstructionHandler,
    void*           userData,
    const XML_Char* target,
    const XML_Char* data);
DECLARE_CALLBACK(void, XML_CommentHandler, void* userData, const XML_Char* data);
DECLARE_CALLBACK(void, XML_StartCdataSectionHandler, void* userData);
DECLARE_CALLBACK(void, XML_EndCdataSectionHandler, void* userData);
DECLARE_CALLBACK(void, XML_DefaultHandler, void* userData, const XML_Char* s, int32_t len);
DECLARE_CALLBACK(
    void,
    XML_StartDoctypeDeclHandler,
    void*           userData,
    const XML_Char* doctypeName,
    const XML_Char* sysid,
    const XML_Char* pubid,
    int32_t         has_internal_subset);
DECLARE_CALLBACK(void, XML_EndDoctypeDeclHandler, void* userData);
DECLARE_CALLBACK(
    void,
    XML_EntityDeclHandler,
    void*           userData,
    const XML_Char* entityName,
    int32_t         is_parameter_entity,
    const XML_Char* value,
    int32_t         value_length,
    const XML_Char* base,
    const XML_Char* systemId,
    const XML_Char* publicId,
    const XML_Char* notationName);
DECLARE_CALLBACK(
    void,
    XML_UnparsedEntityDeclHandler,
    void*           userData,
    const XML_Char* entityName,
    const XML_Char* base,
    const XML_Char* systemId,
    const XML_Char* publicId,
    const XML_Char* notationName);
DECLARE_CALLBACK(
    void,
    XML_NotationDeclHandlerm,
    void*           userData,
    const XML_Char* notationName,
    const XML_Char* base,
    const XML_Char* systemId,
    const XML_Char* publicId);
DECLARE_CALLBACK(
    void,
    XML_StartNamespaceDeclHandler,
    void*           userData,
    const XML_Char* prefix,
    const XML_Char* uri);
DECLARE_CALLBACK(void, XML_EndNamespaceDeclHandler, void* userData, const XML_Char* prefix);
DECLARE_CALLBACK(int32_t, XML_NotStandaloneHandler, void* userData);
DECLARE_CALLBACK(
    int32_t,
    XML_ExternalEntityRefHandler,
    XML_Parser      parser,
    const XML_Char* context,
    const XML_Char* base,
    const XML_Char* systemId,
    const XML_Char* publicId);
DECLARE_CALLBACK(
    void,
    XML_SkippedEntityHandler,
    void*           userData,
    const XML_Char* entityName,
    int32_t         is_parameter_entity);
DECLARE_CALLBACK(
    void,
    XML_NotationDeclHandler,
    void*           userData,
    const XML_Char* notationName,
    const XML_Char* base,
    const XML_Char* systemId,
    const XML_Char* publicId);
DECLARE_CALLBACK(
    int32_t,
    XML_UnknownEncodingHandler,
    void*           encodingHandlerData,
    const XML_Char* name,
    XML_Encoding*   info);
DECLARE_CALLBACK(
    void,
    XML_ElementDeclHandler,
    void*           userData,
    const XML_Char* name,
    XML_Content*    model);
DECLARE_CALLBACK(
    void,
    XML_AttlistDeclHandler,
    void*           userData,
    const XML_Char* elname,
    const XML_Char* attname,
    const XML_Char* att_type,
    const XML_Char* dflt,
    int32_t         isrequired);
DECLARE_CALLBACK(
    void,
    XML_XmlDeclHandler,
    void*           userData,
    const XML_Char* version,
    const XML_Char* encoding,
    int32_t         standalone);

DECLARE_CALLBACK(int32_t, SCANNER, const ENCODING*, const char*, const char*, const char**);

// invention for convenience
DECLARE_CALLBACK(
    const ENCODING*,
    encoding_finder,
    const ENCODING* enc,
    const char*     ptr,
    const char*     end);

// invention for convenience - in reality, this is an anonymous callback
DECLARE_CALLBACK(int32_t, unknown_encoding__convert, void* userData, const char* p);

// gonna be lazy here and just define this as a callback
// In original Expat, Processor is a naked function prototype - not
// a pointer to a function.
DECLARE_CALLBACK(
    XML_Error,
    PProcessor,
    XML_Parser   parser,
    const char*  start,
    const char*  end,
    const char** endPtr);

// structs

struct POSITION {
    /* first line and first column are 0 not 1 */
    uint32_t lineNumber;
    uint32_t columnNumber;
};

struct ATTRIBUTE {
    const char* name;
    const char* valuePtr;
    const char* valueEnd;
    char        normalized;
};

// also known as: struct encoding
struct ENCODING {
    SCANNER scanners[4];
    SCANNER literalScanners[2];
    int32_t (*sameName)(const ENCODING*, const char*, const char*);
    int32_t (*nameMatchesAscii)(const ENCODING*, const char*, const char*, const char*);
    int32_t (*nameLength)(const ENCODING*, const char*);
    const char* (*skipS)(const ENCODING*, const char*);
    int32_t (*getAtts)(const ENCODING* enc, const char* ptr, int32_t attsMax, ATTRIBUTE* atts);
    int32_t (*charRefNumber)(const ENCODING* enc, const char* ptr);
    int32_t (*predefinedEntityName)(const ENCODING*, const char*, const char*);
    int32_t (*updatePosition)(const ENCODING*, const char* ptr, const char* end, POSITION*);
    int32_t (
        *isPublicId)(const ENCODING* enc, const char* ptr, const char* end, const char** badPtr);
    void (*utf8Convert)(
        const ENCODING* enc,
        const char**    fromP,
        const char*     fromLim,
        char**          toP,
        const char*     toLim);
    void (*utf16Convert)(
        const ENCODING* enc,
        const char**    fromP,
        const char*     fromLim,
        uint16_t**      toP,
        const uint16_t* toLim);
    int32_t minBytesPerChar;
    char    isUtf8;
    char    isUtf16;
};

struct INIT_ENCODING {
    ENCODING         initEnc;
    const ENCODING** encPtr;
};

struct PROLOG_STATE {
    int32_t (*handler)(
        PROLOG_STATE*   state,
        int32_t         tok,
        const char*     ptr,
        const char*     end,
        const ENCODING* enc);
    uint32_t level;
    int32_t  role_none;
    uint32_t includeLevel;
    int32_t  documentEntity;
    int32_t  inEntityValue;
};

struct NAMED {
    __expat__KEY name;
};

struct HASH_TABLE {
    NAMED**                    v;
    size_t                     size;
    size_t                     used;
    size_t                     usedLim;
    XML_Memory_Handling_Suite* mem;
};

struct HASH_TABLE_ITER {
    NAMED** p;
    NAMED** end;
};

struct BINDING {
    PREFIX*             prefix;
    BINDING*            nextTagBinding;
    BINDING*            prevPrefixBinding;
    const ATTRIBUTE_ID* attId;
    XML_Char*           uri;
    int32_t             uriLen;
    int32_t             uriAlloc;
};

struct PREFIX {
    const XML_Char* name;
    BINDING*        binding;
};

struct TAG_NAME {
    const XML_Char* str;
    const XML_Char* localPart;
    const XML_Char* prefix;
    int32_t         strLen;
    int32_t         uriLen;
    int32_t         prefixLen;
};

struct TAG {
    TAG*        parent;  /* parent of this element */
    const char* rawName; /* tagName in the original encoding */
    int32_t     rawNameLength;
    TAG_NAME    name;   /* tagName in the API encoding */
    char*       buf;    /* buffer for name components */
    char*       bufEnd; /* end of the buffer */
    BINDING*    bindings;
};

struct ENTITY {
    const XML_Char* name;
    const XML_Char* textPtr;
    int32_t         textLen;
    const XML_Char* systemId;
    const XML_Char* base;
    const XML_Char* publicId;
    const XML_Char* notation;
    XML_Bool        open;
    XML_Bool        is_param;
    XML_Bool        is_internal; /* true if declared in internal subset outside PE */
};

struct CONTENT_SCAFFOLD {
    XML_Content_Type  type;
    XML_Content_Quant quant;
    const XML_Char*   name;
    int32_t           firstchild;
    int32_t           lastchild;
    int32_t           childcnt;
    int32_t           nextsib;
};

struct BLOCK {
    BLOCK*   next;
    int32_t  size;
    XML_Char s[1];
};

struct STRING_POOL {
    BLOCK*                     blocks;
    BLOCK*                     freeBlocks;
    const XML_Char*            end;
    XML_Char*                  ptr;
    XML_Char*                  start;
    XML_Memory_Handling_Suite* mem;
};

/* The XML_Char before the name is used to determine whether
   an attribute has been specified. */
struct ATTRIBUTE_ID {
    XML_Char* name;
    PREFIX*   prefix;
    XML_Bool  maybeTokenized;
    XML_Bool  xmlns;
};

struct DEFAULT_ATTRIBUTE {
    const ATTRIBUTE_ID* id;
    XML_Bool            isCdata;
    const XML_Char*     value;
};

struct ELEMENT_TYPE {
    const XML_Char*     name;
    PREFIX*             prefix;
    const ATTRIBUTE_ID* idAtt;
    int32_t             nDefaultAtts;
    int32_t             allocDefaultAtts;
    DEFAULT_ATTRIBUTE*  defaultAtts;
};

struct DTD {
    HASH_TABLE  generalEntities;
    HASH_TABLE  elementTypes;
    HASH_TABLE  attributeIds;
    HASH_TABLE  prefixes;
    STRING_POOL pool;
    STRING_POOL entityValuePool;
    /* false once a parameter entity reference has been skipped */
    XML_Bool keepProcessing;
    /* true once an internal or external PE reference has been encountered;
       any external subset is considered an external PE reference */
    XML_Bool hasParamEntityRefs;
    XML_Bool standalone;
    /* indicates if external PE has been read */
    XML_Bool   paramEntityRead;
    HASH_TABLE paramEntities;
    PREFIX     defaultPrefix;
    /* === scaffolding for building content model === */
    XML_Bool          in_eldecl;
    CONTENT_SCAFFOLD* scaffold;
    uint32_t          contentStringLen;
    uint32_t          scaffSize;
    uint32_t          scaffCount;
    int32_t           scaffLevel;
    int32_t*          scaffIndex;
};

struct OPEN_INTERNAL_ENTITY {
    const char*           internalEventPtr;
    const char*           internalEventEndPtr;
    OPEN_INTERNAL_ENTITY* next;
    ENTITY*               entity;
};

struct XML_Encoding {
    int32_t map[256];
    void*   data;
    int32_t (*convert)(void* data, const char* s);
    void (*release)(void* data);
};

// also known as: struct XML_cp
struct XML_Content {
    XML_Content_Type  type;
    XML_Content_Quant quant;
    XML_Char*         name;
    uint32_t          numchildren;
    XML_Content*      children;
};

struct XML_Memory_Handling_Suite {
    void* (*malloc_fcn)(size_t size);
    void* (*realloc_fcn)(void* ptr, size_t size);
    void (*free_fcn)(void* ptr);
};

struct XML_ParserStruct {
    /* The first member must be userData so that the XML_GetUserData
       macro works. */
    void*                     m_userData;
    void*                     m_handlerArg;
    char*                     m_buffer;
    XML_Memory_Handling_Suite m_mem;
    /* first character to be parsed */
    const char* m_bufferPtr;
    /* past last character to be parsed */
    char* m_bufferEnd;
    /* allocated end of buffer */
    const char*                      m_bufferLim;
    int32_t                          m_parseEndByteIndex;
    const char*                      m_parseEndPtr;
    XML_Char*                        m_dataBuf;
    XML_Char*                        m_dataBufEnd;
    XML_StartElementHandler          m_startElementHandler;
    XML_EndElementHandler            m_endElementHandler;
    XML_CharacterDataHandler         m_characterDataHandler;
    XML_ProcessingInstructionHandler m_processingInstructionHandler;
    XML_CommentHandler               m_commentHandler;
    XML_StartCdataSectionHandler     m_startCdataSectionHandler;
    XML_EndCdataSectionHandler       m_endCdataSectionHandler;
    XML_DefaultHandler               m_defaultHandler;
    XML_StartDoctypeDeclHandler      m_startDoctypeDeclHandler;
    XML_EndDoctypeDeclHandler        m_endDoctypeDeclHandler;
    XML_UnparsedEntityDeclHandler    m_unparsedEntityDeclHandler;
    XML_NotationDeclHandler          m_notationDeclHandler;
    XML_StartNamespaceDeclHandler    m_startNamespaceDeclHandler;
    XML_EndNamespaceDeclHandler      m_endNamespaceDeclHandler;
    XML_NotStandaloneHandler         m_notStandaloneHandler;
    XML_ExternalEntityRefHandler     m_externalEntityRefHandler;
    void*                            m_externalEntityRefHandlerArg;
    XML_SkippedEntityHandler         m_skippedEntityHandler;
    XML_UnknownEncodingHandler       m_unknownEncodingHandler;
    XML_ElementDeclHandler           m_elementDeclHandler;
    XML_AttlistDeclHandler           m_attlistDeclHandler;
    XML_EntityDeclHandler            m_entityDeclHandler;
    XML_XmlDeclHandler               m_xmlDeclHandler;
    const ENCODING*                  m_encoding;
    INIT_ENCODING                    m_initEncoding;
    const ENCODING*                  m_internalEncoding;
    const XML_Char*                  m_protocolEncodingName;
    XML_Bool                         m_ns;
    XML_Bool                         m_ns_triplets;
    void*                            m_unknownEncodingMem;
    void*                            m_unknownEncodingData;
    void*                            m_unknownEncodingHandlerData;
    void (*m_unknownEncodingRelease)(void*);
    PROLOG_STATE           m_prologState;
    PProcessor             m_processor;
    XML_Error              m_errorCode;
    const char*            m_eventPtr;
    const char*            m_eventEndPtr;
    const char*            m_positionPtr;
    OPEN_INTERNAL_ENTITY*  m_openInternalEntities;
    XML_Bool               m_defaultExpandInternalEntities;
    int32_t                m_tagLevel;
    ENTITY*                m_declEntity;
    const XML_Char*        m_doctypeName;
    const XML_Char*        m_doctypeSysid;
    const XML_Char*        m_doctypePubid;
    const XML_Char*        m_declAttributeType;
    const XML_Char*        m_declNotationName;
    const XML_Char*        m_declNotationPublicId;
    ELEMENT_TYPE*          m_declElementType;
    ATTRIBUTE_ID*          m_declAttributeId;
    XML_Bool               m_declAttributeIsCdata;
    XML_Bool               m_declAttributeIsId;
    DTD                    m_dtd;
    const XML_Char*        m_curBase;
    TAG*                   m_tagStack;
    TAG*                   m_freeTagList;
    BINDING*               m_inheritedBindings;
    BINDING*               m_freeBindingList;
    int32_t                m_attsSize;
    int32_t                m_nSpecifiedAtts;
    int32_t                m_idAttIndex;
    ATTRIBUTE*             m_atts;
    POSITION               m_position;
    STRING_POOL            m_tempPool;
    STRING_POOL            m_temp2Pool;
    char*                  m_groupConnector;
    uint32_t               m_groupSize;
    XML_Char               m_namespaceSeparator;
    XML_Parser             m_parentParser;
    XML_Bool               m_isParamEntity;
    XML_Bool               m_useForeignDTD;
    XML_ParamEntityParsing m_paramEntityParsing;
};

struct normal_encoding {
    ENCODING enc;
    uint8_t  type[256];
    // #ifdef XML_MIN_SIZE
    //     int(FASTCALL* byteType)(const ENCODING*, const char*);
    //     int(FASTCALL* isNameMin)(const ENCODING*, const char*);
    //     int(FASTCALL* isNmstrtMin)(const ENCODING*, const char*);
    //     int(FASTCALL* byteToAscii)(const ENCODING*, const char*);
    //     int(FASTCALL* charMatches)(const ENCODING*, const char*, int);
    // #endif /* XML_MIN_SIZE */
    int32_t (*isName2)(const ENCODING*, const char*);
    int32_t (*isName3)(const ENCODING*, const char*);
    int32_t (*isName4)(const ENCODING*, const char*);
    int32_t (*isNmstrt2)(const ENCODING*, const char*);
    int32_t (*isNmstrt3)(const ENCODING*, const char*);
    int32_t (*isNmstrt4)(const ENCODING*, const char*);
    int32_t (*isInvalid2)(const ENCODING*, const char*);
    int32_t (*isInvalid3)(const ENCODING*, const char*);
    int32_t (*isInvalid4)(const ENCODING*, const char*);
};

struct unknown_encoding {
    normal_encoding           normal;
    unknown_encoding__convert convert;
    void*                     userData;
    uint16_t                  utf16[256];
    char                      utf8[256][4];
};

#endif
