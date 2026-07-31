#include <stdexcept>
#include "Scenario.hpp"

Scenario::Scenario(double sample_time_s, const std::vector<double>& demand_profile_rpm)
    : demand_profile_rpm_(demand_profile_rpm), sample_time_s_(sample_time_s) {
    if (sample_time_s <= 0.0) {
        throw std::invalid_argument("Sample time must be positive.");
    }
    if (demand_profile_rpm.empty()) {
        throw std::invalid_argument("Demand profile cannot be empty.");
    }
    if (std::any_of(demand_profile_rpm.begin(), demand_profile_rpm.end(), [](double rpm) { return rpm < 0.0; })) {
        throw std::invalid_argument("Demand profile must contain non-negative values.");
    }
}

bool Scenario::is_finished() const {
    return current_sample_index_ >= demand_profile_rpm_.size();
}

double Scenario::total_duration()  const {
    return static_cast<double>(demand_profile_rpm_.size()) * sample_time_s_;
}

double Scenario::sample_time() const {
    return sample_time_s_;
}

double Scenario::current_demand() const {
    if (is_finished()) {
        throw std::out_of_range("Current sample index is out of range.");
    }
    return demand_profile_rpm_.at(current_sample_index_);
}

void Scenario::advance() {
    if (!is_finished()) {
        ++current_sample_index_;
    }
}








