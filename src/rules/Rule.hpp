/**
 * @file Rule.hpp
 * @brief Contains the declaration of the Rule abstract base class.
 */

#pragma once

#include "../containers/Vec2.hpp"
#include "../Boid.hpp"
#include "../Flock.hpp"

namespace bd {
    /**
     * @class Rule
     * @brief An abstract base class for all boid behavior rules.
     */
    class Rule {
    public:
        /**
         * @brief Virtual destructor.
         */
        virtual ~Rule() {}

        /**
         * @brief Applies the rule to a boid.
         * It calculates a velocity adjustment vector based on the rule's logic.
         *
         * @param boid The boid to which the rule is being applied.
         * @param flock The flock of boids, providing context for the rule.
         * @return A Vec2<float> representing the calculated velocity adjustment.
         */
        virtual const Vec2<float> apply(const Boid& boid, const Flock& flock) const = 0;
    };
}
