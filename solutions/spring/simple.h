#pragma once

#include <type_traits>
#include "third_party/unitscpp/unitscpp.h"

class SpringController {
 public:
  Force Update(Length position, Time dt);
  void SetGoal(const Length goal) { goal_ = goal; }

 private:
  Length goal_;
};
