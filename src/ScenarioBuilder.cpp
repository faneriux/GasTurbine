#include <stdexcept>
#include <cmath>
#include <cstddef>
#include "ScenarioBuilder.hpp"


ScenarioBuilder::ScenarioBuilder(double sample_time_s)
    : sample_time_s_(sample_time_s) {
    if (sample_time_s_ <= 0.0) {
        throw std::invalid_argument("Sample time must be positive.");
    }
}

    std::size_t ScenarioBuilder::duration_to_samples(double duration_s) const{

        if (duration_s <= 0.0) {
            throw std::invalid_argument("Duration must be positive.");
        }

        constexpr double tolerance = 1e-6;
        const double exact_sample_count = duration_s / sample_time_s_;
        const double rounded_sample_count = std::round(exact_sample_count);
        const double difference = std::abs(exact_sample_count - rounded_sample_count);

        if (difference > tolerance) {
            throw std::invalid_argument("Duration is not a multiple of sample time.");
        }

        return static_cast<std::size_t>(rounded_sample_count);  
    }

ScenarioBuilder& ScenarioBuilder::hold(double rpm, double duration_s) {
    if (rpm < 0.0) {
        throw std::invalid_argument("RPM must be non-negative.");
    }
    if (duration_s <= 0.0) {
        throw std::invalid_argument("Duration must be positive.");
    }

    const std::size_t num_samples = duration_to_samples(duration_s);

    for (std::size_t i=0; i<num_samples; i++){
        demand_profile_rpm_.push_back(rpm);
    }

    return *this;
}



ScenarioBuilder& ScenarioBuilder::ramp(double start_rpm, double end_rpm, double duration_s) {
    if (start_rpm < 0.0 || end_rpm < 0.0) {
        throw std::invalid_argument("RPM values must be non-negative.");
    }
    if (duration_s <= 0.0) {
        throw std::invalid_argument("Duration must be positive.");
    }

    const std::size_t num_samples = duration_to_samples(duration_s);

   for (std::size_t i=0; i<num_samples; i++){
    double progress = static_cast<double>(i+1) / static_cast<double>(num_samples);
    double interpolated_rpm = start_rpm + progress * (end_rpm - start_rpm);
    demand_profile_rpm_.push_back(interpolated_rpm);
   }
   
   return *this;
}

std::vector<double> ScenarioBuilder::build() const {
    if (demand_profile_rpm_.empty()) {
        throw std::runtime_error("Demand profile is empty. Cannot build scenario.");
    }
    return demand_profile_rpm_;
}