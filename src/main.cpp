#include "utils/Utils.hpp"
#include "Simulation.hpp"

int main() {
    Utils::Random::init();

    bd::Settings settings;
    bd::Flock flock(settings);
    bd::Simulation simulation(flock);

    simulation.run();

    return 0;
}