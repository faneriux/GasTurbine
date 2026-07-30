#include "Simulation.hpp"

int main(){

    const double time_step_s = 0.01;
    const double initial_speed_rpm = 1000.0;
    const double time_constant_s = 1.0;
    const double demanded_speed_rpm = 2000.0;
    const double simulation_duration_s = 10.0;

Simulation simulation(time_step_s, initial_speed_rpm, time_constant_s, demanded_speed_rpm, simulation_duration_s);
simulation.run();
return 0;
}