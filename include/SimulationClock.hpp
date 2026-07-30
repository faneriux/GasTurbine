#pragma once
#include <cstddef>
class SimulationClock {
private:

    double time_step_s_;
    std::size_t iteration_count_;

public:
    explicit SimulationClock(double time_step_s = 0.01);
    void advance();
    double current_time()const;
    double time_step()const;
    std::size_t current_iteration()const;   
};

