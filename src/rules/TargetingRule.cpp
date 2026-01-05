//
// Created by arthur on 05/01/2026.
//

#include "TargetingRule.hpp"

bd::TargetingRule::TargetingRule(Vec2<float> target) : _target(target) {}

const Vec2<float> bd::TargetingRule::apply(const bd::Boid &boid, const bd::Flock &flock) const {
    return _target - boid.getPosition();
}

