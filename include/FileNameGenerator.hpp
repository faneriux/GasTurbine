#pragma once
#include <string>

class FileNameGenerator{

public:
    static std::string generate_output_filename(const std::string& base_name, const std::string& extension);
};