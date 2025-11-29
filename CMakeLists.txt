cmake_minimum_required(VERSION 3.20)
project(boids_simulation)

set(CMAKE_CXX_STANDARD 20)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(boids_simulation
        src/main.cpp
        src/containers/DynamicArray.h++
        src/containers/Vec2.hpp
        src/Utils.hpp
)

target_link_libraries(boids_simulation PRIVATE sfml-graphics)

# Enable testing
enable_testing()

