#ifndef FMOD_FMOD_H
#define FMOD_FMOD_H

#include "external/asio/asio.h"
#include "external/d3d9/dsenum.h"
#include "external/d3d9/ikspropertyset.h"
#include "external/d3d9/sound.h"
#include "external/d3d9/sound3dbuffer.h"
#include "external/d3d9/sound3dlistener.h"
#include "external/d3d9/soundbuffer.h"
#include "external/d3d9/soundcapture.h"
#include "external/mmdeviceapi/audiocaptureclient.h"
#include "external/mmdeviceapi/audioclient.h"
#include "external/mmdeviceapi/audioclock.h"
#include "external/mmdeviceapi/audiorenderclient.h"
#include "external/openal/openal.h"
#include "external/srb/srb.h"
#include "external/win/acmstream.h"
#include "external/win/handle.h"
#include "external/win/hresult.h"
#include "external/win/stream.h"
#include "external/win/wavehandle.h"
#include "external/win/waveheader.h"
#include "external/wmsdk/wmprofile.h"
#include "external/wmsdk/wmsyncreader.h"
#include "fmod/flac.h"
#include "fmod/freeverb.h"
#include "fmod/vorbis.h"
#include "system/detect.h"

// struct declarations

DECLARE_STRUCT(ASfxDsp);
DECLARE_STRUCT(EAX50SESSIONPROPERTIES);
DECLARE_STRUCT(FMOD_AABB);
DECLARE_STRUCT(FMOD_ADVANCEDSETTINGS);
DECLARE_STRUCT(FMOD_CDDA_Caps);
DECLARE_STRUCT(FMOD_CDDA_DEVICE);
DECLARE_STRUCT(FMOD_CDDA_InquiryData);
DECLARE_STRUCT(FMOD_CDDA_NTSCSIDRIVE);
DECLARE_STRUCT(FMOD_CDDA_SenseKey);
DECLARE_STRUCT(FMOD_CDDA_StringList);
DECLARE_STRUCT(FMOD_CDDA_TOC);
DECLARE_STRUCT(FMOD_CDDA_TOC_flag);
DECLARE_STRUCT(FMOD_CDTOC);
DECLARE_STRUCT(FMOD_CHANNEL);
DECLARE_STRUCT(FMOD_CHANNELGROUP);
DECLARE_STRUCT(FMOD_CHANNEL_INFO);
DECLARE_STRUCT(FMOD_CODEC_DESCRIPTION);
DECLARE_STRUCT(FMOD_CODEC_DESCRIPTION_EX);
DECLARE_STRUCT(FMOD_CODEC_STATE); //
DECLARE_STRUCT(FMOD_CODEC_WAVEFORMAT);
DECLARE_STRUCT(FMOD_COMPLEX);
DECLARE_STRUCT(FMOD_CREATESOUNDEXINFO);
DECLARE_STRUCT(FMOD_DSP);
DECLARE_STRUCT(FMOD_DSP_DESCRIPTION);
DECLARE_STRUCT(FMOD_DSP_DESCRIPTION_EX);
DECLARE_STRUCT(FMOD_DSP_PARAMETERDESC);
DECLARE_STRUCT(FMOD_DSP_STATE);
DECLARE_STRUCT(FMOD_FSB_HEADER);
DECLARE_STRUCT(FMOD_FSB_SAMPLE_HEADER);
DECLARE_STRUCT(FMOD_FSB_SAMPLE_HEADER_BASIC);
DECLARE_STRUCT(FMOD_GEOMETRY);
DECLARE_STRUCT(FMOD_GUID); // TODO
DECLARE_STRUCT(FMOD_OS_CRITICALSECTION);
DECLARE_STRUCT(FMOD_OS_LIBRARY);
DECLARE_STRUCT(FMOD_OS_LIBRARY);
DECLARE_STRUCT(FMOD_OS_SEMAPHORE);
DECLARE_STRUCT(FMOD_OUTPUT_DESCRIPTION);
DECLARE_STRUCT(FMOD_OUTPUT_DESCRIPTION_EX);
DECLARE_STRUCT(FMOD_OUTPUT_STATE);
DECLARE_STRUCT(FMOD_POLYGON);
DECLARE_STRUCT(FMOD_RECORDING_INFO); // TODO
DECLARE_STRUCT(FMOD_REVERB_CHANNELDATA);
DECLARE_STRUCT(FMOD_REVERB_CHANNELPROPERTIES);
DECLARE_STRUCT(FMOD_REVERB_PROPERTIES); // TODO
DECLARE_STRUCT(FMOD_REVERB_STDPROPERTIES);
DECLARE_STRUCT(FMOD_SINT64P_words);
DECLARE_STRUCT(FMOD_SOUND);
DECLARE_STRUCT(FMOD_SOUNDGROUP);
DECLARE_STRUCT(FMOD_SPEAKERCONFIG);
DECLARE_STRUCT(FMOD_SYNCPOINT);
DECLARE_STRUCT(FMOD_SYSTEM);
DECLARE_STRUCT(FMOD_TAG);
DECLARE_STRUCT(FMOD_UINT64P_words);
DECLARE_STRUCT(FMOD_VECTOR);
DECLARE_STRUCT(FMOD_WASAPIDriver);
DECLARE_STRUCT(FMOD__AsyncData);
DECLARE_STRUCT(FMOD__AsyncThread);
DECLARE_STRUCT(FMOD__CROStream);
DECLARE_STRUCT(FMOD__CROStream__v_table);
DECLARE_STRUCT(FMOD__CddaFile);
DECLARE_STRUCT(FMOD__Channel);
DECLARE_STRUCT(FMOD__ChannelDSound);
DECLARE_STRUCT(FMOD__ChannelDSoundEAX2);
DECLARE_STRUCT(FMOD__ChannelDSoundEAX3);
DECLARE_STRUCT(FMOD__ChannelDSoundEAX4);
DECLARE_STRUCT(FMOD__ChannelEmulated);
DECLARE_STRUCT(FMOD__ChannelGroupI);
DECLARE_STRUCT(FMOD__ChannelI);
DECLARE_STRUCT(FMOD__ChannelMusic);
DECLARE_STRUCT(FMOD__ChannelOpenAL);
DECLARE_STRUCT(FMOD__ChannelOpenALEAX2);
DECLARE_STRUCT(FMOD__ChannelOpenALEAX3);
DECLARE_STRUCT(FMOD__ChannelOpenALEAX4);
DECLARE_STRUCT(FMOD__ChannelOpenALEAX5);
DECLARE_STRUCT(FMOD__ChannelOpenAL__v_table);
DECLARE_STRUCT(FMOD__ChannelPool);
DECLARE_STRUCT(FMOD__ChannelReal);
DECLARE_STRUCT(FMOD__ChannelRealManual3D);
DECLARE_STRUCT(FMOD__ChannelReal__v_table);
DECLARE_STRUCT(FMOD__ChannelSoftware);
DECLARE_STRUCT(FMOD__ChannelStream);
DECLARE_STRUCT(FMOD__Codec);
DECLARE_STRUCT(FMOD__CodecAIFF);
DECLARE_STRUCT(FMOD__CodecASF);
DECLARE_STRUCT(FMOD__CodecCDDA);
DECLARE_STRUCT(FMOD__CodecDLS);
DECLARE_STRUCT(FMOD__CodecDLSEnvelope);
DECLARE_STRUCT(FMOD__CodecDLSEnvelopePoint);
DECLARE_STRUCT(FMOD__CodecDLSInstrument);
DECLARE_STRUCT(FMOD__CodecDLSRegion);
DECLARE_STRUCT(FMOD__CodecDLSSample);
DECLARE_STRUCT(FMOD__CodecFLAC);
DECLARE_STRUCT(FMOD__CodecFSB);
DECLARE_STRUCT(FMOD__CodecFSBCache);
DECLARE_STRUCT(FMOD__CodecIT);
DECLARE_STRUCT(FMOD__CodecMIDI);
DECLARE_STRUCT(FMOD__CodecMIDIChannel);
DECLARE_STRUCT(FMOD__CodecMIDIDLSCache);
DECLARE_STRUCT(FMOD__CodecMIDISubChannel);
DECLARE_STRUCT(FMOD__CodecMIDITrack);
DECLARE_STRUCT(FMOD__CodecMOD);
DECLARE_STRUCT(FMOD__CodecMPEG);
DECLARE_STRUCT(FMOD__CodecMPEG_MemoryBlock);
DECLARE_STRUCT(FMOD__CodecOggVorbis);
DECLARE_STRUCT(FMOD__CodecPlaylist);
DECLARE_STRUCT(FMOD__CodecRaw);
DECLARE_STRUCT(FMOD__CodecS3M);
DECLARE_STRUCT(FMOD__CodecTag);
DECLARE_STRUCT(FMOD__CodecUser);
DECLARE_STRUCT(FMOD__CodecVAG);
DECLARE_STRUCT(FMOD__CodecVAG_Context);
DECLARE_STRUCT(FMOD__CodecWav);
DECLARE_STRUCT(FMOD__CodecXM);
DECLARE_STRUCT(FMOD__DLS_CONNECTIONBLOCK);
DECLARE_STRUCT(FMOD__DLS_INSTRUMENTHEADER);
DECLARE_STRUCT(FMOD__DLS_MIDILOCALE);
DECLARE_STRUCT(FMOD__DLS_REGIONHEADER);
DECLARE_STRUCT(FMOD__DLS_RGNRANGE);
DECLARE_STRUCT(FMOD__DLS_WAVELINK);
DECLARE_STRUCT(FMOD__DLS_WAVESAMPLE);
DECLARE_STRUCT(FMOD__DLS_WAVESAMPLELOOP);
DECLARE_STRUCT(FMOD__DSP);
DECLARE_STRUCT(FMOD__DSPChorus);
DECLARE_STRUCT(FMOD__DSPCodec);
DECLARE_STRUCT(FMOD__DSPCodecADPCM);
DECLARE_STRUCT(FMOD__DSPCodecMPEG);
DECLARE_STRUCT(FMOD__DSPCodecPool);
DECLARE_STRUCT(FMOD__DSPCodecRaw);
DECLARE_STRUCT(FMOD__DSPCompressor);
DECLARE_STRUCT(FMOD__DSPConnection);
DECLARE_STRUCT(FMOD__DSPConnectionPool);
DECLARE_STRUCT(FMOD__DSPConnectionRequest);
DECLARE_STRUCT(FMOD__DSPDistortion);
DECLARE_STRUCT(FMOD__DSPEcho);
DECLARE_STRUCT(FMOD__DSPFFT);
DECLARE_STRUCT(FMOD__DSPFilter);
DECLARE_STRUCT(FMOD__DSPFlange);
DECLARE_STRUCT(FMOD__DSPHighPass);
DECLARE_STRUCT(FMOD__DSPI);
DECLARE_STRUCT(FMOD__DSPITEcho);
DECLARE_STRUCT(FMOD__DSPI__v_table);
DECLARE_STRUCT(FMOD__DSPLowPass);
DECLARE_STRUCT(FMOD__DSPLowPass2);
DECLARE_STRUCT(FMOD__DSPLowPassSimple);
DECLARE_STRUCT(FMOD__DSPNet);
DECLARE_STRUCT(FMOD__DSPNet20);
DECLARE_STRUCT(FMOD__DSPNormalize);
DECLARE_STRUCT(FMOD__DSPOscillator);
DECLARE_STRUCT(FMOD__DSPParamEq);
DECLARE_STRUCT(FMOD__DSPPitchShift);
DECLARE_STRUCT(FMOD__DSPPitchShiftSMB);
DECLARE_STRUCT(FMOD__DSPResampler);
DECLARE_STRUCT(FMOD__DSPResamplerMultiInput);
DECLARE_STRUCT(FMOD__DSPReverb);
DECLARE_STRUCT(FMOD__DSPSfxReverb);
DECLARE_STRUCT(FMOD__DSPSoundCard);
DECLARE_STRUCT(FMOD__DSPWaveTable);
DECLARE_STRUCT(FMOD__DiskFile);
DECLARE_STRUCT(FMOD__File);
DECLARE_STRUCT(FMOD__FileThread);
DECLARE_STRUCT(FMOD__File__v_table);
DECLARE_STRUCT(FMOD__GeometryI);
DECLARE_STRUCT(FMOD__GeometryI__LineTestData);
DECLARE_STRUCT(FMOD__GeometryI__SpatialData);
DECLARE_STRUCT(FMOD__GeometryMgr);
DECLARE_STRUCT(FMOD__Global); // FMOD::Global
DECLARE_STRUCT(FMOD__III_sideinfo);
DECLARE_STRUCT(FMOD__III_sideinfo_ch);
DECLARE_STRUCT(FMOD__LOWPASS_BIQUAD);
DECLARE_STRUCT(FMOD__LevelsInfo);
DECLARE_STRUCT(FMOD__LinkedListNode); // FMOD::LinkedListNode
DECLARE_STRUCT(FMOD__Listener);
DECLARE_STRUCT(FMOD__LocalCriticalSection);
DECLARE_STRUCT(FMOD__LocalMemoryCounter);
DECLARE_STRUCT(FMOD__MIDI_CHUNK);
DECLARE_STRUCT(FMOD__MPEG_FRAME);
DECLARE_STRUCT(FMOD__MTHD_CHUNK);
DECLARE_STRUCT(FMOD__MemBlockHeader); // FMOD::MemBlockHeader
DECLARE_STRUCT(FMOD__MemPool);        // FMOD::MemPool
DECLARE_STRUCT(FMOD__MemSingleton);
DECLARE_STRUCT(FMOD__MemoryFile);
DECLARE_STRUCT(FMOD__Metadata);
DECLARE_STRUCT(FMOD__MusicChannel);
DECLARE_STRUCT(FMOD__MusicChannelIT);
DECLARE_STRUCT(FMOD__MusicChannelMOD);
DECLARE_STRUCT(FMOD__MusicChannelS3M);
DECLARE_STRUCT(FMOD__MusicChannelXM);
DECLARE_STRUCT(FMOD__MusicEnvelopeNode);
DECLARE_STRUCT(FMOD__MusicEnvelopeState);
DECLARE_STRUCT(FMOD__MusicInstrument);
DECLARE_STRUCT(FMOD__MusicNote);
DECLARE_STRUCT(FMOD__MusicPattern);
DECLARE_STRUCT(FMOD__MusicSample);
DECLARE_STRUCT(FMOD__MusicSong);
DECLARE_STRUCT(FMOD__MusicVirtualChannel);
DECLARE_STRUCT(FMOD__NetFile);
DECLARE_STRUCT(FMOD__NullFile);
DECLARE_STRUCT(FMOD__Octree);
DECLARE_STRUCT(FMOD__OctreeNode);
DECLARE_STRUCT(FMOD__Octree__RecursionData);
DECLARE_STRUCT(FMOD__Output); // FMOD::Output
DECLARE_STRUCT(FMOD__OutputASIO);
DECLARE_STRUCT(FMOD__OutputDSound);
DECLARE_STRUCT(FMOD__OutputEmulated);
DECLARE_STRUCT(FMOD__OutputNoSound); // FMOD::OutputNoSound
DECLARE_STRUCT(FMOD__OutputNoSound_NRT);
DECLARE_STRUCT(FMOD__OutputOpenAL);
DECLARE_STRUCT(FMOD__OutputPolled);
DECLARE_STRUCT(FMOD__OutputSoftware); // FMOD::OutputSoftware
DECLARE_STRUCT(FMOD__OutputSoftware__v_table);
DECLARE_STRUCT(FMOD__OutputTimer);
DECLARE_STRUCT(FMOD__OutputWASAPI);
DECLARE_STRUCT(FMOD__OutputWavWriter);
DECLARE_STRUCT(FMOD__OutputWavWriter_NRT);
DECLARE_STRUCT(FMOD__OutputWinMM);
DECLARE_STRUCT(FMOD__Output__v_table);
DECLARE_STRUCT(FMOD__Plugin);
DECLARE_STRUCT(FMOD__PluginFactory);
DECLARE_STRUCT(FMOD__Plugin__v_table);
DECLARE_STRUCT(FMOD__ReverbI);
DECLARE_STRUCT(FMOD__SFX_REVERB_LFPROPS);
DECLARE_STRUCT(FMOD__SNDMIXPLUGIN);
DECLARE_STRUCT(FMOD__SNDMIXPLUGININFO);
DECLARE_STRUCT(FMOD__Sample); // TODO
DECLARE_STRUCT(FMOD__SampleDSound);
DECLARE_STRUCT(FMOD__SampleOpenAL);
DECLARE_STRUCT(FMOD__SampleSoftware);
DECLARE_STRUCT(FMOD__Sample__v_table);
DECLARE_STRUCT(FMOD__SortedLinkedListNode); // FMOD::SortedLinkedListNode
DECLARE_STRUCT(FMOD__Sound);
DECLARE_STRUCT(FMOD__SoundBlock);
DECLARE_STRUCT(FMOD__SoundGroup);
DECLARE_STRUCT(FMOD__SoundGroupI);
DECLARE_STRUCT(FMOD__SoundI); // FMOD::SoundI
DECLARE_STRUCT(FMOD__SoundI__v_table);
DECLARE_STRUCT(FMOD__SoundSentenceEntry);
DECLARE_STRUCT(FMOD__SourceOpenAL);
DECLARE_STRUCT(FMOD__SpeakerLevelsPool);
DECLARE_STRUCT(FMOD__Stream);
DECLARE_STRUCT(FMOD__SyncPoint);
DECLARE_STRUCT(FMOD__System);
DECLARE_STRUCT(FMOD__SystemI); // FMOD::SystemI
DECLARE_STRUCT(FMOD__TagNode);
DECLARE_STRUCT(FMOD__Thread);
DECLARE_STRUCT(FMOD__Thread__v_table);
DECLARE_STRUCT(FMOD__TimeStamp);
DECLARE_STRUCT(FMOD__UserFile);
DECLARE_STRUCT(FMOD__al_table);
DECLARE_STRUCT(FMOD__bandInfoStruct);
DECLARE_STRUCT(FMOD__bitstream_info);
DECLARE_STRUCT(FMOD__gr_info_s);
DECLARE_STRUCT(I3DL2_LISTENERPROPERTIES);
DECLARE_STRUCT(WAVE_FORMATEX);
DECLARE_STRUCT(WAVE_FORMATEXTENSIBLE);
DECLARE_STRUCT(WAVE_FORMAT_IMAADPCM);
DECLARE_STRUCT(WAVE_SMPLHEADER);
DECLARE_STRUCT(WAVE_SMPLHEADER__Loop);
DECLARE_STRUCT(coeff2ndorder);

// union declarations

DECLARE_UNION(FMOD_SINT64P);
DECLARE_UNION(FMOD_UINT64P);
DECLARE_UNION(FMOD__ChannelReal__v_table_merged);
DECLARE_UNION(FMOD__Plugin__v_table_merged);
DECLARE_UNION(WAVE_FORMATEXTENSIBLE_Samples);

// enum declarations

DECLARE_ENUM(FMOD_CHANNELINDEX);
DECLARE_ENUM(FMOD_CHANNEL_CALLBACKTYPE);
DECLARE_ENUM(FMOD_CHANNEL_PANMODE);
DECLARE_ENUM(FMOD_DSPCONNECTIONREQUEST_CMD);
DECLARE_ENUM(FMOD_DSP_CATEGORY);
DECLARE_ENUM(FMOD_DSP_FFT_WINDOW);
DECLARE_ENUM(FMOD_DSP_RESAMPLER);
DECLARE_ENUM(FMOD_DSP_TYPE);
DECLARE_ENUM(FMOD_OPENSTATE);
DECLARE_ENUM(FMOD_OUTPUTTYPE);
DECLARE_ENUM(FMOD_PLUGINTYPE);
DECLARE_ENUM(FMOD_RESAMPLER_END);
DECLARE_ENUM(FMOD_RESULT);
DECLARE_ENUM(FMOD_REVERB_MODE);
DECLARE_ENUM(FMOD_SOUNDGROUP_BEHAVIOR);
DECLARE_ENUM(FMOD_SOUND_FORMAT);
DECLARE_ENUM(FMOD_SOUND_TYPE);
DECLARE_ENUM(FMOD_SPEAKER);
DECLARE_ENUM(FMOD_SPEAKERMAPTYPE);
DECLARE_ENUM(FMOD_SPEAKERMODE);
DECLARE_ENUM(FMOD_SYSTEM_CALLBACKTYPE);
DECLARE_ENUM(FMOD_TAGDATATYPE);
DECLARE_ENUM(FMOD_TAGTYPE);
DECLARE_ENUM(FMOD_THREAD_PRIORITY);
DECLARE_ENUM(FMOD__CODEC_DLS_ENVPOINT);
DECLARE_ENUM(FMOD__CONN_SRC_FLAGS);
DECLARE_ENUM(FMOD__DSPRESAMPLER_SPEEDDIR);
DECLARE_ENUM(FMOD__DSPWAVETABLE_SPEEDDIR);
DECLARE_ENUM(FMOD__MIDI_FORMAT);
DECLARE_ENUM(FMOD__REVERB_VERSION);
DECLARE_ENUM(FMOD__Thead__PRIORITY); // FMOD::Thread::PRIORITY
DECLARE_ENUM(FMOD__CHANNELREAL_PLAYDIR);

// integral types

typedef int32_t FMOD_BOOL;

typedef int64_t  FMOD_SINT64;
typedef uint64_t FMOD_UINT64;

typedef uintptr_t FMOD_UINT_NATIVE;
typedef intptr_t  FMOD_SINT_NATIVE;

typedef float FMOD_FLOAT;
typedef float FMOD_UFLOAT;
typedef float FMOD_FLOAT64;
typedef float FMOD_UFLOAT64;

typedef uint32_t FMOD_MODE;
typedef uint32_t FMOD_TIMEUNIT;
typedef uint32_t FMOD_INITFLAGS;
typedef uint32_t FMOD_CAPS;

typedef uint32_t FMOD_DEBUGLEVEL;
typedef uint32_t FMOD_MEMORY_TYPE;

typedef uint32_t FMOD_SOUND_FLAG;

typedef uint32_t FMOD__CHANNELREAL_FLAG;

typedef uint32_t FMOD_CHANNEL_FLAG;
typedef uint32_t FMOD_CHANNEL_STOPFLAG;

typedef uint32_t FMOD_CODEC_FLAG;

// type aliases

// enums

enum FMOD_RESULT {
    FMOD_OK,                /* No errors. */
    FMOD_ERR_ALREADYLOCKED, /* Tried to call lock a second time before unlock was called. */
    FMOD_ERR_BADCOMMAND, /* Tried to call a function on a data type that does not allow this type of functionality (ie calling Sound::lock on a streaming sound). */
    FMOD_ERR_CDDA_DRIVERS,        /* Neither NTSCSI nor ASPI could be initialised. */
    FMOD_ERR_CDDA_INIT,           /* An error occurred while initialising the CDDA subsystem. */
    FMOD_ERR_CDDA_INVALID_DEVICE, /* Couldn't find the specified device. */
    FMOD_ERR_CDDA_NOAUDIO,        /* No audio tracks on the specified disc. */
    FMOD_ERR_CDDA_NODEVICES,      /* No CD/DVD devices were found. */
    FMOD_ERR_CDDA_NODISC,         /* No disc present in the specified drive. */
    FMOD_ERR_CDDA_READ,           /* A CDDA read error occurred. */
    FMOD_ERR_CHANNEL_ALLOC,       /* Error trying to allocate a channel. */
    FMOD_ERR_CHANNEL_STOLEN,      /* The specified channel has been reused to play another sound. */
    FMOD_ERR_COM, /* A Win32 COM related error occured. COM failed to initialize or a QueryInterface failed meaning a Windows codec or driver was not installed properly. */
    FMOD_ERR_DMA, /* DMA Failure.  See debug output for more information. */
    FMOD_ERR_DSP_CONNECTION, /* DSP connection error.  Connection possibly caused a cyclic dependancy. */
    FMOD_ERR_DSP_FORMAT, /* DSP Format error.  A DSP unit may have attempted to connect to this network with the wrong format. */
    FMOD_ERR_DSP_NOTFOUND, /* DSP connection error.  Couldn't find the DSP unit specified. */
    FMOD_ERR_DSP_RUNNING, /* DSP error.  Cannot perform this operation while the network is in the middle of running.  This will most likely happen if a connection or disconnection is attempted in a DSP callback. */
    FMOD_ERR_DSP_TOOMANYCONNECTIONS, /* DSP connection error.  The unit being connected to or disconnected should only have 1 input or output. */
    FMOD_ERR_FILE_BAD,               /* Error loading file. */
    FMOD_ERR_FILE_COULDNOTSEEK, /* Couldn't perform seek operation.  This is a limitation of the medium (ie netstreams) or the file format. */
    FMOD_ERR_FILE_DISKEJECTED,  /* Media was ejected while reading. */
    FMOD_ERR_FILE_EOF, /* End of file unexpectedly reached while trying to read essential data (truncated data?). */
    FMOD_ERR_FILE_NOTFOUND, /* File not found. */
    FMOD_ERR_FILE_UNWANTED, /* Unwanted file access occured. */
    FMOD_ERR_FORMAT,        /* Unsupported file or audio format. */
    FMOD_ERR_HTTP, /* A HTTP error occurred. This is a catch-all for HTTP errors not listed elsewhere. */
    FMOD_ERR_HTTP_ACCESS,     /* The specified resource requires authentication or is forbidden. */
    FMOD_ERR_HTTP_PROXY_AUTH, /* Proxy authentication is required to access the specified resource. */
    FMOD_ERR_HTTP_SERVER_ERROR, /* A HTTP server error occurred. */
    FMOD_ERR_HTTP_TIMEOUT,      /* The HTTP request timed out. */
    FMOD_ERR_INITIALIZATION,    /* FMOD was not initialized correctly to support this function. */
    FMOD_ERR_INITIALIZED,       /* Cannot call this command after System::init. */
    FMOD_ERR_INTERNAL,          /* An error occured that wasn't supposed to.  Contact support. */
    FMOD_ERR_INVALID_ADDRESS, /* On Xbox 360, this memory address passed to FMOD must be physical, (ie allocated with XPhysicalAlloc.) */
    FMOD_ERR_INVALID_FLOAT,   /* Value passed in was a NaN, Inf or denormalized float. */
    FMOD_ERR_INVALID_HANDLE,  /* An invalid object handle was used. */
    FMOD_ERR_INVALID_PARAM,   /* An invalid parameter was passed to this function. */
    FMOD_ERR_INVALID_SPEAKER, /* An invalid speaker was passed to this function based on the current speaker mode. */
    FMOD_ERR_INVALID_VECTOR, /* The vectors passed in are not unit length, or perpendicular. */
    FMOD_ERR_IRX, /* PS2 only.  fmodex.irx failed to initialize.  This is most likely because you forgot to load it. */
    FMOD_ERR_MAXAUDIBLE,  /* Reached maximum audible playback count for this sound's soundgroup. */
    FMOD_ERR_MEMORY,      /* Not enough memory or resources. */
    FMOD_ERR_MEMORY_IOP,  /* PS2 only.  Not enough memory or resources on PlayStation 2 IOP ram. */
    FMOD_ERR_MEMORY_SRAM, /* Not enough memory or resources on console sound ram. */
    FMOD_ERR_MEMORY_CANTPOINT, /* Can't use FMOD_OPENMEMORY_POINT on non PCM source data, or non mp3/xma/adpcm data if FMOD_CREATECOMPRESSEDSAMPLE was used. */
    FMOD_ERR_NEEDS2D, /* Tried to call a command on a 3d sound when the command was meant for 2d sound. */
    FMOD_ERR_NEEDS3D, /* Tried to call a command on a 2d sound when the command was meant for 3d sound. */
    FMOD_ERR_NEEDSHARDWARE, /* Tried to use a feature that requires hardware support.  (ie trying to play a VAG compressed sound in software on PS2). */
    FMOD_ERR_NEEDSSOFTWARE, /* Tried to use a feature that requires the software engine.  Software engine has either been turned off, or command was executed on a hardware channel which does not support this feature. */
    FMOD_ERR_NET_CONNECT,   /* Couldn't connect to the specified host. */
    FMOD_ERR_NET_SOCKET_ERROR, /* A socket error occurred.  This is a catch-all for socket-related errors not listed elsewhere. */
    FMOD_ERR_NET_URL,         /* The specified URL couldn't be resolved. */
    FMOD_ERR_NET_WOULD_BLOCK, /* Operation on a non-blocking socket could not complete immediately. */
    FMOD_ERR_NOTREADY, /* Operation could not be performed because specified sound is not ready. */
    FMOD_ERR_OUTPUT_ALLOCATED, /* Error initializing output device, but more specifically, the output device is already in use and cannot be reused. */
    FMOD_ERR_OUTPUT_CREATEBUFFER, /* Error creating hardware sound buffer. */
    FMOD_ERR_OUTPUT_DRIVERCALL, /* A call to a standard soundcard driver failed, which could possibly mean a bug in the driver or resources were missing or exhausted. */
    FMOD_ERR_OUTPUT_FORMAT, /* Soundcard does not support the minimum features needed for this soundsystem (16bit stereo output). */
    FMOD_ERR_OUTPUT_INIT,   /* Error initializing output device. */
    FMOD_ERR_OUTPUT_NOHARDWARE, /* FMOD_HARDWARE was specified but the sound card does not have the resources nescessary to play it. */
    FMOD_ERR_OUTPUT_NOSOFTWARE, /* Attempted to create a software sound but no software channels were specified in System::init. */
    FMOD_ERR_PAN,            /* Panning only works with mono or stereo sound sources. */
    FMOD_ERR_PLUGIN,         /* An unspecified error has been returned from a 3rd party plugin. */
    FMOD_ERR_PLUGIN_MISSING, /* A requested output, dsp unit type or codec was not available. */
    FMOD_ERR_PLUGIN_RESOURCE, /* A resource that the plugin requires cannot be found. (ie the DLS file for MIDI playback) */
    FMOD_ERR_PLUGIN_INSTANCES, /* The number of allowed instances of a plugin has been exceeded. */
    FMOD_ERR_RECORD,           /* An error occured trying to initialize the recording device. */
    FMOD_ERR_REVERB_INSTANCE, /* Specified Instance in FMOD_REVERB_PROPERTIES couldn't be set. Most likely because another application has locked the EAX4 FX slot. */
    FMOD_ERR_SUBSOUNDS, /* The error occured because the sound referenced contains subsounds.  (ie you cannot play the parent sound as a static sample, only its subsounds.) */
    FMOD_ERR_SUBSOUND_ALLOCATED, /* This subsound is already being used by another sound, you cannot have more than one parent to a sound.  Null out the other parent's entry first. */
    FMOD_ERR_TAGNOTFOUND,        /* The specified tag could not be found or there are no tags. */
    FMOD_ERR_TOOMANYCHANNELS, /* The sound created exceeds the allowable input channel count.  This can be increased using the maxinputchannels parameter in System::setSoftwareFormat. */
    FMOD_ERR_UNIMPLEMENTED, /* Something in FMOD hasn't been implemented when it should be! contact support! */
    FMOD_ERR_UNINITIALIZED, /* This command failed because System::init or System::setDriver was not called. */
    FMOD_ERR_UNSUPPORTED, /* A command issued was not supported by this object.  Possibly a plugin without certain callbacks specified. */
    FMOD_ERR_UPDATE,      /* An error caused by System::update occured. */
    FMOD_ERR_VERSION,     /* The version number of this file format is not supported. */

    FMOD_ERR_EVENT_FAILED, /* An Event failed to be retrieved, most likely due to 'just fail' being specified as the max playbacks behavior. */
    FMOD_ERR_EVENT_INTERNAL, /* An error occured that wasn't supposed to.  See debug log for reason. */
    FMOD_ERR_EVENT_INFOONLY, /* Can't execute this command on an EVENT_INFOONLY event. */
    FMOD_ERR_EVENT_MAXSTREAMS, /* Event failed because 'Max streams' was hit when FMOD_INIT_FAIL_ON_MAXSTREAMS was specified. */
    FMOD_ERR_EVENT_MISMATCH,     /* FSB mis-matches the FEV it was compiled with. */
    FMOD_ERR_EVENT_NAMECONFLICT, /* A category with the same name already exists. */
    FMOD_ERR_EVENT_NOTFOUND, /* The requested event, event group, event category or event property could not be found. */

    FMOD_RESULT_FORCEINT = 65536 /* Makes sure this enum is signed 32bit. */
};

enum FMOD_CHANNEL_CALLBACKTYPE {
    FMOD_CHANNEL_CALLBACKTYPE_END,          /* Called when a sound ends. */
    FMOD_CHANNEL_CALLBACKTYPE_VIRTUALVOICE, /* Called when a voice is swapped out or swapped in. */
    FMOD_CHANNEL_CALLBACKTYPE_SYNCPOINT, /* Called when a syncpoint is encountered.  Can be from wav
                                            file markers. */

    FMOD_CHANNEL_CALLBACKTYPE_MAX,             /* Maximum number of callback types supported. */
    FMOD_CHANNEL_CALLBACKTYPE_FORCEINT = 65536 /* Makes sure this enum is signed 32bit. */
};

