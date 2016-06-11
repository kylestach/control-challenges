#pragma once

#include <SFML/Graphics.hpp>
#include <map>

namespace frc1678 {

class Visualization {
 public:
  // Renders the visualization and the text
  void Render();

  bool is_open();

 protected:
  // Draw should be overridden by a subclass and should draw the visualization
  // onto the window.
  virtual void Draw(sf::RenderTarget& target) const = 0;

  Visualization(std::string name, sf::VideoMode mode = sf::VideoMode(800, 600));
  virtual ~Visualization() {}
  std::map<std::string, std::string> dashboard_strings_;

 private:
  sf::RenderWindow window_;
  sf::RenderWindow dashboard_;

  void DrawDashboard(sf::RenderTarget& target) const;

  sf::Font dashboard_font_;
};

} /* frc1678 */
