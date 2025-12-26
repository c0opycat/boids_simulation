cmake_minimum_required(VERSION 3.20)
project(boids_simulation)

set(CMAKE_CXX_STANDARD 20)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(boids_simulation
        src/main.cpp
        src/containers/DynamicArray.hpp
        src/containers/Vec2.hpp
        src/utils/Utils.cpp
        src/utils/Utils.hpp
        src/Boid.cpp
        src/Boid.hpp
        src/Settings.cpp
        src/Settings.hpp
        src/Flock.cpp
        src/Flock.hpp
        src/rules/CohesionRule.hpp
        src/rules/CohesionRule.cpp
        src/rules/SeparationRule.cpp
        src/rules/SeparationRule.hpp
        src/rules/AlignementRule.cpp
        src/rules/AlignementRule.hpp
        src/utils/Utils.cpp
)

target_link_libraries(boids_simulation PRIVATE sfml-graphics)

# Enable testing
enable_testing()