enum FMOD_SOUND_TYPE {
    FMOD_SOUND_TYPE_UNKNOWN,   /* 3rd party / unknown plugin format. */
    FMOD_SOUND_TYPE_AAC,       /* AAC.  Currently unsupported. */
    FMOD_SOUND_TYPE_AIFF,      /* AIFF. */
    FMOD_SOUND_TYPE_ASF,       /* Microsoft Advanced Systems Format (ie WMA/ASF/WMV). */
    FMOD_SOUND_TYPE_AT3,       /* Sony ATRAC 3 format */
    FMOD_SOUND_TYPE_CDDA,      /* Digital CD audio. */
    FMOD_SOUND_TYPE_DLS,       /* Sound font / downloadable sound bank. */
    FMOD_SOUND_TYPE_FLAC,      /* FLAC lossless codec. */
    FMOD_SOUND_TYPE_FSB,       /* FMOD Sample Bank. */
    FMOD_SOUND_TYPE_GCADPCM,   /* GameCube ADPCM */
    FMOD_SOUND_TYPE_IT,        /* Impulse Tracker. */
    FMOD_SOUND_TYPE_MIDI,      /* MIDI. */
    FMOD_SOUND_TYPE_MOD,       /* Protracker / Fasttracker MOD. */
    FMOD_SOUND_TYPE_MPEG,      /* MP2/MP3 MPEG. */
    FMOD_SOUND_TYPE_OGGVORBIS, /* Ogg vorbis. */
    FMOD_SOUND_TYPE_PLAYLIST,  /* Information only from ASX/PLS/M3U/WAX playlists */
    FMOD_SOUND_TYPE_RAW,       /* Raw PCM data. */
    FMOD_SOUND_TYPE_S3M,       /* ScreamTracker 3. */
    FMOD_SOUND_TYPE_SF2,       /* Sound font 2 format. */
    FMOD_SOUND_TYPE_USER,      /* User created sound. */
    FMOD_SOUND_TYPE_WAV,       /* Microsoft WAV. */
    FMOD_SOUND_TYPE_XM,        /* FastTracker 2 XM. */
    FMOD_SOUND_TYPE_XMA,       /* Xbox360 XMA */
    FMOD_SOUND_TYPE_VAG,       /* PlayStation 2 / PlayStation Portable adpcm VAG format. */

    FMOD_SOUND_TYPE_MAX,             /* Maximum number of sound types supported. */
    FMOD_SOUND_TYPE_FORCEINT = 65536 /* Makes sure this enum is signed 32bit. */
};

enum FMOD_SOUND_FORMAT {
    FMOD_SOUND_FORMAT_NONE,     /* Unitialized / unknown. */
    FMOD_SOUND_FORMAT_PCM8,     /* 8bit integer PCM data. */
    FMOD_SOUND_FORMAT_PCM16,    /* 16bit integer PCM data.  */
    FMOD_SOUND_FORMAT_PCM24,    /* 24bit integer PCM data.  */
    FMOD_SOUND_FORMAT_PCM32,    /* 32bit integer PCM data.  */
    FMOD_SOUND_FORMAT_PCMFLOAT, /* 32bit floating point PCM data.  */
    FMOD_SOUND_FORMAT_GCADPCM,  /* Compressed GameCube DSP data. */
    FMOD_SOUND_FORMAT_IMAADPCM, /* Compressed IMA ADPCM / Xbox ADPCM data. */
    FMOD_SOUND_FORMAT_VAG,      /* Compressed PlayStation 2 / PlayStation Portable ADPCM data. */
    FMOD_SOUND_FORMAT_XMA,      /* Compressed Xbox360 data. */
    FMOD_SOUND_FORMAT_MPEG,     /* Compressed MPEG layer 2 or 3 data. */

    FMOD_SOUND_FORMAT_MAX,             /* Maximum number of sound formats supported. */
    FMOD_SOUND_FORMAT_FORCEINT = 65536 /* Makes sure this enum is signed 32bit. */
};

enum FMOD_TAGTYPE {
    FMOD_TAGTYPE_UNKNOWN = 0,
    FMOD_TAGTYPE_ID3V1,
    FMOD_TAGTYPE_ID3V2,
    FMOD_TAGTYPE_VORBISCOMMENT,
    FMOD_TAGTYPE_SHOUTCAST,
    FMOD_TAGTYPE_ICECAST,
    FMOD_TAGTYPE_ASF,
    FMOD_TAGTYPE_MIDI,
    FMOD_TAGTYPE_PLAYLIST,
    FMOD_TAGTYPE_FMOD,
    FMOD_TAGTYPE_USER,

    FMOD_TAGTYPE_MAX,             /* Maximum number of tag types supported. */
    FMOD_TAGTYPE_FORCEINT = 65536 /* Makes sure this enum is signed 32bit. */
};

enum FMOD_TAGDATATYPE {
    FMOD_TAGDATATYPE_BINARY = 0,
    FMOD_TAGDATATYPE_INT,
    FMOD_TAGDATATYPE_FLOAT,
    FMOD_TAGDATATYPE_STRING,
    FMOD_TAGDATATYPE_STRING_UTF16,
    FMOD_TAGDATATYPE_STRING_UTF16BE,
    FMOD_TAGDATATYPE_STRING_UTF8,
    FMOD_TAGDATATYPE_CDTOC,

    FMOD_TAGDATATYPE_MAX,             /* Maximum number of tag datatypes supported. */
    FMOD_TAGDATATYPE_FORCEINT = 65536 /* Makes sure this enum is signed 32bit. */
};

enum FMOD_SPEAKERMAPTYPE {
    FMOD_SPEAKERMAPTYPE_DEFAULT,
    FMOD_SPEAKERMAPTYPE_ALLMONO,
    FMOD_SPEAKERMAPTYPE_ALLSTEREO
};

enum FMOD_OPENSTATE {
    FMOD_OPENSTATE_READY = 0, /* Opened and ready to play. */
    FMOD_OPENSTATE_LOADING,   /* Initial load in progress. */
    FMOD_OPENSTATE_ERROR, /* Failed to open - file not found, out of memory etc.  See return value of Sound::getOpenState for what happened. */
    FMOD_OPENSTATE_CONNECTING,      /* Connecting to remote host (internet sounds only). */
    FMOD_OPENSTATE_BUFFERING,       /* Buffering data. */
    FMOD_OPENSTATE_SEEKING,         /* Seeking to subsound and re-flushing stream buffer. */
    FMOD_OPENSTATE_MAX,             /* Maximum number of open state types. */
    FMOD_OPENSTATE_FORCEINT = 65536 /* Makes sure this enum is signed 32bit. */
};

enum FMOD_OUTPUTTYPE {
    FMOD_OUTPUTTYPE_AUTODETECT, /* Picks the best output mode for the platform.  This is the default. */

    FMOD_OUTPUTTYPE_UNKNOWN, /* All         - 3rd party plugin, unknown.  This is for use with System::getOutput only. */
    FMOD_OUTPUTTYPE_NOSOUND,   /* All         - All calls in this mode succeed but make no sound. */
    FMOD_OUTPUTTYPE_WAVWRITER, /* All         - Writes output to fmodoutput.wav by default.  Use the 'extradriverdata' parameter in System::init, by simply passing the filename as a string, to set the wav filename. */
    FMOD_OUTPUTTYPE_NOSOUND_NRT, /* All         - Non-realtime version of FMOD_OUTPUTTYPE_NOSOUND.  User can drive mixer with System::update at whatever rate they want. */
    FMOD_OUTPUTTYPE_WAVWRITER_NRT, /* All         - Non-realtime version of FMOD_OUTPUTTYPE_WAVWRITER.  User can drive mixer with System::update at whatever rate they want. */

    FMOD_OUTPUTTYPE_DSOUND, /* Win32/Win64 - DirectSound output.  Use this to get hardware accelerated 3d audio and EAX Reverb support. (Default on Windows) */
    FMOD_OUTPUTTYPE_WINMM,  /* Win32/Win64 - Windows Multimedia output. */
    FMOD_OUTPUTTYPE_OPENAL, /* Win32/Win64 - OpenAL 1.1 output. Use this for lower CPU overhead than FMOD_OUTPUTTYPE_DSOUND, and also Vista H/W support with Creative Labs cards. */
    FMOD_OUTPUTTYPE_WASAPI, /* Win32       - Windows Audio Session API. (Default on Windows Vista) */
    FMOD_OUTPUTTYPE_ASIO,   /* Win32       - Low latency ASIO driver. */
    FMOD_OUTPUTTYPE_OSS,    /* Linux       - Open Sound System output. (Default on Linux) */
    FMOD_OUTPUTTYPE_ALSA,   /* Linux       - Advanced Linux Sound Architecture output. */
    FMOD_OUTPUTTYPE_ESD,    /* Linux       - Enlightment Sound Daemon output. */
    FMOD_OUTPUTTYPE_SOUNDMANAGER, /* Mac         - Macintosh SoundManager output.  (Default on Mac carbon library)*/
    FMOD_OUTPUTTYPE_COREAUDIO, /* Mac         - Macintosh CoreAudio output.  (Default on Mac OSX library) */
    FMOD_OUTPUTTYPE_XBOX,    /* Xbox        - Native hardware output. (Default on Xbox) */
    FMOD_OUTPUTTYPE_PS2,     /* PS2         - Native hardware output. (Default on PS2) */
    FMOD_OUTPUTTYPE_PS3,     /* PS3         - Native hardware output. (Default on PS3) */
    FMOD_OUTPUTTYPE_GC,      /* GameCube    - Native hardware output. (Default on GameCube) */
    FMOD_OUTPUTTYPE_XBOX360, /* Xbox 360    - Native hardware output. (Default on Xbox 360) */
    FMOD_OUTPUTTYPE_PSP,     /* PSP         - Native hardware output. (Default on PSP) */
    FMOD_OUTPUTTYPE_WII,     /* Wii			- Native hardware output. (Default on Wii) */

    FMOD_OUTPUTTYPE_MAX,             /* Maximum number of output types supported. */
    FMOD_OUTPUTTYPE_FORCEINT = 65536 /* Makes sure this enum is signed 32bit. */
};

enum FMOD_SPEAKERMODE {
    FMOD_SPEAKERMODE_RAW, /* There is no specific speakermode.  Sound channels are mapped in order of input to output.  Use System::setSoftwareFormat to specify speaker count. See remarks for more information. */
    FMOD_SPEAKERMODE_MONO,   /* The speakers are monaural. */
    FMOD_SPEAKERMODE_STEREO, /* The speakers are stereo (DEFAULT). */
    FMOD_SPEAKERMODE_QUAD, /* 4 speaker setup.  This includes front left, front right, rear left, rear right.  */
    FMOD_SPEAKERMODE_SURROUND, /* 5 speaker setup.  This includes front left, front right, center, rear left, rear right. */
    FMOD_SPEAKERMODE_5POINT1, /* 5.1 speaker setup.  This includes front left, front right, center, rear left, rear right and a subwoofer. */
    FMOD_SPEAKERMODE_7POINT1, /* 7.1 speaker setup.  This includes front left, front right, center, rear left, rear right, side left, side right and a subwoofer. */
    FMOD_SPEAKERMODE_PROLOGIC, /* Stereo output, but data is encoded in a way that is picked up by a Prologic/Prologic2 decoder and split into a 5.1 speaker setup. */

    FMOD_SPEAKERMODE_MAX,             /* Maximum number of speaker modes supported. */
    FMOD_SPEAKERMODE_FORCEINT = 65536 /* Makes sure this enum is signed 32bit. */
};

enum FMOD_DSP_TYPE {
    FMOD_DSP_TYPE_UNKNOWN, /* This unit was created via a non FMOD plugin so has an unknown purpose. */
    FMOD_DSP_TYPE_MIXER, /* This unit does nothing but take inputs and mix them together then feed the result to the soundcard unit. */
    FMOD_DSP_TYPE_OSCILLATOR, /* This unit generates sine/square/saw/triangle or noise tones. */
    FMOD_DSP_TYPE_LOWPASS, /* This unit filters sound using a high quality, resonant lowpass filter algorithm but consumes more CPU time. */
    FMOD_DSP_TYPE_ITLOWPASS, /* This unit filters sound using a resonant lowpass filter algorithm that is used in Impulse Tracker, but with limited cutoff range (0 to 8060hz). */
    FMOD_DSP_TYPE_HIGHPASS, /* This unit filters sound using a resonant highpass filter algorithm. */
    FMOD_DSP_TYPE_ECHO, /* This unit produces an echo on the sound and fades out at the desired rate. */
    FMOD_DSP_TYPE_FLANGE,     /* This unit produces a flange effect on the sound. */
    FMOD_DSP_TYPE_DISTORTION, /* This unit distorts the sound. */
    FMOD_DSP_TYPE_NORMALIZE,  /* This unit normalizes or amplifies the sound to a certain level. */
    FMOD_DSP_TYPE_PARAMEQ,    /* This unit attenuates or amplifies a selected frequency range. */
    FMOD_DSP_TYPE_PITCHSHIFT, /* This unit bends the pitch of a sound without changing the speed of playback. */
    FMOD_DSP_TYPE_CHORUS,       /* This unit produces a chorus effect on the sound. */
    FMOD_DSP_TYPE_REVERB,       /* This unit produces a reverb effect on the sound. */
    FMOD_DSP_TYPE_VSTPLUGIN,    /* This unit allows the use of Steinberg VST plugins */
    FMOD_DSP_TYPE_WINAMPPLUGIN, /* This unit allows the use of Nullsoft Winamp plugins */
    FMOD_DSP_TYPE_ITECHO, /* This unit produces an echo on the sound and fades out at the desired rate as is used in Impulse Tracker. */
    FMOD_DSP_TYPE_COMPRESSOR, /* This unit implements dynamic compression (linked multichannel, wideband) */
    FMOD_DSP_TYPE_SFXREVERB,      /* This unit implements SFX reverb */
    FMOD_DSP_TYPE_LOWPASS_SIMPLE, /* This unit filters sound using a simple lowpass with no resonance, but has flexible cutoff and is fast. */
    FMOD_DSP_TYPE_FORCEINT = 65536 /* Makes sure this enum is signed 32bit. */
};

enum FMOD_DSP_CATEGORY {
    FMOD_DSP_CATEGORY_FILTER,       /* This is a unit type that processes incoming data. */
    FMOD_DSP_CATEGORY_DSPCODECMPEG, /* This is a unit type that resamples data from a codec. (MPEG) */
    FMOD_DSP_CATEGORY_DSPCODECADPCM, /* This is a unit type that resamples data from a codec. (ADPCM) */
    FMOD_DSP_CATEGORY_DSPCODECXMA, /* This is a unit type that resamples data from a codec. (XMA) */
    // FMOD_DSP_CATEGORY_DSPCODECCELT, /* This is a unit type that resamples data from a codec. (CELT) */
    FMOD_DSP_CATEGORY_DSPCODECRAW, /* This is a unit type that resamples data from a codec. (RAW) */
    FMOD_DSP_CATEGORY_SOUNDCARD, /* This is a unit type that only receives data. (Not used on PS3 non-recursive SPU mixer) */
    FMOD_DSP_CATEGORY_WAVETABLE, /* This is a unit type that only reads wave data. */
    FMOD_DSP_CATEGORY_RESAMPLER
};

enum FMOD__Thread__PRIORITY {
    PRIORITY_VERYLOW  = -2,
    PRIORITY_LOW      = -1,
    PRIORITY_NORMAL   = 0,
    PRIORITY_HIGH     = 1,
    PRIORITY_VERYHIGH = 2,
    PRIORITY_CRITICAL = 3
};

// Lol, these are the same
enum FMOD_THREAD_PRIORITY {
    FMOD_THREAD_PRIORITY_VERYLOW  = -2,
    FMOD_THREAD_PRIORITY_LOW      = -1,
    FMOD_THREAD_PRIORITY_NORMAL   = 0,
    FMOD_THREAD_PRIORITY_HIGH     = 1,
    FMOD_THREAD_PRIORITY_VERYHIGH = 2,
    FMOD_THREAD_PRIORITY_CRITICAL = 3
};

enum FMOD__REVERB_VERSION {
    REVERB_VERSION_NONE,
    REVERB_VERSION_EAX5,
    REVERB_VERSION_EAX4,
    REVERB_VERSION_EAX3,
    REVERB_VERSION_EAX2,
    REVERB_VERSION_I3DL2
};

enum FMOD_DSP_FFT_WINDOW {
    FMOD_DSP_FFT_WINDOW_RECT, /* w[n] = 1.0                                                                                            */
    FMOD_DSP_FFT_WINDOW_TRIANGLE, /* w[n] = TRI(2n/N)                                                                                      */
    FMOD_DSP_FFT_WINDOW_HAMMING, /* w[n] = 0.54 - (0.46 * COS(n/N) )                                                                      */
    FMOD_DSP_FFT_WINDOW_HANNING, /* w[n] = 0.5 *  (1.0  - COS(n/N) )                                                                      */
    FMOD_DSP_FFT_WINDOW_BLACKMAN, /* w[n] = 0.42 - (0.5  * COS(n/N) ) + (0.08 * COS(2.0 * n/N) )                                           */
    FMOD_DSP_FFT_WINDOW_BLACKMANHARRIS, /* w[n] = 0.35875 - (0.48829 * COS(1.0 * n/N)) + (0.14128 * COS(2.0 * n/N)) - (0.01168 * COS(3.0 * n/N)) */

    FMOD_DSP_FFT_WINDOW_MAX,             /* Maximum number of FFT window types supported. */
    FMOD_DSP_FFT_WINDOW_FORCEINT = 65536 /* Makes sure this enum is signed 32bit. */
};

enum FMOD_REVERB_MODE {
    FMOD_REVERB_PHYSICAL = 0x1,
    FMOD_REVERB_VIRTUAL  = 0x2,
};

enum FMOD_SPEAKER {
    FMOD_SPEAKER_FRONT_LEFT,
    FMOD_SPEAKER_FRONT_RIGHT,
    FMOD_SPEAKER_FRONT_CENTER,
    FMOD_SPEAKER_LOW_FREQUENCY,
    FMOD_SPEAKER_BACK_LEFT,
    FMOD_SPEAKER_BACK_RIGHT,
    FMOD_SPEAKER_SIDE_LEFT,
    FMOD_SPEAKER_SIDE_RIGHT,

    FMOD_SPEAKER_MAX,
    FMOD_SPEAKER_MONO     = FMOD_SPEAKER_FRONT_LEFT,
    FMOD_SPEAKER_NULL     = FMOD_SPEAKER_MAX,
    FMOD_SPEAKER_SBL      = FMOD_SPEAKER_SIDE_LEFT,
    FMOD_SPEAKER_SBR      = FMOD_SPEAKER_SIDE_RIGHT,
    FMOD_SPEAKER_FORCEINT = 65536
};

enum FMOD_DSPCONNECTIONREQUEST_CMD {
    DSPCONNECTION_REQUEST_ADDINPUT,
    DSPCONNECTION_REQUEST_DISCONNECTFROM,
    DSPCONNECTION_REQUEST_DISCONNECTALLINPUTS,
    DSPCONNECTION_REQUEST_DISCONNECTALLOUTPUTS,
    DSPCONNECTION_REQUEST_DISCONNECTALL
};

enum FMOD_CHANNEL_PANMODE {
    FMOD_CHANNEL_PANMODE_PAN,
    FMOD_CHANNEL_PANMODE_SPEAKERMIX,
    FMOD_CHANNEL_PANMODE_SPEAKERLEVELS,
};

enum FMOD_PLUGINTYPE {
    FMOD_PLUGINTYPE_OUTPUT,
    FMOD_PLUGINTYPE_CODEC,
    FMOD_PLUGINTYPE_DSP,

    FMOD_PLUGINTYPE_MAX,
    FMOD_PLUGINTYPE_FORCEINT = 65536
};

enum FMOD_DSP_RESAMPLER {
    FMOD_DSP_RESAMPLER_NOINTERP,
    FMOD_DSP_RESAMPLER_LINEAR,
    FMOD_DSP_RESAMPLER_CUBIC,
    FMOD_DSP_RESAMPLER_SPLINE,

    FMOD_DSP_RESAMPLER_MAX,
    FMOD_DSP_RESAMPLER_FORCEINT = 65536
};

enum FMOD__DSPWAVETABLE_SPEEDDIR {
    DSPWAVETABLE_SPEEDDIR_FORWARDS,
    DSPWAVETABLE_SPEEDDIR_BACKWARDS
};

enum FMOD_RESAMPLER_END {
    FMOD_RESAMPLER_END_MIXBUFFER,
    FMOD_RESAMPLER_END_RESAMPLEBUFFER,
    FMOD_RESAMPLER_END_SOUND,
    FMOD_RESAMPLER_END_SUBSOUND
};

enum FMOD__DSPRESAMPLER_SPEEDDIR {
    DSPRESAMPLER_SPEEDDIR_FORWARDS,
    DSPRESAMPLER_SPEEDDIR_BACKWARDS
};

enum FMOD__CONN_SRC_FLAGS {
    CONN_SRC_FLAG_NONE          = 0x0001,
    CONN_SRC_FLAG_LFO           = 0x0002,
    CONN_SRC_FLAG_KEYONVELOCITY = 0x0004,
    CONN_SRC_FLAG_KEYNUMBER     = 0x0008,
    CONN_SRC_FLAG_EG1           = 0x0010,
    CONN_SRC_FLAG_EG2           = 0x0020,
    CONN_SRC_FLAG_PITCHWHEEL    = 0x0040,
    CONN_SRC_FLAG_MODWHEEL      = 0x0080,
    CONN_SRC_FLAG_CHANNELVOL    = 0x0100,
    CONN_SRC_FLAG_PAN           = 0x0200,
    CONN_SRC_FLAG_EXPRESSION    = 0x0400
};

enum FMOD__CODEC_DLS_ENVPOINT {
    CODEC_DLS_ENVPOINT_ATTACK,
    CODEC_DLS_ENVPOINT_DECAY,
    CODEC_DLS_ENVPOINT_RELEASE,
    CODEC_DLS_ENVPOINT_MAX
};

enum FMOD__MIDI_FORMAT {
    MIDI_FORMAT_SINGLETRACK,
    MIDI_FORMAT_MULTITRACK,
    MIDI_FORMAT_PATTERN,
};

enum FMOD_SYSTEM_CALLBACKTYPE {
    FMOD_SYSTEM_CALLBACKTYPE_DEVICELISTCHANGED
};

enum FMOD_SOUNDGROUP_BEHAVIOR {
    FMOD_SOUNDGROUP_BEHAVIOR_FAIL,
    FMOD_SOUNDGROUP_BEHAVIOR_MUTE,
    FMOD_SOUNDGROUP_BEHAVIOR_STEALLOWEST,
    FMOD_SOUNDGROUP_BEHAVIOR_MAX,
    FMOD_SOUNDGROUP_BEHAVIOR_FORCEINT = 65536
};

enum FMOD_CHANNELINDEX {
    FMOD_CHANNEL_FREE  = -1,
    FMOD_CHANNEL_REUSE = -2
};

enum FMOD__CHANNELREAL_PLAYDIR {
    CHANNELREAL_PLAYDIR_FORWARDS,
    CHANNELREAL_PLAYDIR_BACKWARDS,
    CHANNELREAL_PLAYDIR_MAX = 0xFFFFFFFF
};

// callbacks

// directsound glue code callbacks

// typedef HRESULT(WINAPI* PFN_DSCREATE)(LPGUID lpguid, LPDIRECTSOUND* ppDS, IUnknown FAR* pUnkOuter);
DECLARE_CALLBACK(HRESULT, PFN_DSCREATE, LPGUID lpguid, LPDIRECTSOUND* ppDS, IUnknown* pUnkOuter);
// typedef BOOL(WINAPI* PFN_DSENUMERATE)(LPDSENUMCALLBACKW lpDSEnumCallback, LPVOID lpContext);
DECLARE_CALLBACK(int32_t, PFN_DSENUMERATE, LPDSENUMCALLBACKA lpDSEnumCallback, void* lpContext);
// typedef HRESULT(
//     WINAPI* PFN_DSCREATE8)(LPCGUID lpcGuidDevice, LPDIRECTSOUND8* ppDS8, LPUNKNOWN pUnkOuter);
DECLARE_CALLBACK(
    HRESULT,
    PFN_DSCREATE8,
    LPCGUID         lpcGuidDevice,
    LPDIRECTSOUND8* ppDS8,
    LPUNKNOWN       pUnkOuter);
// typedef HRESULT(
//     WINAPI* PFN_DSCCREATE)(LPGUID lpGUID, LPDIRECTSOUNDCAPTURE* lplpDSC, LPUNKNOWN pUnkOuter);
DECLARE_CALLBACK(
    HRESULT,
    PFN_DSCCREATE,
    LPGUID                lpGUID,
    LPDIRECTSOUNDCAPTURE* lplpDSC,
    LPUNKNOWN             pUnkOuter);
// typedef BOOL(WINAPI* PFN_DSCENUMERATE)(LPDSENUMCALLBACKW lpDSEnumCallback, LPVOID lpContext);
DECLARE_CALLBACK(int32_t, PFN_DSCENUMERATE, LPDSENUMCALLBACKA lpDSEnumCallback, void* lpContext);
// typedef HRESULT(
//     WINAPI* PFN_DSCCREATE8)(LPCGUID lpcGUID, LPDIRECTSOUNDCAPTURE8* lplpDSC, LPUNKNOWN pUnkOuter);
DECLARE_CALLBACK(
    HRESULT,
    PFN_DSCCREATE8,
    LPCGUID                lpcGUID,
    LPDIRECTSOUNDCAPTURE8* lplpDSC,
    LPUNKNOWN              pUnkOuter);

// fmod callbacks

DECLARE_CALLBACK(
    FMOD_RESULT,
    FMOD_CHANNEL_CALLBACK,
    FMOD_CHANNEL*             channel,
    FMOD_CHANNEL_CALLBACKTYPE type,
    int32_t                   command,
    uint32_t                  commanddata1,
    uint32_t                  commanddata2);

DECLARE_CALLBACK(
    FMOD_RESULT,
    FMOD_FILE_OPENCALLBACK,
    const char* name,
    int32_t     unicode,
    uint32_t*   filesize,
    void**      handle,
    void**      userdata);

DECLARE_CALLBACK(FMOD_RESULT, FMOD_FILE_CLOSECALLBACK, void* handle, void* userdata);
DECLARE_CALLBACK(
    FMOD_RESULT,
    FMOD_FILE_READCALLBACK,
    void*     handle,
    void*     buffer,
    uint32_t  sizebytes,
    uint32_t* bytesread,
    void*     userdata);

DECLARE_CALLBACK(FMOD_RESULT, FMOD_FILE_SEEKCALLBACK, void* handle, uint32_t pos, void* userdata);

DECLARE_CALLBACK(void*, FMOD_MEMORY_ALLOCCALLBACK, uint32_t size, FMOD_MEMORY_TYPE type);
DECLARE_CALLBACK(
    void*,
    FMOD_MEMORY_REALLOCCALLBACK,
    void*            ptr,
    uint32_t         size,
    FMOD_MEMORY_TYPE type);
DECLARE_CALLBACK(void, FMOD_MEMORY_FREECALLBACK, void* ptr, FMOD_MEMORY_TYPE type);

DECLARE_CALLBACK(
    FMOD_RESULT,
    FMOD_CODEC_OPENCALLBACK,
    FMOD_CODEC_STATE*       codec_state,
    FMOD_MODE               usermode,
    FMOD_CREATESOUNDEXINFO* userexinfo);
DECLARE_CALLBACK(FMOD_RESULT, FMOD_CODEC_CLOSECALLBACK, FMOD_CODEC_STATE* codec_state);
DECLARE_CALLBACK(
    FMOD_RESULT,
    FMOD_CODEC_READCALLBACK,
    FMOD_CODEC_STATE* codec_state,
    void*             buffer,
    uint32_t          sizebytes,
    uint32_t*         bytesread);
DECLARE_CALLBACK(
    FMOD_RESULT,
    FMOD_CODEC_GETLENGTHCALLBACK,
    FMOD_CODEC_STATE* codec_state,
    uint32_t*         length,
    FMOD_TIMEUNIT     lengthtype);
DECLARE_CALLBACK(
    FMOD_RESULT,
    FMOD_CODEC_SETPOSITIONCALLBACK,
    FMOD_CODEC_STATE* codec_state,
    int32_t           subsound,
    uint32_t          position,
    FMOD_TIMEUNIT     postype);
DECLARE_CALLBACK(
    FMOD_RESULT,
    FMOD_CODEC_GETPOSITIONCALLBACK,
    FMOD_CODEC_STATE* codec_state,
    uint32_t*         position,
    FMOD_TIMEUNIT     postype);
DECLARE_CALLBACK(
    FMOD_RESULT,
    FMOD_CODEC_SOUNDCREATECALLBACK,
    FMOD_CODEC_STATE* codec_state,
    int32_t           subsound,
    FMOD_SOUND*       sound);
DECLARE_CALLBACK(
    FMOD_RESULT,
    FMOD_CODEC_METADATACALLBACK,
    FMOD_CODEC_STATE* codec_state,
    FMOD_TAGTYPE      tagtype,
    char*             name,
    void*             data,
    uint32_t          datalen,
    FMOD_TAGDATATYPE  datatype,
    int32_t           unique);
DECLARE_CALLBACK(
    FMOD_RESULT,
    FMOD_CODEC_GETWAVEFORMAT,
    FMOD_CODEC_STATE*      codec_state,
    int32_t                index,
    FMOD_CODEC_WAVEFORMAT* waveformat);

DECLARE_CALLBACK(FMOD_RESULT, FMOD_SOUND_NONBLOCKCALLBACK, FMOD_SOUND* sound, FMOD_RESULT result);
DECLARE_CALLBACK(
    FMOD_RESULT,
    FMOD_SOUND_PCMREADCALLBACK,
    FMOD_SOUND* sound,
    void*       data,
    uint32_t    datalen);
DECLARE_CALLBACK(
    FMOD_RESULT,
    FMOD_SOUND_PCMSETPOSCALLBACK,
    FMOD_SOUND*   sound,
    int32_t       subsound,
    uint32_t      position,
    FMOD_TIMEUNIT postype);

DECLARE_CALLBACK(
    FMOD_RESULT,
    FMOD_OUTPUT_GETNUMDRIVERSCALLBACK,
    FMOD_OUTPUT_STATE* output_state,
    int32_t*           numdrivers);
DECLARE_CALLBACK(
    FMOD_RESULT,
    FMOD_OUTPUT_GETDRIVERNAMECALLBACK,
    FMOD_OUTPUT_STATE* output_state,
    int32_t            id,
    char*              name,
    int32_t            namelen);
DECLARE_CALLBACK(
    FMOD_RESULT,
    FMOD_OUTPUT_GETDRIVERCAPSCALLBACK,
    FMOD_OUTPUT_STATE* output_state,
    int32_t            id,
    FMOD_CAPS*         caps);
DECLARE_CALLBACK(
    FMOD_RESULT,
    FMOD_OUTPUT_INITCALLBACK,
    FMOD_OUTPUT_STATE* output_state,
    int32_t            selecteddriver,
    FMOD_INITFLAGS     flags,
    int32_t*           outputrate,
    int32_t            outputchannels,
    FMOD_SOUND_FORMAT* outputformat,
    int32_t            dspbufferlength,
    int32_t            dspnumbuffers,
    void*              extradriverdata);
DECLARE_CALLBACK(FMOD_RESULT, FMOD_OUTPUT_CLOSECALLBACK, FMOD_OUTPUT_STATE* output_state);
DECLARE_CALLBACK(FMOD_RESULT, FMOD_OUTPUT_UPDATECALLBACK, FMOD_OUTPUT_STATE* output_state);
DECLARE_CALLBACK(
    FMOD_RESULT,
    FMOD_OUTPUT_GETHANDLECALLBACK,
    FMOD_OUTPUT_STATE* output_state,
    void**             handle);
DECLARE_CALLBACK(
    FMOD_RESULT,
    FMOD_OUTPUT_GETPOSITIONCALLBACK,
    FMOD_OUTPUT_STATE* output_state,
    uint32_t*          pcm);
DECLARE_CALLBACK(
    FMOD_RESULT,
    FMOD_OUTPUT_LOCKCALLBACK,
    FMOD_OUTPUT_STATE* output_state,
    uint32_t           offset,
    uint32_t           length,
    void**             ptr1,
    void**             ptr2,
    uint32_t*          len1,
    uint32_t*          len2);
DECLARE_CALLBACK(
    FMOD_RESULT,
    FMOD_OUTPUT_UNLOCKCALLBACK,
    FMOD_OUTPUT_STATE* output_state,
    void*              ptr1,
    void*              ptr2,
    uint32_t           len1,
    uint32_t           len2);
DECLARE_CALLBACK(
    FMOD_RESULT,
    FMOD_OUTPUT_READFROMMIXER,
    FMOD_OUTPUT_STATE* output_state,
    void*              buffer,
    uint32_t           length);

DECLARE_CALLBACK(
    int32_t,
    FMOD_OUTPUT_GETSAMPLEMAXCHANNELS,
    FMOD_OUTPUT_STATE* output,
    FMOD_MODE          mode,
    FMOD_SOUND_FORMAT  format);
DECLARE_CALLBACK(
    FMOD_RESULT,
    FMOD_OUTPUT_GETDRIVERINFOCALLBACK,
    FMOD_OUTPUT_STATE* output,
    int32_t            id,
    char*              name,
    int32_t            namelen);

