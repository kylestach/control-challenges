#pragma once

#include "third_party/unitscpp/unitscpp.h"

class SlidingBlockController {
 public:
  Force Update(Length position, Time dt);
};
