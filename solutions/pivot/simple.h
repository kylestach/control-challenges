#pragma once

#include "challenges/pivot/pivot.h"
#include "third_party/unitscpp/unitscpp.h"

class PivotController {
 public:
  Force Update(PivotState state, Time dt);
};
