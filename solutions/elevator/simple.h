#pragma once

#include "challenges/elevator/elevator.h"
#include "third_party/unitscpp/unitscpp.h"

class ElevatorController {
 public:
  Voltage Update(ElevatorState current_state, Time dt);
  void SetGoal(const ElevatorState goal) { goal_ = goal; }

 private:
  ElevatorState goal_;
};
