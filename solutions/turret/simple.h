#pragma once

#include "challenges/turret/turret.h"
#include "third_party/unitscpp/unitscpp.h"

class TurretController {
 public:
   Voltage Update(TurretState state, Time dt);
};
