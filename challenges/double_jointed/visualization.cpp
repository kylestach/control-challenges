#include "visualization.h"
#include <cmath>
#include "third_party/unitscpp/unitscpp.h"

DoubleJointedVisualization::DoubleJointedVisualization()
    : frc1678::Visualization("Double Jointed") {}

void DoubleJointedVisualization::SetState(DoubleJointedState state) {
  state_ = state;
  dashboard_strings_["shoulder position"] =
      std::to_string(state_.shoulder_angle()) + "m";
  dashboard_strings_["shoulder velocity"] =
      std::to_string(state_.shoulder_angular_velocity()) + "m/s";
  dashboard_strings_["wrist position"] =
      std::to_string(state_.wrist_angle()) + "m";
  dashboard_strings_["wrist velocity"] =
      std::to_string(state_.wrist_angular_velocity()) + "m/s";
}

void DoubleJointedVisualization::Draw(sf::RenderTarget& target) const {
  sf::Vector2f center(target.getSize().x / 2, target.getSize().y / 2);

  Length pixel = (1 / 300.0) * m;

  Length shoulder_length = 1 * m, wrist_length = .3 * m, thickness = .1 * m;

  // Draw the shoulder
  sf::RectangleShape shoulder(
      sf::Vector2f(shoulder_length.to(pixel), thickness.to(pixel)));
  shoulder.setFillColor(sf::Color::Transparent);
  shoulder.setOutlineColor(sf::Color::White);
  shoulder.setOutlineThickness(5);
  shoulder.setOrigin(thickness.to(pixel) / 2, thickness.to(pixel) / 2);
  shoulder.setPosition(center);
  shoulder.setRotation(-state_.shoulder_angle.to(deg));
  target.draw(shoulder);

  // Draw the wrist
  sf::RectangleShape wrist(
      sf::Vector2f(wrist_length.to(pixel), thickness.to(pixel)));
  wrist.setFillColor(sf::Color::Transparent);
  wrist.setOutlineColor(sf::Color::White);
  wrist.setOutlineThickness(5);
  wrist.setOrigin(thickness.to(pixel) / 2, thickness.to(pixel) / 2);
  double shoulder_end_length_pixels = (shoulder_length - thickness).to(pixel);
  sf::Vector2f shoulder_end(
      shoulder_end_length_pixels * std::cos(-state_.shoulder_angle()),
      shoulder_end_length_pixels * std::sin(-state_.shoulder_angle()));
  wrist.setPosition(center + shoulder_end);
  wrist.setRotation(180 - state_.wrist_angle.to(deg) -
                    state_.shoulder_angle.to(deg));
  target.draw(wrist);
}
