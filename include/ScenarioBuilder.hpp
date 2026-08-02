#pragma once
#include <vector>

class ScenarioBuilder {

private:

const double sample_time_s_;
std::vector<double> demand_profile_rpm_;
std::size_t duration_to_samples(double duration_s) const;

public:
    explicit ScenarioBuilder(double sample_time_s);
    ScenarioBuilder& hold(double rpm, double duration_s);
    ScenarioBuilder& ramp(double start_rpm, double end_rpm, double duration_s);
    std::vector<double> build() const;
};