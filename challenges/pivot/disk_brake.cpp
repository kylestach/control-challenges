#include "pivot.h"
#include "solutions/pivot/disk_brake.h"
#include "disk_brake_visualization.h"
#include <iostream>

int main() {
  PivotVisualization visualizer;
  PivotDBState current_state{160 * deg, 0 * deg / s, false};
  PivotController controller;
  sf::Clock clock;

  //Constants
  const Mass pivot_mass = 30 * kg;
  const Length pivot_length = 1 * m;
  const Time dt = .005 * s;
  const Acceleration gravity = 9.81 * m / (s * s);
  const auto kTheta = (0.1 * N) * (s * m); 
  const auto pivot_moment_inertia = pivot_mass * pivot_length * pivot_length; 
  bool prev_brake = false;
  Time timer = 0 * s;

  while (visualizer.is_open()) {
    if (!visualizer.is_complete()) {

      //Calculate forces applied to system
      auto pivot_friction =  (-kTheta * current_state.angular_velocity); 
      auto torque = ((- gravity * pivot_mass * pivot_length * cos(current_state.angle.to(rad))) + pivot_friction);
      
      //Separate controller output
      auto controller_status = controller.Update(current_state, dt);
      Force controller_force = std::get<0>(controller_status);
      current_state.disk_brake = std::get<1>(controller_status);

      //Calculate how the system reacts to forces
      AngularAcceleration system_acceleration = (torque/pivot_moment_inertia);
      AngularAcceleration controller_acceleration = ((controller_force* pivot_length )/pivot_moment_inertia);

      if(current_state.disk_brake && !prev_brake){
        timer = 0 * s;
      }
      if(current_state.disk_brake) {
        timer += dt;
      }

      prev_brake = current_state.disk_brake;

      //Collisions for the pivot
      if(current_state.angle < 0 * deg) {
        if(current_state.angular_velocity < 0 * deg/s) {
            current_state.angular_velocity = 0 * deg/s;
        }
   	        current_state.angle = 0 * deg;
      } else if(current_state.angle > 180 * deg) {
        if(current_state.angular_velocity > 0 * deg/s) {
            current_state.angular_velocity = 0 * deg/s;
        }
   	        current_state.angle = 180 * deg;
      } else if(!current_state.disk_brake) {
        current_state.angular_velocity += (system_acceleration + controller_acceleration) * dt;
        current_state.angle += current_state.angular_velocity * dt;
      } else if(current_state.disk_brake && timer < .2 * s){
        current_state.angular_velocity += (system_acceleration + controller_acceleration) * dt;
        current_state.angle += current_state.angular_velocity * dt;
      } else if(current_state.disk_brake) {
       current_state.angular_velocity = 0 * deg/s;
       current_state.angle = current_state.angle;
      }
      visualizer.SetState(current_state);

      if(std::abs((current_state.angle - 50 * deg).to(deg)) < 0.1 &&
         std::abs((current_state.angular_velocity.to(deg/s))) < 0.1 &&
         std::abs((controller_force.to(N))) < 0.001 &&
         current_state.disk_brake) {
        visualizer.Complete();
      }
    }
    visualizer.Render();

    sf::sleep(sf::seconds(dt()) - clock.restart());
  }
}
