//
// Created by arthur on 05/01/2026.
//
#pragma once
#include "Rule.hpp"
#include "../containers/Vec2.hpp"

namespace bd {
    class TargetingRule : public Rule {
    private:
        Vec2<float> _target;
    public:
        TargetingRule(Vec2<float> target);
        const Vec2<float> apply(const bd::Boid &boid, const bd::Flock &flock) const override;
    };
}



