#include <cstddef>
#include "SimulationClock.hpp"
#include <iostream>
int main(){

    double time{0.0};
    std::size_t iteration{0};
    SimulationClock clock(0.1);

    while (clock.current_time() < 1.0) {
        
            clock.advance();
            time = clock.current_time();
            iteration = clock.current_iteration();
            

            std::cout << "Current time: " << time << " seconds, Current iteration: " << iteration << std::endl;


    }
    return 0;
}