#pragma once

#include "elevator.h"
#include "visualization/visualization.h"

class ElevatorVisualization : public frc1678::Visualization {
 public:
  ElevatorVisualization();
  void SetState(const ElevatorState state);

 protected:
  void Draw(sf::RenderTarget& target) const override;

 private:
  ElevatorState state_;
};
