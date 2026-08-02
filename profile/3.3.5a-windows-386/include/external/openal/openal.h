#ifndef OPEN_AL_OPEN_AL_H
#define OPEN_AL_OPEN_AL_H

// struct declarations

DECLARE_STRUCT(ALCdevice);
DECLARE_STRUCT(ALCcontext);
DECLARE_STRUCT(OPENALFNTABLE);

// enum declarations

// pointer types
typedef OPENALFNTABLE* LPOPENALFNTABLE;

// integral types

typedef int8_t   ALboolean;
typedef int8_t   ALchar;
typedef int8_t   ALCchar;
typedef int8_t   ALbyte;
typedef uint8_t  ALubyte;
typedef int16_t  ALshort;
typedef uint16_t ALushort;
typedef int32_t  ALint;
typedef uint32_t ALuint;
typedef int32_t  ALsizei;
typedef int32_t  ALenum;
typedef float    ALfloat;
typedef double   ALdouble;
typedef void     ALvoid;

typedef int8_t   ALCboolean;
typedef int8_t   ALCchar;
typedef int8_t   ALCbyte;
typedef uint8_t  ALCubyte;
typedef int16_t  ALCshort;
typedef uint16_t ALCushort;
typedef int32_t  ALCint;
typedef uint32_t ALCuint;
typedef int32_t  ALCsizei;
typedef int32_t  ALCenum;
typedef float    ALCfloat;
typedef double   ALCdouble;
typedef void     ALCvoid;

// callback types

DECLARE_CALLBACK(void, LPALENABLE, ALenum capability);
DECLARE_CALLBACK(void, LPALDISABLE, ALenum capability);
DECLARE_CALLBACK(ALboolean, LPALISENABLED, ALenum capability);
DECLARE_CALLBACK(const ALchar*, LPALGETSTRING, ALenum param);
DECLARE_CALLBACK(void, LPALGETBOOLEANV, ALenum param, ALboolean* data);
DECLARE_CALLBACK(void, LPALGETINTEGERV, ALenum param, ALint* data);
DECLARE_CALLBACK(void, LPALGETFLOATV, ALenum param, ALfloat* data);
DECLARE_CALLBACK(void, LPALGETDOUBLEV, ALenum param, ALdouble* data);
DECLARE_CALLBACK(ALboolean, LPALGETBOOLEAN, ALenum param);
DECLARE_CALLBACK(ALint, LPALGETINTEGER, ALenum param);
DECLARE_CALLBACK(ALfloat, LPALGETFLOAT, ALenum param);
DECLARE_CALLBACK(ALdouble, LPALGETDOUBLE, ALenum param);
DECLARE_CALLBACK(ALenum, LPALGETERROR);
DECLARE_CALLBACK(ALboolean, LPALISEXTENSIONPRESENT, const ALchar* extname);
DECLARE_CALLBACK(void*, LPALGETPROCADDRESS, const ALchar* fname);
DECLARE_CALLBACK(ALenum, LPALGETENUMVALUE, const ALchar* ename);
DECLARE_CALLBACK(void, LPALLISTENERF, ALenum param, ALfloat value);
DECLARE_CALLBACK(
    void,
    LPALLISTENER3F,
    ALenum  param,
    ALfloat value1,
    ALfloat value2,
    ALfloat value3);
DECLARE_CALLBACK(void, LPALLISTENERFV, ALenum param, const ALfloat* values);
DECLARE_CALLBACK(void, LPALLISTENERI, ALenum param, ALint value);
DECLARE_CALLBACK(void, LPALGETLISTENERF, ALenum param, ALfloat* value);
DECLARE_CALLBACK(
    void,
    LPALGETLISTENER3F,
    ALenum   param,
    ALfloat* value1,
    ALfloat* value2,
    ALfloat* value3);
DECLARE_CALLBACK(void, LPALGETLISTENERFV, ALenum param, ALfloat* values);
DECLARE_CALLBACK(void, LPALGETLISTENERI, ALenum param, ALint* value);
DECLARE_CALLBACK(void, LPALGENSOURCES, ALsizei n, ALuint* sources);
DECLARE_CALLBACK(void, LPALDELETESOURCES, ALsizei n, const ALuint* sources);
DECLARE_CALLBACK(ALboolean, LPALISSOURCE, ALuint sid);
DECLARE_CALLBACK(void, LPALSOURCEF, ALuint sid, ALenum param, ALfloat value);
DECLARE_CALLBACK(
    void,
    LPALSOURCE3F,
    ALuint  sid,
    ALenum  param,
    ALfloat value1,
    ALfloat value2,
    ALfloat value3);
