#include "SimulationClock.hpp"
#include <stdexcept>

SimulationClock::SimulationClock(double time_step_s) : time_step_s_(time_step_s), iteration_count_(0) {
    if (time_step_s <= 0.0) {
        throw std::invalid_argument("Time step must be positive.");
    }
}

void SimulationClock::advance() {
    ++iteration_count_;
}

double SimulationClock::current_time() const {
    return static_cast<double>(iteration_count_) * time_step_s_;
}

double SimulationClock::time_step() const {
    return time_step_s_;
}

std::size_t SimulationClock::current_iteration() const {
    return iteration_count_;
}