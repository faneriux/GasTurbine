#include "SpoolModel.hpp"
#include <stdexcept>

SpoolModel::SpoolModel(double initial_speed_rpm, double time_constant_s)
    : speed_rpm_(initial_speed_rpm), time_constant_s_(time_constant_s) {
    if (time_constant_s_ <= 0.0) {
        throw std::invalid_argument("Time constant must be positive.");
    }
    if (initial_speed_rpm < 0.0) {
        throw std::invalid_argument("Initial speed must be non-negative.");
    }
}

void SpoolModel::update(double demanded_speed_rpm, double time_step_s) {
    if (time_step_s <= 0.0) {
        throw std::invalid_argument("Time step must be positive.");
    }
    if (demanded_speed_rpm < 0.0) {
        throw std::invalid_argument("Demanded speed must be non-negative.");
    }
    double speed_change = rate_of_speed_change(demanded_speed_rpm);
    speed_rpm_ += speed_change * time_step_s;
}

double SpoolModel::rate_of_speed_change(double demanded_speed_rpm) const {
    return (demanded_speed_rpm - speed_rpm_) / time_constant_s_;
}

double SpoolModel::current_speed() const {
    return speed_rpm_;
}







