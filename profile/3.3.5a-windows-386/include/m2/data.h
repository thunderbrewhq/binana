#ifndef M2_DATA_H
#define M2_DATA_H

#include "system/types.h"
#include "gx/buffer.h"
#include "tempest/vector.h"
#include "tempest/box.h"
#include "tempest/quaternion.h"

DECLARE_STRUCT(M2SequenceTimes);
DECLARE_STRUCT(M2TrackBase);
DECLARE_STRUCT(M2Attachment);
DECLARE_STRUCT(M2Batch);
DECLARE_STRUCT(M2Bounds);
DECLARE_STRUCT(M2Camera);
DECLARE_STRUCT(M2Color);
DECLARE_STRUCT(M2CompQuat);
DECLARE_STRUCT(M2CompBone__CompressData);
DECLARE_STRUCT(M2CompBone);
DECLARE_STRUCT(M2Event);
DECLARE_STRUCT(M2Light);
DECLARE_STRUCT(M2Loop);
DECLARE_STRUCT(M2Material);
DECLARE_STRUCT(M2Particle);
DECLARE_STRUCT(M2Ribbon);
DECLARE_STRUCT(M2Sequence);
DECLARE_STRUCT(M2SkinSection);
DECLARE_STRUCT(M2Texture);
DECLARE_STRUCT(M2TextureTransform);
DECLARE_STRUCT(M2TextureWeight);
DECLARE_STRUCT(M2Vertex);
DECLARE_STRUCT(M2Data);
DECLARE_STRUCT(M2SkinProfile);

// from whoa: src/model/M2Data.hpp
/*
    M2Array has been modified from the implementation present in 12340. The
    implementation present in 12340 looks like this:

    template<class T>
    struct M2Array {
        uint32_t count;
        union {
            T* data;
            uint32_t offset;
        }
    };

    On a 32-bit system, sizeof(M2Array) == 8 bytes in memory: 4 bytes for the
    count, and 4 bytes for the union. This lines up with M2Array in the .m2
    files: each M2Array is 8 bytes.

    In 12340 (and until 64-bit support was introduced), the M2Init functions
    simply adjust the M2Array when loading:

    m2Data->someM2Array.offset =
        (uint32_t)m2Data + m2Data->someM2Array.offset;

    This ensures T* data points to the appropriate (absolute) location in
    memory.

    Unfortunately, this approach fails on 64-bit systems. On a 64-bit system,
    M2Array would occupy 12 bytes in memory: 4 bytes for the count, and 8 bytes
    for the union. This would make the approach outlined above fail.

    As a result, on 64-bit systems, a different approach is used: M2Arrays are
    assumed (reasonably so) to only exist within the same structure that their
    on-disk offsets reference. Thus, M2Init adjusts the M2Array when loading:

    uintptr_t absoluteOffset =
        (uintptr_t)m2Data + m2Data->someM2Array.offset;
    uintptr_t relativeOffset =
        absoluteOffset - (uintptr_t)&m2Data->someM2Array;
    m2Data->someM2Array.offset =
        (uint32_t)relativeOffset;

    By storing the relative offset, access to the data is possible by adding
    the relative offset to the address of the M2Array:

    uintptr_t absoluteOffset =
        (uintptr_t)m2Data->someM2Array + m2Data->someM2Array.offset;
    T* data = (T*)absoluteOffset;
*/

#define M2_ARRAY(T) typedef struct M2Array_##T M2Array_##T; \
struct M2Array_##T { \
  uint32_t count; \
  union { \
    T* data; \
    uint32_t offset; \
  } data_or_offset; \
};
// declare basic types here
M2_ARRAY(ubyte4);
M2_ARRAY(uint32_t);
M2_ARRAY(C2Vector); // required by M2PartTrack

#define M2_SEQUENCE_KEYS(T) \
M2_ARRAY(T); \
typedef struct M2SequenceKeys_##T M2SequenceKeys_##T; \
struct M2SequenceKeys_##T { \
  M2Array_##T keys; \
};

struct M2SequenceTimes {
  M2Array_uint32_t times;
};
M2_ARRAY(M2SequenceTimes);

struct M2TrackBase {
  uint16_t trackType;
  uint16_t loopIndex;
  M2Array_M2SequenceTimes sequenceTimes;
};

// template<class T>
// class M2Track : public M2TrackBase
#define M2_TRACK(T) \
M2_SEQUENCE_KEYS(T); \
M2_ARRAY(M2SequenceKeys_##T); \
typedef struct M2Track_##T M2Track_##T; \
struct M2Track_##T { \
  M2TrackBase b_base; \
  M2Array_M2SequenceKeys_##T sequenceKeys; \
};
// declare basic types here
M2_TRACK(uint8_t);
M2_TRACK(uint16_t);
M2_TRACK(fixed16);
M2_TRACK(float);
M2_TRACK(C3Vector);
M2_TRACK(C4Quaternion);

