#pragma once

#include "sliding_block.h"
#include "visualization/visualization.h"

class SlidingBlockVisualization : public frc1678::Visualization {
 public:
  SlidingBlockVisualization();
  void SetState(SlidingBlockState state);

 protected:
  void Draw(sf::RenderTarget& target) const override;

 private:
  SlidingBlockState state_;
};
