#include "visualization.h"

SlidingBlockVisualization::SlidingBlockVisualization()
    : frc1678::Visualization("Sliding Block") {}

void SlidingBlockVisualization::SetState(SlidingBlockState state) {
  state_ = state;
  dashboard_strings_["position"] = std::to_string(state_.position()) + "m";
  dashboard_strings_["velocity"] = std::to_string(state_.velocity()) + "m/s";
}

void SlidingBlockVisualization::Draw(sf::RenderTarget& target) const {
  sf::Vector2f center(target.getSize().x / 2, target.getSize().y / 2);

  Length pixel = (1 / 50.0) * m;
  Length block_size = 1 * m;

  // Draw the ground
  sf::RectangleShape ground(sf::Vector2f(target.getSize().x, 5));
  ground.setPosition(sf::Vector2f(0, center.y));
  ground.setFillColor(sf::Color::Red);
  target.draw(ground);

  // Draw the block
  sf::RectangleShape block(
      sf::Vector2f(block_size.to(pixel), block_size.to(pixel)));
  // Draw the block relative to its bottom center
  block.setOrigin(block_size.to(pixel) / 2, block_size.to(pixel));
  block.setPosition(center + sf::Vector2f(state_.position.to(pixel), 0));
  target.draw(block);
}