struct M2Attachment {
  uint32_t attachmentId;
  uint16_t boneIndex;
  C3Vector position;
  M2Track_uint8_t visibilityTrack;
};
M2_ARRAY(M2Attachment);

struct M2Batch {
  uint8_t flags;
  int8_t priorityPlane;
  uint16_t shader;
  uint16_t skinSectionIndex;
  uint16_t geosetIndex;
  uint16_t colorIndex;
  uint16_t materialIndex;
  uint16_t materialLayer;
  uint16_t textureCount;
  uint16_t textureComboIndex;
  uint16_t textureCoordComboIndex;
  uint16_t textureWeightComboIndex;
  uint16_t textureTransformComboIndex;
};
M2_ARRAY(M2Batch);

struct M2Bounds {
  CAaBox extent;
  float radius;
};

#define M2_SPLINE_KEY(T) \
typedef struct M2SplineKey_##T M2SplineKey_##T; \
struct M2SplineKey_##T { \
  T value; \
  T inTan; \
  T outTan; \
};
// declare types here
M2_SPLINE_KEY(float);
M2_SPLINE_KEY(C3Vector);
M2_TRACK(M2SplineKey_float);
M2_TRACK(M2SplineKey_C3Vector);

struct M2Camera {
  uint32_t cameraId;
  float fieldOfView;
  float farClip;
  float nearClip;
  M2Track_M2SplineKey_C3Vector positionTrack;
  C3Vector positionPivot;
  M2Track_M2SplineKey_C3Vector targetTrack;
  C3Vector targetPivot;
  M2Track_M2SplineKey_float rollTrack;
};
M2_ARRAY(M2Camera);

struct M2Color {
  M2Track_C3Vector colorTrack;
  M2Track_fixed16 alphaTrack;
};
M2_ARRAY(M2Color);

struct M2CompQuat {
  uint32_t auCompQ[2];
};
M2_TRACK(M2CompQuat);

struct M2CompBone__CompressData {
  uint16_t uDistToFurthDesc;
  uint16_t uZRatioOfChain;
};

struct M2CompBone {
  uint32_t boneId;
  uint32_t flags;
  uint16_t parentIndex;
  uint16_t uDistToParent;
  union {
    M2CompBone__CompressData CompressData;
    uint32_t boneNameCRC;
  };
  M2Track_C3Vector translationTrack;
  M2Track_M2CompQuat rotationTrack;
  M2Track_C3Vector scaleTrack;
  C3Vector pivot;
};
M2_ARRAY(M2CompBone);

struct M2Event {
  uint32_t eventId;
  uint32_t data;
  uint16_t boneIndex;
  C3Vector position;
  M2TrackBase eventTrack;
};
M2_ARRAY(M2Event);

struct M2Light {
  uint16_t lightType;
  uint16_t boneIndex;
  C3Vector position;
  M2Track_C3Vector ambientColorTrack;
  M2Track_float ambientIntensityTrack;
  M2Track_C3Vector diffuseColorTrack;
  M2Track_float diffuseIntensityTrack;
  M2Track_float attenuationStartTrack;
  M2Track_float attenuationEndTrack;
  M2Track_uint8_t visibilityTrack;
};
M2_ARRAY(M2Light);

struct M2Loop {
  uint32_t length;
};
M2_ARRAY(M2Loop);

struct M2Material {
  uint16_t flags;
  uint16_t blendMode;
};
M2_ARRAY(M2Material);

#define M2_PART_TRACK(T) \
typedef struct M2PartTrack_##T M2PartTrack_##T; \
struct M2PartTrack_##T { \
  M2Array_fixed16 times; \
  M2Array_##T values; \
};
// declare types here
M2_PART_TRACK(fixed16);
M2_PART_TRACK(uint16_t);
M2_PART_TRACK(C2Vector);
M2_PART_TRACK(C3Vector);

struct M2Particle {
  uint32_t particleId;
  uint32_t flags;
  C3Vector position;
  uint16_t boneIndex;
  uint16_t textureIndex;
  M2Array_uint8_t geometryMdl;
  M2Array_uint8_t recursionMdl;
  uint8_t blendMode;
  uint8_t emitterType;
  uint16_t colorIndex;
  uint16_t pad;
  int16_t priorityPlane;
  uint16_t rows;
  uint16_t cols;
  M2Track_float speedTrack;
  M2Track_float variationTrack;
  M2Track_float latitudeTrack;
  M2Track_float longitudeTrack;
  M2Track_float gravityTrack;
  M2Track_float lifeTrack;
  float lifeVariation;
  M2Track_float emissionRateTrack;
  float emissionRateVariation;
  M2Track_float widthTrack;
  M2Track_float lengthTrack;
  M2Track_float zsourceTrack;
  M2PartTrack_C3Vector colorTrack;
  M2PartTrack_fixed16 alphaTrack;
  M2PartTrack_C2Vector scaleTrack;
  C2Vector scaleVariation;
  M2PartTrack_uint16_t headCellTrack;
  M2PartTrack_uint16_t tailCellTrack;
  float tailLength;
  float twinkleFPS;
  float twinkleOnOff;
  CRange twinkleScale;
  float ivelScale;
  float drag;
  float initialSpin;
  float initialSpinVariation;
  float spin;
  float spinVariation;
  CAaBox tumble;
  C3Vector windVector;
  float windTime;
  float followSpeed1;
  float followScale1;
  float followSpeed2;
  float followScale2;
  M2Array_C3Vector spline;
  M2Track_uint8_t visibilityTrack;
};
M2_ARRAY(M2Particle);

