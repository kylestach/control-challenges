#pragma once

#include "third_party/unitscpp/unitscpp.h"

class GoalSlidingBlockController {
 public:
  Force Update(Length position, Time dt);
  void SetGoal(Length goal) { goal_ = goal; }

 private:
  Length goal_;
};
