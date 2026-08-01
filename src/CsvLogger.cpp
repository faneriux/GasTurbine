#include "CsvLogger.hpp"
#include <stdexcept>

CsvLogger::CsvLogger(const std::string& filename) : file_(filename) {
    if (!is_open()) {
        throw std::runtime_error(std::string("Failed to open file: ") + filename);
    }
    write_header();
    if (!file_){
        throw std::runtime_error(std::string("Failed to write CSV header to file: ") + filename);
    }
    }

bool CsvLogger::is_open() const {
    return file_.is_open();
}

void CsvLogger::write_header() {
    file_ << "Time_s,Demanded_Speed_RPM,Current_Speed_RPM\n";
}

void CsvLogger::log(double time_s, double demanded_speed_rpm, double current_speed_rpm) {
    file_ 
            << time_s 
            << "," 
            << demanded_speed_rpm 
            << "," 
            << current_speed_rpm 
            << "\n";
}