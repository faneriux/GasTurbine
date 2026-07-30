#pragma once

class SpoolModel {
private:

    double speed_rpm_;
    double time_constant_s_;
    double rate_of_speed_change(double demanded_speed_rpm) const;
    

    public:
    explicit SpoolModel(double initial_speed_rpm = 0.0, double time_constant_s = 1.0);
    void update(double demanded_speed_rpm, double time_step_s);
    double current_speed() const;
    
};

