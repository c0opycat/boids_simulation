#include "TargetingRule.hpp"

bd::TargetingRule::TargetingRule(const Vec2<float> target) : _target(target) {}

const Vec2<float> bd::TargetingRule::apply(const Boid &boid, const Flock &flock) const {
    return _target - boid.getPosition();
}

