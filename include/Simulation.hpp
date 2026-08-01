#pragma once
#include "SimulationClock.hpp"
#include "SpoolModel.hpp"
#include "Scenario.hpp"
#include "CsvLogger.hpp"

class Simulation
{

private:
    SimulationClock clock_;
    SpoolModel spool_;
    Scenario scenario_;
    CsvLogger logger_;

public:
    Simulation(double time_step_s, 
               double initial_speed_rpm, 
               double time_constant_s, 
               const std::vector<double>& demand_profile_rpm,
               const std::string& output_filename);

    void run();

};