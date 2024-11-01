#ifndef CAMERA_CAMERA_H
#define CAMERA_CAMERA_H

DECLARE_STRUCT(CAngle);
DECLARE_STRUCT(CCamera);

#include "common/datamanager.h"

typedef HDATAMGR HCAMERA;

// class CAngle : public TManaged<float>
struct CAngle {
  TManaged_float b_base;
  float m_cos;
  float m_sin;
};

// class CCamera : public CDataMgr
struct CCamera {
  TManaged_C3Vector m_position;
  TManaged_C3Vector m_target;
  TManaged_float m_distance;
  TManaged_float m_zFar;
  TManaged_float m_zNear;
  CAngle m_aoa;
  CAngle m_fov;
  CAngle m_roll;
  CAngle m_rotation;
};

#endif