DECLARE_CALLBACK(
    FMOD_RESULT,
    FMOD_OUTPUT_GETDRIVERINFOWCALLBACK,
    FMOD_OUTPUT_STATE* output,
    int32_t            id,
    int16_t*           name,
    int32_t            namelen);
DECLARE_CALLBACK(
    FMOD_RESULT,
    FMOD_OUTPUT_GETDRIVERCAPSEXCALLBACK,
    FMOD_OUTPUT_STATE* output,
    int32_t            id,
    FMOD_CAPS*         caps,
    int32_t*           minfrequency,
    int32_t*           maxfrequency,
    FMOD_SPEAKERMODE*  controlpanelspeakermode);
DECLARE_CALLBACK(
    FMOD_RESULT,
    FMOD_OUTPUT_GETDRIVERCAPSEX2CALLBACK,
    FMOD_OUTPUT_STATE* output,
    int32_t            id,
    FMOD_CAPS*         caps,
    int32_t*           minfrequency,
    int32_t*           maxfrequency,
    FMOD_SPEAKERMODE*  controlpanelspeakermode,
    int32_t*           num2dchannels,
    int32_t*           num3dchannels,
    int32_t*           totalchannels);
DECLARE_CALLBACK(
    FMOD_RESULT,
    FMOD_OUTPUT_INITEXCALLBACK,
    FMOD_OUTPUT_STATE* output,
    int32_t            selecteddriver,
    FMOD_INITFLAGS     flags,
    int32_t*           outputrate,
    int32_t            outputchannels,
    FMOD_SOUND_FORMAT* outputformat,
    FMOD_SPEAKERMODE*  speakermode,
    int32_t            dspbufferlength,
    int32_t            dspnumbuffers,
    int32_t            max2dchannels,
    int32_t            max3dchannels,
    void*              extradriverdata);
DECLARE_CALLBACK(FMOD_RESULT, FMOD_OUTPUT_STARTCALLBACK, FMOD_OUTPUT_STATE* output);
DECLARE_CALLBACK(FMOD_RESULT, FMOD_OUTPUT_STOPCALLBACK, FMOD_OUTPUT_STATE* output);
DECLARE_CALLBACK(FMOD_RESULT, FMOD_OUTPUT_UPDATEFINISHEDCALLBACK, FMOD_OUTPUT_STATE* output);
DECLARE_CALLBACK(
    FMOD_RESULT,
    FMOD_OUTPUT_CREATESAMPLECALLBACK,
    FMOD_OUTPUT_STATE*     output,
    FMOD_MODE              mode,
    FMOD_CODEC_WAVEFORMAT* waveformat,
    FMOD__Sample**         sample);
DECLARE_CALLBACK(
    FMOD_RESULT,
    FMOD_OUTPUT_GETSOUNDRAMCALLBACK,
    FMOD_OUTPUT_STATE* output,
    int32_t*           currentalloced,
    int32_t*           maxalloced,
    int32_t*           total);
DECLARE_CALLBACK(FMOD_RESULT, FMOD_OUTPUT_POSTMIXCALLBACK, FMOD_OUTPUT_STATE* output);
DECLARE_CALLBACK(
    FMOD_RESULT,
    FMOD_OUTPUT_RECORDGETDRIVERCAPSCALLBACK,
    FMOD_OUTPUT_STATE* output,
    int32_t            id,
    FMOD_CAPS*         caps,
    int32_t*           minfrequency,
    int32_t*           maxfrequency);
DECLARE_CALLBACK(
    FMOD_RESULT,
    FMOD_OUTPUT_RECORDSTARTCALLBACK,
    FMOD_OUTPUT_STATE* output,
    int32_t            id,
    FMOD_SOUND*        sound,
    int32_t            loop);
DECLARE_CALLBACK(FMOD_RESULT, FMOD_OUTPUT_RECORDSTOPCALLBACK, FMOD_OUTPUT_STATE* output);
DECLARE_CALLBACK(
    FMOD_RESULT,
    FMOD_OUTPUT_RECORDGETPOSITIONCALLBACK,
    FMOD_OUTPUT_STATE* output,
    uint32_t*          pcm);
DECLARE_CALLBACK(
    FMOD_RESULT,
    FMOD_OUTPUT_RECORDLOCKCALLBACK,
    FMOD_OUTPUT_STATE* output,
    uint32_t           offset,
    uint32_t           length,
    void**             ptr1,
    void**             ptr2,
    uint32_t*          len1,
    uint32_t*          len2);
DECLARE_CALLBACK(
    FMOD_RESULT,
    FMOD_OUTPUT_RECORDUNLOCKCALLBACK,
    FMOD_OUTPUT_STATE* output,
    void*              ptr1,
    void*              ptr2,
    uint32_t           len1,
    uint32_t           len2);
DECLARE_CALLBACK(
    FMOD_RESULT,
    FMOD_OUTPUT_SETREVERBCALLBACK,
    FMOD_OUTPUT_STATE*      output,
    FMOD_REVERB_PROPERTIES* prop);
DECLARE_CALLBACK(
    FMOD_RESULT,
    FMOD_OUTPUT_GETREVERBCALLBACK,
    FMOD_OUTPUT_STATE*      output,
    FMOD_REVERB_PROPERTIES* prop);

DECLARE_CALLBACK(FMOD_RESULT, FMOD_CODEC_RESETCALLBACK, FMOD_CODEC_STATE* codec);
DECLARE_CALLBACK(FMOD_RESULT, FMOD_CODEC_CANPOINTCALLBACK, FMOD_CODEC_STATE* codec);

DECLARE_CALLBACK(FMOD_RESULT, FMOD_DSP_CREATECALLBACK, FMOD_DSP_STATE* dsp_state);
DECLARE_CALLBACK(FMOD_RESULT, FMOD_DSP_RELEASECALLBACK, FMOD_DSP_STATE* dsp_state);
DECLARE_CALLBACK(FMOD_RESULT, FMOD_DSP_RESETCALLBACK, FMOD_DSP_STATE* dsp_state);
DECLARE_CALLBACK(
    FMOD_RESULT,
    FMOD_DSP_READCALLBACK,
    FMOD_DSP_STATE* dsp_state,
    float*          inbuffer,
    float*          outbuffer,
    uint32_t        length,
    int32_t         inchannels,
    int32_t         outchannels);
DECLARE_CALLBACK(
    FMOD_RESULT,
    FMOD_DSP_SETPOSITIONCALLBACK,
    FMOD_DSP_STATE* dsp_state,
    uint32_t        pos);
DECLARE_CALLBACK(
    FMOD_RESULT,
    FMOD_DSP_SETPARAMCALLBACK,
    FMOD_DSP_STATE* dsp_state,
    int32_t         index,
    float           value);
DECLARE_CALLBACK(
    FMOD_RESULT,
    FMOD_DSP_GETPARAMCALLBACK,
    FMOD_DSP_STATE* dsp_state,
    int32_t         index,
    float*          value,
    char*           valuestr);
DECLARE_CALLBACK(
    FMOD_RESULT,
    FMOD_DSP_DIALOGCALLBACK,
    FMOD_DSP_STATE* dsp_state,
    void*           hwnd,
    int32_t         show);

// custom helper
DECLARE_CALLBACK(void, FMOD_THREAD_USERDATACALLBACK, void* userdata);

DECLARE_CALLBACK(float, FMOD_3D_ROLLOFFCALLBACK, FMOD_CHANNEL* channel, float distance);

DECLARE_CALLBACK(ALenum, EAXSet, const GUID*, ALuint, ALuint, ALvoid*, ALuint);
DECLARE_CALLBACK(ALenum, EAXGet, const GUID*, ALuint, ALuint, ALvoid*, ALuint);

DECLARE_CALLBACK(uint32_t, FUNC_SENDASPI32COMMAND, SRB* srb);
DECLARE_CALLBACK(uint32_t, FUNC_GETASPI32SUPPORTINFO);

DECLARE_CALLBACK(
    HRESULT,
    PFN_WMCREATESYNCREADER,
    IUnknown*       pUnkCert,
    uint32_t        dwRights,
    IWMSyncReader** ppSyncReader);

DECLARE_CALLBACK(
    FMOD_RESULT,
    FMOD_SYSTEM_CALLBACK,
    FMOD_SYSTEM*             system,
    FMOD_SYSTEM_CALLBACKTYPE type,
    uint32_t                 commandata1,
    uint32_t                 commanddata2);

DECLARE_CALLBACK(
    bool,
    FMOD__Octree__RecursionData__octreeLineTestCallback,
    FMOD__OctreeNode* item,
    void*             data);

// structs

struct FMOD_UINT64P_words {
    uint32_t mLo;
    uint32_t mHi;
};

struct FMOD_SINT64P_words {
    uint32_t mLo;
    int32_t  mHi;
};

union FMOD_UINT64P {
    FMOD_UINT64        mValue;
    FMOD_UINT64P_words words;
};

union FMOD_SINT64P {
    FMOD_SINT64        mValue;
    FMOD_SINT64P_words words;
};

struct FMOD_GUID {
    uint32_t Data1;
    uint16_t Data2;
    uint16_t Data3;
    uint8_t  Data4[8];
};

struct EAX50SESSIONPROPERTIES {
    uint32_t ulEAXVersion;
    uint32_t ulMaxActiveSends;
};

// size = 0x12
#pragma pack(push, 1)
struct WAVE_FORMATEX {
    uint16_t wFormatTag;      // 0x00
    uint16_t nChannels;       // 0x02
    uint32_t nSamplesPerSec;  // 0x04
    uint32_t nAvgBytesPerSec; // 0x08
    uint16_t nBlockAlign;     // 0x0C
    uint16_t wBitsPerSample;  // 0x0E
    uint16_t cbSize;          // 0x10
};
#pragma pack(pop)

#pragma pack(push, 1)
struct WAVE_FORMAT_IMAADPCM {
    WAVE_FORMATEX wfx;
    uint16_t      wSamplesPerBlock;
};
#pragma pack(pop)

union WAVE_FORMATEXTENSIBLE_Samples {
    uint16_t wValidBitsPerSample;
    uint16_t wSamplesPerBlock;
    uint16_t wReserved;
};

// size = 0x28
#pragma pack(push, 1)
struct __attribute__((aligned(1))) WAVE_FORMATEXTENSIBLE {
    WAVE_FORMATEX                 Format;        // 0x00
    WAVE_FORMATEXTENSIBLE_Samples Samples;       // 0x12
    uint32_t                      dwChannelMask; // 0x14
    FMOD_GUID                     SubFormat;     // 0x18
};
#pragma pack(pop)