DECLARE_CALLBACK(void, LPALSOURCEFV, ALuint sid, ALenum param, const ALfloat* values);
DECLARE_CALLBACK(void, LPALSOURCEI, ALuint sid, ALenum param, ALint value);
DECLARE_CALLBACK(void, LPALGETSOURCEF, ALuint sid, ALenum param, ALfloat* value);
DECLARE_CALLBACK(
    void,
    LPALGETSOURCE3F,
    ALuint   sid,
    ALenum   param,
    ALfloat* value1,
    ALfloat* value2,
    ALfloat* value3);
DECLARE_CALLBACK(void, LPALGETSOURCEFV, ALuint sid, ALenum param, ALfloat* values);
DECLARE_CALLBACK(void, LPALGETSOURCEI, ALuint sid, ALenum param, ALint* value);
DECLARE_CALLBACK(void, LPALSOURCEPLAYV, ALsizei ns, const ALuint* sids);
DECLARE_CALLBACK(void, LPALSOURCESTOPV, ALsizei ns, const ALuint* sids);
DECLARE_CALLBACK(void, LPALSOURCEREWINDV, ALsizei ns, const ALuint* sids);
DECLARE_CALLBACK(void, LPALSOURCEPAUSEV, ALsizei ns, const ALuint* sids);
DECLARE_CALLBACK(void, LPALSOURCEPLAY, ALuint sid);
DECLARE_CALLBACK(void, LPALSOURCESTOP, ALuint sid);
DECLARE_CALLBACK(void, LPALSOURCEREWIND, ALuint sid);
DECLARE_CALLBACK(void, LPALSOURCEPAUSE, ALuint sid);
DECLARE_CALLBACK(void, LPALSOURCEQUEUEBUFFERS, ALuint sid, ALsizei numEntries, const ALuint* bids);
DECLARE_CALLBACK(void, LPALSOURCEUNQUEUEBUFFERS, ALuint sid, ALsizei numEntries, ALuint* bids);
DECLARE_CALLBACK(void, LPALGENBUFFERS, ALsizei n, ALuint* buffers);
DECLARE_CALLBACK(void, LPALDELETEBUFFERS, ALsizei n, const ALuint* buffers);
DECLARE_CALLBACK(ALboolean, LPALISBUFFER, ALuint bid);
DECLARE_CALLBACK(
    void,
    LPALBUFFERDATA,
    ALuint        bid,
    ALenum        format,
    const ALvoid* data,
    ALsizei       size,
    ALsizei       freq);
DECLARE_CALLBACK(void, LPALGETBUFFERF, ALuint bid, ALenum param, ALfloat* value);
DECLARE_CALLBACK(void, LPALGETBUFFERI, ALuint bid, ALenum param, ALint* value);
DECLARE_CALLBACK(void, LPALDOPPLERFACTOR, ALfloat value);
DECLARE_CALLBACK(void, LPALDOPPLERVELOCITY, ALfloat value);
DECLARE_CALLBACK(void, LPALDISTANCEMODEL, ALenum distanceModel);

DECLARE_CALLBACK(ALCcontext*, LPALCCREATECONTEXT, ALCdevice* device, const ALCint* attrlist);
DECLARE_CALLBACK(ALCboolean, LPALCMAKECONTEXTCURRENT, ALCcontext* context);
DECLARE_CALLBACK(void, LPALCPROCESSCONTEXT, ALCcontext* context);
DECLARE_CALLBACK(void, LPALCSUSPENDCONTEXT, ALCcontext* context);
DECLARE_CALLBACK(void, LPALCDESTROYCONTEXT, ALCcontext* context);
DECLARE_CALLBACK(ALCcontext*, LPALCGETCURRENTCONTEXT);
DECLARE_CALLBACK(ALCdevice*, LPALCGETCONTEXTSDEVICE, ALCcontext* context);
DECLARE_CALLBACK(ALCdevice*, LPALCOPENDEVICE, const ALCchar* devicename);
DECLARE_CALLBACK(ALCboolean, LPALCCLOSEDEVICE, ALCdevice* device);
DECLARE_CALLBACK(ALCenum, LPALCGETERROR, ALCdevice* device);
DECLARE_CALLBACK(ALCboolean, LPALCISEXTENSIONPRESENT, ALCdevice* device, const ALCchar* extname);
DECLARE_CALLBACK(void*, LPALCGETPROCADDRESS, ALCdevice* device, const ALCchar* funcname);
DECLARE_CALLBACK(ALCenum, LPALCGETENUMVALUE, ALCdevice* device, const ALCchar* enumname);
DECLARE_CALLBACK(const ALCchar*, LPALCGETSTRING, ALCdevice* device, ALCenum param);
DECLARE_CALLBACK(
    void,
    LPALCGETINTEGERV,
    ALCdevice* device,
    ALCenum    param,
    ALCsizei   size,
    ALCint*    dest);
