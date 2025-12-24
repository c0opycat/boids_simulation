//
// Created by arthur on 24/12/2025.
//

#include "AlignementRule.hpp"

#include "Rule.hpp"

const Vec2<float> bd::AlignementRule::apply(const Boid &boid, const Flock &flock) const {
    const Vec2<float> v = boid.getSpeed();
    const DynamicArray<bd::Boid>& boids = flock.getBoids();
    const size_t nb_boids = boids.size();

    Vec2<float> force = {0.0f, 0.0f};
    for (size_t i = 0; i < nb_boids; ++i) {
        force += boids[i].getSpeed() - v;
    }

    return force / static_cast<float>(nb_boids);
}
