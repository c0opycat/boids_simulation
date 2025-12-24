//
// Created by arthur on 24/12/2025.
//


#pragma once
#include "Rule.hpp"

namespace bd {
    class AlignementRule : public Rule {
    public:
        const Vec2<float> apply(const Boid &boid, const Flock &flock) const override;
    };
}
