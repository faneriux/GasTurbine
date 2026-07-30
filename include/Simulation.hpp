#pragma once
#include "SimulationClock.hpp"
#include "SpoolModel.hpp"

class Simulation
{

private:
    SimulationClock clock_;
    SpoolModel spool_;

    double demanded_speed_rpm_;
    double simulation_duration_s_;

public:
    Simulation(double time_step_s, 
               double initial_speed_rpm, 
               double time_constant_s, 
               double demanded_speed_rpm, 
               double simulation_duration_s);
    void run();
};