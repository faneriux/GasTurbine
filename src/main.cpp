#include "Simulation.hpp"
#include "FileNameGenerator.hpp"

int main(){

    const double time_step_s = 0.01;
    const double initial_speed_rpm = 0.0;
    const double time_constant_s = 0.1;
    const std::vector<double> demanded_speed_rpm = {0, 0, 0, 1, 2, 3, 4, 5, 0};
    const std::string output_filename = FileNameGenerator::generate_output_filename("../output/Run", "csv");

    Simulation simulation(time_step_s, initial_speed_rpm, time_constant_s, demanded_speed_rpm, output_filename);
    simulation.run();
    return 0;
}