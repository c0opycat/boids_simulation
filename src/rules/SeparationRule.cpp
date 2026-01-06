#include "SeparationRule.hpp"
#include "../utils/Utils.hpp"

const Vec2<float> bd::SeparationRule::apply(const Boid &boid, const Flock &flock) const {
    const Vec2<float> p = boid.getPosition();
    const DynamicArray<Boid>& boids = flock.getBoids();
    const size_t nb_boids = boids.size();

    Vec2<float> force{0.f, 0.f};

    for (size_t i = 0; i < nb_boids; ++i) {
        const Vec2<float> pi = boids[i].getPosition();

        if (flock.areNeighbors(boid, boids[i])) {
            const Vec2<float> diff = p - pi;
            const float distance = diff.length();

            if (distance < flock.getSettings().getDMin()) {
                const float distSqr = distance * distance;
                if (distSqr > 0) {
                    force += diff/distSqr;
                }
            }
        }
    }

    return force;
}