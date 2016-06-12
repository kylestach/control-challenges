#pragma once

#include "double_jointed.h"
#include "visualization/visualization.h"

class DoubleJointedVisualization : public frc1678::Visualization {
 public:
  DoubleJointedVisualization();
  void SetState(DoubleJointedState state);

 protected:
  void Draw(sf::RenderTarget& target) const override;

 private:
  DoubleJointedState state_;
};
