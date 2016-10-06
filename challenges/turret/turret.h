#pragma once

#include "third_party/unitscpp/unitscpp.h"

struct TurretState {
  Angle angle;
  Angle goal;
  AngularVelocity angular_velocity;
};
