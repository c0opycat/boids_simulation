//
// Created by arthur on 28/11/2025.
//

#include "utils/Utils.hpp"
#include "Simulation.hpp"

int main() {
    Utils::Random::init();

    bd::Settings settings;
    bd::Flock flock(settings);
    const bd::Simulation simulation(flock);

    simulation.run();

    return 0;
}