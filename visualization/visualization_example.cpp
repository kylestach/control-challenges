#include "visualization.h"
#include <cmath>
#include "third_party/unitscpp/unitscpp.h"

struct ExampleState {
  Angle angle;
};

class ExampleVisualization : public frc1678::Visualization {
 public:
  ExampleVisualization() : frc1678::Visualization("Example") {}
  virtual ~ExampleVisualization() {}

  void SetState(ExampleState state) {
    state_ = state;
    dashboard_strings_["angle"] = std::to_string(state.angle());
  }

 protected:
  void Draw(sf::RenderTarget& target) const override {
    sf::RectangleShape rect;
    rect.setOrigin(50, 50);
    rect.setPosition(400, 300);
    rect.setSize(sf::Vector2f(100, 100));
    rect.setFillColor(sf::Color::White);
    rect.setRotation(state_.angle.to(deg));
    target.draw(rect);
  }

 private:
  ExampleState state_;
};

int main() {
  ExampleVisualization ex_vis;
  ExampleState state;
  sf::Clock clock;
  while (ex_vis.is_open()) {
    state.angle = std::sin(clock.getElapsedTime().asSeconds()) * rad;
    ex_vis.SetState(state);
    ex_vis.Render();
    sf::sleep(sf::milliseconds(10));
  }
}
