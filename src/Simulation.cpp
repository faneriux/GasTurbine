#include "Simulation.hpp"
#include <iostream>
#include <stdexcept>

Simulation::Simulation(double time_step_s, 
                       double initial_speed_rpm, 
                       double time_constant_s, 
                       double demanded_speed_rpm, 
                       double simulation_duration_s)
    : clock_(time_step_s),
      spool_(initial_speed_rpm, time_constant_s),
      demanded_speed_rpm_(demanded_speed_rpm),
      simulation_duration_s_(simulation_duration_s) {
    if (demanded_speed_rpm < 0.0) {
        throw std::invalid_argument("Demanded speed must be non-negative.");
    }
    if (simulation_duration_s <= 0.0) {
        throw std::invalid_argument("Simulation duration must be positive.");
    }
}
    void Simulation::run() {
        while (clock_.current_time() < simulation_duration_s_) {
            clock_.advance();
            spool_.update(demanded_speed_rpm_, clock_.time_step());  
            std::cout << "Current time: " << clock_.current_time() << " seconds, Current speed: " << spool_.current_speed() << " RPM" << std::endl;
        }

    };
