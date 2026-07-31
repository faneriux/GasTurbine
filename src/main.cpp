#include "Simulation.hpp"

int main(){

    const double time_step_s = 0.01;
    const double initial_speed_rpm = 0.0;
    const double time_constant_s = 0.1;
    const std::vector<double> demanded_speed_rpm = {0, 0, 1000, 3000, 5000, 5000, 3000, 1000, 0};

    Simulation simulation(time_step_s, initial_speed_rpm, time_constant_s, {demanded_speed_rpm});
    simulation.run();
    return 0;
}