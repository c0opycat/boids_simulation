//
// Created by lcooper on 30/12/2025.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "Boid.hpp"
#include "Flock.hpp"

namespace bd {
    class Simulation {
        const float BOID_SIZE = 5.f;
        bd::Flock& _flock;
    public:
        Simulation(bd::Flock& flock);
        void drawBoid(sf::RenderWindow& window, const Boid& boid) const;
        void run() const;
    };
}