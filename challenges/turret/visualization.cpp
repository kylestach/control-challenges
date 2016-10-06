#include "visualization.h"
#include <cmath>
#include "third_party/unitscpp/unitscpp.h"

TurretVisualization::TurretVisualization()
    : frc1678::Visualization("Turret") {}

void TurretVisualization::SetState(TurretState state) {
  state_ = state;
  dashboard_strings_["angle"] =
      std::to_string(state_.angle.to(deg)) + "deg";
  dashboard_strings_["angular velocity"] =
      std::to_string(state_.angular_velocity.to(deg/s)) + "deg/s";
  dashboard_strings_["goal"] =
      std::to_string(state_.goal.to(deg)) + "deg";
}

void TurretVisualization::Draw(sf::RenderTarget& target) const {
  sf::Vector2f center(target.getSize().x / 2, target.getSize().y / 2);

  Length pixel = (1 / 300.0) * m;

  Length turret_radius = 1 * m, dot_radius = 0.1 * m;

  // Draw the turret
  sf::CircleShape turret(turret_radius.to(pixel));
  turret.setFillColor(sf::Color::Blue);
  turret.setOutlineColor(sf::Color::White);
  turret.setOutlineThickness(5);
  turret.setOrigin(turret_radius.to(pixel), turret_radius.to(pixel));
  turret.setPosition(center);
  turret.setRotation(-state_.angle.to(deg));
  target.draw(turret);

  // Draw the marker dot
  sf::CircleShape dot(dot_radius.to(pixel));
  dot.setFillColor(sf::Color::Red);
  dot.setOutlineColor(sf::Color::White);
  dot.setOutlineThickness(5);
  dot.setOrigin(dot_radius.to(pixel), dot_radius.to(pixel));
  double end_length_pixels = (-turret_radius).to(pixel);
  sf::Vector2f end(
      end_length_pixels * std::cos(-state_.angle()),
      end_length_pixels * std::sin(-state_.angle()));
  dot.setPosition(center+end);
  target.draw(dot);
}
