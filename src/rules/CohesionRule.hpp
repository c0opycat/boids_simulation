/**
 * @file CohesionRule.hpp
 * @brief Contains the declaration of the CohesionRule class.
 */

#pragma once

#include "Rule.hpp"

namespace bd {
    /**
     * @class CohesionRule
     * @brief Implements the cohesion rule for boids.
     *
     * This rule makes boids steer towards their neighbors.
     */
    class CohesionRule : public Rule {
    public:
        /**
         * @brief Applies the cohesion rule to a boid.
         *
         * Calculates the vector pointing from the boid's current position to the
         * center of mass of the flock.
         *
         * @param boid The boid to which the rule is being applied.
         * @param flock The flock of boids.
         * @return A Vec2<float> representing the cohesion vector.
         */
        const Vec2<float> apply(const Boid& boid, const Flock& flock) const override;
    };
}
