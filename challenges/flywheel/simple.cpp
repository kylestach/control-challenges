#include "solutions/flywheel/simple.h"

#include <cmath>
#include "flywheel.h"
#include "third_party/unitscpp/unitscpp.h"
#include "visualization.h"

int main() {
  FlywheelController controller;
  FlywheelVisualization visualizer;
  FlywheelState current_state{0 * rpm};
  sf::Clock clock;

  // 775 pro stats
  const Current stall_current = 134 * A, free_current = .7 * A;
  const Torque stall_torque = .71 * N * m;
  const AngularVelocity free_speed = 18730 * rpm;

  const Resistance R = 12 * V / stall_current;
  const auto kT = stall_torque / stall_current;
  const auto kV = (12 * V - free_current * R) / free_speed;

  const Length radius = 2 * in;
  const Mass flywheel_mass = .5 * kg;
  const auto J = (radius * radius) * flywheel_mass;
  const Unitless G = 1 / 2.5;

  const Time dt = .01 * s;
  const AngularVelocity goal = 4000 * rpm;

  controller.SetGoal(goal);

  while (visualizer.is_open()) {
    if (!visualizer.is_complete()) {
      Voltage u = controller.Update(current_state.velocity, dt);
      Torque torque =
          kT * u / (G * R) - kT * kV * current_state.velocity / (G * G * R);
      if (std::abs(goal.to(rpm) - current_state.velocity.to(rpm)) < 5 &&
          std::abs(torque()) < .5) {
        visualizer.Complete();
      } else {
        AngularAcceleration acceleration = torque / J;
        current_state.velocity += dt * acceleration;
        visualizer.SetState(current_state);
      }
    }
    visualizer.Render();

    sf::sleep(sf::seconds(dt()) - clock.restart());
  }
}
