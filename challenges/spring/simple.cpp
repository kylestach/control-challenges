#include "solutions/spring/simple.h"

#include <cmath>
#include "spring.h"
#include "visualization.h"

int main() {
  SpringController controller;
  SpringVisualization visualizer;
  SpringState current_state{5 * m, 0 * m / s};
  sf::Clock clock;

  const Mass block_mass = 5 * kg;
  const Time dt = .01 * s;
  const auto kF = (10 * N) / (m / s);
  const auto kH = (200 * N) / m;
  const Length goal = -1 * m;

  controller.SetGoal(goal);

  while (visualizer.is_open()) {
    if (!visualizer.is_complete()) {
      Force force = controller.Update(current_state.position, dt) -
                    kH * current_state.position - kF * current_state.velocity;
      if (std::abs(current_state.velocity()) < .01 &&
          std::abs(goal() - current_state.position()) < .01 &&
          std::abs(force()) < .01) {
        visualizer.Complete();
      } else {
        Acceleration acceleration = force / block_mass;
        current_state.velocity += dt * acceleration;
        current_state.position += dt * current_state.velocity;
        if (current_state.position < -3 * m) {
          current_state.position = -3 * m;
          current_state.velocity = 0 * m / s;
        }

        visualizer.SetState(current_state);
      }
    }
    visualizer.Render();

    sf::sleep(sf::seconds(dt()) - clock.restart());
  }
}
