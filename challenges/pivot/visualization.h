#pragma once

#include "pivot.h"
#include "visualization/visualization.h"

class PivotVisualization : public frc1678::Visualization {
 public:
  PivotVisualization();
  void SetState(PivotState state);

 protected:
  void Draw(sf::RenderTarget& target) const override;

 private:
  PivotState state_;
};
