//
// Created by lcooper on 05/12/2025.
//

#include "CohesionRule.hpp"

const Vec2<float> bd::CohesionRule::apply(const bd::Boid& boid, const bd::Flock& flock) const {
    const Vec2<float> p = boid.getPosition();
    const DynamicArray<bd::Boid>& boids = flock.getBoids();
    const size_t nb_boids = boids.size();
    size_t nb_neighbors = 0;

    Vec2<float> sum_diff_positions(0.f, 0.f);
    for (std::size_t i = 0; i < nb_boids; i++) {
        if (flock.areNeighbors(boid, boids[i])) {
            sum_diff_positions += boids[i].getPosition() - p;
            nb_neighbors++;
        }
    }

    if (nb_neighbors == 0) {
        return {0.f, 0.f};
    }

    return sum_diff_positions / static_cast<float>(nb_neighbors);
}