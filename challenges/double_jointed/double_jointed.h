#pragma once

#include "third_party/unitscpp/unitscpp.h"

struct DoubleJointedState {
  // 0 is parallel to the ground
  Angle shoulder_angle;
  AngularVelocity shoulder_angular_velocity;

  // Relative to the shoulder
  Angle wrist_angle;
  AngularVelocity wrist_angular_velocity;
};
