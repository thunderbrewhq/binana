#ifndef M2_MODEL_H
#define M2_MODEL_H

DECLARE_STRUCT(M2ModelAttachment);
DECLARE_STRUCT(M2ModelBoneSeq);
DECLARE_STRUCT(M2ModelBone);
DECLARE_STRUCT(M2ModelCamera);
DECLARE_STRUCT(M2ModelColor);
DECLARE_STRUCT(M2ModelLight);
DECLARE_STRUCT(M2ModelRibbon);
DECLARE_STRUCT(M2ModelTextureTransform);
DECLARE_STRUCT(M2ModelTextureWeight);
DECLARE_STRUCT(M2ModelOptGeo);
DECLARE_STRUCT(CM2ModelCall);
DECLARE_STRUCT(CM2Model);

#include "camera/camera.h"
#include "m2/data.h"
#include "m2/scene.h"
#include "m2/shared.h"
#include "m2/lighting.h"
#include "m2/ribbon.h"
#include "tempest/vector.h"
#include "tempest/quaternion.h"
#include "gx/texture.h"

// template<class T>
#define M2_MODEL_TRACK(T) \
typedef struct M2ModelTrack_##T M2ModelTrack_##T; \
struct M2ModelTrack_##T { \
  uint32_t currentKey; \
  M2Track_##T* sourceTrack; \
  T currentValue; \
};
M2_MODEL_TRACK(uint8_t);
M2_MODEL_TRACK(float);
M2_MODEL_TRACK(C3Vector);
M2_MODEL_TRACK(C4Quaternion);
 
struct M2ModelAttachment {
  int32_t unk;
};

struct M2ModelBoneSeq {
  uint32_t uint0;
  uint16_t uint4;
  uint16_t uint6;
  uint16_t uint8;
  uint8_t uintA;
  uint8_t uintB;
  uint32_t uintC;
  uint32_t uint10;
  float float14;
  float float18;
  uint32_t uint1C;
  uint32_t uint20;
};

struct M2ModelBone {
  M2ModelTrack_C3Vector translationTrack;
  M2ModelTrack_C4Quaternion rotationTrack;
  M2ModelTrack_C3Vector scaleTrack;
  M2ModelBoneSeq sequence;
  M2ModelBoneSeq secondarySequence;
  uint32_t flags;
  uint32_t uint90;
  uint16_t uint94;
  uint32_t uint9C;
  float floatA0;
  float floatA4;
  float floatA8;
};

struct M2ModelCamera {
  M2ModelTrack_C3Vector positionTrack;
  M2ModelTrack_C3Vector targetTrack;
  M2ModelTrack_float rollTrack;
  HCAMERA m_camera;
};

struct M2ModelColor {
  M2ModelTrack_C3Vector colorTrack;
  M2ModelTrack_float alphaTrack;
};

struct M2ModelLight {
  M2ModelTrack_C3Vector ambientColorTrack;
  M2ModelTrack_float ambientIntensityTrack;
  M2ModelTrack_C3Vector diffuseColorTrack;
  M2ModelTrack_float diffuseIntensityTrack;
  M2ModelTrack_uint8_t visibilityTrack;
  uint32_t uint64;
  CM2Light light;
};

struct M2ModelRibbon {
  uint32_t dword0;
  uint32_t dword4;
  uint32_t dword8;
  uint32_t dwordC;
  uint32_t dword10;
  uint32_t dword14;
  uint32_t dword18;
  uint32_t dword1C;
  uint32_t dword20;
  uint32_t dword24;
  uint32_t dword28;
  uint32_t dword2C;
  uint32_t dword30;
  uint32_t dword34;
  uint32_t dword38;
  uint32_t dword3C;
  uint32_t dword40;
  uint32_t dword44;
  uint32_t dword48;
  uint32_t dword4C;
};

struct M2ModelTextureTransform {
  int32_t unk;
};

struct M2ModelTextureWeight {
  M2ModelTrack_float weightTrack;
};

struct M2ModelOptGeo {
  M2Batch* batches;
  uint32_t dword4;
  M2SkinSection* skinSections;
  uint32_t dwordC;
  uint32_t dword10;
  uint32_t dword14;
  uint32_t dword18;
  CShaderEffect** effects;
  uint32_t dword20;
  uint32_t dword24;
  uint32_t dword28;
  uint32_t dword2C;
  uint32_t dword30;
  uint32_t dword34;
  uint32_t dword38;
  uint32_t dword3C;
  uint32_t dword40;
  uint32_t dword44;
  uint32_t dword48;
  uint32_t dword4C;
};

