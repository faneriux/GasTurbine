cmake_minimum_required(VERSION 3.25)

project(GasTurbineProjects LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(GasTurbineProjects
    src/main.cpp
    src/SimulationClock.cpp
    src/SpoolModel.cpp
    src/Simulation.cpp
)

target_include_directories(GasTurbineProjects PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

target_compile_options(GasTurbineProjects PRIVATE
    -Wall
    -Wextra
    -Wpedantic
    -Wconversion
    -Wshadow
)