#include "solutions/sliding_block/goal.h"

#include <cmath>
#include "sliding_block.h"
#include "visualization.h"

int main() {
  GoalSlidingBlockController controller;
  SlidingBlockVisualization visualizer;
  SlidingBlockState current_state{5 * m, 0 * m / s};
  sf::Clock clock;

  const Length goal = -3 * m;
  const Mass block_mass = 5 * kg;
  const Time dt = .01 * s;
  const auto kF = (3 * N) / (m / s);

  controller.SetGoal(goal);

  while (visualizer.is_open()) {
    if (std::abs(current_state.velocity()) < .01 &&
        std::abs(current_state.position() - goal()) < .01) {
      visualizer.Complete();
    } else {
      Force force = controller.Update(current_state.position, dt) -
                    kF * current_state.velocity;
      Acceleration acceleration = force / block_mass;
      current_state.velocity += dt * acceleration;
      current_state.position += dt * current_state.velocity;

      visualizer.SetState(current_state);
    }
    visualizer.Render();

    sf::sleep(sf::seconds(dt()) - clock.restart());
  }
}
