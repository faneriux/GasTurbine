#include "SimulationClock.hpp"
#include "SpoolModel.hpp"
#include <iostream>

int main(){

    const double time_step = 0.5; // seconds
    const double demanded_speed = 5000.0; // RPM
    const double initial_speed = 0.0; // RPM
    const double time_constant = 1.0; // seconds
    const double simulation_duration = 10.0; // seconds
    SimulationClock clock(time_step); 
    SpoolModel spool(initial_speed, time_constant);
    
    while (clock.current_time() < simulation_duration) {

            spool.update(demanded_speed, clock.time_step());
            clock.advance();
            std::cout << "Current time: " << clock.current_time() << " seconds, Current speed: " << spool.current_speed() << " RPM" << std::endl;

    }
    
    return 0;
}