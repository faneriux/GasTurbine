#pragma once
#include <fstream>
#include <string>

class CsvLogger {
public:
    CsvLogger(const std::string& filename);
    void log(double time_s, 
        double demanded_speed_rpm, 
        double current_speed_rpm);
private:                    
    std::ofstream file_;
    bool is_open() const;
    void write_header();

};      
