#include "solutions/sliding_block/no_friction.h"

#include <cmath>
#include "sliding_block.h"
#include "visualization.h"

int main() {
  FrictionlessSlidingBlockController controller;
  SlidingBlockVisualization visualizer;
  SlidingBlockState current_state{5 * m, 0 * m / s};
  sf::Clock clock;

  const Mass block_mass = 5 * kg;
  const Time dt = .01 * s;

  while (visualizer.is_open()) {
    if (std::abs(current_state.velocity()) < .01 &&
        std::abs(current_state.position()) < .01) {
      visualizer.Complete();
    } else {
      Force force = controller.Update(current_state.position, dt);
      Acceleration acceleration = force / block_mass;
      current_state.velocity += dt * acceleration;
      current_state.position += dt * current_state.velocity;

      visualizer.SetState(current_state);
    }
    visualizer.Render();

    sf::sleep(sf::seconds(dt()) - clock.restart());
  }
}
