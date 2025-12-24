//
// Created by arthur on 24/12/2025.
//

#include "SeparationRule.hpp"

const Vec2<float> bd::SeparationRule::apply(const Boid &boid, const Flock &flock) const {
    const Vec2<float> p = boid.getPosition();
    const DynamicArray<bd::Boid>& boids = flock.getBoids();
    const size_t nb_boids = boids.size();

    Vec2<float> force{0.f, 0.f};

    for (size_t i = 0; i < nb_boids; ++i) {
        const Vec2<float> pi = boids[i].getPosition();
        Vec2<float> diff = p - pi;
        float distSqr = diff.getX()*diff.getX() + diff.getY()*diff.getY();

        //pour éviter la division par 0 si c'est le même boid
        if (distSqr > 0) {
            force += diff/distSqr;
        }

    }

    return force;

}
