#include "visualization.h"

SpringVisualization::SpringVisualization()
    : frc1678::Visualization("Sliding Block") {}

void SpringVisualization::SetState(SpringState state) {
  state_ = state;
  dashboard_strings_["position"] = std::to_string(state_.position()) + "m";
  dashboard_strings_["velocity"] = std::to_string(state_.velocity()) + "m/s";
}

void SpringVisualization::Draw(sf::RenderTarget& target) const {
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
  // Draw the block relative to it's bottom center
  block.setOrigin(block_size.to(pixel) / 2, block_size.to(pixel));
  block.setPosition(center + sf::Vector2f(state_.position.to(pixel), 0));
  target.draw(block);

  // Draw the "spring"
  Length spring_length_unstretched = 3 * m;
  Unitless spring_stretch_factor =
      (state_.position + spring_length_unstretched) / spring_length_unstretched;
  sf::RectangleShape spring(sf::Vector2f(
      spring_stretch_factor() * spring_length_unstretched.to(pixel),
      20.0 / spring_stretch_factor()));
  spring.setOrigin(0.0, 10.0 / spring_stretch_factor());
  spring.setPosition(center + sf::Vector2f(-spring_length_unstretched.to(pixel),
                                           -m.to(pixel) / 2));
  target.draw(spring);
}
