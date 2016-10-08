#include "visualization.h"

ElevatorVisualization::ElevatorVisualization()
    : frc1678::Visualization("Elevator") {}

void ElevatorVisualization::SetState(const ElevatorState state) {
  state_ = state;
  dashboard_strings_["Position"] = std::to_string(-state.position.to(m)) + " m";
  dashboard_strings_["Velocity"] =
      std::to_string(-state.velocity.to(m / s)) + " m/s";
}

void ElevatorVisualization::Draw(sf::RenderTarget& target) const {
  sf::Vector2f center(target.getSize().x / 2, target.getSize().y / 2);
  Length pixel = (1 / 300.0) * m;
  Length elevator_size = 0.1 * m;

  sf::RectangleShape elevator(
      sf::Vector2f(elevator_size.to(pixel), elevator_size.to(pixel)));
  elevator.setFillColor(sf::Color::Blue);
  elevator.setOutlineColor(sf::Color::White);
  elevator.setOutlineThickness(5);

  elevator.setOrigin(elevator_size.to(pixel) / 2, elevator_size.to(pixel));
  elevator.setPosition(center + sf::Vector2f(0, state_.position.to(pixel)));
  target.draw(elevator);
}
