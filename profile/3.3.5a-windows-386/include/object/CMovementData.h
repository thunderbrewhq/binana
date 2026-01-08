#ifndef CMOVEMENTDATA_H
#define CMOVEMENTDATA_H

DECLARE_STRUCT(CMovementData);

#include "system/types.h"
#include "tempest/vector.h"

struct CMovementData
{
    void* transportPtr1;
    void* transportPtr2;
    uint64_t TransportGUID;
    C3Vector position;
    int32_t unkFlag;
    float Facing;
    float Pitch;
    void* dataPtr;
    int32_t unkFlag2; //0x2C
    int32_t unk_030;
    int32_t unk_034;
    C3Vector groundNormal;
    int32_t moveFlag1;
    int32_t moveFlag2;
    C3Vector anchorPosition;
    float AnchorFacing;
    float AnchorPitch;
    int32_t unk_060;
    C3Vector direction;
    C2Vector direction2d;
    float cosAnchorPitch;
    float sinAnchorPitch;
    int32_t FallTime;
    float StartFallHeight;
    float unkFloat;
    float MoveSpeed;
    float WalkSpeed;
    float RunSpeed;
    float BackSpeed;
    float SwimSpeed;
    float BackSwimSpeed;
    float FlyMountSpeed;
    float FlyMountBackSpeed;
    float TurnSpeed;
    float FlyMountUnkUpDownRotationSpeed1;
    float FlyMountUnkUpDownRotationSpeed2;
    float FallSpeed;
    void* CGMoveSplinePtr;
    int32_t PerfCount;
    int32_t unkFlag3;
    float CollisonBoxHalfWidth;
    float CollisionBoxHeight;
    float ObjectScale;
    int32_t unk_0D4;
    int32_t unk_0D8;
    int32_t unk_0DC;
    int32_t unk_0E0;
    int32_t unk_0E4;
    int32_t unkFlags_00; //0xE8
    int32_t unkFlags_01; //0xEC
    int32_t unkFlags_02; //0xF0
    int32_t unkFlags_03; //0xF4
    int32_t unkFlags_04; //0xF8
    int32_t unkFlags_05; //0xFC
    int32_t unkFlags_06; //0x100
    int32_t unkFlags_07; //0x104
    int32_t unkFlags_08; //0x108
    int32_t unkFlags_09; //0x10C
    int32_t unkFlags_10; //0x110
    int32_t unkFlags_11; //0x114
    int32_t unkFlags_12; //0x118
    int32_t unkFlags_13; //0x11C
    int32_t unkFlags_14; //0x120
    int32_t unkFlags_15; //0x124
    int32_t unk_128;
    int32_t unk_12C;
    int32_t unk_130;
    int32_t unk_134;
    int32_t unk_138;
    void* linkedList_ptr1;
    void* linkedList_ptr2;
    void* objectPtr;
};

#endif