/**
 * @file SeparationRule.hpp
 * @brief Contains the declaration of the SeparationRule class.
 */


#pragma once
#include "Rule.hpp"

namespace bd {
    /**
     * @class SeparationRule
     * @brief Implements the separation rule for boids.
     *
     * The separation rule steers a boid to avoid crowding its local flockmates.
     * This prevents boids from colliding and keeps them spread out.
     */
    class SeparationRule : public Rule {
    public:
        /**
         * @brief Applies the separation rule to a boid within a flock.
         *
         * Calculates a steering force that moves the `boid` away from its
         * close neighbors in the `flock` to prevent overcrowding.
         *
         * @param boid The boid to which the rule is being applied.
         * @param flock The flock of boids, used to find neighbors.
         * @return A Vec2<float> representing the separation vector.
         */
        const Vec2<float> apply(const Boid& boid, const Flock &flock) const override;

    };
}

