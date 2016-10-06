#pragma once

#include "third_party/unitscpp/unitscpp.h"

struct PivotState {
  // 0 is parallel to the ground
  Angle angle;
  AngularVelocity angular_velocity;
};
struct PivotDBState {
  // 0 is parallel to the ground
  Angle angle;
  AngularVelocity angular_velocity;
  bool disk_brake;
};
