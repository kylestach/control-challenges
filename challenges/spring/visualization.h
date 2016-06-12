#pragma once

#include "spring.h"
#include "visualization/visualization.h"

class SpringVisualization : public frc1678::Visualization {
 public:
  SpringVisualization();
  void SetState(SpringState state);

 protected:
  void Draw(sf::RenderTarget& target) const override;

 private:
  SpringState state_;
};
