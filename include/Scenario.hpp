#pragma once
#include <cstddef>
#include <vector>
class Scenario{

private:
    std::size_t current_sample_index_ = 0;
    std::vector<double> demand_profile_rpm_;
    const double sample_time_s_;

public:
    Scenario(double sample_time_s, const std::vector<double>& demand_profile_rpm);
    bool is_finished() const;
    double current_demand() const;
    void advance();
    double total_duration() const;
    double sample_time() const;


};