#pragma once

#include "challenges/pivot/pivot.h"
#include "third_party/unitscpp/unitscpp.h"
#include <tuple>

class PivotController {
 public:
   std::tuple<Force, bool> Update(PivotDBState state, Time dt);
};
