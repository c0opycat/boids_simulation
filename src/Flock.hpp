//
// Created by lcooper on 03/12/2025.
//

#pragma once

#include "containers/DynamicArray.hpp"
#include "Boid.hpp"
#include "Settings.hpp"

namespace bd {
    class Flock {
        DynamicArray<Boid> _boids;
        Settings& _settings;
    public:
        Flock(Settings& settings);
        Flock(const size_t nb_boids, Settings& settings);
        const DynamicArray<Boid>& getBoids() const;
        Settings& getSettings() const;
        void addBoids(const size_t count);
        void addBoid(const Boid& boid);
        void removeBoids(const size_t count);
        void clearBoids();
        void updateBoids(const float deltaTime);
    };
}
