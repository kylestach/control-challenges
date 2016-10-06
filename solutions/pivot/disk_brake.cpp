#include "disk_brake.h"
#include <iostream>
#include <math.h>

// Return a force to move the pivot to 50 degrees and activate the disk brake
// To reach the end criteria, the controller must return very low force at 
// the end and finish with a disk brake engagement, which has a delay to
// accomodate for the delay in firing the solenoid.
std::tuple<Force, bool> PivotController::Update(PivotDBState state, Time dt) {
  std::cout << "Implement the control function here! "
               "(solutions/pivot/disk_brake.cpp)"
            << std::endl;
  return std::make_tuple(0 * N, false); // Force of the controller, if disk brake should be engaged.
}
