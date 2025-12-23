//
// Created by lcooper on 05/12/2025.
//

#pragma once

#include "../containers/Vec2.hpp"
#include "../Boid.hpp"
#include "../Flock.hpp"

namespace bd {
    class Rule {
    public:
        virtual ~Rule() {}
        virtual const Vec2<float> apply(const Boid& boid, const Flock& flock) const = 0;
    };
}