struct M2Ribbon {
  uint32_t ribbonId;
  uint16_t boneIndex;
  C3Vector position;
  M2Track_uint16_t textureIndices;
  M2Track_uint16_t materialIndices;
  M2Track_C3Vector colorTrack;
  M2Track_fixed16 alphaTrack;
  M2Track_float heightAboveTrack;
  M2Track_float heightBelowTrack;
  float edgesPerSecond;
  float edgeLifetime;
  float gravity;
  uint16_t textureRows;
  uint16_t textureCols;
  M2Track_uint16_t textureSlotTrack;
  M2Track_uint8_t visibilityTrack;
  int16_t priorityPlane;
  uint16_t pad;
};
M2_ARRAY(M2Ribbon);

struct M2Sequence {
  uint16_t id;
  uint16_t variationIndex;
  uint32_t duration;
  float movespeed;
  uint32_t flags;
  uint32_t frequency;
  CiRange replay;
  uint32_t blendtime;
  M2Bounds bounds;
  uint16_t variationNext;
  uint16_t aliasNext;
};
M2_ARRAY(M2Sequence);

struct M2SkinSection {
  uint32_t skinSectionId;
  uint16_t vertexStart;
  uint16_t vertexCount;
  uint16_t indexStart;
  uint16_t indexCount;
  uint16_t boneCount;
  uint16_t boneComboIndex;
  uint16_t boneInfluences;
  uint16_t centerBoneIndex;
  C3Vector centerPosition;
  C3Vector sortCenterPosition;
  float sortRadius;
};
M2_ARRAY(M2SkinSection);

struct M2Texture {
  uint32_t textureId;
  uint16_t flags;
  M2Array_uint8_t filename;
};
M2_ARRAY(M2Texture);

struct M2TextureTransform {
  M2Track_C3Vector translationTrack;
  M2Track_M2CompQuat rotationTrack;
  M2Track_C3Vector scaleTrack;
};
M2_ARRAY(M2TextureTransform);

struct M2TextureWeight {
  M2Track_fixed16 weightTrack;
};
M2_ARRAY(M2TextureWeight);

struct M2Vertex {
  C3Vector position;
  ubyte4 weights;
  ubyte4 indices;
  C3Vector normal;
  C2Vector texcoord[2];
};
M2_ARRAY(M2Vertex);

// .m2 files
struct M2Data {
  uint32_t MD20;
  uint32_t version;
  M2Array_uint8_t name;
  uint32_t flags;
  M2Array_M2Loop loops;
  M2Array_M2Sequence sequences;
  M2Array_uint16_t sequenceIdxHashById;
  M2Array_M2CompBone bones;
  M2Array_uint16_t boneIndicesById;
  M2Array_M2Vertex vertices;
  uint32_t numSkinProfiles;
  M2Array_M2Color colors;
  M2Array_M2Texture textures;
  M2Array_M2TextureWeight textureWeights;
  M2Array_M2TextureTransform textureTransforms;
  M2Array_uint16_t textureIndicesById;
  M2Array_M2Material materials;
  M2Array_uint16_t boneCombos;
  M2Array_uint16_t textureCombos;
  M2Array_uint16_t textureCoordCombos;
  M2Array_uint16_t textureWeightCombos;
  M2Array_uint16_t textureTransformCombos;
  M2Bounds bounds;
  M2Bounds collisionBounds;
  M2Array_uint16_t collisionIndices;
  M2Array_C3Vector collisionPositions;
  M2Array_C3Vector collisionFaceNormals;
  M2Array_M2Attachment attachments;
  M2Array_uint16_t attachmentIndicesById;
  M2Array_M2Event events;
  M2Array_M2Light lights;
  M2Array_M2Camera cameras;
  M2Array_uint16_t cameraIndicesById;
  M2Array_M2Ribbon ribbons;
  M2Array_M2Particle particles;
  M2Array_uint16_t textureCombinerCombos;
};

// .skin files
struct M2SkinProfile {
  uint32_t magic;
  M2Array_uint16_t vertices;
  M2Array_uint16_t indices;
  M2Array_ubyte4 bones;
  M2Array_M2SkinSection skinSections;
  M2Array_M2Batch batches;
  uint32_t boneCountMax;
};

#endif