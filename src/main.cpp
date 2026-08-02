#include "Simulation.hpp"
#include "FileNameGenerator.hpp"
#include "ScenarioBuilder.hpp"

int main(){

    const double time_step_s = 0.01;
    const double initial_speed_rpm = 0.0;
    const double time_constant_s = 0.1;
    const std::string output_filename = FileNameGenerator::generate_output_filename("../output/Run", "csv");
    ScenarioBuilder scenario_builder(time_step_s);
    const std::vector<double> demanded_speed_rpm = scenario_builder
        .hold(0.0, 1.0)
        .ramp(0.0, 1000.0, 5.0)
        .hold(1000.0, 2.0)
        .ramp(1000.0, 500.0, 3.0)
        .hold(500.0, 2.0)
        .ramp(500.0, 1500.0, 4.0)
        .hold(1500.0, 2.0)
        .ramp(1500.0, 2000.0, 3.0)
        .hold(2000.0, 2.0)
        .ramp(0.0, 2000.0, 0.5)
        .hold(1000.0, 2.0)
        .ramp(1000.0, 500.0, 3.0)
        .hold(500.0, 2.0)
        .ramp(500.0, 200.0, 4.5)
        .hold(200.0, 2.5)
        .build();

    Simulation simulation(time_step_s, initial_speed_rpm, time_constant_s, demanded_speed_rpm, output_filename);
    simulation.run();
    return 0;
}