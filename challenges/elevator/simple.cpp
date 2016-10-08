#include "solutions/elevator/simple.h"

#include <cmath>
#include "elevator.h"
#include "third_party/unitscpp/unitscpp.h"
#include "visualization.h"

int main() {
  ElevatorController controller;
  ElevatorVisualization visualizer;
  ElevatorState current_state{0 * m, 0 * m / s};
  sf::Clock clock;

  // 775 pro stats
  const Current stall_current = 134 * A, free_current = .7 * A;
  const Torque stall_torque = .71 * N * m;
  const AngularVelocity free_speed = 18730 * rpm;

  const Resistance R = 12 * V / stall_current;
  const auto kT = stall_torque / stall_current;
  const auto kV = (12 * V - free_current * R) / free_speed;

  const Length radius = 2 * in;
  const Mass system_mass = 1 * kg;
  const auto J = (radius * radius) * system_mass;
  const Unitless G = 1 / 2.5;

  const Time dt = .005 * s;
  const ElevatorState goal = {0.5 * m, 0 * m / s};

  // Gravity's a thing!
  const Acceleration gravity = 9.8 * m / s / s;

  controller.SetGoal(goal);

  while (visualizer.is_open()) {
    if (!visualizer.is_complete()) {
      // Get the voltage from the controller
      Voltage u = controller.Update(current_state, dt);
      // Model the motor's torque using a model of the motor and the gears.
      Torque torque = kT * u / (G * R) -
                      kT * kV * (current_state.velocity / radius) / (G * G * R);

      // Calculate acceleration by torque and factor in a gravity
      Acceleration acceleration = (torque / J) * radius + gravity;

      // Check if the challenge is completed successfully
      if (std::abs(current_state.position.to(-m) - goal.position.to(m)) <
              0.05 &&
          std::abs(current_state.velocity.to(m / s)) < 0.01) {
        visualizer.Complete();
      } else {
        // Otherwize, update the system with the calculated acceleration
        current_state.velocity += dt * acceleration;
        current_state.position += dt * current_state.velocity;
        visualizer.SetState(current_state);
      }
    }
    visualizer.Render();

    sf::sleep(sf::seconds(dt()) - clock.restart());
  }
}
