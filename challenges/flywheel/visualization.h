#pragma once

#include "flywheel.h"
#include "visualization/visualization.h"

class FlywheelVisualization : public frc1678::Visualization {
 public:
  FlywheelVisualization();
  void SetState(const FlywheelState state);

 protected:
  void Draw(sf::RenderTarget& target) const override;

 private:
  FlywheelState state_;
};
