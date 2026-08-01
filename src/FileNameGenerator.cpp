#include "FileNameGenerator.hpp"
#include <chrono>
#include <ctime>

std::string FileNameGenerator::generate_output_filename(const std::string& base_name, const std::string& extension) {
    // Get the current time as a string
    auto now = std::chrono::system_clock::now();
    std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);
    std::tm now_tm = *std::localtime(&now_time_t);

    // Format the time into a string
    char time_buffer[32];
    std::strftime(time_buffer, sizeof(time_buffer), "%Y%m%d_%H%M%S", &now_tm);

    // Construct the filename
    return base_name + "_" + time_buffer + "." + extension;
}