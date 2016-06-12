#include "double_jointed.h"
#include "visualization.h"

int main() {
  DoubleJointedVisualization visualizer;
  DoubleJointedState current_state{0 * rad, 0 * rad / s, 0 * rad, 0 * rad / s};
  sf::Clock clock;

  const Time dt = .01 * s;

  while (visualizer.is_open()) {
    if (!visualizer.is_complete()) {
      current_state.shoulder_angular_velocity = 30 * deg / s;
      current_state.shoulder_angle +=
          current_state.shoulder_angular_velocity * dt;
      current_state.wrist_angular_velocity = -30 * deg / s;
      current_state.wrist_angle += current_state.wrist_angular_velocity * dt;
      visualizer.SetState(current_state);
    }
    visualizer.Render();

    sf::sleep(sf::seconds(dt()) - clock.restart());
  }
}
