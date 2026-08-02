#ifndef D3D9_DSFX_I3DL_REVERB_H
#define D3D9_DSFX_I3DL_REVERB_H

DECLARE_STRUCT(DSFXI3DL2Reverb);

typedef DSFXI3DL2Reverb*       LPDSFXI3DL2Reverb;
typedef const DSFXI3DL2Reverb* LPCDSFXI3DL2Reverb;

struct DSFXI3DL2Reverb {
    int32_t lRoom;
    int32_t lRoomHF;
    float   flRoomRolloffFactor;
    float   flDecayTime;
    float   flDecayHFRatio;
    int32_t lReflections;
    float   flReflectionsDelay;
    int32_t lReverb;
    float   flReverbDelay;
    float   flDiffusion;
    float   flDensity;
    float   flHFReference;
};

#endif
