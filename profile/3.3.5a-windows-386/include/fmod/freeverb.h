#ifndef FMOD_FREEVERB_H
#define FMOD_FREEVERB_H

DECLARE_STRUCT(revmodel);
DECLARE_STRUCT(comb);
DECLARE_STRUCT(allpass);

struct comb {
    float   feedback;
    float   filterstore;
    float   damp1;
    float   damp2;
    float*  buffer;
    int32_t bufsize;
    int32_t bufidx;
};

struct allpass {
    float   feedback;
    float*  buffer;
    int32_t bufsize;
    int32_t bufidx;
};

struct revmodel {
    float   gain;
    float   roomsize;
    float   roomsize1;
    float   damp;
    float   damp1;
    float   wet;
    float   wet1;
    float   wet2;
    float   dry;
    float   width;
    float   mode;
    comb    combL[8];
    comb    combR[8];
    allpass allpassL[4];
    allpass allpassR[4];
    float   bufcombL1[1116];
    float   bufcombR1[1139];
    float   bufcombL2[1188];
    float   bufcombR2[1211];
    float   bufcombL3[1277];
    float   bufcombR3[1300];
    float   bufcombL4[1356];
    float   bufcombR4[1379];
    float   bufcombL5[1422];
    float   bufcombR5[1445];
    float   bufcombL6[1491];
    float   bufcombR6[1514];
    float   bufcombL7[1557];
    float   bufcombR7[1580];
    float   bufcombL8[1617];
    float   bufcombR8[1640];
    float   bufallpassL1[556];
    float   bufallpassR1[579];
    float   bufallpassL2[441];
    float   bufallpassR2[464];
    float   bufallpassL3[341];
    float   bufallpassR3[364];
    float   bufallpassL4[225];
    float   bufallpassR4[248];
};

#endif
