#include <iostream>

int main(){

constexpr double time_step_s{0.01};
constexpr double simulation_duration_s{5.0};

double simulation_time_s{0.0};

std::size_t iteration{0};

while (simulation_time_s < simulation_duration_s)
{

    if (iteration % 100 == 0)
    {
    std::cout << simulation_time_s << '\n';
    }

    ++iteration;
    simulation_time_s = static_cast<double>(iteration) * time_step_s;
}

    return 0;
}