#pragma once

#include "third_party/unitscpp/unitscpp.h"

class FlywheelController {
 public:
  Voltage Update(AngularVelocity velocity, Time dt);
  void SetGoal(const AngularVelocity goal) { goal_ = goal; }

 private:
  AngularVelocity goal_;
};
