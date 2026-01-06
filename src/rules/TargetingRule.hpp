/**
 * @file TargetingRule.hpp
 * @brief Contains the declaration of the TargetingRule class.
 */


#pragma once
#include "Rule.hpp"
#include "../containers/Vec2.hpp"

namespace bd {
    /**
     * @class TargetingRule
     * @brief A rule that makes boids steer towards a specific target point.
     */
    class TargetingRule : public Rule {
        Vec2<float> _target;
    public:
        /**
         * @brief Constructs a TargetingRule with a specific target.
         * @param target A vector representing the coordinates of the target.
         */
        TargetingRule(const Vec2<float> target);

        /**
         * @brief Calculates the steering force to guide the boid towards the target.
         * @param boid The boid for which to calculate the steering force.
         * @param flock The flock the boid belongs to (used for context, though not directly in this rule).
         * @return The steering force as a Vec2<float>.
         */
        const Vec2<float> apply(const Boid &boid, const Flock &flock) const override;
    };
}



