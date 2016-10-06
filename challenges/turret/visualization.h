#pragma once

#include "turret.h"
#include "visualization/visualization.h"

class TurretVisualization : public frc1678::Visualization {
 public:
  TurretVisualization();
  void SetState(TurretState state);

 protected:
  void Draw(sf::RenderTarget& target) const override;

 private:
  TurretState state_;
};
