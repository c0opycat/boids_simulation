#include "AlignmentRule.hpp"

#include "Rule.hpp"

const Vec2<float> bd::AlignmentRule::apply(const Boid &boid, const Flock &flock) const {
    const Vec2<float> v = boid.getSpeed();
    const DynamicArray<Boid>& boids = flock.getBoids();
    const size_t nb_boids = boids.size();
    size_t nb_neighbors = 0;

    Vec2<float> force = {0.0f, 0.0f};
    for (size_t i = 0; i < nb_boids; ++i) {
        if (flock.areNeighbors(boid, boids[i])) {
            force += boids[i].getSpeed() - v;
            nb_neighbors++;
        }
    }

    if (nb_neighbors == 0) {
        return {0.f, 0.f};
    }

    return force / static_cast<float>(nb_neighbors);
}
