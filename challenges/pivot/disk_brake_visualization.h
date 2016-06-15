#pragma once

#include "pivot.h"
#include "visualization/visualization.h"

class PivotVisualization : public frc1678::Visualization {
 public:
  PivotVisualization();
  void SetState(PivotDBState state);

 protected:
  void Draw(sf::RenderTarget& target) const override;

 private:
  PivotDBState state_;
};