DECLARE_CALLBACK(void, LPALSPEEDOFSOUND, ALfloat value);

// structs
struct OPENALFNTABLE {
    LPALENABLE               alEnable;
    LPALDISABLE              alDisable;
    LPALISENABLED            alIsEnabled;
    LPALGETBOOLEAN           alGetBoolean;
    LPALGETINTEGER           alGetInteger;
    LPALGETFLOAT             alGetFloat;
    LPALGETDOUBLE            alGetDouble;
    LPALGETBOOLEANV          alGetBooleanv;
    LPALGETINTEGERV          alGetIntegerv;
    LPALGETFLOATV            alGetFloatv;
    LPALGETDOUBLEV           alGetDoublev;
    LPALGETSTRING            alGetString;
    LPALGETERROR             alGetError;
    LPALISEXTENSIONPRESENT   alIsExtensionPresent;
    LPALGETPROCADDRESS       alGetProcAddress;
    LPALGETENUMVALUE         alGetEnumValue;
    LPALLISTENERI            alListeneri;
    LPALLISTENERF            alListenerf;
    LPALLISTENER3F           alListener3f;
    LPALLISTENERFV           alListenerfv;
    LPALGETLISTENERI         alGetListeneri;
    LPALGETLISTENERF         alGetListenerf;
    LPALGETLISTENER3F        alGetListener3f;
    LPALGETLISTENERFV        alGetListenerfv;
    LPALGENSOURCES           alGenSources;
    LPALDELETESOURCES        alDeleteSources;
    LPALISSOURCE             alIsSource;
    LPALSOURCEI              alSourcei;
    LPALSOURCEF              alSourcef;
    LPALSOURCE3F             alSource3f;
    LPALSOURCEFV             alSourcefv;
    LPALGETSOURCEI           alGetSourcei;
    LPALGETSOURCEF           alGetSourcef;
    LPALGETSOURCEFV          alGetSourcefv;
    LPALSOURCEPLAYV          alSourcePlayv;
    LPALSOURCEPAUSEV         alSourcePausev;
    LPALSOURCESTOPV          alSourceStopv;
    LPALSOURCEPLAY           alSourcePlay;
    LPALSOURCEPAUSE          alSourcePause;
    LPALSOURCESTOP           alSourceStop;
    LPALGENBUFFERS           alGenBuffers;
    LPALDELETEBUFFERS        alDeleteBuffers;
    LPALISBUFFER             alIsBuffer;
    LPALBUFFERDATA           alBufferData;
    LPALGETBUFFERI           alGetBufferi;
    LPALGETBUFFERF           alGetBufferf;
    LPALSOURCEQUEUEBUFFERS   alSourceQueueBuffers;
    LPALSOURCEUNQUEUEBUFFERS alSourceUnqueueBuffers;
    LPALDISTANCEMODEL        alDistanceModel;
    LPALDOPPLERFACTOR        alDopplerFactor;
    LPALDOPPLERVELOCITY      alDopplerVelocity;
    LPALCGETSTRING           alcGetString;
    LPALCGETINTEGERV         alcGetIntegerv;
    LPALCOPENDEVICE          alcOpenDevice;
    LPALCCLOSEDEVICE         alcCloseDevice;
    LPALCCREATECONTEXT       alcCreateContext;
    LPALCMAKECONTEXTCURRENT  alcMakeContextCurrent;
    LPALCPROCESSCONTEXT      alcProcessContext;
    LPALCGETCURRENTCONTEXT   alcGetCurrentContext;
    LPALCGETCONTEXTSDEVICE   alcGetContextsDevice;
    LPALCSUSPENDCONTEXT      alcSuspendContext;
    LPALCDESTROYCONTEXT      alcDestroyContext;
    LPALCGETERROR            alcGetError;
    LPALCISEXTENSIONPRESENT  alcIsExtensionPresent;
    LPALCGETPROCADDRESS      alcGetProcAddress;
    LPALCGETENUMVALUE        alcGetEnumValue;

    LPALSPEEDOFSOUND alSpeedOfSound;
};

#endif
