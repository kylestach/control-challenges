#include "visualization.h"

FlywheelVisualization::FlywheelVisualization()
    : frc1678::Visualization("Flywheel") {}

void FlywheelVisualization::SetState(const FlywheelState state) {
  state_ = state;
  dashboard_strings_["velocity"] =
      std::to_string(state.velocity.to(rpm)) + "rpm";
}

void FlywheelVisualization::Draw(sf::RenderTarget& target) const {
  Length pixel = in / 50.0;
  // Draw the wheel
  Length wheel_radius = 2 * in * (1 + state_.velocity.to(rpm) / 10000.0);
  sf::CircleShape wheel(wheel_radius.to(pixel));
  wheel.setOrigin(wheel_radius.to(pixel), wheel_radius.to(pixel));
  wheel.setPosition(target.getSize().x / 2, target.getSize().y / 2);
  wheel.setFillColor(sf::Color::White);
  target.draw(wheel);
}
