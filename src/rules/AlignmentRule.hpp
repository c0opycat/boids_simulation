/**
 * @file AlignmentRule.hpp
 * @brief Contains the declaration of the AlignmentRule class.
 */

#pragma once
#include "Rule.hpp"

namespace bd {
    /**
     * @class AlignmentRule
     * @brief Implements the alignment rule for boids.
     *
     * The alignment rule steers a boid towards the average heading of its neighbors.
     * This helps boids to move in roughly the same direction.
     */
    class AlignmentRule : public Rule {
    public:
        /**
         * @brief Applies the alignment rule to a boid within a flock.
         *
         * Calculates a steering force that aligns the `boid` with the average
         * direction of its perceived neighbors in the `flock`.
         *
         * @param boid The boid to which the rule is being applied.
         * @param flock The flock of boids, used to find neighbors.
         * @return A Vec2<float> representing the alignment Vector.
         */
        const Vec2<float> apply(const Boid &boid, const Flock &flock) const override;
    };
}
