#pragma once
#include "SimulationClock.hpp"
#include "SpoolModel.hpp"
#include "Scenario.hpp"


class Simulation
{

private:
    SimulationClock clock_;
    SpoolModel spool_;
    Scenario scenario_;



public:
    Simulation(double time_step_s, 
               double initial_speed_rpm, 
               double time_constant_s, 
               const std::vector<double>& demand_profile_rpm);


    void run();

};