#include "no_friction.h"
#include <iostream>

// Return a force to move the block to 0, but this time friction won't slow the
// block down
Force FrictionlessSlidingBlockController::Update(Length position, Time dt) {
  std::cout << "Implement the control function here! "
               "(solutions/sliding_block/no_friction.cpp)"
            << std::endl;
  return 0 * N;
}
