#include "visualization.h"

namespace frc1678 {

Visualization::Visualization(std::string name, sf::VideoMode mode)
    : window_(mode, name), dashboard_(sf::VideoMode(400, 600), "Dashboard") {
  dashboard_font_.loadFromFile("visualization/font.ttf");
}

void Visualization::Render() {
  window_.clear();
  Draw(window_);

  if (is_complete()) {
    sf::Text text(
        "Finished in " + std::to_string(total_time_.asSeconds()) + "s",
        dashboard_font_);
    text.setCharacterSize(50);
    text.setOrigin(text.getLocalBounds().width / 2,
                   text.getLocalBounds().height / 2);
    text.setPosition(window_.getSize().x / 2, 2 * window_.getSize().y / 3);
    text.setColor(sf::Color::Green);
    text.setStyle(sf::Text::Bold);
    window_.draw(text);
  }

  window_.display();

  dashboard_strings_["time"] =
      std::to_string(
          (is_complete() ? total_time_ : timer_.getElapsedTime()).asSeconds()) +
      "s";
  dashboard_.clear();
  DrawDashboard(dashboard_);
  dashboard_.display();

  sf::Event event;
  while (window_.pollEvent(event) || dashboard_.pollEvent(event)) {
    if (event.type == sf::Event::Closed) window_.close();
  }
}

bool Visualization::is_open() { return window_.isOpen(); }
bool Visualization::is_complete() { return finished_; }

void Visualization::Complete() {
  if (!is_complete()) total_time_ = timer_.getElapsedTime();
  finished_ = true;
}

void Visualization::DrawDashboard(sf::RenderTarget& dashboard) const {
  sf::Text text;
  text.setFont(dashboard_font_);
  text.setCharacterSize(30);
  sf::Vector2f next_pos{20, 20};
  text.setColor(sf::Color::White);

  for (const auto& pair : dashboard_strings_) {
    text.setString(pair.first + ": " + pair.second);
    text.setPosition(next_pos);
    dashboard.draw(text);
    next_pos.y += 40;
  }
}

} /*  frc1678 */
