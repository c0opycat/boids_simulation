//
// Created by lcooper on 05/12/2025.
//

#pragma once

#include "Rule.hpp"

namespace bd {
    class CohesionRule : public Rule {
    public:
        const Vec2<float> apply(const Boid& boid, const Flock& flock) const override;
    };
}