#pragma pack(push, 1)
struct WAVE_SMPLHEADER__Loop {
    uint32_t Identifier;
    uint32_t Type;
    uint32_t Start;
    uint32_t End;
    uint32_t Fraction;
    uint32_t Count;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct WAVE_SMPLHEADER {
    uint32_t              Manufacturer;
    uint32_t              Product;
    uint32_t              SamplePeriod;
    uint32_t              Note;
    uint32_t              FineTune;
    uint32_t              SMPTEFormat;
    uint32_t              SMPTEOffset;
    uint32_t              Loops;
    uint32_t              SamplerData;
    WAVE_SMPLHEADER__Loop Loop;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct FMOD__DLS_MIDILOCALE {
    uint32_t ulBank;
    uint32_t ulInstrument;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct FMOD__DLS_INSTRUMENTHEADER {
    uint32_t             cRegions;
    FMOD__DLS_MIDILOCALE Locale;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct FMOD__DLS_RGNRANGE {
    uint16_t usLow;
    uint16_t usHigh;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct FMOD__DLS_REGIONHEADER {
    FMOD__DLS_RGNRANGE RangeKey;
    FMOD__DLS_RGNRANGE RangeVelocity;
    uint16_t           fusOptions;
    uint16_t           usKeyGroup;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct FMOD__DLS_WAVELINK {
    uint16_t fusOptions;
    uint16_t usPhaseGroup;
    uint32_t ulChannel;
    uint32_t ulTableIndex;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct FMOD__DLS_WAVESAMPLELOOP {
    uint32_t cbSize;
    uint32_t ulLoopType;
    uint32_t ulLoopStart;
    uint32_t ulLoopLength;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct FMOD__DLS_WAVESAMPLE {
    uint32_t                 cbSize;
    uint16_t                 usUnityNote;
    int16_t                  sFineTune;
    int32_t                  lAttenuation;
    uint32_t                 fulOptions;
    uint32_t                 cSampleLoops;
    FMOD__DLS_WAVESAMPLELOOP loop[1];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct FMOD__DLS_CONNECTIONBLOCK {
    uint16_t usSource;
    uint16_t usControl;
    uint16_t usDestination;
    uint16_t usTransform;
    int32_t  lScale;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct FMOD__MIDI_CHUNK {
    char     mID[4];
    uint32_t mSize;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct FMOD__MTHD_CHUNK {
    FMOD__MIDI_CHUNK mChunk;
    uint16_t         mFormat;
    uint16_t         mNumTracks;
    uint16_t         mDivision;
};
#pragma pack(pop)

struct FMOD_TAG {
    FMOD_TAGTYPE     type;
    FMOD_TAGDATATYPE datatype;
    char*            name;
    void*            data;
    uint32_t         datalen;
    FMOD_BOOL        updated;
};

struct FMOD_VECTOR {
    float x; /* X co-ordinate in 3D space. */
    float y; /* Y co-ordinate in 3D space. */
    float z; /* Z co-ordinate in 3D space. */
};

struct FMOD_AABB {
    float xMin;
    float xMax;
    float yMin;
    float yMax;
    float zMin;
    float zMax;
};

struct FMOD_COMPLEX {
    float re;
    float im;
};

struct FMOD__DSPFFT {
    FMOD_COMPLEX mFFTBuffer[16384];
    float        mCosTab[8192];
};

struct FMOD__TimeStamp {
    uint32_t    mIn;             // 0x00
    uint32_t    mOut;            // 0x04
    uint32_t    mPausedIn;       // 0x08
    uint32_t    mPausedOut;      // 0x0C
    uint32_t    mTotalIn;        // 0x10
    uint32_t    mTotalOut;       // 0x14
    FMOD_UFLOAT mPercent;        // 0x18
    FMOD_UFLOAT mAvTotal;        // 0x1C
    FMOD_UFLOAT mAvCurrent;      // 0x20
    FMOD_UFLOAT mCPUUSage;       // 0x24
    bool        mPaused;         // 0x28
    uint32_t    mPausedTotal;    // 0x2C
    int32_t     mPausedRefCount; // 0x30
    bool        mTiming;         // 0x34
};

struct FMOD_REVERB_CHANNELPROPERTIES {
    int32_t  Direct;
    int32_t  DirectHF;
    int32_t  Room;
    int32_t  RoomHF;
    int32_t  Obstruction;
    float    ObstructionLFRatio;
    int32_t  Occlusion;
    float    OcclusionLFRatio;
    float    OcclusionRoomRatio;
    float    OcclusionDirectRatio;
    int32_t  Exclusion;
    float    ExclusionLFRatio;
    int32_t  OutsideVolumeHF;
    float    DopplerFactor;
    float    RolloffFactor;
    float    RoomRolloffFactor;
    float    AirAbsorptionFactor;
    uint32_t Flags;
};

// size = 0x38
struct FMOD_ADVANCEDSETTINGS {
    int32_t       cbsize;          // 0x00
    int32_t       maxMPEGcodecs;   // 0x04
    int32_t       maxADPCMcodecs;  // 0x08
    int32_t       maxXMAcodecs;    // 0x0C
    int32_t       maxPCMcodecs;    // 0x10
    int32_t       ASIONumChannels; // 0x14
    char**        ASIOChannelList; // 0x18
    FMOD_SPEAKER* ASIOSpeakerList; // 0x1C
    int32_t       max3DReverbDSPs; // 0x20
    float         HRTFMinAngle;    // 0x24
    float         HRTFMaxAngle;    // 0x28
    float         HRTFFreq;        // 0x2C
    float         vol0virtualvol;  // 0x30
    int32_t       eventqueuesize;  // 0x34
};

// unconfirmed
struct FMOD_SPEAKERCONFIG {
    // FMOD_SPEAKER mSpeaker;      // 0x00
    // FMOD_VECTOR  mPosition;     // 0x04
    // FMOD_VECTOR  mXZNormal;     // 0x10
    // float        mXZAngle;      // 0x1C
    // float        mDistance;     // 0x20
    // bool         mActive;       // 0x24
    // bool         mPairUseVBAP;  // 0x25
    // float        mPairVBAPSign; // 0x28
    FMOD_SPEAKER mSpeaker;  // 0x00
    FMOD_VECTOR  mPosition; // 0x04
    uint32_t     mXZAngle;  // 0x10
    float        mDistance; // 0x14
    bool         mActive;   // 0x18
};

// size >= 0x7C
struct FMOD_CHANNEL_INFO {
    // float*             mLevels;      // 0x00
    // uint32_t           mPCM;         // 0x04
    // uint32_t           mLoopStart;   // 0x08
    // uint32_t           mLoopEnd;     // 0x0C
    // FMOD__ChannelReal* mRealChannel; // 0x10
    // FMOD__SoundI*      mSound;       // 0x14
    // FMOD__DSPI*        mDSP;         // 0x18
    // int32_t            mLoopCount;   // 0x1C
    // bool               mMute;        // 0x20
    // bool               mPaused;      // 0x21
    // uint32_t           mDSPClockHi;  // 0x24
    // uint32_t           mDSPClockLo;  // 0x28
    // FMOD_MODE          mode;         // 0x2C
    float*                        mLevels;           // 0x00
    uint32_t                      mPCM;              // 0x04
    uint32_t                      mLoopStart;        // 0x08
    uint32_t                      mLoopEnd;          // 0x0C
    FMOD__ChannelReal*            mRealChannel;      // 0x10
    FMOD__SoundI*                 mSound;            // 0x14
    FMOD__DSPI*                   mDSP;              // 0x18 unconfirmed
    int32_t                       mLoopCount;        // 0x1C
    bool                          mMute;             // 0x20
    bool                          mPaused;           // 0x21
    uint32_t                      mDSPClockHi;       // 0x24
    uint32_t                      mDSPClockLo;       // 0x28
    FMOD_REVERB_CHANNELPROPERTIES mReverbProperties; // 0x2C
    FMOD__DSPI*                   mDSPChain;         // 0x74 invented name
    FMOD_MODE                     mMode;             // 0x78
};

struct FMOD_CDDA_StringList {
    uint32_t value;
    char*    string;
};

struct FMOD_CDDA_SenseKey {
    uint8_t SK;
    uint8_t ASC;
    uint8_t ASCQ;
};

struct FMOD_CDTOC {
    int32_t numtracks;  /* [out] The number of tracks on the CD */
    int32_t min[100];   /* [out] The start offset of each track in minutes */
    int32_t sec[100];   /* [out] The start offset of each track in seconds */
    int32_t frame[100]; /* [out] The start offset of each track in frames */
};

struct FMOD_CDDA_InquiryData {
#if defined(BITFIELDS_SUPPORTED)
    uint8_t peripheral_device_type : 5;
    uint8_t peripheral_qualifier : 3;

    uint8_t device_type_modifier : 7;
    uint8_t removable_medium : 1;

    uint8_t ansi_version : 3;
    uint8_t ecma_version : 3;
    uint8_t iso_version : 2;

    uint8_t response_data_format : 4;
    uint8_t res00 : 2;
    uint8_t term_io_process : 1;
    uint8_t async_event_notification : 1;

    uint8_t additional_length;

    uint8_t res01;

    uint8_t res02;

    uint8_t soft_reset : 1;
    uint8_t cmd_queue : 1;
    uint8_t res03 : 1;
    uint8_t linked : 1;
    uint8_t sync : 1;
    uint8_t wide_bus_16 : 1;
    uint8_t wide_bus_32 : 1;
    uint8_t relative_addressing : 1;
#else
    uint8_t bitfield00;
    uint8_t bitfield01;
    uint8_t bitfield02;
    uint8_t bitfield03;
    uint8_t res01;
    uint8_t res02;
    uint8_t bitfield06;
#endif
    char vendor_id[8]; // Not null-terminated - padded with spaces
    char product_id[16];
    char product_revision[4];
};

struct FMOD_CDDA_TOC_flag {
#if defined(BITFIELDS_SUPPORTED)
    uint8_t pre_emphasis : 1; // TRUE = audio w/pre-emphasis, FALSE = audio w/out pre-emphasis
    uint8_t digital_copy_permitted : 1; // TRUE = copy permitted, FALSE = copy prohibited
    uint8_t data_track : 1;             // TRUE = data track, FALSE = audio track
    uint8_t four_channel : 1;           // TRUE = four channel audio, FALSE = two channel audio
    uint8_t adr : 4;                    // ADR sub-channel Q field
#else
    uint8_t value;
#endif
};

struct FMOD_CDDA_TOC {
    uint32_t           num_tracks;
    FMOD_CDDA_TOC_flag flags[100];
    uint8_t            track_number[100];
    uint32_t           start_sector[100];
    uint32_t           num_sectors[100];
};

struct FMOD_CDDA_Caps {
#if defined(BITFIELDS_SUPPORTED)
    uint8_t page_code : 6;
    uint8_t res00 : 1;
    uint8_t ps : 1;

    uint8_t page_length;

    uint8_t cdr_read : 1;
    uint8_t cdrw_read : 1;
    uint8_t method2 : 1;
    uint8_t dvdrom_read : 1;
    uint8_t dvdr_read : 1;
    uint8_t dvdram_read : 1;
    uint8_t res01 : 2;

    uint8_t cdr_write : 1;
    uint8_t cdrw_write : 1;
    uint8_t test_write : 1;
    uint8_t res02 : 1;
    uint8_t dvdr_write : 1;
    uint8_t dvdram_write : 1;
    uint8_t res022 : 2;

    uint8_t audio_play : 1;
    uint8_t composite : 1;
    uint8_t digital_port1 : 1;
    uint8_t digital_port2 : 1;
    uint8_t mode2_form1 : 1;
    uint8_t mode2_form2 : 1;
    uint8_t multi_session : 1;
    uint8_t buf : 1;

    uint8_t cdda_support : 1;
    uint8_t cdda_accurate : 1;
    uint8_t rw_support : 1;
    uint8_t rw_deinterleaved_corrected : 1;
    uint8_t c2pointer_support : 1;
    uint8_t isrc : 1;
    uint8_t upc : 1;
    uint8_t read_barcode : 1;

    uint8_t lock : 1;
    uint8_t lock_state : 1;
    uint8_t prevent_jumper : 1;
    uint8_t eject : 1;
    uint8_t res04 : 1;
    uint8_t loading_mech_type : 3;

    uint8_t seperate_vol_per_channel : 1;
    uint8_t seperate_channel_mute : 1;
    uint8_t disc_present_reporting : 1;
    uint8_t sw_slot_selection : 1;
    uint8_t side_change_capable : 1;
    uint8_t rw_in_leadin : 1;
    uint8_t res05 : 2;

    uint8_t max_read_speed_hi; // Obsolete?
    uint8_t max_read_speed_lo; // Obsolete?

    uint8_t num_volume_levels_hi;
    uint8_t num_volume_levels_lo;

    uint8_t buffer_size_hi;
    uint8_t buffer_size_lo;

    uint8_t current_read_speed_hi; // Obsolete?
    uint8_t current_read_speed_lo; // Obsolete?

    uint8_t res06;

    uint8_t res07 : 1;
    uint8_t bck : 1;
    uint8_t rck : 1;
    uint8_t lsbf : 1;
    uint8_t length : 2;
    uint8_t res08 : 2;

    uint8_t max_write_speed_hi; // Obsolete?
    uint8_t max_write_speed_lo; // Obsolete?

    uint8_t current_write_speed_hi; // Obsolete?
    uint8_t current_write_speed_lo; // Obsolete?

    uint8_t copy_mgmt_revision_hi;
    uint8_t copy_mgmt_revision_lo;

    uint8_t res09;
    uint8_t res10;
#else
    uint8_t bitfield00;  // 0x00
    uint8_t page_length; // 0x01

    uint8_t bitfield02; // 0x02

    uint8_t bitfield03; // 0x03

    uint8_t bitfield04; // 0x04
    uint8_t bitfield05; // 0x05

    uint8_t bitfield06; // 0x06

    uint8_t bitfield07; // 0x07

    uint8_t max_read_speed_hi; // 0x08
    uint8_t max_read_speed_lo; // 0x09

    uint8_t num_volume_levels_hi; // 0x0A
    uint8_t num_volume_levels_lo; // 0x0B

    uint8_t buffer_size_hi; // 0x0C
    uint8_t buffer_size_lo; // 0x0D

    uint8_t current_read_speed_hi; // 0x0E
    uint8_t current_read_speed_lo; // 0x0F

    uint8_t res06; // 0x10

    uint8_t bitfield11;         // 0x11
    uint8_t max_write_speed_hi; // 0x12
    uint8_t max_write_sp;       // 0x13
#endif
};

struct FMOD_CDDA_DEVICE {
    char*   name;       // NULL-terminated string describing this device i.e. drive letter
    char*   scsiaddr;   // ASCII string representing the scsi addr of this device
    char*   devicename; // String containing the vendor id and product id etc. of this device
    int32_t letter;     // Drive letter for this drive
    int32_t target_id;  // SCSI address
    int32_t adapter_id;
    int32_t lun_id;
    int32_t device_open; // TRUE if device has been opened
    int32_t speed;       // Desired speed e.g. 4x, 32x
    FMOD_CDDA_SenseKey     sense_key;
    FMOD_CDDA_TOC          toc;      // Table of contents
    FMOD_CDTOC             usertoc;  // Table of contents for user consumption
    FMOD_CDDA_InquiryData  inq_data; // Standard INQUIRY data
    FMOD_CDDA_Caps*        caps;     // Mode page 0x2A capabilities info
    FUNC_SENDASPI32COMMAND SendASPI32Command;
};

struct FMOD_CDDA_NTSCSIDRIVE {
    uint8_t               ha;
    uint8_t               tgt;
    uint8_t               lun;
    uint8_t               letter;
    bool                  used;
    HANDLE                device;
    FMOD_CDDA_InquiryData inq_data;
};

struct FMOD_FSB_HEADER {
    char        id[4];      // 0x00
    int32_t     numsamples; // 0x04
    uint32_t    shdrsize;   // 0x08
    uint32_t    datasize;   // 0x0C
    uint32_t    version;    // 0x10
    uint32_t    mode;       // 0x14
    FMOD_UINT64 hash;       // 0x18
    FMOD_GUID   guid;       // 0x20
};

struct FMOD_FSB_SAMPLE_HEADER {
    uint16_t size;
    char     name[30];
    uint32_t lengthsamples;
    uint32_t lengthcompressedbytes;
    uint32_t loopstart;
    uint32_t loopend;
    uint32_t mode;
    int32_t  deffreq;
    uint16_t defvol;
    int16_t  defpan;
    uint16_t defpri;
    uint16_t numchannels;
    // #ifndef FMOD_FSB_FORCE_3_0
    //     float    mindistance;
    //     float    maxdistance;
    //     uint32_t size_32bits;
    //     uint16_t varvol;
    //     int16_t  varpan;
    // #endif
}; /* 80 bytes */

struct FMOD_FSB_SAMPLE_HEADER_BASIC {
    uint32_t lengthsamples;
    uint32_t lengthcompressedbytes;
};

struct FMOD__LinkedListNode {
    FMOD__LinkedListNode* mNodeNext;
    FMOD__LinkedListNode* mNodePrev;
    void*                 mNodeData;
};

//    class SortedLinkedListNode : public LinkedListNode
struct FMOD__SortedLinkedListNode {
    FMOD__LinkedListNode _;
    uint32_t             mNodePriority;
};

struct FMOD__LocalCriticalSection {
    FMOD_OS_CRITICALSECTION* mCrit;
    bool                     mEntered;
};

struct FMOD__LocalMemoryCounter {
    int32_t mUsageAtStart; // invented name
};

#define INTERFACE FMOD__Plugin
struct FMOD__Plugin__v_table {
    E_METHOD(FMOD_RESULT, _00_release);
};
#undef INTERFACE

#define INTERFACE FMOD__DSPI
struct FMOD__DSPI__v_table {
    // Plugin methods
    E_METHOD(FMOD_RESULT, _00_release);
    // DSPI methods
    P_METHOD(
        FMOD_RESULT,
        _01_execute,
        float*           inbuffer,
        float**          outbuffer,
        uint32_t*        length,
        int32_t          inchannels,
        int32_t*         outchannels,
        FMOD_SPEAKERMODE speakermode); // invented parameter names
    P_METHOD(
        FMOD_RESULT,
        _02_execute,
        void*            inbuffer,
        void**           outbuffer,
        uint32_t*        length,
        int32_t          inchannels,
        int32_t*         outchannels,
        FMOD_SPEAKERMODE speakermode); // invented parameter names
    P_METHOD(FMOD_RESULT, _03_alloc, FMOD_DSP_DESCRIPTION_EX* description);
    P_METHOD(FMOD_RESULT, _04_setPosition, uint32_t position, bool processinputs);
    P_METHOD(FMOD_RESULT, _05_release, bool freethis);
    P_METHOD(FMOD_RESULT, _06_getSystemObject, FMOD__SystemI** system);
    P_METHOD(FMOD_RESULT, _07_addInput, FMOD__DSPI* target);
    E_METHOD(FMOD_RESULT, _08_remove);
    E_METHOD(FMOD_RESULT, _09_reset);
    P_METHOD(FMOD_RESULT, _10_setParameter, int32_t index, float value);
    P_METHOD(
        FMOD_RESULT,
        _11_getParameter,
        int32_t index,
        float*  value,
        char*   valuestr,
        int32_t valuestrlen);
    P_METHOD(FMOD_RESULT, _12_getNumParameters, int32_t* numparams);
    P_METHOD(
        FMOD_RESULT,
        _13_getParameterInfo,
        int32_t index,
        char*   name,
        char*   label,
        char*   description,
        int32_t descriptionlen,
        float*  min,
        float*  max);
    P_METHOD(FMOD_RESULT, _14_showConfigDialog, void* hwnd, bool show);
    P_METHOD(
        FMOD_RESULT,
        _15_getInfo,
        char*     name,
        uint32_t* version,
        int32_t*  channels,
        int32_t*  configwidth,
        int32_t*  configheight);
    P_METHOD(FMOD_RESULT, _16_getType, FMOD_DSP_TYPE* type);
    P_METHOD(
        FMOD_RESULT,
        _17_setDefaults,
        float   frequency,
        float   volume,
        float   pan,
        int32_t priority);
    P_METHOD(
        FMOD_RESULT,
        _18_getDefaults,
        float*   frequency,
        float*   volume,
        float*   pan,
        int32_t* priority);
    P_METHOD(FMOD_RESULT, _19_setTargetFrequency, int32_t frequency);
    P_METHOD(FMOD_RESULT, _20_getTargetFrequency, int32_t* frequency);
};
#undef INTERFACE

#define INTERFACE FMOD__Output
struct FMOD__Output__v_table {
    // Plugin methods
    E_METHOD(FMOD_RESULT, _00_release);
    // Output methods
    P_METHOD(
        FMOD_RESULT,
        _01_getFreeChannel,
        FMOD_MODE           mode,
        FMOD__ChannelReal** realchannel,
        int32_t             numchannels,
        int32_t             numsoundchannels,
        int32_t*            found);
};
#undef INTERFACE

#define INTERFACE FMOD__OutputSoftware
struct FMOD__OutputSoftware__v_table {
    // Plugin methods
    E_METHOD(FMOD_RESULT, _00_release);
    // Output methods
    P_METHOD(
        FMOD_RESULT,
        _01_getFreeChannel,
        FMOD_MODE           mode,
        FMOD__ChannelReal** realchannel,
        int32_t             numchannels,
        int32_t             numsoundchannels,
        int32_t*            found);
    // OutputSoftware methods
    P_METHOD(FMOD_RESULT, _02_init, int32_t maxsoftwarechannels);
};
#undef INTERFACE

union FMOD__Plugin__v_table_merged {
    FMOD__Plugin__v_table*         plugin;
    FMOD__DSPI__v_table*           dspi;
    FMOD__Output__v_table*         output;
    FMOD__OutputSoftware__v_table* outputsoftware;
};

// size = [0x18]
// class Plugin : SortedLinkedListNode
struct FMOD__Plugin {
    FMOD__Plugin__v_table_merged v_table;
    FMOD__LinkedListNode         _;       // 0x04
    FMOD__SystemI*               mSystem; // 0x10 (confirmed)
    FMOD__Global*                mGlobal; // 0x14
};

#define INTERFACE FMOD__Thread
struct FMOD__Thread__v_table {
    E_METHOD(FMOD_RESULT, _00_threadFunc);
    P_METHOD(void, _01_scalar_deleting_destructor, uint8_t __flags);
};
#undef INTERFACE

// size = [0x124] (unconfirmed)
struct FMOD__Thread {
    FMOD__Thread__v_table* v_table;        // 0x000
    char                   mName[256];     // 0x004
    void*                  mHandle;        // 0x104
    bool                   mRunning;       // 0x108
    void*                  mUserData;      // 0x10C
    void*                  mStack;         // 0x110
    FMOD_OS_SEMAPHORE*     mSema;          // 0x114
    FMOD_OS_SEMAPHORE*     mEndSema;       // 0x118
    void (*mUserCallback)(void* userdata); // 0x11C
    int32_t mPeriod;                       // 0x120
};

// size size = 0x154
// class AsyncThread : public LinkedListNode
struct FMOD__AsyncThread {
    FMOD__LinkedListNode     _;             // 0x000
    FMOD__Thread             mThread;       // 0x00C
    bool                     mThreadActive; // 0x130
    FMOD__LinkedListNode     mHead;         // 0x134
    FMOD_OS_CRITICALSECTION* mCrit;         // 0x140
    bool                     mOwned;        // 0x144
    bool                     mBusy;         // 0x145
    bool                     mDone;         // 0x146
    FMOD__LinkedListNode     mCallbackHead; // 0x148
};

struct FMOD_DSP_STATE {
    FMOD_DSP* instance;
    void*     plugindata;
};

// size = 0x30
struct FMOD_CODEC_DESCRIPTION {
    const char*                    name;            // 0x00
    uint32_t                       version;         // 0x04
    int32_t                        defaultasstream; // 0x08
    FMOD_TIMEUNIT                  timeunits;       // 0x0C
    FMOD_CODEC_OPENCALLBACK        open;            // 0x10
    FMOD_CODEC_CLOSECALLBACK       close;           // 0x14
    FMOD_CODEC_READCALLBACK        read;            // 0x18
    FMOD_CODEC_GETLENGTHCALLBACK   getlength;       // 0x1C
    FMOD_CODEC_SETPOSITIONCALLBACK setposition;     // 0x20
    FMOD_CODEC_GETPOSITIONCALLBACK getposition;     // 0x24
    FMOD_CODEC_SOUNDCREATECALLBACK soundcreate;     // 0x28
    FMOD_CODEC_GETWAVEFORMAT       getwaveformat;   // 0x2C
};

// size = 0x50
// struct FMOD_CODEC_DESCRIPTION_EX : public FMOD_CODEC_DESCRIPTION, public SortedLinkedListNode
struct FMOD_CODEC_DESCRIPTION_EX {
    FMOD_CODEC_DESCRIPTION      _0;       // 0x00
    FMOD__LinkedListNode        _1;       // 0x30
    FMOD_SOUND_TYPE             mType;    // 0x3C
    int32_t                     mSize;    // 0x40
    FMOD_OS_LIBRARY*            mModule;  // 0x44
    FMOD_CODEC_RESETCALLBACK    reset;    // 0x48
    FMOD_CODEC_CANPOINTCALLBACK canpoint; // 0x4C
};

struct FMOD_DSP_PARAMETERDESC {
    float       min;
    float       max;
    float       defaultval;
    char        name[16];
    char        label[16];
    const char* description;
};

// size = 0x5C (confirmed!)
struct FMOD_DSP_DESCRIPTION {
    char                         name[32];      // 0x00
    uint32_t                     version;       // 0x20
    int32_t                      channels;      // 0x24
    FMOD_DSP_CREATECALLBACK      create;        // 0x28
    FMOD_DSP_RELEASECALLBACK     release;       // 0x2C
    FMOD_DSP_RESETCALLBACK       reset;         // 0x30
    FMOD_DSP_READCALLBACK        read;          // 0x34
    FMOD_DSP_SETPOSITIONCALLBACK setposition;   // 0x38
    int32_t                      numparameters; // 0x3C
    FMOD_DSP_PARAMETERDESC*      paramdesc;     // 0x40
    FMOD_DSP_SETPARAMCALLBACK    setparameter;  // 0x44
    FMOD_DSP_GETPARAMCALLBACK    getparameter;  // 0x48
    FMOD_DSP_DIALOGCALLBACK      config;        // 0x4C
    int32_t                      configwidth;   // 0x50
    int32_t                      configheight;  // 0x54
    void*                        userdata;      // 0x58
};

// size = 0x84
// struct FMOD_DSP_DESCRIPTION_EX : public FMOD_DSP_DESCRIPTION, public LinkedListNode
struct FMOD_DSP_DESCRIPTION_EX {
    FMOD_DSP_DESCRIPTION _0;                    // 0x00
    FMOD__LinkedListNode _1;                    // 0x5C
    FMOD_SOUND_FORMAT    mFormat;               // 0x68
    FMOD_DSP_TYPE        mType;                 // 0x6C
    int32_t              mSize;                 // 0x70
    FMOD_DSP_CATEGORY    mCategory;             // 0x74
    FMOD_OS_LIBRARY*     mModule;               // 0x78
    void*                mAEffect;              // 0x7C
    int32_t              mResamplerBlockLength; // 0x80

    //     //
    // int32_t mResamplerBlockLength; // 0x70
    // uint32_t mHandle; // 0x74
    // DSPI* mDSPSoundCard; // 0x78
    // FMOD_DSP_GETMEMORYUSED getmemoryused;
};

// size >= 0xE0
// size ~= 0xF4
struct FMOD__DSPI {
    FMOD__Plugin            _0;                // 0x00
    FMOD_DSP_STATE          _1;                // 0x18
    FMOD__LinkedListNode    mInputHead;        // 0x20
    FMOD__LinkedListNode    mOutputHead;       // 0x2C
    int32_t                 mNumInputs;        // 0x38
    int32_t                 mNumOutputs;       // 0x3C
    float*                  mOutputBuffer;     // 0x40
    int32_t                 mTargetFrequency;  // 0x44
    int32_t                 mTreeLevel;        // 0x48
    FMOD_DSP_DESCRIPTION_EX mDescription;      // 0x4C
    float                   mDefaultVolume;    // 0xD0
    float                   mDefaultFrequency; // 0xD4
    float                   mDefaultPan;       // 0xD8
    int32_t                 mDefaultPriority;  // 0xDC
    float*                  mBuffer;           // 0xE0
    int32_t  mBufferChannels; // 0xE4 unconfirmed: assumed to be present despite no evidence of use
    uint32_t mFlags;          // 0xE8
    uint8_t* mWantsToFinish;  // 0xEC
    uint8_t  mWantsToFinishMem; // 0xF0
};

// size = 0x104
struct FMOD__DSPFilter {
    FMOD__DSPI _;                // 0x000
    float*     mHistoryBuffer;   // 0x0F4
    uint32_t   mHistoryPosition; // 0x0F8
    int32_t    mHistoryLength;   // 0x0FC
    int32_t    mBufferChannels;  // 0x100
};

// size >= 0x150
// size = 160 on mac
// size = 168 on windows
struct FMOD__DSPResampler {
    FMOD__DSPFilter _; // 0x000
    // (64-bit alignment) uint32_t        unk104;             // 0x104
    FMOD_UINT64P mPosition;               // 0x108
    FMOD_SINT64P mSpeed;                  // 0x110 confirmed
    float        mFrequency;              // 0x118 confirmed
    int32_t      mTargetFrequency;        // 0x11C confirmed
    FMOD_UINT64P mResamplePosition;       // 0x120
    void*        mResampleBufferMemory;   // 0x128
    void*        mResampleBuffer;         // 0x12C
    int32_t      mResampleBufferChannels; // 0x130
    uint32_t     mResampleBlockLength;    // 0x134
    uint32_t     mResampleBufferLength;   // 0x138
    uint32_t     mResampleBufferPos;      // 0x13C
    uint32_t     mResampleFinishPos;      // 0x140
    uint32_t     mOverflowLength;         // 0x144
    uint32_t     mReadPosition;           // 0x148
    int32_t      mFill;                   // 0x14C
    uint32_t     mLength;                 // 0x150
    uint32_t     mLoopStart;              // 0x154
    int32_t      mLoopLength;             // 0x158
    uint32_t     mLoopCount;              // 0x15C
    FMOD_MODE    mMode;                   // 0x160
};

// size = 0x168
// it is not certain whether this extends the DSPResampler structure any
struct FMOD__DSPResamplerMultiInput {
    FMOD__DSPResampler _;
};

// size = [0x110]
struct FMOD__DSPCodecPool {
    FMOD__SystemI*   mSystem;         // 0x000
    int32_t          mNumDSPCodecs;   // 0x004
    FMOD__DSPCodec** mPool;           // 0x008
    bool             mAllocated[256]; // 0x00C
    uint8_t*         mReadBuffer;     // 0x10C
};

// size = 0x118
struct FMOD__DSPWaveTable {
    FMOD__DSPI                  _;          // 0x000
    FMOD_UINT64P                mPosition;  // 0x0F8
    FMOD_SINT64P                mSpeed;     // 0x100
    FMOD__DSPWAVETABLE_SPEEDDIR mDirection; // 0x108
    uint32_t                    mFrequency; // 0x10C
    FMOD__ChannelReal*          mChannel;   // 0x110
    FMOD__SoundI*               mSound;     // 0x114
};

struct FMOD_OUTPUT_STATE {
    void*                     plugindata;
    FMOD_OUTPUT_READFROMMIXER readfrommixer;
};

// size = 0x34 (mac)
struct FMOD_OUTPUT_DESCRIPTION {
    const char*                       name;          // 0x00
    uint32_t                          version;       // 0x04
    int32_t                           polling;       // 0x08
    FMOD_OUTPUT_GETNUMDRIVERSCALLBACK getnumdrivers; // 0x0C
    FMOD_OUTPUT_GETDRIVERNAMECALLBACK getdrivername; // 0x10
    FMOD_OUTPUT_GETDRIVERCAPSCALLBACK getdrivercaps; // 0x14
    FMOD_OUTPUT_INITCALLBACK          init;          // 0x18
    FMOD_OUTPUT_CLOSECALLBACK         close;         // 0x1C
    FMOD_OUTPUT_UPDATECALLBACK        update;        // 0x20
    FMOD_OUTPUT_GETHANDLECALLBACK     gethandle;     // 0x24
    FMOD_OUTPUT_GETPOSITIONCALLBACK   getposition;   // 0x28
    FMOD_OUTPUT_LOCKCALLBACK          lock;          // 0x2C
    FMOD_OUTPUT_UNLOCKCALLBACK        unlock;        // 0x30
};

// size = 0x98
// struct FMOD_OUTPUT_DESCRIPTION_EX : public FMOD_OUTPUT_DESCRIPTION, public LinkedListNode
struct FMOD_OUTPUT_DESCRIPTION_EX {
    FMOD_OUTPUT_DESCRIPTION                 _0;                   // 0x00
    FMOD__LinkedListNode                    _1;                   // 0x34
    FMOD_OUTPUTTYPE                         mType;                // 0x40
    int32_t                                 mSize;                // 0x44
    FMOD_OS_LIBRARY*                        mModule;              // 0x48
    FMOD_OUTPUT_GETSAMPLEMAXCHANNELS        getsamplemaxchannels; // 0x4C
    FMOD_OUTPUT_GETDRIVERCAPSEXCALLBACK     getdrivercapsex;      // 0x50
    FMOD_OUTPUT_GETDRIVERCAPSEX2CALLBACK    getdrivercapsex2;     // 0x54
    FMOD_OUTPUT_INITEXCALLBACK              initex;               // 0x58
    FMOD_OUTPUT_STARTCALLBACK               start;                // 0x5C
    FMOD_OUTPUT_STOPCALLBACK                stop;                 // 0x60
    FMOD_OUTPUT_UPDATEFINISHEDCALLBACK      updatedfinished;      // 0x64
    FMOD_OUTPUT_CREATESAMPLECALLBACK        createsample;         // 0x68
    FMOD_OUTPUT_GETSOUNDRAMCALLBACK         getsoundram;          // 0x6C
    FMOD_OUTPUT_POSTMIXCALLBACK             postmixcallback;      // 0x70
    FMOD_OUTPUT_GETNUMDRIVERSCALLBACK       record_getnumdrivers; // 0x74
    FMOD_OUTPUT_GETDRIVERINFOCALLBACK       record_getdriverinfo; // 0x78
    FMOD_OUTPUT_RECORDGETDRIVERCAPSCALLBACK record_getdrivercaps; // 0x7C
    FMOD_OUTPUT_RECORDSTARTCALLBACK         record_start;         // 0x80
    FMOD_OUTPUT_RECORDSTOPCALLBACK          record_stop;          // 0x84
    FMOD_OUTPUT_RECORDGETPOSITIONCALLBACK   record_getposition;   // 0x88
    FMOD_OUTPUT_RECORDLOCKCALLBACK          record_lock;          // 0x8C
    FMOD_OUTPUT_RECORDUNLOCKCALLBACK        record_unlock;        // 0x90
    FMOD_OUTPUT_SETREVERBCALLBACK           reverb_setproperties; // 0x94
        // FMOD_OUTPUT_GETSAMPLEMAXCHANNELS        getsamplemaxchannels;  // 0x50
        // FMOD_OUTPUT_GETDRIVERINFOCALLBACK       getdriverinfo;         // 0x54
        // FMOD_OUTPUT_GETDRIVERINFOWCALLBACK      getdriverinfow;        // 0x58
        // FMOD_OUTPUT_GETDRIVERCAPSEXCALLBACK     getdrivercapsex;       // 0x5C
        // FMOD_OUTPUT_GETDRIVERCAPSEX2CALLBACK    getdrivercapsex2;      // 0x60
        // FMOD_OUTPUT_INITEXCALLBACK              initex;                // 0x64
        // FMOD_OUTPUT_STARTCALLBACK               start;                 // 0x68
        // FMOD_OUTPUT_STOPCALLBACK                stop;                  // 0x6C
        // FMOD_OUTPUT_UPDATEFINISHEDCALLBACK      updatefinished;        // 0x70
        // FMOD_OUTPUT_CREATESAMPLECALLBACK        createsample;          // 0x74
        // FMOD_OUTPUT_GETSOUNDRAMCALLBACK         getsoundram;           // 0x78
        // FMOD_OUTPUT_POSTMIXCALLBACK             postmixcallback;       // 0x7C
        // FMOD_OUTPUT_GETNUMDRIVERSCALLBACK       record_getnumdrivers;  // 0x80
        // FMOD_OUTPUT_GETDRIVERINFOCALLBACK       record_getdriverinfo;  // 0x84
        // FMOD_OUTPUT_GETDRIVERINFOWCALLBACK      record_getdriverinfow; // 0x88
        // FMOD_OUTPUT_RECORDGETDRIVERCAPSCALLBACK record_getdrivercaps;  // 0x8C
        // FMOD_OUTPUT_RECORDSTARTCALLBACK         record_start;          // 0x90
        // FMOD_OUTPUT_RECORDSTOPCALLBACK          record_stop;
        // FMOD_OUTPUT_RECORDGETPOSITIONCALLBACK   record_getposition;
        // FMOD_OUTPUT_RECORDLOCKCALLBACK          record_lock;
        // FMOD_OUTPUT_RECORDUNLOCKCALLBACK        record_unlock;
        // FMOD_OUTPUT_SETREVERBCALLBACK           reverb_setproperties;
        // // FMOD_OUTPUT_GETMEMORYUSED               getmemoryused;
};

// size = 0x270
struct FMOD__PluginFactory {
    char                       mPluginPath[256]; // 0x000
    FMOD_CODEC_DESCRIPTION_EX  mCodecHead;       // 0x100
    FMOD_DSP_DESCRIPTION_EX    mDSPHead;         // 0x150
    FMOD_OUTPUT_DESCRIPTION_EX mOutputHead;      // 0x1D4
    FMOD__SystemI*             mSystem;          // 0x26C
};

// FMOD::MemPool
struct FMOD__MemPool {
    uint8_t* mBitmap;                       // 0x000
    uint8_t* mData;                         // 0x004
    bool     mCustomPool;                   // 0x008
    int32_t  mSizeBytes;                    // 0x00C
    int32_t  mSizeBlocks;                   // 0x010
    int32_t  mNumBlocks;                    // 0x014
    int32_t  mMaxBlocks;                    // 0x018
    uint32_t mCurrentAllocated[33];         // 0x020
    uint32_t mCurrentAllocatedThreadID[32]; // 0x0A0
    uint32_t mMaxAllocated;                 // 0x120
    int32_t  mActualMaxBytes;               // 0x124
    int32_t  mWastage;                      // 0x128
    int32_t  mFirstFreeBlock;               // 0x12C
    //
    FMOD_MEMORY_ALLOCCALLBACK   mAlloc;     // 0x130
    FMOD_MEMORY_REALLOCCALLBACK mRealloc;   // 0x134
    FMOD_MEMORY_FREECALLBACK    mFree;      // 0x138
    FMOD_OS_CRITICALSECTION*    mCrit;      // 0x13C
    int32_t                     mBlockSize; // 0x140
};

struct FMOD__MemSingleton {
    void*   mBuffer;
    int32_t mRefCount;
};

// FMOD::Global
struct FMOD__Global {
    FMOD__SystemI* gSystemHead;        // 0x000
    FMOD__MemPool* gSystemPool;        // 0x004
    int32_t        gSystemInitCount;   // 0x008
    FMOD_UINT64P   gDSPClock;          // 0x010
    uint32_t       gDSPClockTimeStamp; // 0x018
    int32_t        gFileBusy;          // 0x01C
};

// FMOD::MemBlockHeader
struct FMOD__MemBlockHeader {
    int32_t  mSize;
    int32_t  mNumBlocks;
    int32_t  mBlockOffset;
    uint32_t mThreadID;
};

// class TagNode : public LinkedListNode

// this is not yet confirmed:
struct FMOD__TagNode {
    FMOD__LinkedListNode _;              // 0x000
    FMOD_TAGTYPE         mType;          // 0x00C
    FMOD_TAGDATATYPE     mDataType;      // 0x010
    char*                mName;          // 0x014
    void*                mData[2];       // 0x018
    uint32_t             mDataLen;       // 0x020
    bool                 mUpdated;       // 0x024
    bool                 mUnique;        // 0x025
    int32_t              mCurrentBuffer; // 0x028
};

// size = [0x2C]
struct FMOD__Metadata {
    FMOD__TagNode mList;
};

// size = 0x154
struct FMOD__FileThread {
    FMOD__LinkedListNode     _;                // 0x000
    FMOD__Thread             mThread;          // 0x00C
    bool                     mThreadActive;    // 0x130
    FMOD__LinkedListNode     mFileListHead;    // 0x134
    FMOD__LinkedListNode*    mFileListCurrent; // 0x140
    FMOD__LinkedListNode*    mFileListNext;    // 0x144
    FMOD_OS_CRITICALSECTION* mFileListCrit;    // 0x148
    int32_t                  mDeviceType;      // 0x14C
    bool                     mOwned;           // 0x150
};

#define INTERFACE FMOD__File
struct FMOD__File__v_table {
    P_METHOD(FMOD_RESULT, _00_getMetadata, FMOD__Metadata** metadata);
    P_METHOD(FMOD_RESULT, _01_getSize, uint32_t* size);
    P_METHOD(FMOD_RESULT, _02_reallyOpen, const char* name_or_data, uint32_t* filesize);
    E_METHOD(FMOD_RESULT, _03_reallyClose);
    P_METHOD(FMOD_RESULT, _04_reallyRead, void* buffer, uint32_t size, uint32_t* read);
    P_METHOD(FMOD_RESULT, _05_reallySeek, uint32_t pos);
    E_METHOD(FMOD_RESULT, _06_reallyCancel);
};
#undef INTERFACE

// size >= 0x1A0
struct FMOD__File {
    FMOD__File__v_table* v_table;         // 0x00 TODO
    FMOD__LinkedListNode _;               // 0x004
    uint32_t             mLength;         // 0x010
    uint32_t             mLengthOriginal; // 0x014
    uint32_t             mFileSize;       // 0x018
    bool    mBufferIsString; // 0x01C invented name: equivalent to mFlags & FMOD_FILE_BUFFERISSTRING
    void*   mRiderUserData;  // 0x020
    void*   mRiderHandle;    // 0x024
    bool    mUnicode;        // 0x028  invented name: equivalent to mFlags & FMOD_FILE_UNICODE
    int32_t mDeviceType;     // 0x02C
    char    mName[256];      // 0x030
    char    mEncryptionKey[32];             // 0x130
    uint32_t          mEncryptionKeyLength; // 0x150
    int32_t           mEncryptionKeyIndex;  // 0x154
    uint32_t          mBufferPos;           // 0x158
    uint32_t          mBufferSize;          // 0x15C
    uint32_t          mBufferSkip;          // 0x160
    uint32_t          mBlockSize;           // 0x164
    uint32_t          mBlockOffset;         // 0x168
    uint32_t          mCurrentPosition;     // 0x16C
    uint32_t          mNextPosition;        // 0x170
    uint32_t          mNextPositionDisplay; // 0x174
    uint32_t          mStartOffset;         // 0x178
    bool              mBigEndian; // 0x17C invented name: equivalent to mFlags & FMOD_FILE_BIGENDIAN
    bool              mBusy;      // 0x17D invented name: equivalent to mFlags & FMOD_FILE_BUSY
    bool              mStarving;  // 0x17E invented name: equivalent to mFlags & FMOD_FILE_STARVING
    bool              mExit;      // 0x17F invented name: equivalent to mFlags & FMOD_FILE_EXIT
    int32_t           mPercentBuffered; // 0x180
    FMOD_RESULT       mAsyncError;      // 0x184
    bool              mFlipping;   // 0x188 invented name: equivalent to mFlags & FMOD_FILE_FLIPPING
    FMOD__FileThread* mFileThread; // 0x18C
    FMOD_OS_SEMAPHORE* mSema;      // 0x190
    bool               mSeekable;  // 0x194 invented name: equivalent to mFlags & FMOD_FILE_SEEKABLE
    FMOD__SystemI*     mSystem;    // 0x198
    void*              mBuffer;    // 0x19C
};

// size = 0x2FC
struct FMOD__NetFile {
    FMOD__File     _;                 // 0x000
    void*          mHandle;           // 0x1A0
    int32_t        mProtocol;         // 0x1A4
    uint32_t       unk1A8;            // 0x1A8
    uint32_t       unk1AC;            // 0x1AC
    int32_t        mMetaint;          // 0x1B0
    uint32_t       mBytesBeforeMeta;  // 0x1B4
    char*          mMetabuf;          // 0x1B8
    int32_t        mMetaFormat;       // 0x1BC
    FMOD__Metadata mMetadata;         // 0x1C0
    uint32_t       unk1EC;            // 0x1EC
    uint32_t       unk1F0;            // 0x1F0
    uint32_t       unk1F4;            // 0x1F4
    uint32_t       unk1F8;            // 0x1F8
    uint32_t       unk1FC;            // 0x1FC
    uint32_t       unk200;            // 0x200
    uint32_t       unk204;            // 0x204
    uint32_t       unk208;            // 0x208
    uint32_t       unk20C;            // 0x20C
    uint32_t       unk210;            // 0x210
    uint32_t       unk214;            // 0x214
    uint32_t       unk218;            // 0x218
    uint32_t       unk21C;            // 0x21C
    uint32_t       unk220;            // 0x220
    uint32_t       unk224;            // 0x224
    uint32_t       unk228;            // 0x228
    uint32_t       unk22C;            // 0x22C
    uint32_t       unk230;            // 0x230
    uint32_t       unk234;            // 0x234
    uint32_t       unk238;            // 0x238
    uint32_t       unk23C;            // 0x23C
    uint32_t       unk240;            // 0x240
    uint32_t       unk244;            // 0x244
    uint32_t       unk248;            // 0x248
    uint32_t       unk24C;            // 0x24C
    uint32_t       unk250;            // 0x250
    uint32_t       unk254;            // 0x254
    uint32_t       unk258;            // 0x258
    uint32_t       unk25C;            // 0x25C
    uint32_t       unk260;            // 0x260
    uint32_t       unk264;            // 0x264
    uint32_t       unk268;            // 0x268
    uint32_t       unk26C;            // 0x26C
    uint32_t       unk270;            // 0x270
    uint32_t       unk274;            // 0x274
    uint32_t       unk278;            // 0x278
    uint32_t       unk27C;            // 0x27C
    uint32_t       unk280;            // 0x280
    uint32_t       unk284;            // 0x284
    uint32_t       unk288;            // 0x288
    uint32_t       unk28C;            // 0x28C
    uint32_t       unk290;            // 0x290
    uint32_t       unk294;            // 0x294
    uint32_t       unk298;            // 0x298
    uint32_t       unk29C;            // 0x29C
    uint32_t       unk2A0;            // 0x2A0
    uint32_t       unk2A4;            // 0x2A4
    uint32_t       unk2A8;            // 0x2A8
    uint32_t       unk2AC;            // 0x2AC
    uint32_t       unk2B0;            // 0x2B0
    uint32_t       unk2B4;            // 0x2B4
    uint32_t       unk2B8;            // 0x2B8
    uint32_t       unk2BC;            // 0x2BC
    uint32_t       unk2C0;            // 0x2C0
    uint32_t       unk2C4;            // 0x2C4
    uint32_t       unk2C8;            // 0x2C8
    uint32_t       unk2CC;            // 0x2CC
    uint32_t       unk2D0;            // 0x2D0
    uint32_t       unk2D4;            // 0x2D4
    uint32_t       unk2D8;            // 0x2D8
    uint32_t       unk2DC;            // 0x2DC
    uint32_t       unk2E0;            // 0x2E0
    uint32_t       unk2E4;            // 0x2E4
    uint32_t       unk2E8;            // 0x2E8
    uint32_t       unk2EC;            // 0x2EC
    uint32_t       unk2F0;            // 0x2F0
    bool           mChunked;          // 0x2F4
    uint32_t       mBytesLeftInChunk; // 0x2F8
};

// class DiskFile : public File
struct FMOD__DiskFile {
    FMOD__File _;       // 0x000
    void*      mHandle; // 0x1A0
};

struct FMOD__MemoryFile {
    FMOD__File _;         // 0x000
    uint32_t   mPosition; // 0x1A0
    void*      mMem;      // 0x1A4
};

// size = [0x1B8]
struct FMOD__UserFile {
    FMOD__File              _;              // 0x000
    FMOD_FILE_OPENCALLBACK  mOpenCallback;  // 0x1A0
    FMOD_FILE_CLOSECALLBACK mCloseCallback; // 0x1A4
    FMOD_FILE_READCALLBACK  mReadCallback;  // 0x1A8
    FMOD_FILE_SEEKCALLBACK  mSeekCallback;  // 0x1AC
    void*                   mHandle;        // 0x1B0
    void*                   mUserData;      // 0x1B4
};

struct FMOD__NullFile {
    FMOD__File _;         // 0x000
    uint32_t   mPosition; // 0x1A0
};

// size = 0x20C
struct FMOD__CddaFile {
    FMOD__File        _;                 // 0x000
    FMOD_CDDA_DEVICE* mDevice;           // 0x1A0
    char*             mReadBuf;          // 0x1A4
    char*             mReadPtr;          // 0x1A8
    uint32_t          mReadSizebytes;    // 0x1AC
    uint32_t          mStartSector;      // 0x1B0
    uint32_t          mCurrentSector;    // 0x1B4
    uint32_t          mSectorsInChunk;   // 0x1B8
    uint32_t          mSectorsLeft;      // 0x1BC
    uint32_t          mJitterBuf;        // 0x1C0
    uint32_t          mJitterBufSectors; // 0x1C4
    bool              mJitterBufEmpty;   // 0x1C8
    bool              mJitterCorrection; // 0x1C9
    uint32_t          mLastTimeAccessed; // 0x1CC
    bool              mGotUserToc;       // 0x1D0
    FMOD__Metadata    mMetadata;         // 0x1D4
    int32_t           mCurrentTrack;     // 0x200
    char**            mTrackFiles;       // 0x204
    void*             mTrackHandle;      // 0x208
};

struct FMOD_CREATESOUNDEXINFO {
    int32_t                      cbsize;
    uint32_t                     length;
    uint32_t                     fileoffset;
    int32_t                      numchannels;
    int32_t                      defaultfrequency;
    FMOD_SOUND_FORMAT            format;
    uint32_t                     decodebuffersize;
    int32_t                      initialsubsound;
    int32_t                      numsubsounds;
    int32_t*                     inclusionlist;
    int32_t                      inclusionlistnum;
    FMOD_SOUND_PCMREADCALLBACK   pcmreadcallback;
    FMOD_SOUND_PCMSETPOSCALLBACK pcmsetposcallback;
    FMOD_SOUND_NONBLOCKCALLBACK  nonblockcallback;
    const char*                  dlsname;
    const char*                  encryptionkey;
    int32_t                      maxpolyphony;
    void*                        userdata;
    FMOD_SOUND_TYPE              suggestedsoundtype;
    FMOD_FILE_OPENCALLBACK       useropen;
    FMOD_FILE_CLOSECALLBACK      userclose;
    FMOD_FILE_READCALLBACK       userread;
    FMOD_FILE_SEEKCALLBACK       userseek;
    FMOD_SPEAKERMAPTYPE          speakermap;
    FMOD_SOUNDGROUP*             initialsoundgroup;
    uint32_t                     initialseekposition;
    FMOD_TIMEUNIT                initialseekpostype;
};

// size = 0x128
struct FMOD_CODEC_WAVEFORMAT {
    char              name[256];
    FMOD_SOUND_FORMAT format;
    int32_t           channels;
    int32_t           frequency;
    uint32_t          lengthbytes;
    uint32_t          lengthpcm;
    int32_t           blockalign;
    int32_t           loopstart;
    int32_t           loopend;
    FMOD_MODE         mode;
    uint32_t          channelmask;
};

struct FMOD_CODEC_STATE {
    int32_t                     numsubsounds; // 0x00
    FMOD_CODEC_WAVEFORMAT*      waveformat;   // 0x04
    void*                       plugindata;   // 0x08
    void*                       filehandle;   // 0x0C
    uint32_t                    filesize;     // 0x10
    FMOD_FILE_READCALLBACK      fileread;     // 0x14
    FMOD_FILE_SEEKCALLBACK      fileseek;     // 0x18
    FMOD_CODEC_METADATACALLBACK metadata;     // 0x1C
};

// size = 0x188
struct FMOD__AsyncData {
    char                   mName[256];    // 0x00
    FMOD__AsyncThread*     mThread;       // 0x100
    FMOD__LinkedListNode   mNode;         // 0x104
    void*                  mNameData;     // 0x110
    FMOD_CREATESOUNDEXINFO mExInfo;       // 0x114
    bool                   mExInfoExists; // 0x180
    FMOD_RESULT            mResult;       // 0x184
};

// size = 0xD8
struct FMOD__Codec {
    //
    FMOD__Plugin     _0; // 0x00
    FMOD_CODEC_STATE _1;
    // 0x18 calls to descriptor pass pointer to this, then descriptor functions sub 0x18 from pointer to hack back to plugin
    FMOD_CODEC_WAVEFORMAT*    mWaveFormatMemory;     // 0x38
    FMOD_SOUND_TYPE           mType;                 // 0x3C
    FMOD_CODEC_DESCRIPTION_EX mDescription;          // 0x40
    uint32_t                  mSrcDataOffset;        // 0x90
    uint32_t                  mLoopPoints[2];        // 0x94
    int32_t                   mSubSoundIndex;        // 0x9C
    FMOD_CODEC_FLAG           mFlags;                // 0xA0
    uint32_t                  mBlockAlign;           // 0xA4
    uint8_t*                  mReadBuffer;           // 0xA8
    uint32_t                  mReadBufferLength;     // 0xAC
    uint8_t*                  mPCMBuffer;            // 0xB0
    uint8_t*                  mPCMBufferMemory;      // 0xB4
    uint32_t                  mPCMBufferLength;      // 0xB8
    uint32_t                  mPCMBufferLengthBytes; // 0xBC
    uint32_t                  mPCMBufferOffsetBytes; // 0xC0
    uint32_t                  mPCMBufferFilledBytes; // 0xC4
    FMOD_MODE                 mMode;                 // 0xC8
    FMOD_MODE                 mOriginalMode;         // 0xCC unconfirmed
    FMOD__Metadata*           mMetadata;             // 0xD0
    FMOD__File*               mFile;                 // 0xD4
};

// size = 0xD8
struct FMOD__CodecTag {
    FMOD__Codec _;
};

// size = 0xDC
struct FMOD__CodecCDDA {
    FMOD__Codec _;             // 0x000
    int32_t     mCurrentTrack; // 0x0D8
};

struct FMOD__al_table {
    int16_t bits;
    int16_t d;
};

// size = [0x4C]
struct FMOD__MPEG_FRAME {
    FMOD__al_table* alloc;              // 0x00
    int32_t         stereo;             // 0x04
    int32_t         jsbound;            // 0x08
    int32_t         II_sblimit;         // 0x0C
    int32_t         lsf;                // 0x10
    int32_t         mpeg25;             // 0x14
    int32_t         header_change;      // 0x18
    int32_t         lay;                // 0x1C
    int32_t         error_protection;   // 0x20
    int32_t         bitrate_index;      // 0x24
    int32_t         sampling_frequency; // 0x28
    int32_t         padding;            // 0x2C
    int32_t         extension;          // 0x30
    int32_t         mode;               // 0x34
    int32_t         mode_ext;           // 0x38
    int32_t         copyright;          // 0x3C
    int32_t         original;           // 0x40
    int32_t         emphasis;           // 0x44
    int32_t         framesize;          // 0x48
};

struct FMOD__gr_info_s {
    int32_t  scfsi;
    uint32_t part2_3_length;
    uint32_t big_values;
    uint32_t scalefac_compress;
    uint32_t block_type;
    uint32_t mixed_block_flag;
    uint32_t table_select[3];
    uint32_t subblock_gain[3];
    uint32_t maxband[3];
    uint32_t maxbandl;
    uint32_t maxb;
    uint32_t region1start;
    uint32_t region2start;
    uint32_t preflag;
    uint32_t scalefac_scale;
    uint32_t count1table_select;
    float*   full_gain[3];
    float*   pow2gain;
};

struct FMOD__III_sideinfo_ch {
    FMOD__gr_info_s gr[2];
};

struct FMOD__III_sideinfo {
    uint32_t main_data_begin;
    uint32_t private_bits;

    FMOD__III_sideinfo_ch ch[2];
};

struct FMOD__bandInfoStruct {
    int32_t longIdx[23];
    int32_t longDiff[22];
    int32_t shortIdx[14];
    int32_t shortDiff[13];
};

struct FMOD__bitstream_info {
    int32_t  mBitIndex;
    uint8_t* mWordPointer;
};

// size = 0x48E8
struct FMOD__CodecMPEG_MemoryBlock {
    //
    // uint8_t              mBSSpace[2][2304];    // 0x0000
    // float                mSynthBuffsMem[1168]; // 0x1200
    // float*               mSynthBuffs;          // 0x2440
    // float                mBlock[2][2][576];    // 0x2444
    // int32_t              mFrameSize;           // 0x4844
    // int32_t              mFrameSizeOld;        // 0x4848
    // FMOD__MPEG_FRAME     mFrame;               // 0x484C
    // uint32_t             mFrameHeader;         // 0x4898
    // int32_t              mPcmPoint;            // 0x489C
    // int32_t              mBSNum;               // 0x48A0
    // int32_t              mSynthBo;             // 0x48A4
    // FMOD__bitstream_info mBSI;                 // 0x48A8
    // int32_t              mBlc[2];              // 0x4878 (confirmed)
    // int32_t              mLayer;               // 0x487C
    // uint32_t             mNumFrames;           // 0x4880
    // uint32_t*            mFrameOffset;         // 0x48C0
    // uint8_t              mXingToc[100];        // 0x4880 (confirmed)
    // bool                 mHasXingNumFrames;    // 0x48E4 (confirmed)
    // bool                 mHasXingToc;          // 0x48E5 (confirmed)

    int32_t              mFrameSize;           // 0x0000
    int32_t              mFrameSizeOld;        // 0x0004
    FMOD__MPEG_FRAME     mFrame;               // 0x0008
    uint32_t             mFrameHeader;         // 0x0054
    uint32_t             mNumFrames;           // 0x0058
    uint32_t*            mFrameOffset;         // 0x005C
    int32_t              mPcmPoint;            // 0x0060 deduction
    int32_t              mLayer;               // 0x0064
    uint8_t              mBSSpace[2][2304];    // 0x0068
    uint32_t             mBSNum;               // 0x1268
    float                mSynthBuffsMem[1152]; // 0x126C
    int32_t              mSynthBo;             // 0x246C
    FMOD__bitstream_info mBSI;                 // 0x2470
    float                mBlock[2][2][576];    // 0x2478
    int32_t              mBlc[2];              // 0x4878
    uint8_t              mXingToc[100];        // 0x4880
    bool                 mHasXingNumFrames;    // 0x48E4
    bool                 mHasXingToc;          // 0x48E5
};

// size = [0xF4]
struct FMOD__CodecMPEG {
    FMOD__Codec                  _;                    // 0x000
    FMOD__CodecMPEG_MemoryBlock* mMemoryBlock;         // 0x0D8
    FMOD__CodecMPEG_MemoryBlock* mMemoryBlockMemory;   // 0x0DC
    FMOD__SyncPoint*             mSyncPoint;           // 0x0E0
    int32_t                      mNumSyncPoints;       // 0x0E4
    uint32_t                     mPCMFrameLengthBytes; // 0x0E8
    uint8_t*                     mPCMBufferMemory;     // 0x0EC
    int32_t                      mChannels;            // 0x0F0
};

#pragma pack(push, 4)
struct FMOD__CodecFSBCache {
    FMOD__LinkedListNode _; // 0x00
    // ordinarily this would align to 0x10 (8-byte alignment due to uint64)
    FMOD_FSB_HEADER                mHeader; // 0x1C
    FMOD_FSB_SAMPLE_HEADER**       mShdr;   // 0x3C
    FMOD_FSB_SAMPLE_HEADER_BASIC** mShdrb;  // 0x40
    char*                          mShdrData;
    uint32_t*                      mDataOffset;
    int32_t                        mSharecount;
    // bool                           mStillLoading; 0x50 cannot exist at this offset
};
#pragma pack(pop)

// size = 0x13C
struct FMOD__CodecFSB {
    FMOD__Codec                    _; // 0x000
    FMOD_FSB_HEADER                mHeader;
    FMOD_FSB_SAMPLE_HEADER**       mShdr;          // 0x108
    FMOD_FSB_SAMPLE_HEADER_BASIC** mShdrb;         // 0x10C
    FMOD_FSB_SAMPLE_HEADER*        mFirstSample;   // 0x110
    uint32_t*                      mDataOffset;    // 0x114
    int32_t                        mCurrentIndex;  // 0x118
    FMOD__CodecFSBCache*           mCacheEntry;    // 0x11C
    char**                         mSyncPointData; // 0x120
    char**                         unk124;         // 0x124
    FMOD__CodecWav*                mADPCM;         // 0x128
    bool                           mDecodeADPCM;   // 0x12C
    FMOD__CodecMPEG*               mMPEG;          // 0x130
    int32_t                        mChannels;      // 0x134
    FMOD_MODE                      mUserMode;      // 0x138
};

// size = 0x13C
struct FMOD__CodecWav {
    FMOD__Codec            _;                     // 0x000
    HACMSTREAM             mACMCodec;             // 0x0D8
    WAVE_FORMATEXTENSIBLE  mDestFormat;           // 0x0DC
    uint32_t               mNumSyncPoints;        // 0x104
    FMOD__SyncPoint*       mSyncPoint;            // 0x108
    int32_t                mSamplesPerADPCMBlock; // 0x10C
    WAVE_FORMATEXTENSIBLE  mSrcFormatMemory;      // 0x110
    WAVE_FORMATEXTENSIBLE* mSrcFormat;            // 0x138
};

struct FMOD__CodecVAG_Context {
    float mS1;
    float mS2;
};

// size = 0x278
struct FMOD__CodecVAG {
    FMOD__Codec _; // 0x000
    // FMOD_CODEC_WAVEFORMAT  mWaveFormat;   // 0x0D8
    // uint8_t                mPCMBlock[56]; // 0x200
    // FMOD__CodecVAG_Context mContext[16];
    FMOD_CODEC_WAVEFORMAT  mWaveFormat;   // 0x0D8
    uint8_t                mPCMBlock[56]; // 0x200
    FMOD__CodecVAG_Context mContext[8];   // 0x238
};

// size = 0x204
struct FMOD__CodecRaw {
    FMOD__Codec           _;                     // 0x000
    FMOD_CODEC_WAVEFORMAT mWaveFormat;           // 0x0D8
    int32_t               mSamplesPerADPCMBlock; // 0x200
};

// size = 0x4D0
struct FMOD__CodecOggVorbis {
    FMOD__Codec           _;
    OggVorbis_File        mVf;            // 0x0D8
    FMOD__SyncPoint*      mSyncPoint;     // 0x3A0
    uint32_t              mNumSyncPoints; // 0x3A4
    FMOD_CODEC_WAVEFORMAT mWaveFormat;    // 0x3A8 confirmed
};

// size = 0xDC
struct FMOD__CodecAIFF {
    FMOD__Codec _;             // 0x00
    bool        mIsAIFC;       // 0xD8
    bool        mLittleEndian; // 0xD9
};

// size = 0xE0
struct FMOD__CodecFLAC {
    FMOD__Codec          _;           // 0x00
    FLAC__StreamDecoder* mDecoder;    // 0xD8
    bool                 mFrameReady; // 0xDC
};

// size = 0x450
struct FMOD__DSPCodec {
    FMOD__DSPResampler    _;            // 0x000
    int32_t               mPoolIndex;   // 0x168
    FMOD__MemoryFile      mMemoryFile;  // 0x16C
    uint32_t              mPosition;    // 0x314
    uint32_t              mNewPosition; // 0x318
    FMOD__DSPCodecPool*   mPool;        // 0x31C
    FMOD_CODEC_WAVEFORMAT mWaveFormat;  // 0x320
    FMOD__Codec*          mCodec;       // 0x448
};

// size = 0x72C0
struct FMOD__DSPCodecMPEG {
    FMOD__DSPCodec              _;                           // 0x0000
    char                        mResampleBufferMemory[9360]; // 0x0450
    FMOD__CodecMPEG             mCodecMemory;                // 0x28E0
    FMOD__CodecMPEG_MemoryBlock mCodecMemoryBlock;           // 0x29D4
};

// size = 0x820
struct FMOD__DSPCodecADPCM {
    FMOD__DSPCodec _;                          // 0x000
    char           mResampleBufferMemory[656]; // 0x450
    FMOD__CodecWav mCodecMemory;               // 0x6E0
};

// size = 0x2868
struct FMOD__DSPCodecRaw {
    FMOD__DSPCodec _;                           // 0x0000
    char           mResampleBufferMemory[8720]; // 0x0450
    FMOD__CodecRaw mCodecMemory;                // 0x2660
};

struct FMOD__SoundSentenceEntry {
    int32_t  mIndex;
    uint32_t mLength;
};

// size = 0x118
struct FMOD__SyncPoint {
    FMOD__SortedLinkedListNode _;          // 0x000
    uint32_t                   mOffset;    // 0x010
    char                       mName[256]; // 0x014
    uint32_t                   mIndex;     // 0x114
};

#define INTERFACE FMOD__SoundI
struct FMOD__SoundI__v_table {
    // FMOD::SoundI::isStream
    // FMOD::SoundI::release
    // FMOD::SoundI::getSystemObject
    // FMOD::SoundI::lock
    // FMOD::SoundI::unlock
    // FMOD::SoundI::setDefaults
    // FMOD::SoundI::getDefaults
    // FMOD::SoundI::setVariations
    // FMOD::SoundI::getVariations
    // FMOD::SoundI::set3DMinMaxDistance
    // FMOD::SoundI::get3DMinMaxDistance
    // FMOD::SoundI::set3DConeSettings
    // FMOD::SoundI::get3DConeSettings
    // FMOD::SoundI::set3DCustomRolloff
    // FMOD::SoundI::get3DCustomRolloff
    // FMOD::SoundI::setSubSound
    // FMOD::SoundI::getSubSound
    // FMOD::SoundI::setSubSoundSentence
    // FMOD::SoundI::getName
    // FMOD::SoundI::getLength
    // FMOD::SoundI::getFormat
    // FMOD::SoundI::getNumSubSounds
    // FMOD::SoundI::getNumTags
    // FMOD::SoundI::getTag
    // FMOD::SoundI::getOpenState
    // FMOD::SoundI::readData
    // FMOD::SoundI::seekData
    // FMOD::SoundI::setSoundGroup
    // FMOD::SoundI::getSoundGroup
    // FMOD::SoundI::getNumSyncPoints
    // FMOD::SoundI::getSyncPoint
    // FMOD::SoundI::getSyncPointInfo
    // FMOD::SoundI::addSyncPoint
    // FMOD::SoundI::deleteSyncPoint
    // FMOD::SoundI::setMode
    // FMOD::SoundI::getMode
    // FMOD::SoundI::setLoopCount
    // FMOD::SoundI::getLoopCount
    // FMOD::SoundI::setLoopPoints
    // FMOD::SoundI::getLoopPoints
    // FMOD::SoundI::setPosition
    // FMOD::SoundI::getPosition
    // FMOD::SoundI::setUserData
    // FMOD::SoundI::getUserData

    E_METHOD(bool, _00_isStream);
    P_METHOD(FMOD_RESULT, _01_release, bool freethis);
    P_METHOD(FMOD_RESULT, _02_getSystemObject, FMOD__System** system);
    P_METHOD(
        FMOD_RESULT,
        _03_lock,
        uint32_t  offset,
        uint32_t  length,
        void**    ptr1,
        void**    ptr2,
        uint32_t* len1,
        uint32_t* len2);
    P_METHOD(FMOD_RESULT, _04_unlock, void* ptr1, void* ptr2, uint32_t len1, uint32_t len2);
    P_METHOD(
        FMOD_RESULT,
        _05_setDefaults,
        float   frequency,
        float   volume,
        float   pan,
        int32_t priority);
    P_METHOD(
        FMOD_RESULT,
        _06_getDefaults,
        float*   frequency,
        float*   volume,
        float*   pan,
        int32_t* priority);
    P_METHOD(FMOD_RESULT, _07_setVariations, float frequencyvar, float volumevar, float panvar);
    P_METHOD(FMOD_RESULT, _08_getVariations, float* frequencyvar, float* volumevar, float* panvar);
    P_METHOD(FMOD_RESULT, _09_set3DMinMaxDistance, float min, float max);
    P_METHOD(FMOD_RESULT, _10_get3DMinMaxDistance, float* min, float* max);
    P_METHOD(
        FMOD_RESULT,
        _11_set3DConeSettings,
        float insideconeangle,
        float outsideconeangle,
        float outsidevolume);
    P_METHOD(
        FMOD_RESULT,
        _12_get3DConeSettings,
        float* insideconeangle,
        float* outsideconeangle,
        float* outsidevolume);
    P_METHOD(FMOD_RESULT, _13_set3DCustomRolloff, FMOD_VECTOR* points, int32_t numpoints);
    P_METHOD(FMOD_RESULT, _14_get3DCustomRolloff, FMOD_VECTOR** points, int32_t* numpoints);
    P_METHOD(FMOD_RESULT, _15_setSubSound, int32_t index, FMOD__SoundI* subsound);
    P_METHOD(FMOD_RESULT, _16_getSubSound, int32_t index, FMOD__SoundI** subsound);
    P_METHOD(FMOD_RESULT, _17_setSubSoundSentence, int32_t* subsoundlist, int32_t numsubsounds);
    P_METHOD(FMOD_RESULT, _18_getName, char* name, int32_t namelen);
    P_METHOD(FMOD_RESULT, _19_getLength, uint32_t* length, FMOD_TIMEUNIT lengthtype);
    P_METHOD(
        FMOD_RESULT,
        _20_getFormat,
        FMOD_SOUND_TYPE*   type,
        FMOD_SOUND_FORMAT* format,
        int32_t*           channels,
        int32_t*           bits);
    P_METHOD(FMOD_RESULT, _21_getNumSubSounds, int32_t* numsubsounds);
    P_METHOD(FMOD_RESULT, _22_getNumTags, int32_t* numtags, int32_t* numtagsupdated);
    P_METHOD(FMOD_RESULT, _23_getTag, const char* name, int32_t index, FMOD_TAG* tag);
    P_METHOD(
        FMOD_RESULT,
        _24_getOpenState,
        FMOD_OPENSTATE* openstate,
        uint32_t*       percentbuffered,
        bool*           starving);
    P_METHOD(FMOD_RESULT, _25_readData, void* buffer, uint32_t lenbytes, uint32_t* read);
    P_METHOD(FMOD_RESULT, _26_seekData, uint32_t pcm);
    P_METHOD(FMOD_RESULT, _27_setSoundGroup, FMOD__SoundGroupI* soundgroup);
    P_METHOD(FMOD_RESULT, _28_getSoundGroup, FMOD__SoundGroupI** soundgroup);
    P_METHOD(FMOD_RESULT, _29_getNumSyncPoints, int32_t* numsyncpoints);
    P_METHOD(FMOD_RESULT, _30_getSyncPoint, int32_t index, FMOD_SYNCPOINT** point);
    P_METHOD(
        FMOD_RESULT,
        _31_getSyncPointInfo,
        FMOD_SYNCPOINT* point,
        char*           name,
        int32_t         namelen,
        uint32_t*       offset,
        FMOD_TIMEUNIT   offsettype);
    P_METHOD(
        FMOD_RESULT,
        _32_addSyncPoint,
        uint32_t         offset,
        FMOD_TIMEUNIT    offsettype,
        const char*      name,
        FMOD_SYNCPOINT** point,
        int32_t          subsound,
        bool             fixupindicies);
    P_METHOD(FMOD_RESULT, _33_deleteSyncPoint, FMOD_SYNCPOINT* point);
    P_METHOD(FMOD_RESULT, _34_setMode, FMOD_MODE mode);
    P_METHOD(FMOD_RESULT, _35_getMode, FMOD_MODE* mode);
    P_METHOD(FMOD_RESULT, _36_setLoopCount, int32_t loopcount);
    P_METHOD(FMOD_RESULT, _37_getLoopCount, int32_t* loopcount);
    P_METHOD(
        FMOD_RESULT,
        _38_setLoopPoints,
        uint32_t      loopstart,
        FMOD_TIMEUNIT loopstarttype,
        uint32_t      loopend,
        FMOD_TIMEUNIT loopendtype);
    P_METHOD(
        FMOD_RESULT,
        _39_getLoopPoints,
        uint32_t*     loopstart,
        FMOD_TIMEUNIT loopstarttype,
        uint32_t*     loopend,
        FMOD_TIMEUNIT loopendtype);
    P_METHOD(FMOD_RESULT, _40_setPosition, uint32_t position);
    P_METHOD(FMOD_RESULT, _41_getPosition, uint32_t* position);
    P_METHOD(FMOD_RESULT, _42_setUserData, void* userdata);
    P_METHOD(FMOD_RESULT, _43_getUserData, void** userdata);
};
#undef INTERFACE

// overlaps FMOD::SoundI::v_table
#define INTERFACE FMOD__Sample
struct FMOD__Sample__v_table {
    E_METHOD(bool, _00_isStream);
    P_METHOD(FMOD_RESULT, _01_release, bool freethis);
    P_METHOD(FMOD_RESULT, _02_getSystemObject, FMOD__System** system);
    P_METHOD(
        FMOD_RESULT,
        _03_lock,
        uint32_t  offset,
        uint32_t  length,
        void**    ptr1,
        void**    ptr2,
        uint32_t* len1,
        uint32_t* len2);
    P_METHOD(FMOD_RESULT, _04_unlock, void* ptr1, void* ptr2, uint32_t len1, uint32_t len2);
    P_METHOD(
        FMOD_RESULT,
        _05_setDefaults,
        float   frequency,
        float   volume,
        float   pan,
        int32_t priority);
    P_METHOD(
        FMOD_RESULT,
        _06_getDefaults,
        float*   frequency,
        float*   volume,
        float*   pan,
        int32_t* priority);
    P_METHOD(FMOD_RESULT, _07_setVariations, float frequencyvar, float volumevar, float panvar);
    P_METHOD(FMOD_RESULT, _08_getVariations, float* frequencyvar, float* volumevar, float* panvar);
    P_METHOD(FMOD_RESULT, _09_set3DMinMaxDistance, float min, float max);
    P_METHOD(FMOD_RESULT, _10_get3DMinMaxDistance, float* min, float* max);
    P_METHOD(
        FMOD_RESULT,
        _11_set3DConeSettings,
        float insideconeangle,
        float outsideconeangle,
        float outsidevolume);
    P_METHOD(
        FMOD_RESULT,
        _12_get3DConeSettings,
        float* insideconeangle,
        float* outsideconeangle,
        float* outsidevolume);
    P_METHOD(FMOD_RESULT, _13_set3DCustomRolloff, FMOD_VECTOR* points, int32_t numpoints);
    P_METHOD(FMOD_RESULT, _14_get3DCustomRolloff, FMOD_VECTOR** points, int32_t* numpoints);
    P_METHOD(FMOD_RESULT, _15_setSubSound, int32_t index, FMOD__SoundI* subsound);
    P_METHOD(FMOD_RESULT, _16_getSubSound, int32_t index, FMOD__SoundI** subsound);
    P_METHOD(FMOD_RESULT, _17_setSubSoundSentence, int32_t* subsoundlist, int32_t numsubsounds);
    P_METHOD(FMOD_RESULT, _18_getName, char* name, int32_t namelen);
    P_METHOD(FMOD_RESULT, _19_getLength, uint32_t* length, FMOD_TIMEUNIT lengthtype);
    P_METHOD(
        FMOD_RESULT,
        _20_getFormat,
        FMOD_SOUND_TYPE*   type,
        FMOD_SOUND_FORMAT* format,
        int32_t*           channels,
        int32_t*           bits);
    P_METHOD(FMOD_RESULT, _21_getNumSubSounds, int32_t* numsubsounds);
    P_METHOD(FMOD_RESULT, _22_getNumTags, int32_t* numtags, int32_t* numtagsupdated);
    P_METHOD(FMOD_RESULT, _23_getTag, const char* name, int32_t index, FMOD_TAG* tag);
    P_METHOD(
        FMOD_RESULT,
        _24_getOpenState,
        FMOD_OPENSTATE* openstate,
        uint32_t*       percentbuffered,
        bool*           starving);
    P_METHOD(FMOD_RESULT, _25_readData, void* buffer, uint32_t lenbytes, uint32_t* read);
    P_METHOD(FMOD_RESULT, _26_seekData, uint32_t pcm);
    P_METHOD(FMOD_RESULT, _27_setSoundGroup, FMOD__SoundGroupI* soundgroup);
    P_METHOD(FMOD_RESULT, _28_getSoundGroup, FMOD__SoundGroupI** soundgroup);
    P_METHOD(FMOD_RESULT, _29_getNumSyncPoints, int32_t* numsyncpoints);
    P_METHOD(FMOD_RESULT, _30_getSyncPoint, int32_t index, FMOD_SYNCPOINT** point);
    P_METHOD(
        FMOD_RESULT,
        _31_getSyncPointInfo,
        FMOD_SYNCPOINT* point,
        char*           name,
        int32_t         namelen,
        uint32_t*       offset,
        FMOD_TIMEUNIT   offsettype);
    P_METHOD(
        FMOD_RESULT,
        _32_addSyncPoint,
        uint32_t         offset,
        FMOD_TIMEUNIT    offsettype,
        const char*      name,
        FMOD_SYNCPOINT** point,
        int32_t          subsound,
        bool             fixupindicies);
    P_METHOD(FMOD_RESULT, _33_deleteSyncPoint, FMOD_SYNCPOINT* point);
    P_METHOD(FMOD_RESULT, _34_setMode, FMOD_MODE mode);
    P_METHOD(FMOD_RESULT, _35_getMode, FMOD_MODE* mode);
    P_METHOD(FMOD_RESULT, _36_setLoopCount, int32_t loopcount);
    P_METHOD(FMOD_RESULT, _37_getLoopCount, int32_t* loopcount);
    P_METHOD(
        FMOD_RESULT,
        _38_setLoopPoints,
        uint32_t      loopstart,
        FMOD_TIMEUNIT loopstarttype,
        uint32_t      loopend,
        FMOD_TIMEUNIT loopendtype);
    P_METHOD(
        FMOD_RESULT,
        _39_getLoopPoints,
        uint32_t*     loopstart,
        FMOD_TIMEUNIT loopstarttype,
        uint32_t*     loopend,
        FMOD_TIMEUNIT loopendtype);
    P_METHOD(FMOD_RESULT, _40_setPosition, uint32_t position);
    P_METHOD(FMOD_RESULT, _41_getPosition, uint32_t* position);
    P_METHOD(FMOD_RESULT, _42_setUserData, void* userdata);
    P_METHOD(FMOD_RESULT, _43_getUserData, void** userdata);
    // FMOD::Sample methods
    P_METHOD(
        FMOD_RESULT,
        _44_lockInternal,
        uint32_t  offset,
        uint32_t  length,
        void**    ptr1,
        void**    ptr2,
        uint32_t* len1,
        uint32_t* len2);
    P_METHOD(FMOD_RESULT, _45_unlockInternal, void* ptr1, void* ptr2, uint32_t len1, uint32_t len2);
    P_METHOD(FMOD_RESULT, _46_setBufferData, void* data);
};
#undef INTERFACE

// must be at least 0xE4
// the true size of this must be revealed by SoundI::getMemoryUsedImpl
//    class SoundI : public LinkedListNode
struct FMOD__SoundI {
    FMOD__Sample__v_table*       v_table;                  // 0x00
    FMOD__LinkedListNode         _;                        // 0x04
    FMOD_SOUND_TYPE              mType;                    // 0x10
    FMOD_SOUND_FORMAT            mFormat;                  // 0x14
    FMOD_MODE                    mMode;                    // 0x18
    char*                        mName;                    // 0x1C
    uint32_t                     mPosition;                // 0x20
    uint32_t                     mLength;                  // 0x24
    uint32_t                     mLengthBytes;             // 0x28
    uint32_t                     mLoopStart;               // 0x2C
    uint32_t                     mLoopLength;              // 0x30
    int32_t                      mLoopCount;               // 0x34
    FMOD_SOUND_FLAG              mFlags;                   // 0x38
    FMOD__Codec*                 mCodec;                   // 0x3C
    int32_t                      mChannels;                // 0x40
    float                        mDefaultVolume;           // 0x44
    float                        mDefaultFrequency;        // 0x48
    float                        mDefaultPan;              // 0x4C
    int32_t                      mDefaultPriority;         // 0x50
    uint32_t                     mDefaultChannelMask;      // 0x54
    float                        mFrequencyVariation;      // 0x58
    float                        mVolumeVariation;         // 0x5C
    float                        mPanVariation;            // 0x60
    float                        mMinDistance;             // 0x64
    float                        mMaxDistance;             // 0x68
    float                        mConeInsideAngle;         // 0x6C
    float                        mConeOutsideAngle;        // 0x70
    float                        mConeOutsideVolume;       // 0x74
    FMOD_VECTOR*                 mRolloffPoint;            // 0x78
    int32_t                      mNumRolloffPoints;        // 0x7C
    FMOD__SoundI**               mSubSound;                // 0x80
    FMOD__SoundI*                mSubSoundShared;          // 0x84
    int32_t                      mNumSubSounds;            // 0x88
    int32_t                      mNumActiveSubSounds;      // 0x8C
    FMOD__SoundI*                mSubSoundParent;          // 0x90
    int32_t                      mSubSoundIndex;           // 0x94
    FMOD__SoundSentenceEntry*    mSubSoundList;            // 0x98
    int32_t                      mSubSoundListNum;         // 0x9C
    int32_t                      mSubSoundListCurrent;     // 0xA0
    FMOD__SoundI*                mSubSampleParent;         // 0xA4
    void*                        mUserData;                // 0xA8
    FMOD__SystemI*               mSystem;                  // 0xAC
    uint32_t                     mMemoryUsed;              // 0xB0
    int32_t                      mNumSyncPoints;           // 0xB4
    FMOD__SyncPoint*             mSyncPointHead;           // 0xB8
    FMOD__AsyncData*             mAsyncData;               // 0xBC
    FMOD_OPENSTATE               mOpenState;               // 0xC0
    FMOD__SoundGroupI*           mSoundGroup;              // 0xC4
    FMOD__LinkedListNode         mSoundGroupNode;          // 0xC8
    int32_t                      mNumAudible;              // 0xD4
    FMOD_SOUND_PCMREADCALLBACK   mPostReadCallback;        // 0xD8
    FMOD_SOUND_PCMSETPOSCALLBACK mPostSetPositionCallback; // 0xDC
    FMOD_SOUND*                  mPostCallbackSound;       // 0xE0
};

// size = 0x3C (0x34 on mac)
struct FMOD__SoundGroupI {
    FMOD__LinkedListNode     _;                   // 0x00
    FMOD__SystemI*           mSystem;             // 0x0C
    void*                    mUserData;           // 0x10
    FMOD__LinkedListNode     mSoundHead;          // 0x14
    char*                    mName;               // 0x20
    int32_t                  mMaxAudible;         // 0x24
    FMOD_SOUNDGROUP_BEHAVIOR mMaxAudibleBehavior; // 0x28
    int32_t                  mPlayCount;          // 0x2C
    int32_t                  mNumAudible;         // 0x30
    float                    mFadeSpeed;          // 0x34
    float                    mVolume;             // 0x38
};

// size >= 0x138
// class Sample : public SoundI
struct FMOD__Sample {
    // mNumSubSamples and mLockCanRead are part of SoundI in later releases.
    // something unexpected is happening here!
    FMOD__SoundI _;              // 0x000
    int32_t      mNumSubSamples; // 0xE4
    // the fact that subsamples are getting released by Sample and not SoundI
    // seem to point to them being members of Sample. double check this later.
    FMOD__Sample* mSubSample[16]; // 0xE8
    void*         mLockBuffer;    // 0x128 real start of Sample members?
    uint32_t      mLockLength;    // 0x12C
    uint32_t      mLockOffset;    // 0x130
    bool          mLockCanRead;   // 0x134
};

// size = 0x150
struct FMOD__SampleSoftware {
    FMOD__Sample _;                          // 0x000
    void*        mBuffer;                    // 0x138
    void*        mBufferMemory;              // 0x13C
    char*        mLoopPointDataEnd;          // 0x140
    char         mLoopPointDataEndMemory[8]; // 0x144
    bool         unk14C;                     // 0x14C
};

// size = 0x148
struct FMOD__SampleDSound {
    FMOD__Sample          _;            // 0x000
    IDirectSoundBuffer8*  mBuffer;      // 0x138
    IDirectSound3DBuffer* mBuffer3D;    // 0x13C
    FMOD__OutputDSound*   mOutput;      // 0x140
    bool                  mLOCSoftware; // 0x144
};

// size = 0x150
struct FMOD__SampleOpenAL {
    FMOD__Sample _;                          // 0x000
    void*        mBuffer;                    // 0x138
    void*        mBufferMemory;              // 0x13C
    char*        mLoopPointDataEnd;          // 0x140
    char         mLoopPointDataEndMemory[8]; // 0x144
    bool         mDataEndCopied;             // 0x14C
};

// size = 0x14 (confirmed)
struct FMOD__ChannelPool {
    int32_t             mNumChannels;  // 0x00
    int32_t             mChannelsUsed; // 0x04
    FMOD__SystemI*      mSystem;       // 0x08
    FMOD__Output*       mOutput;       // 0x0C
    FMOD__ChannelReal** mChannel;      // 0x10
};

// size = 0x5C (mac)
struct FMOD__ChannelGroup {
    uint32_t unk00; // 0x00
    uint32_t unk04; // 0x04
    uint32_t unk08; // 0x08
    uint32_t unk0C; // 0x0C
    uint32_t unk10; // 0x10
    uint32_t unk14; // 0x14
    uint32_t unk18; // 0x18
    uint32_t unk1C; // 0x1C
    uint32_t unk20; // 0x20
    uint32_t unk24; // 0x24
    uint32_t unk28; // 0x28
    uint32_t unk2C; // 0x2C
    uint32_t unk30; // 0x30
    uint32_t unk34; // 0x34
    uint32_t unk38; // 0x38
    uint32_t unk3C; // 0x3C
    uint32_t unk40; // 0x40
    uint32_t unk44; // 0x44
    uint32_t unk48; // 0x48
    uint32_t unk4C; // 0x4C
    uint32_t unk50; // 0x50
    uint32_t unk54; // 0x54
    uint32_t unk58; // 0x58
};

// size = 0x5C
struct FMOD__ChannelGroupI {
    // uint32_t unk00; // 0x00
    // uint32_t unk04; // 0x04
    // uint32_t unk08; // 0x08
    // uint32_t unk0C; // 0x0C
    // uint32_t unk10; // 0x10
    // uint32_t unk14; // 0x14
    // uint32_t unk18; // 0x18
    // uint32_t unk1C; // 0x1C
    // uint32_t unk20; // 0x20
    // uint32_t unk24; // 0x24
    // uint32_t unk28; // 0x28
    // uint32_t unk2C; // 0x2C
    // uint32_t unk30; // 0x30
    // uint32_t unk34; // 0x34
    // uint32_t unk38; // 0x38
    // uint32_t unk3C; // 0x3C
    // uint32_t unk40; // 0x40
    // uint32_t unk44; // 0x44
    // uint32_t unk48; // 0x48
    // uint32_t unk4C; // 0x4C
    // uint32_t unk50; // 0x50
    // uint32_t unk54; // 0x54
    // uint32_t unk58; // 0x58
    FMOD__LinkedListNode _;                          // 0x00
    FMOD__SystemI*       mSystem;                    // 0x0C
    FMOD__DSPI*          mDSPHead;                   // 0x10 confirmed!
    FMOD__DSPI*          mDSPMixTarget;              // 0x14 confirmed!
    void*                mUserData;                  // 0x18
    FMOD__ChannelGroupI* mParent;                    // 0x1C confirmed!
    FMOD__ChannelGroupI* mGroupHead;                 // 0x20
    FMOD__LinkedListNode mChannelHead;               // 0x24
    int32_t              mNumChannels;               // 0x30
    char*                mName;                      // 0x34
    float                mVolume;                    // 0x38
    float                mRealVolume;                // 0x3C
    float                mDirectOcclusion;           // 0x40
    float                mReverbOcclusion;           // 0x44
    float                mRealDirectOcclusionVolume; // 0x48
    float                mRealReverbOcclusionVolume; // 0x4C
    float                mPitch;                     // 0x50
    float                mRealPitch;                 // 0x54
    bool                 mMute;                      // 0x58
    bool                 mPaused;                    // 0x59
};

#pragma pack(push, 1)
struct FMOD__MusicEnvelopeNode {
    int8_t   mValue;
    uint16_t mTick;
};
#pragma pack(pop)

struct FMOD__SNDMIXPLUGININFO {
    uint32_t dwPluginId1;
    uint32_t dwPluginId2;
    uint32_t dwInputRouting;
    uint32_t dwOutputRouting;
    uint32_t dwReserved[4];
    char     szName[32];
    char     szLibraryName[64];
};

struct FMOD__SNDMIXPLUGINDATA_ECHO {
    float unknown;
    float mWetDryMix;
    float mFeedback;
    float mLeftDelay;
    float mRightDelay;
    float mPanDelay;
};

struct FMOD__SNDMIXPLUGIN {
    FMOD__ChannelGroupI    mChannelGroup;
    void*                  pMixPlugin;
    FMOD__SNDMIXPLUGININFO Info;
};

// size = 0x30
struct FMOD__MusicSample {
    // FMOD__SoundI*     mSound;
    // uint32_t          mMiddleC;
    // uint8_t           mDefaultVolume;
    // uint8_t           mDefaultPan;
    // uint32_t          mLoopStart;
    // uint32_t          mLoopLength;
    // int32_t           mRelative;
    // int32_t           mFineTune;
    // uint32_t          mRawLength;
    // uint8_t           mFlags;
    // uint8_t           mGlobalVolume;
    // uint32_t          mSusLoopBegin;
    // uint32_t          mSusLoopEnd;
    // uint8_t           mVibSpeed;
    // uint8_t           mVibDepth;
    // uint8_t           mVibType;
    // uint8_t           mVibRate;
    // FMOD_SOUND_FORMAT mOriginalFormat;
    FMOD__SoundI* mSound;         // 0x00 confirmed
    uint32_t      mMiddleC;       // 0x04 confirmed
    uint8_t       mDefaultVolume; // 0x08
    uint8_t       mDefaultPan;    // 0x09
    uint32_t      mLoopStart;     // 0x0C
    uint32_t      mLoopLength;    // 0x10
    int32_t       mRelative;      // 0x14
    int32_t       mFineTune;      // 0x18
    uint32_t      mRawLength;     // 0x1C
    uint8_t       mFlags;         // 0x20
    uint8_t       mGlobalVolume;  // 0x21
    uint32_t      mSusLoopBegin;  // 0x24
    uint32_t      mSusLoopEnd;    // 0x28
    uint8_t       mVibSpeed;      // 0x2C
    uint8_t       mVibDepth;      // 0x2D
    uint8_t       mVibType;       // 0x2E
    uint8_t       mVibRate;       // 0x2F
};

// size = 0x594
struct FMOD__MusicInstrument {
    int8_t            mName[28];
    int32_t           mNumSamples;
    FMOD__MusicSample mSample[16];
    uint8_t           mKeyMap[96];
    uint8_t           mVolumeType;
    uint8_t           mVolumeNumPoints;
    uint16_t          mVolumePoints[40];
    uint8_t           mVolumeSustain;
    uint8_t           mVolumeLoopStart;
    uint8_t           mVolumeLoopEnd;
    uint8_t           mVolumeSustainLoopStart;
    uint8_t           mVolumeSustainLoopEnd;
    uint8_t           mPanType;
    uint8_t           mPanNumPoints;
    uint16_t          mPanPoints[40];
    uint8_t           mPanSustain;
    uint8_t           mPanLoopStart;
    uint8_t           mPanLoopEnd;
    uint8_t           mPanSustainLoopStart;
    uint8_t           mPanSustainLoopEnd;
    uint8_t           mPitchType;
    uint8_t           mPitchNumpoints;
    uint16_t          mPitchPoints[40];
    uint8_t           mPitchSustain;
    uint8_t           mPitchLoopStart;
    uint8_t           mPitchLoopEnd;
    uint8_t           mPitchSustainLoopStart;
    uint8_t           mPitchSustainLoopEnd;
    uint8_t           mVibratoType;
    uint8_t           mVibratoSweep;
    uint8_t           mVibratoDepth;
    uint8_t           mVibratoRate;
    uint16_t          mVolumeFade;
    uint8_t           mGlobalVolume;
    uint8_t           mDefaultPan;
    uint8_t           mNNA;
    uint8_t           mDupCheckType;
    uint8_t           mDupCheckAction;
    uint8_t           mPitchPanSep;
    uint8_t           mPitchPanCenter;
    uint8_t           mVolumeVariation;
    uint8_t           mPanVariation;
    uint8_t           mNoteTable[240];
    uint32_t          mFilterCutOff;
    uint32_t          mFilterResonance;
    uint8_t           mMIDIOutput;
};

struct FMOD__MusicEnvelopeState {
    int32_t mTick;
    int32_t mPosition;
    int32_t mFraction;
    int32_t mValue;
    int32_t mDelta;
    bool    mStopped;
};

#define INTERFACE FMOD__ChannelReal
struct FMOD__ChannelReal__v_table {
    P_METHOD(
        FMOD_RESULT,
        _00_init,
        int32_t        index,
        FMOD__SystemI* system,
        FMOD__Output*  output,
        FMOD__DSPI*    dspmixtarget);
    E_METHOD(FMOD_RESULT, _01_set2DFreqVolumePanFor3D);
    E_METHOD(bool, _02_isStream);
    P_METHOD(
        FMOD_RESULT,
        _03_moveChannelGroup,
        FMOD__ChannelGroupI* oldchannelgroup,
        FMOD__ChannelGroupI* newchannelgroup);
    P_METHOD(FMOD__ChannelReal*, _04_scalar_deleting_destructor, uint8_t __flag);
    E_METHOD(FMOD_RESULT, _05_close);
    P_METHOD(FMOD_RESULT, _06_alloc, FMOD__DSPI* dsp);
    E_METHOD(FMOD_RESULT, _07_alloc);
    E_METHOD(FMOD_RESULT, _08_start);
    P_METHOD(FMOD_RESULT, _09_update, int32_t delta);
    E_METHOD(FMOD_RESULT, _10_updateStream);
    P_METHOD(FMOD_RESULT, _11_stop, bool a2, bool a3, bool a4); // TODO
    P_METHOD(FMOD_RESULT, _12_stop, bool a2, bool a3);          // TODO
    P_METHOD(FMOD_RESULT, _13_setPaused, bool paused);
    P_METHOD(FMOD_RESULT, _14_getPaused, bool* paused);
    P_METHOD(FMOD_RESULT, _15_setVolume, float volume);
    P_METHOD(FMOD_RESULT, _16_setFrequency, float frequency);
    P_METHOD(FMOD_RESULT, _17_setPan, float pan, float fbpan);
    P_METHOD(FMOD_RESULT, _18_setDelay, uint32_t delayhi, uint32_t delaylo);
    P_METHOD(
        FMOD_RESULT,
        _19_setSpeakerMix,
        float frontleft,
        float frontright,
        float center,
        float lfe,
        float backleft,
        float backright,
        float sideleft,
        float sideright);
    P_METHOD(FMOD_RESULT, _20_setSpeakerLevels, int32_t speaker, float* levels, int32_t numlevels);
    P_METHOD(FMOD_RESULT, _21_updateSpeakerLevels, float volume);
    P_METHOD(FMOD_RESULT, _22_setPosition, uint32_t position, FMOD_TIMEUNIT postype);
    P_METHOD(FMOD_RESULT, _23_getPosition, uint32_t* position, FMOD_TIMEUNIT postype);
    P_METHOD(FMOD_RESULT, _24_setLoopPoints, uint32_t loopstart, uint32_t looplength);
    P_METHOD(FMOD_RESULT, _25_setLoopCount, int32_t loopcount);
    E_METHOD(FMOD_RESULT, _26_set3DAttributes);
    E_METHOD(FMOD_RESULT, _27_set3DMinMaxDistance);
    P_METHOD(FMOD_RESULT, _28_set3DOcclusion, float directOcclusion, float reverbOcclusion);
    P_METHOD(FMOD_RESULT, _29_setReverbProperties, const FMOD_REVERB_CHANNELPROPERTIES* prop);
    P_METHOD(FMOD_RESULT, _30_getReverbProperties, FMOD_REVERB_CHANNELPROPERTIES* prop);
    P_METHOD(FMOD_RESULT, _31_isPlaying, bool* isplaying);
    P_METHOD(FMOD_RESULT, _32_isVirtual, bool* isvirtual);
    P_METHOD(
        FMOD_RESULT,
        _33_getSpectrum,
        float*              spectrumarray,
        int32_t             numentries,
        int32_t             channeloffset,
        FMOD_DSP_FFT_WINDOW windowtype);
    P_METHOD(
        FMOD_RESULT,
        _34_getWaveData,
        float*  wavearray,
        int32_t numvalues,
        int32_t channeloffset);
    P_METHOD(FMOD_RESULT, _35_getDSPHead, FMOD__DSPI** dsp);
    P_METHOD(FMOD_RESULT, _36_setMode, FMOD_MODE mode);
};
#undef INTERFACE

#define INTERFACE FMOD__ChannelOpenAL
struct FMOD__ChannelOpenAL__v_table {
    // FMOD::ChannelReal methods
    P_METHOD(
        FMOD_RESULT,
        _00_init,
        int32_t        index,
        FMOD__SystemI* system,
        FMOD__Output*  output,
        FMOD__DSPI*    dspmixtarget);
    E_METHOD(FMOD_RESULT, _01_set2DFreqVolumePanFor3D);
    E_METHOD(bool, _02_isStream);
    P_METHOD(
        FMOD_RESULT,
        _03_moveChannelGroup,
        FMOD__ChannelGroupI* oldchannelgroup,
        FMOD__ChannelGroupI* newchannelgroup);
    P_METHOD(FMOD__ChannelReal*, _04_scalar_deleting_destructor, uint8_t __flag);
    E_METHOD(FMOD_RESULT, _05_close);
    P_METHOD(FMOD_RESULT, _06_alloc, FMOD__DSPI* dsp);
    E_METHOD(FMOD_RESULT, _07_alloc);
    E_METHOD(FMOD_RESULT, _08_start);
    P_METHOD(FMOD_RESULT, _09_update, int32_t delta);
    E_METHOD(FMOD_RESULT, _10_updateStream);
    P_METHOD(FMOD_RESULT, _11_stop, bool a2, bool a3, bool a4); // TODO
    P_METHOD(FMOD_RESULT, _12_stop, bool a2, bool a3);          // TODO
    P_METHOD(FMOD_RESULT, _13_setPaused, bool paused);
    P_METHOD(FMOD_RESULT, _14_getPaused, bool* paused);
    P_METHOD(FMOD_RESULT, _15_setVolume, float volume);
    P_METHOD(FMOD_RESULT, _16_setFrequency, float frequency);
    P_METHOD(FMOD_RESULT, _17_setPan, float pan, float fbpan);
    P_METHOD(FMOD_RESULT, _18_setDelay, uint32_t delayhi, uint32_t delaylo); // TODO
    P_METHOD(
        FMOD_RESULT,
        _19_setSpeakerMix,
        float frontleft,
        float frontright,
        float center,
        float lfe,
        float backleft,
        float backright,
        float sideleft,
        float sideright);
    P_METHOD(FMOD_RESULT, _20_setSpeakerLevels, int32_t speaker, float* levels, int32_t numlevels);
    P_METHOD(FMOD_RESULT, _21_updateSpeakerLevels, float volume);
    P_METHOD(FMOD_RESULT, _22_setPosition, uint32_t position, FMOD_TIMEUNIT postype);
    P_METHOD(FMOD_RESULT, _23_getPosition, uint32_t* position, FMOD_TIMEUNIT postype);
    P_METHOD(FMOD_RESULT, _24_setLoopPoints, uint32_t loopstart, uint32_t looplength);
    P_METHOD(FMOD_RESULT, _25_setLoopCount, int32_t loopcount);
    E_METHOD(FMOD_RESULT, _26_set3DAttributes);
    E_METHOD(FMOD_RESULT, _27_set3DMinMaxDistance);
    P_METHOD(FMOD_RESULT, _28_set3DOcclusion, float directOcclusion, float reverbOcclusion);
    P_METHOD(FMOD_RESULT, _29_setReverbProperties, FMOD_REVERB_CHANNELPROPERTIES* prop);
    P_METHOD(FMOD_RESULT, _30_getReverbProperties, FMOD_REVERB_CHANNELPROPERTIES* prop);
    P_METHOD(FMOD_RESULT, _31_isPlaying, bool* isplaying);
    P_METHOD(FMOD_RESULT, _32_isVirtual, bool* isvirtual);
    P_METHOD(
        FMOD_RESULT,
        _33_getSpectrum,
        float*              spectrumarray,
        int32_t             numentries,
        int32_t             channeloffset,
        FMOD_DSP_FFT_WINDOW windowtype);
    P_METHOD(
        FMOD_RESULT,
        _34_getWaveData,
        float*  wavearray,
        int32_t numvalues,
        int32_t channeloffset);
    P_METHOD(FMOD_RESULT, _35_getDSPHead, FMOD__DSPI** dsp);
    P_METHOD(FMOD_RESULT, _36_setMode, FMOD_MODE mode);
    // FMOD::ChannelOpenAL methods
    E_METHOD(FMOD_RESULT, _37_setupChannel);
};
#undef INTERFACE

union FMOD__ChannelReal__v_table_merged {
    FMOD__ChannelReal__v_table   channelreal;
    FMOD__ChannelOpenAL__v_table channelopenal;
};

// size = 0x98
struct FMOD__ChannelReal {
    // FMOD__SystemI*         mSystem;          // 0x00
    // int32_t                mSubChannelIndex; // 0x04
    // FMOD__ChannelPool*     mPool;            // 0x08
    // FMOD__ChannelI*        mParent;          // 0x0C
    // FMOD__Output*          mOutput;          // 0x10
    // FMOD__SoundI*          mSound;           // 0x14
    // FMOD__DSPI*            mDSP;             // 0x18
    // FMOD_MODE              mMode;            // 0x1C
    // FMOD__CHANNELREAL_FLAG mFlags;
    // int32_t                mIndex;
    // uint32_t               mPosition;
    // int32_t                mDirection;
    // int32_t                mLoopCount;
    // uint32_t               mLoopStart;
    // uint32_t               mLoopLength;
    // uint32_t               mLength;
    // float                  mMaxFrequency;
    // float                  mMinFrequency;
    // int32_t                mSubSoundListCurrent;
    //
    FMOD__ChannelReal__v_table_merged* v_table; // 0x00 TODO!!
    FMOD__SystemI*                     mSystem; // 0x04
    int32_t                mNumSubChannels;  // 0x08 invented: see ChannelStream::mNumRealChannels
    FMOD__ChannelReal*     mSubChannel[16];  // 0x0C invented: see ChannelStream::mRealChannel
    int32_t                mSubChannelIndex; // 0x4C
    FMOD__ChannelPool*     mPool;            // 0x50
    FMOD__ChannelI*        mParent;          // 0x54
    FMOD__Output*          mOutput;          // 0x58
    FMOD__SoundI*          mSound;           // 0x5C
    FMOD__DSPI*            mDSP;             // 0x60 unconfirmed
    FMOD_MODE              mMode;            // 0x64
    FMOD__CHANNELREAL_FLAG mFlags;           // 0x68
    int32_t                mIndex;           // 0x6C
    uint32_t               mPosition;        // 0x70
    int32_t                mDirection;       // 0x74 FMOD__CHANNELREAL_PLAYDIR
    int32_t                mLoopCount;       // 0x78
    uint32_t               mLoopStart;       // 0x7C
    uint32_t               mLoopLength;      // 0x80
    uint32_t               mLength;          // 0x84
    uint32_t               mStartDelay;      // 0x88 invented: implied by mEndDelay
    uint32_t               mEndDelay;        // 0x8C invented: taken from ChannelI
    float                  mMaxFrequency;    // 0x90
    float                  mMinFrequency;    // 0x94
};

struct FMOD__ChannelRealManual3D {
    FMOD__ChannelReal _;                // 0x00
    float             mAngleToListener; // 0x98
};

// size = 0x2D8
struct FMOD__ChannelSoftware {
    FMOD__ChannelRealManual3D _;                   // 0x000
    FMOD__DSPI*               mDSPHead;            // 0x09C
    FMOD__DSPFilter           mDSPHeadMemory;      // 0x0A0
    FMOD__DSPWaveTable*       mDSPWaveTable;       // 0x1A4
    FMOD__DSPWaveTable        mDSPWaveTableMemory; // 0x1A8
    FMOD__DSPResampler*       mDSPResampler;       // 0x2C0
    FMOD__DSPI*               mDSPLowPass;         // 0x2C4 XREF moveChannelGroup
    FMOD__DSPI*               mDSPReverb;          // 0x2C8
    FMOD__DSPCodec*           mDSPCodec;           // 0x2CC
    FMOD__DSPI*               unk2D0;              // 0x2D0 TODO type is not certain
    FMOD__DSPConnection*      mDSPConnection;      // 0x2D4
};

// class ChannelStream : public ChannelReal, public LinkedListNode
// vtable contains 37 methods
struct FMOD__ChannelStream {
    FMOD__ChannelReal    _0;
    FMOD__LinkedListNode _1;        // 0x98
    volatile bool        mFinished; // 0xA4
    uint32_t             mLastPCM;
    uint32_t             mDecodeOffset;
    uint32_t             mSamplesPlayed;
    uint32_t             mSamplesWritten;
    FMOD__LinkedListNode mStreamNode;
    int32_t              mNumRealChannels;
    FMOD__ChannelReal*   mRealChannel[16];
};

// IMPORTANT: review this
struct FMOD__ChannelEmulated {
    FMOD__ChannelReal _;
    FMOD__DSPFilter   mDSPHeadMemory;
    FMOD__DSPI*       mDSPHead;
};

// size = 0xB0
struct FMOD__ChannelDSound {
    FMOD__ChannelReal _;                  // 0x00
                                          // uint32_t          unk98; // 0x98
                                          // uint32_t          unk9C; // 0x9C
                                          // uint32_t          unkA0; // 0xA0
                                          // uint32_t          unkA4; // 0xA4
                                          // uint32_t          unkA8; // 0xA8
                                          // uint32_t          unkAC; // 0xAC
    bool                  mLOCSoftware;   // 0x98
    FMOD__OutputDSound*   mOutputDSound;  // 0x9C
    IDirectSoundBuffer8*  mBuffer;        // 0xA0
    IDirectSound3DBuffer* mBuffer3D;      // 0xA4
    IKsPropertySet*       mBufferReverb;  // 0xA8
    IKsPropertySet*       mBufferQuality; // 0xAC
};

struct FMOD__ChannelDSoundEAX2 {
    FMOD__ChannelDSound _;
};

struct FMOD__ChannelDSoundEAX3 {
    FMOD__ChannelDSound _;
};

struct FMOD__ChannelDSoundEAX4 {
    FMOD__ChannelDSound _;
};

// size = 0x328
struct FMOD__ChannelOpenAL {
    FMOD__ChannelReal   _;                   // 0x000
    FMOD__DSPI*         mDSPHead;            // 0x098
    FMOD__DSPFilter     mDSPHeadMemory;      // 0x09C
    FMOD__DSPWaveTable* mDSPWaveTable;       // 0x1A0
    uint32_t            unk1A4;              // 0x1A4
    FMOD__DSPWaveTable  mDSPWaveTableMemory; // 0x1A8
    FMOD__DSPResampler* mDSPResampler;       // 0x2C0
    FMOD__DSPI*         mDSPLowPass;         // 0x2C4
    FMOD__DSPCodec*     mDSPCodec;           // 0x2C8
    uint32_t            unk2CC;              // 0x2CC
    FMOD__OutputOpenAL* mOutputOAL;          // 0x2D0
    int32_t             mNumSources;         // 0x2D4
    FMOD__SourceOpenAL* mSources[16];        // 0x2D8
    int16_t*            mBuffer;             // 0x318
    float*              mTempBuffer;         // 0x31C
    bool                mInitialFill;        // 0x320
    uint32_t            unk324;              // 0x324
};

struct FMOD__ChannelOpenALEAX2 {
    FMOD__ChannelOpenAL _;
};

struct FMOD__ChannelOpenALEAX3 {
    FMOD__ChannelOpenAL _;
};

struct FMOD__ChannelOpenALEAX4 {
    FMOD__ChannelOpenAL _;
};

struct FMOD__ChannelOpenALEAX5 {
    FMOD__ChannelOpenAL _;
};

// class Stream : public SoundI
struct FMOD__Stream {
    FMOD__SoundI         _;                 // 0x000
    FMOD__LinkedListNode mStreamNode;       // 0x0E4
    FMOD__ChannelStream* mChannel;          // 0x0F0
    FMOD__Sample*        mSample;           // 0x0F4
    uint32_t             mLastPos;          // 0x0F8
    int32_t              mBlockSize;        // 0x0FC
    int32_t              mLoopCountCurrent; // 0x100
    int32_t              mInitialPosition;  // 0x104
};

// size = 0x19C
// class ChannelI : public LinkedListNode
struct FMOD__ChannelI {
    FMOD__LinkedListNode       _;                      // 0x00
    FMOD__SortedLinkedListNode mSortedListNode;        // 0x0C
    int32_t                    mIndex;                 // 0x1C
    void*                      mUserData;              // 0x20
    uint32_t                   mHandleOriginal;        // 0x24
    FMOD__SystemI*             mSystem;                // 0x28
    uint32_t                   mNumRealChannels;       // 0x2C
    FMOD__ChannelReal*         mRealChannel[16];       // 0x30
    uint32_t                   mHandleCurrent;         // 0x70
    FMOD_CHANNEL_FLAG          mFlags;                 // 0x74
    FMOD_CHANNEL_PANMODE       mLastPanMode;           // 0x78
    int32_t                    mPriority;              // 0x7C
    uint32_t                   mListPosition;          // 0x80
    FMOD__SyncPoint*           mSyncPointCurrent;      // 0x84
    FMOD__ChannelGroupI*       mChannelGroup;          // 0x88
    FMOD__LinkedListNode       mChannelGroupNode;      // 0x8C
    float                      mFadeVolume;            // 0x98
    float                      mFadeTarget;            // 0x9C
    float                      mVolume;                // 0xA0
    float                      mFrequency;             // 0xA4
    float                      mPan;                   // 0xA8
    float                      mSpeakerFL;             // 0xAC
    float                      mSpeakerFR;             // 0xB0
    float                      mSpeakerC;              // 0xB4
    float                      mSpeakerLFE;            // 0xB8
    float                      mSpeakerBL;             // 0xBC
    float                      mSpeakerBR;             // 0xC0
    float                      mSpeakerSL;             // 0xC4
    float                      mSpeakerSR;             // 0xC8
    float                      mInputMix[16];          // 0xCC
    float*                     mLevels;                // 0x10C
    float                      mDirectOcclusionVolume; // 0x110 invented name
    float                      mReverbDryVolume;       // 0x114
    float                      mVolume3D;              // 0x118
    float                      mPitch3D;               // 0x11C
    FMOD_VECTOR                mPosition3D;            // 0x120
    FMOD_VECTOR                mVelocity3D;            // 0x12C
    float                      mDistance;              // 0x138
    float                      mMinDistance;           // 0x13C
    float                      mMaxDistance;           // 0x140
    float                      mConeVolume3D;          // 0x144
    float                      mConeInsideAngle;       // 0x148
    float                      mConeOutsideAngle;      // 0x14C
    float                      mConeOutsideVolume;     // 0x150
    FMOD_VECTOR                mConeOrientation;       // 0x154
    float                      mDirectOcclusion;       // 0x160
    float                      mReverbOcclusion;       // 0x164
    float                      mDirectOcclusionTarget; // 0x168
    float                      mReverbOcclusionTarget; // 0x16C
    FMOD_VECTOR*               mRolloffPoint;          // 0x170
    int32_t                    mNumRolloffPoints;      // 0x174
    float                      mSpread;                // 0x178
    float                      m3DPanLevel;            // 0x17C
    float                      m3DDopplerLevel;        // 0x180
    FMOD_CHANNEL_CALLBACK      mCallback[3];           // 0x184
    int32_t                    mCommand[3];            // 0x190 invented name
};

// size = [0x240] (implied by CodecMOD::openInternal)
// proof: 0090CA49
struct FMOD__MusicVirtualChannel {
    FMOD__LinkedListNode     _;
    int32_t                  mIndex;
    bool                     mAllocated;
    bool                     mFlip;
    FMOD__ChannelI           mChannel;
    FMOD__MusicSample*       mSample;
    FMOD__MusicSong*         mSong;
    uint8_t                  mLastInstrument;
    uint8_t                  mLastNote;
    uint8_t                  mLastSample;
    bool                     mBackground;
    uint8_t                  mNoteControl;
    uint8_t                  mNNA;
    uint8_t                  mVolType;
    int32_t                  mFrequency;
    int32_t                  mVolume;
    int32_t                  mPan;
    int32_t                  mVolumeDelta;
    int32_t                  mFrequencyDelta;
    int32_t                  mPanDelta;
    uint32_t                 mSampleOffset;
    int32_t                  mDirection;
    int32_t                  mSampGlobalVol;
    FMOD__MusicEnvelopeState mEnvVolume;
    FMOD__MusicEnvelopeState mEnvPan;
    int32_t                  mEnvPitchTick;
    int32_t                  mEnvPitchPos;
    int32_t                  mEnvPitchFrac;
    int32_t                  mEnvPitch;
    int32_t                  mEnvPitchDelta;
    bool                     mEnvPitchStopped;
    bool                     mFade;
    int32_t                  mFadeOutVolume;
    int32_t                  mIVibPos;
    int32_t                  mIVibSweepPos;
    bool                     mKeyOff;
    bool                     mRamping;
    int32_t                  mTicksToDie;
};

// size = 0x29C
struct FMOD__MusicChannel {
    // FMOD__MusicVirtualChannel mVirtualChannelHead;
    // uint8_t                   mInstrument;
    // uint8_t                   mNote;
    // uint8_t                   mSample;
    // uint8_t                   mRealNote;
    // int32_t                   mPeriod;
    // uint8_t                   mRecentEffect;
    // int32_t                   mVolume;
    // int32_t                   mPan;
    // int32_t                   mVolumeDelta;
    // uint32_t                  mSampleOffset;
    // int32_t                   mGlobalVolume;
    // float                     mMasterVolume;
    // uint8_t                   mPortaUpDown;
    // uint8_t                   mPortaDown;
    // uint8_t                   mPortaUp;
    // uint8_t                   mXtraPortaDown;
    // uint8_t                   mXtraPortaUp;
    // uint8_t                   mVolumeSlide;
    // uint8_t                   mPanSlide;
    // uint8_t                   mRetrigX;
    // uint8_t                   mRetrigY;
    // uint8_t                   mRetrigCount;
    // int32_t                   mPortaTarget;
    // uint8_t                   mPortaSpeed;
    // uint8_t                   mPortaReached;
    // int8_t                    mVibPos;
    // uint8_t                   mVibSpeed;
    // uint8_t                   mVibDepth;
    // uint8_t                   mVibType;
    // int8_t                    mTremoloPosition;
    // uint8_t                   mTremoloSpeed;
    // uint8_t                   mTremoloDepth;
    // int32_t                   mPanbrelloPos;
    // uint8_t                   mPanbrelloSpeed
    // uint8_t                   mPanbrelloDepth;
    // uint8_t                   mTremorPosition;
    // uint8_t                   mTremorOn;
    // uint8_t                   mTremorOff;
    // uint8_t                   mArpeggio;
    // int32_t                   mPatternLoopRow;
    // int32_t                   mPatternLoopNumber;
    // uint8_t                   mChannelVolumeSlide;
    // uint8_t                   mSpecialParam;
    // uint8_t                   mWaveControl;
    // uint8_t                   mWaveControlVibrato;
    // uint8_t                   mWaveControlTremolo;
    // uint8_t                   mWaveControlPan;
    // uint8_t                   mFineVolumeSlideDown;
    // uint8_t                   mFineVolumeSlideUp;
    // uint8_t                   mFinePortaUp;
    // uint8_t                   mFinePortaDown;
    // uint8_t                   mHighOffset;
    // uint8_t                   mVolumeColumnVolumeSlide;

    FMOD__MusicVirtualChannel mVirtualChannelHead;      // 0x000
    uint8_t                   mInstrument;              // 0x240
    uint8_t                   mNote;                    // 0x241
    uint8_t                   mSample;                  // 0x242
    uint8_t                   mRealNote;                // 0x243
    int32_t                   mPeriod;                  // 0x244
    uint8_t                   mRecentEffect;            // 0x248
    int32_t                   mVolume;                  // 0x24C
    int32_t                   mPan;                     // 0x250
    int32_t                   mVolumeDelta;             // 0x254
    uint32_t                  mSampleOffset;            // 0x258
    int32_t                   mGlobalVolume;            // 0x25C
    uint8_t                   mPortaUpDown;             // 0x260
    uint8_t                   mPortaDown;               // 0x261
    uint8_t                   mPortaUp;                 // 0x262
    uint8_t                   mXtraPortaDown;           // 0x263
    uint8_t                   mXtraPortaUp;             // 0x264
    uint8_t                   mVolumeSlide;             // 0x265
    uint8_t                   mPanSlide;                // 0x266
    uint8_t                   mRetrigX;                 // 0x267
    uint8_t                   mRetrigY;                 // 0x268
    uint8_t                   mRetrigCount;             // 0x269
    int32_t                   mPortaTarget;             // 0x26C
    uint8_t                   mPortaSpeed;              // 0x270
    uint8_t                   mPortaReached;            // 0x271
    int8_t                    mVibPos;                  // 0x272
    uint8_t                   mVibSpeed;                // 0x273
    uint8_t                   mVibDepth;                // 0x274
    uint8_t                   mVibType;                 // 0x275
    int8_t                    mTremoloPosition;         // 0x276
    uint8_t                   mTremoloSpeed;            // 0x277
    uint8_t                   mTremoloDepth;            // 0x278
    int32_t                   mPanbrelloPos;            // 0x27C
    uint8_t                   mPanbrelloSpeed;          // 0x280
    uint8_t                   mPanbrelloDepth;          // 0x281
    uint8_t                   mTremorPosition;          // 0x282
    uint8_t                   mTremorOn;                // 0x283
    uint8_t                   mTremorOff;               // 0x284
    uint8_t                   mArpeggio;                // 0x285
    uint32_t                  mLoopRow;                 // 0x288
    uint32_t                  mPatternLoopNumber;       // 0x28C
    uint8_t                   mChannelVolumeSlide;      // 0x290
    uint8_t                   mSpecialParam;            // 0x291
    uint8_t                   mWaveControl;             // 0x292 confirmed
    uint8_t                   mWaveControlVibrato;      // 0x293
    uint8_t                   mWaveControlTremolo;      // 0x294
    uint8_t                   mWaveControlPan;          // 0x295
    uint8_t                   mFineVolumeSlideDown;     // 0x296
    uint8_t                   mFineVolumeSlideUp;       // 0x297
    uint8_t                   mFinePortaUp;             // 0x298
    uint8_t                   mFinePortaDown;           // 0x299
    uint8_t                   mHighOffset;              // 0x29A
    uint8_t                   mVolumeColumnVolumeSlide; // 0x29B
};

struct FMOD__MusicChannelMOD {
    FMOD__MusicChannel _;
};

struct FMOD__MusicChannelS3M {
    FMOD__MusicChannel _;
};

struct FMOD__MusicChannelXM {
    FMOD__MusicChannel _;
};

struct FMOD__MusicChannelIT {
    FMOD__MusicChannel _;
    FMOD__CodecIT*     mModule;
};

struct FMOD__ChannelMusic {
    FMOD__ChannelReal _;
    FMOD__MusicSong*  mMusic;
};

struct FMOD__MusicPattern {
    int32_t          mRows;
    FMOD__MusicNote* mData;
};

struct FMOD__MusicNote {
    uint8_t mNote;
    uint8_t mNumber;
    uint8_t mVolume;
    uint8_t mEffect;
    uint8_t mEffectParam;
};

// size = [???]
// size by inference: 0x80C = sizeof(CodecMOD) - (sizeof(MusicSample) * 31)
struct FMOD__MusicSong {
    // FMOD__Codec         _;
    // char                mSongName[256];
    // FMOD__MusicPattern* mPattern;
    // FMOD__DSPI*         mDSPHead;
    // bool*               mVisited;
    // uint8_t             mOrderList[256];
    //
    // int32_t                    mNumChannels; // 0x2E4 confirmed
    // FMOD__MusicChannel*        mMusicChannel[64];
    // int32_t                    mNumVirtualChannels;
    // FMOD__MusicVirtualChannel* mVirtualChannel;
    // FMOD__ChannelPool*         mChannelPool;
    // FMOD__ChannelSoftware*     mChannelSoftware;
    // FMOD__DSPI**               mLowPass;
    // FMOD__ChannelGroupI        mChannelGroup;
    // FMOD__ChannelMusic         mHardwareMusicChannel;
    //
    // int32_t  mMixerSamplesLeft;
    // int32_t  mMixerSamplesPerTick;
    // uint32_t mPCMOffset;
    // uint32_t mDSPTick;
    //
    // int32_t  mDefaultSpeed;
    // uint32_t mDefaultBPM;
    // uint8_t  mDefaultPan[64];
    // uint8_t  mDefaultVolume[64];
    // uint8_t  mDefaultGlobalVolume;
    //
    // int32_t mNumOrders;
    // int32_t mNumPatterns;
    // int32_t mNumPatternsMem;
    // int32_t mNumInstruments;
    // int32_t mNumSamples; // 0x500 confirmed
    //
    // FMOD__MusicInstrument* mInstrument;
    // int8_t*                mPatternPtr;
    // uint8_t                mLastNote[64];
    // uint8_t                mLastNumber[64];
    // uint8_t                mLastVolume[64];
    // uint8_t                mLastEffect[64];
    // uint8_t                mLastEffectParam[64];
    // uint8_t                mPreviousMaskVariable[64];
    // FMOD__MusicNote        mNote[64];
    //
    // int32_t  mRestart;
    // float    mMasterSpeed;   // 0x7D0 confirmed
    // float    mPanSeparation; // 0x7D4 confirmed
    // int32_t  mMasterVolume;
    // int32_t  mGlobalVolume;
    // uint8_t  mGlobalVolumeSlide;
    // uint16_t mMusicFlags;
    // bool     mPlaying;
    // bool     mFinished;
    // bool     mLooping;
    // int32_t  mTick;
    // int32_t  mSpeed;
    // int32_t  mBPM;
    // int32_t  mRow;
    // int32_t  mOrder;
    // int32_t  mPatternDelay;
    // int32_t  mPatternDelayTicks;
    // int32_t  mNextRow;
    // int32_t  mNextOrder;

    // ^-- overview of later versions.
    // v-- the 4.09.07 version (strictly)
    FMOD__Codec                _;                         // 0x000
    char                       mSongName[256];            // 0x0D8
    FMOD__MusicPattern*        mPattern;                  // 0x1D8
    FMOD__DSPI*                mDSPHead;                  // 0x1DC
    bool*                      mVisited;                  // 0x1E0
    uint8_t                    mOrderList[256];           // 0x1E4
    int32_t                    mNumChannels;              // 0x2E4 confirmed
    FMOD__MusicChannel*        mMusicChannel[64];         // 0x2E8 confirmed
    int32_t                    mNumVirtualChannels;       // 0x3E8
    FMOD__MusicVirtualChannel* mVirtualChannel;           // 0x3EC
    FMOD__ChannelPool*         mChannelPool;              // 0x3F0
    FMOD__ChannelSoftware*     mChannelSoftware;          // 0x3F4
    FMOD__DSPI**               mLowPass;                  // 0x3F8
    FMOD__ChannelGroupI        mChannelGroup;             // 0x3FC
    int32_t                    mMixerSamplesLeft;         // 0x458
    int32_t                    mMixerSamplesPerTick;      // 0x45C
    uint32_t                   mPCMOffset;                // 0x460
    uint32_t                   mDefaultSpeed;             // 0x464 confirmed
    uint32_t                   mDefaultBPM;               // 0x468 confirmed
    uint8_t                    mDefaultPan[64];           // 0x46C
    uint8_t                    mDefaultVolume[64];        // 0x4AC
    uint8_t                    mDefaultGlobalVolume;      // 0x4EC
    int32_t                    mNumOrders;                // 0x4F0
    int32_t                    mNumPatterns;              // 0x4F4 confirmed
    int32_t                    mNumPatternsMem;           // 0x4F8
    int32_t                    mNumInstruments;           // 0x4FC
    int32_t                    mNumSamples;               // 0x500 confirmed
    FMOD__MusicInstrument*     mInstrument;               // 0x504
    uint32_t                   unk508;                    // 0x508
    uint8_t                    mLastNote[64];             // 0x50C
    uint8_t                    mLastNumber[64];           // 0x54C
    uint8_t                    mLastVolume[64];           // 0x58C
    uint8_t                    mLastEffect[64];           // 0x5CC
    uint8_t                    mLastEffectParam[64];      // 0x60C
    uint8_t                    mPreviousMaskVariable[64]; // 0x64C
    FMOD__MusicNote            mNote[64];                 // 0x68C
    int32_t                    mRestart;                  // 0x7CC
    float                      mMasterSpeed;              // 0x7D0 confirmed
    float                      mPanSeparation;            // 0x7D4 confirmed
    int32_t                    mMasterVolume;             // 0x7D8
    int32_t                    mGlobalVolume;             // 0x7DC
    uint8_t                    mGlobalVolumeSlide;        // 0x7E0
    uint16_t                   mMusicFlags;               // 0x7E2
    bool                       mPlaying;                  // 0x7E4
    bool                       mFinished;                 // 0x7E5
    bool                       mLooping;                  // 0x7E6
    int32_t                    mTick;                     // 0x7E8
    int32_t                    mSpeed;                    // 0x7EC
    int32_t                    mBPM;                      // 0x7F0 confirmed
    int32_t                    mRow;                      // 0x7F4
    int32_t                    mOrder;                    // 0x7F8
    int32_t                    mPatternDelay;             // 0x7FC
    int32_t                    mPatternDelayTicks;        // 0x800
    int32_t                    mNextRow;                  // 0x804
    int32_t                    mNextOrder;                // 0x808 confirmed
};

// size = 0xDDC
struct FMOD__CodecMOD {
    FMOD__MusicSong   _;           // 0x000
    FMOD__MusicSample mSample[31]; // 0x80C
};

// size = 0x1A9C
struct FMOD__CodecS3M {
    FMOD__MusicSong   _;           // 0x000
    FMOD__MusicSample mSample[99]; // 0x80C
};

// size = 0x810
struct FMOD__CodecXM {
    FMOD__MusicSong     _;       // 0x000
    FMOD__MusicSample** mSample; // 0x80C
};

// size = 0x39F4
struct FMOD__CodecIT {
    FMOD__MusicSong     _; // 0x000
    FMOD__MusicSample** mSample;
    FMOD__MusicSample   mSampleMem[256];
    int8_t*             mPatternPtr; // 0x3810 confirmed
    uint32_t*           mSrcBuffer;
    uint32_t*           mSrcPos;
    uint8_t             mSrcRemBits;
    int32_t             mNumRealChannels;
    FMOD__SNDMIXPLUGIN* mMixPlugin[50]; // 0x3824 (mac)
    uint32_t            mChannelPlugin[64];
    FMOD__DSPI*         mDSPFinalHead;
    FMOD__DSPI*         mDSPEffectHead;
};

struct FMOD__CodecDLSEnvelopePoint {
    float mTime;
    float mSrcValue;
    float mDestValue;
};

struct FMOD__CodecDLSEnvelope {
    FMOD__CodecDLSEnvelopePoint mPoint[3];
    FMOD__CODEC_DLS_ENVPOINT    mPosition;
    float                       mTime;
    float                       mSustain;
    float                       mRange;
    bool                        mActive;
};

struct FMOD__CodecDLSRegion {
    FMOD__DLS_REGIONHEADER     mRegionHeader;
    FMOD__DLS_WAVESAMPLE       mWaveSample;
    FMOD__DLS_WAVELINK         mWaveLink;
    int32_t                    mNumConnectionBlocks;
    FMOD__DLS_CONNECTIONBLOCK* mConnectionBlock;
};

struct FMOD__CodecDLSInstrument {
    char                       mName[256];
    FMOD__DLS_INSTRUMENTHEADER mHeader;
    FMOD__CodecDLSRegion*      mRegion;
    int32_t                    mNumConnectionBlocks;
    FMOD__DLS_CONNECTIONBLOCK* mConnectionBlock;
};

struct FMOD__CodecDLSSample {
    char                 mName[256];
    uint32_t             mDataOffset;
    FMOD__DLS_WAVESAMPLE mWaveSample;
};

// size = 0xF8
struct FMOD__CodecDLS {
    FMOD__Codec               _;               // 0x00
    int32_t                   mNumInstruments; // 0xD8
    int32_t                   mInstrumentID;   // 0xDC
    FMOD__CodecDLSInstrument* mInstrument;     // 0xE0
    int32_t                   mNumSamples;     // 0xE4
    int32_t                   mSampleID;       // 0xE8
    FMOD__CodecDLSSample*     mSample;         // 0xEC
    int32_t                   mCurrentIndex;   // 0xF0
    uint32_t                  mRegionID;       // 0xF4
};

struct FMOD__CodecMIDIDLSCache {
    FMOD__LinkedListNode _;
    char                 mFilePath[256];
    FMOD__SoundI*        mDLSFile;
    int32_t              mRefCount;
};

// size = 0x268
struct FMOD__CodecMIDISubChannel {
    FMOD__LinkedListNode       _;
    FMOD__CodecMIDI*           mMIDI;
    FMOD__ChannelI             mChannel;
    FMOD__CodecDLSInstrument*  mInstrument;
    float                      mLFOStartDelay; // 0x1B0 (mac)
    float                      mLFOTime;       // 0x1B4 (mac)
    float                      mLFOFrequency;  // 0x1B8 (mac)
    FMOD__CodecDLSEnvelope     mVolumeEnvelope;
    FMOD__CodecDLSEnvelope     mPitchEnvelope;
    int32_t                    mCurrentNote;
    FMOD__SoundI*              mSound;
    uint8_t                    mKeyOnKey;
    uint8_t                    mUnityNote;
    int32_t                    mFineTune;
    uint8_t                    mKeyOnVelocity;
    int32_t                    mNumArticulators;
    FMOD__DLS_CONNECTIONBLOCK* mArticulator;
    float                      mTremoloScale;
    float                      mVibratoScale;
    float                      mPanbrelloScale;
    bool                       mKeyOff;  // 0x254 (mac)
    int32_t                    mMiddleC; // 0x258 (mac)
    int32_t                    mKeyGroup;
    float                      mSampleAttenuation;
    FMOD__CodecMIDIChannel*    mParent;
};

// size = 0x2AC
struct FMOD__CodecMIDIChannel {
    FMOD__LinkedListNode      _;
    FMOD__CodecMIDITrack*     mTrack;
    FMOD__CodecMIDISubChannel mChannelHead;
    uint8_t                   mIndex;
    uint8_t                   mKeyOffVelocity;
    uint8_t                   mKeyOnVelocity;
    uint8_t                   mAfterTouchKey;
    uint8_t                   mAfterTouchPressure;
    uint32_t                  mBank;
    uint8_t                   mProgram;
    uint32_t                  mRPN;
    uint8_t                   mChannelPressure;
    // float                     mMasterVolume;
    int32_t mPitchBend;
    int32_t mPitchBendSensitivity;
    bool    mDamperPedal;
    int32_t mModWheel;
    int32_t mVolume;
    int32_t mPan;
    int32_t mExpression;
};

// size = [0x20]
struct FMOD__CodecMIDITrack {
    FMOD__CodecMIDI* mMIDI;
    uint8_t*         mData;
    uint32_t         mOffset;
    uint32_t         mLength;
    int32_t          mIndex;
    bool             mReadDelta;
    float            mTick;
    bool             mFinished;
    uint8_t          mPort;
    uint8_t          mEvent;
};

// size = 0x2EBC
struct FMOD__CodecMIDI {
    FMOD__Codec                _; // 0x0000
    FMOD__DSPI*                mDSPHead;
    FMOD__ChannelPool*         mChannelPool;
    FMOD__ChannelSoftware*     mChannelSoftware;
    int32_t                    mNumSubChannels;
    FMOD__ChannelGroupI        mChannelGroup; // 0x00E8 confirmed
    FMOD__CodecMIDISubChannel* mMIDISubChannel;
    FMOD__CodecMIDIChannel     mMIDIChannel[16];
    bool                       mFinished;
    int32_t                    mSequenceNumber;
    uint32_t                   mMixerSamplesLeft;
    uint32_t                   mMixerSamplesPerTick;
    float                      mTimingScale;
    uint32_t                   mPCMOffset; // 0x2C1C (mac)
    int32_t                    mNumTracks; // 0x2C20 confirmed
    FMOD__MIDI_FORMAT          mMIDIFormat;
    int32_t                    mDivision;
    uint8_t                    mSMTPOffsetHours;
    uint8_t                    mSMTPOffsetMinutes;
    uint8_t                    mSMTPOffsetSeconds;
    uint8_t                    mSMTPOffsetFrames;
    uint8_t                    mSMTPOffsetSubFrames;
    uint8_t                    mTimeSignatureNumerator;
    uint8_t                    mTimeSignatureDenominator;
    uint8_t                    mTimeSignatureMetronome;
    uint8_t                    mTimeSignatureNotated32nds;
    uint8_t                    mKeySignatureSF;
    uint8_t                    mKeySignatureMI;
    FMOD__CodecMIDITrack*      mTrack; // 0x2C38 confirmed
    uint32_t                   mTempo;
    float                      mTick;                // 0x2C40 (mac)
    float                      mMillisecondsPerTick; // 0x2C44
    FMOD__SoundI*              mDLSSound;            // 0x2C48
    FMOD__CodecDLS*            mDLS;                 // 0x2C4C
    bool*                      mSampleInclusionList;
    FMOD__CodecMIDISubChannel  mChannelFreeListHead;
};

#define INTERFACE FMOD__CROStream
struct FMOD__CROStream__v_table {
    // IUnknown methods
    COM_P_METHOD(HRESULT, _00_QueryInterface, REFIID riid, void** ppvObject);
    COM_E_METHOD(uint32_t, _01_AddRef);
    COM_E_METHOD(uint32_t, _02_Release);
    // ISequentialStream methods
    COM_P_METHOD(HRESULT, _03_Read, void* pv, uint32_t cb, uint32_t* pcbRead);
    // COM_P_METHOD(HRESULT, _04_RemoteRead, uint8_t* pv, uint32_t cb, uint32_t* pcbRead);
    COM_P_METHOD(HRESULT, _05_Write, const void* pv, uint32_t cb, uint32_t* pcbWritten);
    // COM_P_METHOD(HRESULT, _06_RemoteWrite, const uint8_t* pv, uint32_t cb, uint32_t* pcbWritten);
    // IStream methods
    COM_P_METHOD(
        HRESULT,
        _07_Seek,
        LARGE_INTEGER   dlibMove,
        uint32_t        dwOrigin,
        ULARGE_INTEGER* plibNewPosition);
    // COM_P_METHOD(
    //     HRESULT,
    //     _08_RemoteSeek,
    //     LARGE_INTEGER   dlibMove,
    //     uint32_t        dwOrigin,
    //     ULARGE_INTEGER* plibNewPosition);
    COM_P_METHOD(HRESULT, _09_SetSize, ULARGE_INTEGER libNewSize);
    COM_P_METHOD(
        HRESULT,
        _10_CopyTo,
        IStream*        pstm,
        ULARGE_INTEGER  cb,
        ULARGE_INTEGER* pcbRead,
        ULARGE_INTEGER* pcbWritten);
    // COM_P_METHOD(
    //     HRESULT,
    //     _11_RemoteCopyTo,
    //     IStream*        pstm,
    //     ULARGE_INTEGER  cb,
    //     ULARGE_INTEGER* pcbRead,
    //     ULARGE_INTEGER* pcbWritten);
    COM_P_METHOD(HRESULT, _12_Commit, uint32_t grfCommitFlags);
    COM_E_METHOD(HRESULT, _13_Revert);
    COM_P_METHOD(
        HRESULT,
        _14_LockRegion,
        ULARGE_INTEGER libOffset,
        ULARGE_INTEGER cb,
        uint32_t       dwLockType);
    COM_P_METHOD(
        HRESULT,
        _15_UnlockRegion,
        ULARGE_INTEGER libOffset,
        ULARGE_INTEGER cb,
        uint32_t       dwLockType);
    COM_P_METHOD(HRESULT, _16_Stat, STATSTG* pstatstg, uint32_t grfStatFlag);
    COM_P_METHOD(HRESULT, _17_Clone, IStream** ppstm);
    // CROStream methods
    // COM_P_METHOD(HRESULT, _18_Open, const char* ptszURL);
};
#undef INTERFACE

struct FMOD__CROStream {
    FMOD__CROStream__v_table* v_table;
    FMOD__File*               mFile;
    int32_t                   m_cRefs;
};

// size = 0x100
struct FMOD__CodecASF {
    FMOD__Codec      _;       // 0x000
    IWMSyncReader*   mReader; // 0x0D8
    FMOD__CROStream* mStream; // 0x0DC
    // bool             mCoInitialized;  // 0x0E0
    // uint16_t         mAudioStreamNum; // 0x0E4
    // uint16_t         mVideoStreamNum; // 0x0E6
    // uint64_t         mSampleTime;     // 0x0E8
    // bool             mSeekable;       // 0x0F0
    // int32_t          mNumSyncPoints;  // 0x0F4
    // FMOD__SyncPoint* mSyncPoint;      // 0x0F8
    // uint32_t         mExcessBytes;    // 0x0FC
    uint16_t mAudioStreamNum; // 0x0E0
    uint16_t mVideoStreamNum; // 0x0E2
    // uint32_t         unk0E4;          // 0x0E4
    uint64_t         mSampleTime;    // 0x0E8
    bool             mSeekable;      // 0x0F0
    int32_t          mNumSyncPoints; // 0x0F4
    FMOD__SyncPoint* mSyncPoint;     // 0x0F8
    uint32_t         mExcessBytes;   // 0x0FC
};

// size = 0x200
struct FMOD__CodecUser {
    FMOD__Codec           _;           // 0x000
    FMOD_CODEC_WAVEFORMAT mWaveFormat; // 0x0D8
};

// size = 0x200
struct FMOD__CodecPlaylist {
    FMOD__Codec           _;           // 0x000
    FMOD_CODEC_WAVEFORMAT mWaveFormat; // 0x0D8
};

// size = 0x118
struct FMOD__DSPOscillator {
    FMOD__DSPFilter _;          // 0x000
    float           mRate;      // 0x104
    int32_t         mType;      // 0x108
    float           mRateHz;    // 0x10C
    int32_t         mDirection; // 0x110
    float           mPosition;  // 0x114
};

struct FMOD__LOWPASS_BIQUAD {
    float a0;
    float a1;
    float a2;
    float b0;
    float b1;
    float b2;
};

// size = 0x270
struct FMOD__DSPLowPass {
    FMOD__DSPFilter _; // 0x000
    // float                mResonance;       // 0x104
    // float                mResonanceUpdate; // 0x108
    // float                mCutoffHz;        // 0x10C
    // float                mCutoffHzUpdate;  // 0x110
    // float                mCutoffHzMaximum; // 0x114
    // float                mGainFactor[2];   // 0x118
    // float                mHistory[16][4];
    // float                mCoefficients[9];
    // FMOD__LOWPASS_BIQUAD mProtoCoef[2];
    float                mResonance;       // 0x104
    float                mResonanceUpdate; // 0x108
    float                mCutoffHz;        // 0x10C
    float                mCutoffHzUpdate;  // 0x110
    float                mGainFactor[2];   // 0x114
    float                mHistory[16][4];  // 0x11C
    float                mCoefficients[9]; // 0x21C
    FMOD__LOWPASS_BIQUAD mProtoCoef[2];    // 0x240
};

// size = 0x1A0
struct FMOD__DSPLowPass2 {
    FMOD__DSPFilter _;                // 0x000
    float           mResonance;       // 0x104
    float           mResonanceUpdate; // 0x108
    float           mCutoffHz;        // 0x10C
    float           mCutoffHzUpdate;  // 0x110
    float           mFilter_Y[16][2]; // 0x114
    float           mFilter_A0;       // 0x194
    float           mFilter_B0;       // 0x198
    float           mFilter_B1;       // 0x19C
};

// size = 0x194
struct FMOD__DSPLowPassSimple {
    FMOD__DSPFilter _;                   // 0x000
    float           mCutoffHz;           // 0x104
    float           mCutoffHzUpdate;     // 0x108
    float           mFilter_Y[16][2];    // 0x188
    float           mFilter_tc;          // 0x18C
    float           mFilter_oneminus_tc; // 0x190
};

// size = 0x22C
struct FMOD__DSPHighPass {
    FMOD__DSPFilter _; // 0x000
    float           mCutoffHz;
    float           mCutoffHzUpdate;
    float           mResonance;
    float           mResonanceUpdate;
    float           mIn1[16];
    float           mIn2[16];
    float           mOut1[16];
    float           mOut2[16];
    float           mCoefficient_A0;
    float           mCoefficient_A1;
    float           mCoefficient_A2;
    float           mCoefficient_B0;
    float           mCoefficient_B1;
    float           mCoefficient_B2;
};

// size = 0x138
struct FMOD__DSPEcho {
    // FMOD__DSPFilter _;                 // 0x000
    // float           mDecay;            // 0x104
    // float           mDecayRatio;       // 0x108
    // float           mDryMix;           // 0x10C
    // float           mWetMix;           // 0x110
    // int32_t         mMaxChannels;      // 0x114
    // float           mDelayUpdate;      // 0x118
    // float           mDecayRatioUpdate; // 0x11C
    // float           mDryMixUpdate;     // 0x120
    // float           mWetMixUpdate;     // 0x124
    // int16_t*        mEchoBuffer;       // 0x128
    // int16_t*        mEchoBufferMemory;
    // uint32_t        mEchoBufferLengthBytes;
    // uint32_t        mEchoPosition;
    // uint32_t        mEchoLength;
    // uint32_t        mMaxLength;
    // int32_t         mOutputRate;
    // int32_t         mChannels;
    // int32_t         mChannelsUpdate;
    //
    // uint16_t mOldSpeakerMask;
    FMOD__DSPFilter _;                      // 0x000
    float           mDelay;                 // 0x104
    float           mDecayRatio;            // 0x108
    float           mDryMix;                // 0x10C
    float           mWetMix;                // 0x110
    int32_t         mMaxChannels;           // 0x114
    float*          mEchoBuffer;            // 0x118 (could be mEchoBufferMemory?)
    float*          mEchoBufferMemory;      // 0x11C unused
    uint32_t        mEchoBufferLengthBytes; // 0x120
    uint32_t        mEchoPosition;          // 0x124
    uint32_t        mEchoLength;            // 0x128
    uint32_t        mMaxLength;             // 0x12C unused
    int32_t         mOutputRate;            // 0x130
    int32_t         mChannels;              // 0x134
};

// size = 0x8134
struct FMOD__DSPFlange {
    FMOD__DSPFilter _;                        // 0x000
    float           mDepth;                   // 0x104
    float           mDryMix;                  // 0x108
    float           mWetMix;                  // 0x10C
    float           mRateHz;                  // 0x110
    float*          mFlangeBuffer;            // 0x114 TODO confirm type
    uint32_t        mFlangeBufferLength;      // 0x118
    uint32_t        mFlangeBufferLengthBytes; // 0x11C
    uint32_t        mFlangeBufferPosition;    // 0x120
    float           mFlangePosition;          // 0x124
    float           mFlangeTick;              // 0x128
    float           mFlangeSpeed;             // 0x12C
    int32_t         mOutputRate;              // 0x130
    float           mCosTab[8192];            // 0x134
};

// size = 0x10C
struct FMOD__DSPDistortion {
    FMOD__DSPFilter _;             // 0x000
    float           mLevel;        // 0x104
    bool            mSupportsSIMD; // 0x108
};

// size = 0x120
struct FMOD__DSPNormalize {
    FMOD__DSPFilter _;              // 0x000
    float           mThreshold;     // 0x104
    float           mMaxAmp;        // 0x108
    float           mFadeTime;      // 0x10C
    float           mAttackSpeed;   // 0x110
    float           mMaximum;       // 0x114
    float           mTargetMaximum; // 0x118
    int32_t         mOutputRate;    // 0x11C
};

// size = 0x234
struct FMOD__DSPParamEq {
    FMOD__DSPFilter _;                 // 0x000
    float           mCenter;           // 0x104
    float           mBandwidth;        // 0x108
    float           mGain;             // 0x10C
    float           mCenterUpdate;     // 0x110
    float           mBandwidthUpdate;  // 0x114
    float           mGainUpdate;       // 0x118
    float           mFilterIn[16][2];  // 0x11C
    float           mFilterOut[16][2]; // 0x19C
    float           mCoefficient_a0;   // 0x21C
    float           mCoefficient_a1;   // 0x220
    float           mCoefficient_a2;   // 0x224
    float           mCoefficient_b0;   // 0x228
    float           mCoefficient_b1;   // 0x22C
    float           mCoefficient_b2;   // 0x230
};

// size = 0x1403C
struct FMOD__DSPPitchShiftSMB {
    float   mInFIFO[4096];
    float   mOutFIFO[4096];
    float   mLastPhase[2052];
    float   mSumPhase[2052];
    float   mOutputAccum[8192];
    float*  mWindow;
    int32_t mRover;
    float   mPitchRatioFromLast;
    int32_t mFFTFrameSize;
    int32_t mFFTFrameBits;
    float*  mCosTab;
    bool    mResetPhaseFlag;
};

// size = 0xC124
struct FMOD__DSPPitchShift {
    FMOD__DSPFilter         _;             // 0x0000
    float                   mCosTab[8192]; // 0x0104
    float                   mWindow[4096];
    float                   mPitch;
    int32_t                 mFFTSize;
    int32_t                 mOverlap;
    int32_t                 mMaxChannels;
    FMOD__DSPPitchShiftSMB* mPitchShift;
    int32_t                 mOutputRate;
    int32_t                 mChannels;
    int32_t                 mFFTFrameBits;
};

// size = 0x8150
struct FMOD__DSPChorus {
    FMOD__DSPFilter _;
    float           mDepth;                   // 0x104
    float           mDryMix;                  // 0x108
    float           mWetMix1;                 // 0x10C
    float           mWetMix2;                 // 0x110
    float           mWetMix3;                 // 0x114
    float           mFeedback;                // 0x118
    float           mDelay;                   // 0x11C
    float           mRateHz;                  // 0x120
    int16_t*        mChorusBuffer;            // 0x124
    int16_t*        mChorusBufferMemory;      // 0x128
    uint32_t        mChorusBufferLength;      // 0x12C
    uint32_t        mChorusBufferLengthBytes; // 0x130
    uint32_t        mChorusBufferPosition;    // 0x134
    float           mChorusPosition[3];       // 0x138
    float           mChorusTick;              // 0x144
    float           mChorusSpeed;             // 0x148
    int32_t         mOutputRate;              // 0x14C
    float           mCosTab[8192];            // 0x0150
};

// size = 0x19118
struct FMOD__DSPReverb {
    FMOD__DSPFilter _;       // 0x0000
    revmodel        mReverb; // 0x0104
};

// size = 0x140
struct FMOD__DSPITEcho {
    FMOD__DSPFilter _;                         // 0x000
    float           mWetDryMix;                // 0x104
    float           mFeedback;                 // 0x108
    float           mDelay[2];                 // 0x10C
    bool            mPanDelay;                 // 0x114
    float*          mEchoBuffer[2];            // 0x118
    uint32_t        mEchoBufferLengthBytes[2]; // 0x120
    uint32_t        mEchoPosition[2];          // 0x128
    uint32_t        mEchoLength[2];            // 0x130
    uint32_t        mMaxLength;                // 0x138
    int32_t         mOutputRate;               // 0x13C
};

// size = 0x16C
struct FMOD__DSPCompressor {
    FMOD__DSPFilter _; // 0x000
    float           mHoldConstant;
    float           mAttack_ms;
    float           mAttack_constant;
    float           mRelease_ms;
    float           mRelease_constant;
    float           mThreshold_dB;
    float           mThreshold_lin;
    float           mGainMakeup_dB;
    float           mGainMakeup_lin;
    float           mGain;
    float           mMaxChannelIn[16];
};

struct I3DL2_LISTENERPROPERTIES {
    int32_t lRoom;               // [-10000, 0]      default: -10000 mB
    int32_t lRoomHF;             // [-10000, 0]      default: 0 mB
    float   flRoomRolloffFactor; // [0.0, 10.0]      default: 0.0
    float   flDecayTime;         // [0.1, 20.0]      default: 1.0 s
    float   flDecayHFRatio;      // [0.1, 2.0]       default: 0.5
    int32_t lReflections;        // [-10000, 1000]   default: -10000 mB
    float   flReflectionsDelay;  // [0.0, 0.3]       default: 0.02 s
    int32_t lReverb;             // [-10000, 2000]   default: -10000 mB
    float   flReverbDelay;       // [0.0, 0.1]       default: 0.04 s
    float   flDiffusion;         // [0.0, 100.0]     default: 100.0 %
    float   flDensity;           // [0.0, 100.0]     default: 100.0 %
    float   flHFReference;       // [20.0, 20000.0]  default: 5000.0 Hz
};

struct coeff2ndorder {
    float a0;
    float a1;
    float a2;
    float b1;
    float b2;
};

struct ASfxDsp {
    float*        mInBuff;                       // 0x000
    int32_t       mNumAllocatedInBuffSamples;    // 0x004
    float         mRoomHF;                       // 0x008
    bool          mRoomHFChanged;                // 0x00C
    float         mLatchRoomHF;                  // 0x010
    float         mPrevRoomHF;                   // 0x014
    float         mOldRoomHF;                    // 0x018
    float         mzRoomHF0;                     // 0x01C
    float         mzRoomHF1;                     // 0x020
    coeff2ndorder mRoomLFcoeffs;                 // 0x024
    float         mRoomLF;                       // 0x038
    float         mzRoomLF0;                     // 0x03C
    float         mzRoomLF1;                     // 0x040
    float         mDecayHF[8];                   // 0x044
    bool          mDecayHFChanged[8];            // 0x064
    float         mLatchDecayHF[8];              // 0x06C
    float         mLatchOneMinusDecayHF[8];      // 0x08C
    float         mPrevDecayHF[8];               // 0x0AC
    float         mOldDecayHF[8];                // 0x0CC
    float         mzDecayHF[8];                  // 0x0EC
    float         mMatrix[24];                   // 0x10C
    float         mFeedback[8];                  // 0x16C
    float         mLatchFeedback[8];             // 0x18C
    float         mOldFeedback[8];               // 0x1AC
    float         mPrevFeedback[8];              // 0x1CC
    float         mHadamard;                     // 0x1EC
    bool          mHadamardChanged;              // 0x1F0
    float         mLatchHadamard;                // 0x1F4
    float         mPrevHadamard;                 // 0x1F8
    float         mOldHadamard;                  // 0x1FC
    float         mERgain;                       // 0x200
    float         mLRgain;                       // 0x204
    bool          mLRgainChanged;                // 0x208
    float         mLatchLRgain;                  // 0x20C
    float         mPrevLRgain;                   // 0x210
    float         mOldLRgain;                    // 0x214
    bool          mERgainChanged;                // 0x218
    float         mLatchERgain;                  // 0x21C
    float         mPrevERgain;                   // 0x220
    float         mOldERgain;                    // 0x224
    float         mDiffusionScale;               // 0x228
    bool          mDiffusionScaleChanged;        // 0x22C
    float         mLatchDiffusionScale;          // 0x230
    float         mPrevDiffusionScale;           // 0x234
    float         mOldDiffusionScale;            // 0x238
    float         mAllpassGain;                  // 0x23C
    int32_t       mNumLateReverbDelays;          // 0x240
    float**       mLateDelays;                   // 0x244 weird: float*[8]
    float         mLateDelayLenSec[8];           // 0x248
    int32_t       mLateDelayLenSamples[8];       // 0x268
    int32_t       mOldLateDelayLenSamples[8];    // 0x288
    int32_t       mLateDelayLenBSamples[8];      // 0x2A8 TODO: confirm this
    int32_t       mLateDelaySamplesAllocated[8]; // 0x2C8
    bool          mLateChanged[8];               // 0x2E8
    int32_t       mLateMask[8];                  // 0x2F0
    int32_t       mLateWritePointer[8];          // 0x310
    int32_t       mLateReadPointer[8];           // 0x330
    int32_t       mOldLateReadPointer[8];        // 0x350
    int32_t       mLateReadPointerB[8];          // 0x370
    float*        mEarlyLateDelay;               // 0x390
    // TODO: confirm this: this is probably an unused cache line optimization
    float*  mEarlyLateDelayMemory;       // 0x394
    float   mEarlyLateSec[9];            // 0x398
    int32_t mEarlyLateSamples[9];        // 0x3BC
    int32_t mOldEarlyLateSamples[9];     // 0x3E0
    bool    mEarlyLateChanged[9];        // 0x404
    int32_t mEarlyLateSamplesAllocated;  // 0x410
    int32_t mEarlyLateMask;              // 0x414
    int32_t mEarlyLateWritePointer;      // 0x418
    int32_t mEarlyLateReadPointer[9];    // 0x41C
    int32_t mOldEarlyLateReadPointer[9]; // 0x440
    float*  mEarlyDelay;                 // 0x464
    float   mEarlyDelayLenSec[7];        // 0x468
    int32_t mEarlyDelayLenSamples[7];    // 0x484
    int32_t mEarlyDelaySamplesAllocated; // 0x4A0
    int32_t mEarlyMask;                  // 0x4A4
    int32_t mEarlyWritePointer;          // 0x4A8
    int32_t mEarlyReadPointer[7];        // 0x4AC
    float** mAllpassDelays;              // 0x4C8 weird: float*[2]
    float   mAllpassDelayLenSec[2];      // 0x4CC
    int32_t mAllpassDelayLenSamples[2];  // 0x4D4
    int32_t mAllpassSamplesAllocated[2]; // 0x4DC
    int32_t mAllpassMask[2];             // 0x4E4
    int32_t mAllpassWritePointer[2];     // 0x4EC
    int32_t mAllpassReadPointer[2];      // 0x4F4
    int32_t mNumMatrixStages;            // 0x4FC
};

struct FMOD__SFX_REVERB_LFPROPS {
    int32_t mRoomLF;
    float   mLFReference;
};

// 0x188
struct FMOD__DSPSfxReverb {
    FMOD__DSPFilter          _;              // 0x000
    I3DL2_LISTENERPROPERTIES mProps;         // 0x104 TODO confirm
    I3DL2_LISTENERPROPERTIES mUpdateProps;   // 0x134
    bool                     mUpdateFlag;    // 0x164 XREF readInternal
    float                    mDryLevelmB;    // 0x168
    float                    mDryLevelLin;   // 0x16C
    FMOD__SFX_REVERB_LFPROPS mLFProps;       // 0x170
    FMOD__SFX_REVERB_LFPROPS mUpdateLFProps; // 0x178
    ASfxDsp*                 mpSfxDsp;       // 0x180
    int32_t                  mOutputRate;    // 0x184
};

// size = 0x10C
struct FMOD__DSPSoundCard {
    FMOD__DSPFilter _;                // 0x000
    float*          mMixBuffer;       // 0x104 invented the memory-aligned pointer to 0x108
    float*          mMixBufferMemory; // 0x108 invented: the memory buffer
};

// size = 0x270
struct FMOD__Output {
    FMOD__Plugin         _0;                     // 0x00
    FMOD_OUTPUT_STATE    _1;                     // 0x18
    FMOD__ChannelPool*   mChannelPool;           // 0x20
    bool                 mPolling;               // 0x24
    FMOD__SystemI*       mSystem;                // 0x28
    FMOD__ChannelPool*   mChannelPool3D;         // 0x2C
    int32_t              mMixAheadBlocks;        // 0x30
    FMOD__ChannelGroupI* mMusicChannelGroup;     // 0x34
    int32_t              mNum2DChannelsFromCaps; // 0x38
    int32_t              mNum3DChannelsFromCaps; // 0x3C
    int32_t              mTotalChannelsFromCaps; // 0x40
    bool                 mRecording;             // 0x44 XREF OutputWASAPI::recordUpdate
    int32_t              mRecordOffset;          // 0x48
    bool                 mRecordLoop;            // 0x4C
    FMOD_SOUND_FORMAT    mRecordFormat; // 0x50 TODO: is this part of a FMOD_RECORDING_INFO struct?
    uint32_t             mRecordLastCursorPos; // 0x54
    uint32_t             mRecordBufferLength;  // 0x58
    FMOD__SoundI*        mRecordSound;         // 0x5C
    int32_t              mRecordRate;          // 0x60
    bool                 mRecordResample; // 0x64 "record use channels?" "record use resampler DSP?"
    FMOD__DSPResampler   mRecordResamplerDSP;     // 0x68
    float*               mRecordTempBuffer;       // 0x1D0
    uint32_t             mRecordTempBufferLength; // 0x1D4
    FMOD_OUTPUT_DESCRIPTION_EX mDescription;      // 0x1D8
};

// size = [0x3A0] (unconfirmed)
// class OutputPolled : public Output, public Thread
struct FMOD__OutputPolled {
    FMOD__Output       _0;                    // 0x000
    FMOD__Thread       _1;                    // 0x270
    int32_t            mCursorBlock;          // 0x394
    bool               mPolledFromMainThread; // 0x398
    FMOD_OS_SEMAPHORE* mFinishedSema;         // 0x39C
};

// class OutputNoSound : public OutputPolled
//
// size = 0x3A8
struct FMOD__OutputNoSound {
    FMOD__OutputPolled _;                 // 0x000
    uint32_t           mBlockLengthBytes; // 0x3A0
    char*              mBuffer;           // 0x3A4
};

// size = 0x278
struct FMOD__OutputNoSound_NRT {
    FMOD__Output _;             // 0x000
    uint32_t     mBufferLength; // 0x270
    void*        mBuffer;       // 0x274
};

// size = 0x278 (26C mac)
struct FMOD__OutputSoftware {
    FMOD__Output           _;
    FMOD__ChannelSoftware* mChannel;
};

struct FMOD__OutputEmulated {
    FMOD__Output           _;
    FMOD__ChannelEmulated* mChannel;
};

// size = ???
// class OutputTimer : public Output
struct FMOD__OutputTimer {
    FMOD__Output             _;                 // 0x000
    float                    mMixerTimerPeriod; // 0x270
    uint32_t                 mMixerTimerID;     // 0x274
    bool                     mPlaying;          // 0x278
    bool                     mThreadElevated;   // 0x279
    FMOD_OS_CRITICALSECTION* mMixerCrit;        // 0x27C
    int32_t                  mFillBlock;        // 0x280
    uint32_t                 unk284;            // 0x284
};

struct FMOD__SourceOpenAL {
    bool    used;
    ALuint  sid;
    ALuint* bid;
};

// size = 0x470
struct FMOD__OutputOpenAL {
    FMOD__OutputTimer    _;                    // 0x00
    OPENALFNTABLE        mOALFnTable;          // 0x288
    bool                 mSetupOnce;           // 0x394
    bool                 mInitialised;         // 0x395
    bool                 mDLLInitialised;      // 0x396
    ALCdevice*           mDevice;              // 0x398
    ALCcontext*          mContext;             // 0x39C
    int32_t              mNumDrivers;          // 0x3A0
    char*                mDriverNames[32];     // 0x3A4
    int32_t              mNumBuffers;          // 0x424
    uint32_t             mBufferLength;        // 0x428
    uint32_t             mBufferLengthBytes;   // 0x42C
    uint32_t             mPcmBase;             // 0x430
    char*                mBufferData;          // 0x434
    int32_t              mNumChannels;         // 0x438
    FMOD__ChannelOpenAL* mChannels;            // 0x43C
    int32_t              mNumSources;          // 0x440
    FMOD__SourceOpenAL*  mSources;             // 0x444
    uint32_t             mMixerSourceOffset;   // 0x448
    int32_t              mRate;                // 0x44C
    FMOD_SOUND_FORMAT    mFormat;              // 0x450
    ALuint               mFormatOAL;           // 0x454
    int32_t              mNumHwChannels;       // 0x458
    int32_t              mOutputChannels;      // 0x45C
    FMOD__REVERB_VERSION mReverbVersion;       // 0x460
    bool                 mMixerReverbDisabled; // 0x464
    EAXSet               mEAXSet;              // 0x468
    EAXGet               mEAXGet;              // 0x46C
};

// size = 0x928
struct FMOD__OutputDSound {
    FMOD__OutputPolled         _;                            // 0x000
    bool                       mDLLInitialized;              // 0x3A0
    bool                       mCoInitialized;               // 0x3A1
    bool                       mGlobalFocus;                 // 0x3A2
    bool                       mNeedToCommit;                // 0x3A3
    FMOD_INITFLAGS             mInitFlags;                   // 0x3A4
    int32_t                    mDirectXVersion;              // 0x3A8
    HMODULE                    mDSoundModule;                // 0x3AC
    HMODULE                    mDSound3DModule;              // 0x3B0
    PFN_DSCREATE8              mDirectSoundCreate;           // 0x3B4
    PFN_DSENUMERATE            mDirectSoundEnumerate;        // 0x3B8
    IDirectSound8*             mDirectSound;                 // 0x3BC
    IDirectSound3DListener*    mDirectSoundListener;         // 0x3C0
    PFN_DSCENUMERATE           mDirectSoundCaptureEnumerate; // 0x3C4
    PFN_DSCCREATE8             mDirectSoundCaptureCreate;    // 0x3C8
    IDirectSoundCapture8*      mDirectSoundCapture;          // 0x3CC
    IDirectSoundCaptureBuffer* mDirectSoundCaptureBuffer;    // 0x3D0
    FMOD__REVERB_VERSION       mReverbVersion;               // 0x3D4
    uint32_t                   mFeaturesReverb;              // 0x3D8
    IKsPropertySet*            mBufferReverb;                // 0x3DC
    FMOD__SampleDSound*        mSampleReverb;                // 0x3E0
    bool                       mUseSoftware2DBuffers;        // 0x3E4
    bool                       mUseSoftware3DBuffers;        // 0x3E5
    float                      mMinFrequency;                // 0x3E8
    float                      mMaxFrequency;                // 0x3EC
    uint32_t                   mBufferLength;                // 0x3F0
    uint32_t                   mNumBuffers;                  // 0x3F4
    float                      mLastDopplerScale;            // 0x3F8
    float                      mLastDistancerScale;          // 0x3FC
    float                      mLastRolloffrScale;           // 0x400
    FMOD_SPEAKERMODE           mSpeakerMode;                 // 0x404
    FMOD__ChannelDSound*       mChannel2D;                   // 0x408
    FMOD__ChannelDSound*       mChannel3D;                   // 0x40C
    FMOD__Sample*              mSample;                      // 0x410
    uint32_t                   mBufferMemoryCurrent;         // 0x414
    uint32_t                   mBufferMemoryMax;             // 0x418
    int32_t                    mNumDrivers;                  // 0x41C
    char*                      mDriverName[32];              // 0x420
    GUID                       mGUID[32];                    // 0x4A0
    int32_t                    mRecordNumDrivers;            // 0x6A0
    char*                      mRecordDriverName[32];        // 0x6A4
    GUID                       mRecordGUID[32];              // 0x724
    uint32_t                   unk924;                       // 0x924
};

// size = 0x4C0
struct FMOD__OutputWavWriter {
    FMOD__OutputPolled _;                  // 0x000
    char               mFileName[256];     // 0x3A0
    void*              mBuffer;            // 0x4A0
    uint32_t           mBufferLengthBytes; // 0x4A4
    int32_t            mChannels;          // 0x4A8
    int32_t            mRate;              // 0x4AC
    int32_t            mBits;              // 0x4B0
    uint32_t           mLengthBytes;       // 0x4B4
    FMOD_SOUND_FORMAT  mFormat;            // 0x4B8
    // FILE* mFP;
    void* mFP; // 0x4BC
};

// size = 0x398
struct FMOD__OutputWavWriter_NRT {
    FMOD__Output      _;                  // 0x000
    char              mFileName[256];     // 0x270
    void*             mBuffer;            // 0x370
    uint32_t          mBufferLength;      // 0x374
    uint32_t          mBufferLengthBytes; // 0x378
    int32_t           mChannels;          // 0x37C
    int32_t           mRate;              // 0x380
    int32_t           mBits;              // 0x384
    uint32_t          mLengthBytes;       // 0x388
    FMOD_SOUND_FORMAT mFormat;            // 0x38C
    // FILE* mFP;
    void* mFP; // 0x390
};

// size = [0x24]
struct FMOD__SoundBlock {
    WAVEHDR wavehdr; // 0x00
    char*   data;    // 0x20
};

// size = 0x1330
struct FMOD__OutputWinMM {
    FMOD__OutputPolled _;                    // 0x0000
    bool               mCoInitialized;       // 0x03A0
    HWAVEOUT           mHandle;              // 0x03A4
    bool               mRunning;             // 0x03A8
    char*              mBuffer;              // 0x03AC
    FMOD__SoundBlock   mBlock[1];            // 0x03B0
    int32_t            mNumBlocks;           // 0x03D4
    uint32_t           mBlockLengthBytes;    // 0x03D8
    HWAVEIN            mRecordHandle;        // 0x03DC
    FMOD__Thread       mRecordThread;        // 0x03E0
    bool               mRecording;           // 0x0504
    int32_t            mRecordCurrentBlock;  // 0x0508
    int32_t            mRecordNextBlock;     // 0x050C
    FMOD__SoundBlock   mRecordBlock[100];    // 0x0510
    uint32_t           mRecordData;          // 0x1320
    uint32_t           mRecordBlockLenBytes; // 0x1324
    uint32_t           mRecordBlockAlign;    // 0x1328
    uint32_t           unk132C;              // 0x132C
};

// FMOD::FMOD_WASAPIDriver
struct FMOD_WASAPIDriver {
    char* id;
    char* name;
};

// size = 0x4D0
struct FMOD__OutputWASAPI {
    FMOD__OutputTimer        _;                    // 0x000
    bool                     mCoInitialized;       // 0x288
    bool                     mInitialised;         // 0x289
    bool                     mExclusiveMode;       // 0x28A
    int32_t                  mNumRenderDrivers;    // 0x28C
    FMOD_WASAPIDriver        mRenderDrivers[32];   // 0x290
    IAudioClient*            mRenderAudioClient;   // 0x390
    IAudioClock*             mRenderAudioClock;    // 0x394 invented name
    IAudioRenderClient*      mRenderClient;        // 0x398
    uint8_t*                 mRenderBuffer;        // 0x39C invented name
    uint32_t                 mRenderBufferLength;  // 0x3A0
    int32_t                  mNumCaptureDrivers;   // 0x3A4
    FMOD_WASAPIDriver        mCaptureDrivers[32];  // 0x3A8
    IAudioClient*            mCaptureAudioClient;  // 0x4A8 from FMOD_WASAPIRecordMembers
    IAudioCaptureClient*     mCaptureClient;       // 0x4AC
    uint8_t*                 mRecordBuffer;        // 0x4B0
    int32_t                  mRecordBlockAlign;    // 0x4B4
    float                    mRecordTimerPeriod;   // 0x4B8 invented name
    int32_t                  mRecordWritePosition; // 0x4BC
    bool                     mRecordStereoToMono;  // 0x4C0 from FMOD_WASAPIRecordMembers
    FMOD_OS_CRITICALSECTION* mRecordTimerCrit;     // 0x4C4 invented name
    uint32_t                 mRecordTimerID;       // 0x4C8
    uint32_t                 unk4CC;               // 0x4CC
};

// size = 0x2B8
struct FMOD__OutputASIO {
    FMOD__Output     _;                           // 0x000
    AsioDrivers*     mHandle;                     // 0x270
    int32_t          mInputChannels;              // 0x274
    int32_t          mOutputChannels;             // 0x278
    int32_t          mBufferMinSize;              // 0x27C
    int32_t          mBufferMaxSize;              // 0x280
    int32_t          mBufferPreferredSize;        // 0x284
    int32_t          mBufferGranularity;          // 0x288
    bool             mPostOutput;                 // 0x28C
    float*           mInterleavedBuffer;          // 0x290
    float*           mInterleavedRecordBuffer;    // 0x294
    uint32_t         mInterleavedRecordBufferPos; // 0x298
    bool             mRecordLoop;                 // 0x29C
    ASIOCallbacks    mCallbacks;                  // 0x2A0
    ASIOBufferInfo*  mBufferInfo;                 // 0x2B0
    ASIOChannelInfo* mChannelInfo;                // 0x2B4
};

struct FMOD_REVERB_STDPROPERTIES {
    int32_t Environment;
    float   Room;
    float   RoomHF;
    float   RoomLF;
    float   DecayTime;
    float   DecayHFRatio;
    float   Reflections;
    float   ReflectionsDelay;
    float   Reverb;
    float   ReverbDelay;
    float   HFReference;
    float   LFReference;
    float   RoomRolloffFactor;
    float   Diffusion;
    float   Density;
};

struct FMOD_REVERB_PROPERTIES {
    int32_t  Instance;
    int32_t  Environment;
    float    EnvSize;
    float    EnvDiffusion;
    int32_t  Room;
    int32_t  RoomHF;
    int32_t  RoomLF;
    float    DecayTime;
    float    DecayHFRatio;
    float    DecayLFRatio;
    int32_t  Reflections;
    float    ReflectionsDelay;
    float    ReflectionsPan[3];
    int32_t  Reverb;
    float    ReverbDelay;
    float    ReverbPan[3];
    float    EchoTime;
    float    EchoDepth;
    float    ModulationTime;
    float    ModulationDepth;
    float    AirAbsorptionHF;
    float    HFReference;
    float    LFReference;
    float    RoomRolloffFactor;
    float    Diffusion;
    float    Density;
    uint32_t Flags;
};

struct FMOD_REVERB_CHANNELDATA {
    FMOD_REVERB_CHANNELPROPERTIES mChanProps; // Channel properties which determine input levels
    FMOD__DSPConnection*          mDSPConnection;
    // float                         mPresenceGain;
};

// unknown if this exists in this version
// struct FMOD_REVERB_INSTANCE {
//     FMOD__DSPI*              mDSP;         // DSP which implements the reverb
//     FMOD_REVERB_CHANNELDATA* mChannelData; // Channeldata for each instance
//     FMOD_REVERB_PROPERTIES   mProps;       // ID3L2 listener properties determines nature of reverb
// };

// size = 0xC0
struct FMOD__ReverbI {
    FMOD__LinkedListNode     _;                       // 0x00
    FMOD__SystemI*           mSystem;                 // 0x0C
    FMOD__DSPI*              mDSP;                    // 0x10
    FMOD_REVERB_CHANNELDATA* mChannelData;            // 0x14
    FMOD_REVERB_PROPERTIES   mProps;                  // 0x18
    uint32_t                 mUserData;               // 0x94
    float*                   mPresenceGain;           // 0x98 invented/inferred name
    float                    mGain;                   // 0x9C
    bool                     mDisableIfNoEnvironment; // 0xA0
    bool                     m3D;                     // 0xA1
    bool                     mActive;                 // 0xA2
    FMOD_REVERB_MODE         mMode;                   // 0xA4
    FMOD_VECTOR              mPosition;               // 0xA8
    float                    mMinRadius;              // 0xB4
    float                    mMaxRadius;              // 0xB8
    float                    mMinMaxDistance;         // 0xBC
};

struct FMOD__OctreeNode {
    FMOD_AABB         aabb;
    int32_t           flags;
    uint32_t          splitLevel;
    uint32_t          pos[3];
    FMOD__OctreeNode* parent;
    FMOD__OctreeNode* hi;
    FMOD__OctreeNode* lo;
    FMOD__OctreeNode* nextItem;
};

struct FMOD__Octree__RecursionData {
    FMOD__Octree__RecursionData__octreeLineTestCallback octreeLineTestCallback;
    void*                                               data;
    bool                                                exit;
};

// size = [0x18]
struct FMOD__Octree {
    FMOD__OctreeNode* mRoot;
    FMOD_VECTOR       mCenter;
    float             mScale;
    FMOD__OctreeNode* mFreeList;
};

struct FMOD_POLYGON {
    FMOD__OctreeNode node;
    FMOD__OctreeNode nodeInternal;
    float            distance;
    FMOD_VECTOR      normal;
    float            directOcclusion;
    float            reverbOcclusion;
    int32_t          flags;
    FMOD_VECTOR      vertices;
};

struct FMOD__GeometryI__SpatialData {
    FMOD__OctreeNode octreeNode;
    FMOD__OctreeNode octreeInternalNode;
    FMOD__GeometryI* geometry;
};

struct FMOD__GeometryI__LineTestData {
    FMOD_VECTOR      start;
    FMOD_VECTOR      end;
    float            directTransmission;
    float            reverbTransmission;
    FMOD__GeometryI* geometryI;
};

// size = [0x10C]
struct FMOD__GeometryI {
    FMOD__LinkedListNode          _;                  // 0x000
    FMOD__GeometryMgr*            mGeometryMgr;       // 0x00C
    int32_t                       mMaxNumVertices;    // 0x010
    int32_t                       mNumVertices;       // 0x014
    int32_t                       mMaxNumPolygons;    // 0x018
    int32_t                       mNumPolygons;       // 0x01C
    int32_t*                      mPolygonOffsets;    // 0x020
    int32_t                       mPolygonDataPos;    // 0x024
    uint8_t*                      mPolygonData;       // 0x028
    void*                         mUserData;          // 0x02C
    FMOD__OctreeNode*             mPolygonUpdateList; // 0x030 confirmed
    FMOD_AABB                     mAABB;              // 0x034
    bool                          mActive;            // 0x04C
    FMOD_VECTOR                   mForward;           // 0x050
    FMOD_VECTOR                   mUp;                // 0x05C
    FMOD_VECTOR                   mPosition;          // 0x068
    FMOD_VECTOR                   mScale;             // 0x074
    float                         mMatrix[3][4];      // 0x080
    float                         mInvMatrix[3][4];   // 0x0B0
    FMOD__GeometryI__SpatialData* mSpatialData;       // 0x0E0
    FMOD__Octree                  mOctree;            // 0x0E4 confirmed
    FMOD__GeometryI*              mNextUpdateItem;    // 0x0FC
    bool                          mToBeUpdated;       // 0x100
    uint32_t                      unk104;             // 0x104
    uint32_t                      unk108;             // 0x108
};

// size = [0x18]
struct FMOD__GeometryMgr {
    FMOD__SystemI*   mSystem;          // 0x00
    bool             mMoved;           // 0x04
    FMOD__Octree*    mMainOctree;      // 0x08
    uint32_t         unk0C;            // 0x0C
    FMOD__GeometryI* mFirstUpdateItem; // 0x10
    float            mWorldSize;       // 0x14
};

struct FMOD__Listener {
    FMOD_VECTOR mPosition;     // 0x00
    FMOD_VECTOR mLastPosition; // 0x0C
    FMOD_VECTOR mVelocity;     // 0x18
    FMOD_VECTOR mLastVelocity; // 0x24
    FMOD_VECTOR mUp;           // 0x30
    FMOD_VECTOR mLastUp;       // 0x3C
    FMOD_VECTOR mFront;        // 0x48
    FMOD_VECTOR mLastFront;    // 0x54
    FMOD_VECTOR mRight;        // 0x60
    bool        mMoved;        // 0x6C
    bool        mRotated;      // 0x6D

    // uint32_t unk00; // 0x00
    // uint32_t unk04; // 0x04
    // uint32_t unk08; // 0x08
    // uint32_t unk0C; // 0x0C
    // uint32_t unk10; // 0x10
    // uint32_t unk14; // 0x14
    // uint32_t unk18; // 0x18
    // uint32_t unk1C; // 0x1C
    // uint32_t unk20; // 0x20
    // uint32_t unk24; // 0x24
    // uint32_t unk28; // 0x28
    // uint32_t unk2C; // 0x2C
    // uint32_t unk30; // 0x30
    // uint32_t unk34; // 0x34
    // uint32_t unk38; // 0x38
    // uint32_t unk3C; // 0x3C
    // uint32_t unk40; // 0x40
    // uint32_t unk44; // 0x44
    // uint32_t unk48; // 0x48
    // uint32_t unk4C; // 0x4C
    // uint32_t unk50; // 0x50
    // uint32_t unk54; // 0x54
    // uint32_t unk58; // 0x58
    // uint32_t unk5C; // 0x5C
    // uint32_t unk60; // 0x60
    // uint32_t unk64; // 0x64
    // uint32_t unk68; // 0x68
    // uint32_t unk6C; // 0x6C
};

struct FMOD__LevelsInfo {
    bool   inuse;
    float* levelsmemory;
};

struct FMOD__SpeakerLevelsPool {
    FMOD__LevelsInfo* mLevelsPool;
    FMOD__SystemI*    mSystem;
};

struct FMOD__DSPConnectionRequest {
    FMOD__LinkedListNode          _;
    FMOD__DSPI*                   mThis;       // 0x0C
    FMOD__DSPI*                   mTarget;     // 0x10
    FMOD__DSPConnection*          mConnection; // 0x14
    FMOD_DSPCONNECTIONREQUEST_CMD mRequest;    // 0x18
};

// unconfirmed:
// in mac, the size is at least 0x2A8
struct FMOD__DSPConnectionPool {
    FMOD__SystemI*        mSystem;               // 0x000
    FMOD__DSPConnection*  mConnection[32];       // 0x004
    FMOD__DSPConnection*  mConnectionMemory[32]; // 0x084
    FMOD__LinkedListNode* mNodeMemory[32];       // 0x104
    int32_t               mNumInputLevels;       // 0x184
    int32_t               mNumOutputLevels;      // 0x188
    int32_t               mNumConnections;       // 0x18C
    FMOD__LinkedListNode  mUsedListHead;         // 0x190
    FMOD__LinkedListNode  mFreeListHead;         // 0x19C
    float*                mLevelData[32];        // 0x1A8
    float*                mLevelDataMemory[32];  // 0x228
};

struct FMOD__DSPConnection {
    FMOD__LinkedListNode  mInputNode;        // 0x00
    FMOD__LinkedListNode  mOutputNode;       // 0x0C
    FMOD__LinkedListNode* mNode;             // 0x18
    int16_t               mMaxOutputLevels;  // 0x1C
    int16_t               mMaxInputLevels;   // 0x1E
    float*                mLevel[16];        // 0x20
    float*                mLevelCurrent[16]; // 0x60
    float*                mLevelDelta[16];   // 0xA0
    FMOD__DSPI*           mInputUnit;        // 0xE0
    FMOD__DSPI*           mOutputUnit;       // 0xE4
    int16_t               mRampCount;        // 0xE8
    int16_t               mSetLevelsUsed;    // 0xEA
    float                 mVolume;           // 0xEC
};

// TODO: identify the true name of this
// this was replaced with the FMOD Profiler in later editions
struct FMOD__DSPNet {
    bool            mInitialized;         // 0x00
    uint32_t        mTimeSinceLastUpdate; // 0x04
    void*           mListenSocket;        // 0x08
    void*           mClientSocket;        // 0x0C
    uint32_t        unk10;                // 0x10 allocated
    uint32_t        unk14;                // 0x14
    uint32_t        unk18;                // 0x18
    uint32_t        unk1C;                // 0x1C allocated
    FMOD__DSPNet20* unk20;                // 0x20
    uint32_t        unk24;                // 0x24
    uint32_t        unk28;                // 0x28
};

struct FMOD__DSPNet20 {
    int32_t unk00;
    int32_t unk04;
    int32_t unk08;
};

// size = 0x8668
// class SystemI : public LinkedListNode
struct FMOD__SystemI {
    FMOD__LinkedListNode       _;
    bool                       mInitialized;                  // 0x00C
    bool                       mPluginsLoaded;                // 0x00D
    FMOD_UINT_NATIVE           mMainThreadID;                 // 0x010
    FMOD_INITFLAGS             mFlags;                        // 0x014
    FMOD__SoundI               mSoundListHead;                // 0x018
    int32_t                    mNumChannels;                  // 0x0FC
    FMOD__ChannelI*            mChannel;                      // 0x100
    FMOD__ChannelI             mChannelUsedListHead;          // 0x104
    FMOD__ChannelI             mChannelFreeListHead;          // 0x2A0
    FMOD__SortedLinkedListNode mChannelSortedListHead;        // 0x43C
    FMOD__Output*              mOutput;                       // 0x44C
    FMOD_OUTPUTTYPE            mOutputType;                   // 0x450
    FMOD_SOUND_FORMAT          mOutputFormat;                 // 0x454
    int32_t                    mOutputRate;                   // 0x458
    int32_t                    mOutputHandle;                 // 0x45C
    int32_t                    mMaxInputChannels;             // 0x460
    int32_t                    mMaxOutputChannels;            // 0x464
    int32_t                    mSelectedDriver;               // 0x468
    FMOD__OutputEmulated*      mEmulated;                     // 0x46C
    int32_t                    mRecordID;                     // 0x470
    uint32_t                   mDSPBlockSize;                 // 0x474
    uint32_t                   mDSPBufferSize;                // 0x478
    float*                     mDSPTempBuff[2];               // 0x47C
    float*                     mDSPTempBuffMem[2];            // 0x484
    float*                     mDSPMixBuff[128];              // 0x48C
    FMOD__DSPConnectionPool    mDSPConnectionPool;            // 0x68C
    FMOD_OS_CRITICALSECTION*   mDSPCrit;                      // 0x934
    FMOD_OS_CRITICALSECTION*   mDSPLockCrit;                  // 0x938
    FMOD_OS_CRITICALSECTION*   mDSPConnectionCrit;            // 0x93C
    FMOD_OS_CRITICALSECTION*   mDSPFlushingCrit;              // 0x940 invented name
    bool                       mDSPActive;                    // 0x944
    FMOD__DSPI*                mDSPSoundCard;                 // 0x948
    FMOD__DSPI*                mDSPChannelGroupTarget;        // 0x94C
    FMOD__TimeStamp            mDSPTimeStamp;                 // 0x950
    int32_t                    mDSPTempBuffIndex;             // 0x988 invented name
    FMOD__DSPConnectionRequest mConnectionRequest[1024];      // 0x98C
    FMOD__DSPConnectionRequest mConnectionRequestUsedHead;    // 0x798C
    FMOD__DSPConnectionRequest mConnectionRequestFreeHead;    // 0x79A8
    bool                       mConnectionRequestFlushing;    // 0x79C4
    FMOD__Listener             mListener[4];                  // 0x79C8
    int32_t                    mNumListeners;                 // 0x7B88
    float                      mDistanceScale;                // 0x7B8C
    float                      mRolloffScale;                 // 0x7B90
    float                      mDopplerScale;                 // 0x7B94
    FMOD_3D_ROLLOFFCALLBACK    mRolloffCallback;              // 0x7B98
    FMOD__PluginFactory*       mPluginFactory;                // 0x7B9C
    char                       mPluginPath[256];              // 0x7BA0
    int32_t                    mFSBPluginHandle;              // 0x7CA0
    int32_t                    mWAVPluginHandle;              // 0x7CA4
    int32_t                    mMPEGPluginHandle;             // 0x7CA8
    FMOD_ADVANCEDSETTINGS      mAdvancedSettings;             // 0x7CAC
    void*                      mUserData;                     // 0x7CE4
    FMOD__TimeStamp            mUpdateTimeStamp;              // 0x7CE8
    uint32_t                   mLastTimeStamp;                // 0x7D20
    uint32_t                   mIndex;                        // 0x7D24
    int32_t                    mNumSoftwareChannels;          // 0x7D28
    int32_t                    mMinHardwareChannels2D;        // 0x7D2C
    int32_t                    mMaxHardwareChannels2D;        // 0x7D30
    int32_t                    mMinHardwareChannels3D;        // 0x7D34
    int32_t                    mMaxHardwareChannels3D;        // 0x7D38
    FMOD__ChannelGroupI*       mChannelGroup;                 // 0x7D3C
    FMOD__ChannelGroupI        mChannelGroupHead;             // 0x7D40
    FMOD__SoundGroupI*         mSoundGroup;                   // 0x7D9C
    FMOD__LinkedListNode       mSoundGroupUsedHead;           // 0x7DA0
    FMOD__LinkedListNode       mSoundGroupFreeHead;           // 0x7DAC
    FMOD_DSP_RESAMPLER         mResampleMethod;               // 0x7DB8
    FMOD__MemSingleton         mMultiSubSampleLockBuffer;     // 0x7DBC
    FMOD_OS_CRITICALSECTION*   mMultiSubSampleLockBufferCrit; // 0x7DC4
    FMOD_OS_CRITICALSECTION*   mSoundLockBufferCrit;          // 0x7DC8 invented name
    FMOD_FILE_OPENCALLBACK     mOpenRiderCallback;            // 0x7DCC
    FMOD_FILE_CLOSECALLBACK    mCloseRiderCallback;           // 0x7DD0
    FMOD_FILE_READCALLBACK     mReadRiderCallback;            // 0x7DD4
    FMOD_FILE_SEEKCALLBACK     mSeekRiderCallback;            // 0x7DD8
    FMOD_SYSTEM_CALLBACK       mCallback[32];                 // 0x7DDC
    FMOD__SpeakerLevelsPool    mSpeakerLevelsPool;            // 0x7E5C
    uint32_t                   mStreamFileBufferSize;         // 0x7E64
    FMOD_TIMEUNIT              mStreamFileBufferSizeType;     // 0x7E68
    FMOD_SPEAKERMODE           mSpeakerMode;                  // 0x7E6C
    FMOD_SPEAKERCONFIG         mSpeaker[8];                   // 0x7E70
    FMOD_SPEAKERCONFIG*        mSpeakerList[8];               // 0x7F50
    FMOD__LinkedListNode       mStreamListChannelHead;        // 0x7F70
    FMOD__LinkedListNode*      mStreamListChannelCurrent;     // 0x7F7C
    FMOD__LinkedListNode*      mStreamListChannelNext;        // 0x7F80
    FMOD__LinkedListNode       mStreamListSoundHead;          // 0x7F84
    FMOD__Thread               mStreamThread;                 // 0x7F90
    bool                       mStreamThreadActive;           // 0x80B4
    FMOD_OS_CRITICALSECTION*   mStreamRealchanCrit;           // 0x80B8
    FMOD_OS_CRITICALSECTION*   mStreamUpdateCrit;             // 0x80BC
    FMOD_OS_CRITICALSECTION*   mStreamListCrit;               // 0x80C0
    FMOD__TimeStamp            mStreamTimeStamp;              // 0x80C4
    FMOD__OutputSoftware*      mSoftware;                     // 0x80FC
    FMOD_SPEAKER               mASIOSpeakerList[16];          // 0x8100
    FMOD__DSPCodecPool         mDSPCodecPool_MPEG;            // 0x8140
    FMOD__DSPCodecPool         mDSPCodecPool_ADPCM;           // 0x8250
    FMOD__GeometryI*           mGeometryList;                 // 0x8360
    FMOD__GeometryMgr          mGeometryMgr;                  // 0x8364
    FMOD__ReverbI              mReverbGlobal;                 // 0x837C
    FMOD__ReverbI              mReverb3D;                     // 0x843C
    FMOD__ReverbI              mReverb3DHead;                 // 0x84FC
    bool                       mReverb3DActive;               // 0x85BC
    FMOD_REVERB_PROPERTIES     mReverb3DAmbientProperties;    // 0x85C0
    FMOD__DSPNet               mDSPNet;                       // 0x863C
};

#endif
