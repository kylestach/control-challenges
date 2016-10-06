#include "pivot.h"
#include "solutions/pivot/simple.h"
#include "visualization.h"

int main() {
  PivotVisualization visualizer;
  PivotState current_state{70 * deg, 0 * deg / s};
  PivotController controller;
  sf::Clock clock;

  //Constants
  const Mass pivot_mass = 30 * kg;
  const Length pivot_length = 1 * m;
  const Time dt = .005 * s;
  const Acceleration gravity = 9.81 * m / (s * s);
  const auto kTheta = (3 * N) * (s * m); 
  const auto pivot_moment_inertia = pivot_mass * pivot_length * pivot_length; 

  while (visualizer.is_open()) {
    if (!visualizer.is_complete()) {

      //Calculate forces applied to system
      auto pivot_friction =  (-kTheta * current_state.angular_velocity); 
      auto torque = ((- gravity * pivot_mass * pivot_length * cos(current_state.angle.to(rad))) + pivot_friction);

      //Calculate how the system reacts to forces
      AngularAcceleration system_acceleration = (torque/pivot_moment_inertia);
      AngularAcceleration controller_acceleration = ((controller.Update(current_state, dt)* pivot_length )/pivot_moment_inertia);

      //Collisions for the pivot
      if(current_state.angle < 0 * deg) {
        if(current_state.angular_velocity < 0 * deg/s) {
          current_state.angular_velocity = 0 * deg/s;
   	      current_state.angle = 0 * deg;
        }
      } else if(current_state.angle > 180 * deg) {
        if(current_state.angular_velocity > 0 * deg/s) {
            current_state.angular_velocity = 0 * deg/s;
   	        current_state.angle = 180 * deg;
        }
      } else {
      current_state.angular_velocity += (system_acceleration + controller_acceleration) * dt;
      current_state.angle +=
          current_state.angular_velocity * dt;
      }
      visualizer.SetState(current_state);

      if(std::abs((current_state.angle - 50 * deg).to(deg)) < 0.1 &&
         std::abs((current_state.angular_velocity.to(deg/s))) < 0.1) {
        visualizer.Complete();
      }
    }
    visualizer.Render();

    sf::sleep(sf::seconds(dt()) - clock.restart());
  }
}
