#include "Simulation.hpp"
#include <iostream>

Simulation::Simulation(double time_step_s, 
                         double initial_speed_rpm, 
                         double time_constant_s, 
                         const std::vector<double>& demand_profile_rpm)
    : clock_(time_step_s), spool_(initial_speed_rpm, time_constant_s), scenario_(time_step_s, demand_profile_rpm) {}


void Simulation::run() {
    while (!scenario_.is_finished()) {
        const double demanded_speed_rpm = scenario_.current_demand();
        spool_.update(demanded_speed_rpm, clock_.time_step());
        clock_.advance();
        std::cout << "Time: " << clock_.current_time() << " s, "
                  << "Demanded Speed: " << demanded_speed_rpm << " RPM, "
                  << "Current Speed: " << spool_.current_speed() << " RPM\n"; 
        scenario_.advance();
    }
}