#include "visualization.h"
#include <cmath>
#include "third_party/unitscpp/unitscpp.h"

PivotVisualization::PivotVisualization()
    : frc1678::Visualization("Pivot") {}

void PivotVisualization::SetState(PivotState state) {
  state_ = state;
  dashboard_strings_["angle"] =
      std::to_string(state_.angle.to(deg)) + "deg";
  dashboard_strings_["angular velocity"] =
      std::to_string(state_.angular_velocity.to(deg/s)) + "deg/s";
}

void PivotVisualization::Draw(sf::RenderTarget& target) const {
  sf::Vector2f center(target.getSize().x / 2, target.getSize().y / 2);

  Length pixel = (1 / 300.0) * m;

  Length pivot_length = 1 * m, thickness = .1 * m;

  // Draw the ground
  sf::RectangleShape ground(sf::Vector2f(target.getSize().x, 5));
  ground.setPosition(sf::Vector2f(0, center.y));
  ground.setFillColor(sf::Color::Red);
  target.draw(ground);

  // Draw the pivot
  sf::RectangleShape pivot(
      sf::Vector2f(pivot_length.to(pixel), thickness.to(pixel)));
  pivot.setFillColor(sf::Color::Blue);
  pivot.setOutlineColor(sf::Color::White);
  pivot.setOutlineThickness(5);
  pivot.setOrigin(thickness.to(pixel) / 2, thickness.to(pixel) / 2);
  pivot.setPosition(center);
  pivot.setRotation(-state_.angle.to(deg));
  target.draw(pivot);
}
