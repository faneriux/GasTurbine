#include "SimulationClock.hpp"

SimulationClock::SimulationClock(double time_step_s) : time_step_s_(time_step_s), iteration_count_(0) {}

void SimulationClock::advance() {
    iteration_count_++;
}

double SimulationClock::current_time() const {
    return static_cast<double>(iteration_count_) * time_step_s_;
}

std::size_t SimulationClock::current_iteration() const {
    return iteration_count_;
}