struct CM2ModelCall {
  uint32_t type;
  CM2ModelCall* modelCallNext;
  uint32_t time;
  uint32_t args[8];
};

struct CM2Model {
  uint32_t m_refCount;
  uint32_t m_flags;
  CM2Model** m_scenePrev;
  CM2Model* m_sceneNext;
  // uint32_t m_loaded : 1;
  // uint32_t m_flag2 : 1;
  // uint32_t m_flag4 : 1;
  // uint32_t m_flag8 : 1;
  // uint32_t m_flag10 : 1;
  // uint32_t m_flag20 : 1;
  // uint32_t m_flag40 : 1;
  // uint32_t m_flag80 : 1;
  // uint32_t m_flag100 : 1;
  // uint32_t m_flag200 : 1;
  // uint32_t m_flag400 : 1;
  // uint32_t m_flag800 : 1;
  // uint32_t m_flag1000 : 1;
  // uint32_t m_flag2000 : 1;
  // uint32_t m_flag4000 : 1;
  // uint32_t m_flag8000 : 1;
  // uint32_t m_flag10000 : 1;
  // uint32_t m_flag20000 : 1;
  // uint32_t m_flag40000 : 1;
  // uint32_t m_flag80000 : 1;
  // uint32_t m_flag100000 : 1;
  // uint32_t m_flag200000 : 1;
  // uint32_t m_flag400000 : 1;
  uint32_t f_flags;
  uint32_t dword14;
  CM2Model** m_callbackPrev;
  CM2Model* m_callbackNext;
  void* m_loadedCallback;
  void* m_loadedArg;
  CM2Scene* m_scene;
  CM2Shared* m_shared;
  CM2Model* model30;
  CM2ModelCall* m_modelCallList;
  CM2ModelCall** m_modelCallTail;
  uint32_t dword3C;
  CM2Model** m_animatePrev;
  CM2Model* m_animateNext;
  CM2Model* m_attachParent;
  void* m_attachments;
  uint32_t dword50;
  uint32_t dword54;
  CM2Model* model58;
  uint32_t dword5C;
  CM2Model* model60;
  uint32_t m_time;
  CM2Model** m_drawPrev;
  CM2Model* m_drawNext;
  uint32_t* m_loops;
  uint32_t uint74;
  uint32_t dword78;
  uint32_t dword7C;
  uint32_t dword80;
  uint32_t dword84;
  float float88;
  uint32_t uint8C;
  uint32_t uint90;
  M2ModelBone* m_bones;
  C44Matrix* m_boneMatrices;
  void* m_skinSections;
  M2ModelColor* m_colors;
  HTEXTURE* m_textures;
  M2ModelTextureWeight* m_textureWeights;
  void* m_textureTransforms;
  C44Matrix* m_textureMatrices;
  C44Matrix matrixB4;
  C44Matrix matrixF4;
  C44Matrix matrix134;
  uint32_t dword174;
  float m_alpha;
  uint32_t dword17C;
  uint32_t dword180;
  uint32_t dword184;
  uint32_t dword188;
  uint32_t dword18C;
  uint32_t dword190;
  uint32_t dword194;
  float float198;
  float alpha19C;
  C3Vector m_currentDiffuse;
  C3Vector m_currentEmissive;
  uint32_t dword1B8;
  void* m_drawCallback;
  uint32_t dword1C0;
  uint32_t dword1C4;
  uint32_t dword1C8;
  uint32_t dword1CC;
  M2ModelLight* m_lights;
  CM2Lighting m_lighting;
  CM2Lighting* m_currentLighting;
  void* m_lightingCallback;
  void* m_lightingArg;
  M2ModelCamera* m_cameras;
  M2ModelRibbon* m_ribbons;
  CRibbonEmitter* m_ribbonEmitters;
  void* m_particles;
  uint32_t dword2C4;
  uint32_t dword2C8;
  uint32_t dword2CC;
  M2ModelOptGeo* m_optGeo;
  uint32_t dword2D4;
  uint32_t dword2D8;
  uint32_t dword2DC;
  uint32_t dword2E0;
  uint32_t dword2E4;
  uint32_t dword2E8;
  uint32_t dword2EC;
};

#endif