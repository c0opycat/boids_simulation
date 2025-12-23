#include "gtest/gtest.h"
#include "../src/rules/CohesionRule.hpp"
#include "../src/Boid.hpp"
#include "../src/Flock.hpp"
#include "../src/Settings.hpp" // Include Settings.hpp

TEST(CohesionRuleTest, Apply) {
    bd::Settings settings;
    bd::Flock flock(settings);
    flock.clearBoids();

    const bd::Boid boid1(10.f, 10.f, 0.f, 0.f);
    const bd::Boid boid2(20.f, 20.f, 0.f, 0.f);
    const bd::Boid boid3(30.f, 30.f, 0.f, 0.f);

    flock.addBoid(boid1);
    flock.addBoid(boid2);
    flock.addBoid(boid3);

    const bd::Boid boid(5.f, 5.f, 0.f, 0.f);

    const bd::CohesionRule rule;
    const Vec2<float> result = rule.apply(boid, flock);

    const Vec2<float> expected = {15.f, 15.f};

    ASSERT_FLOAT_EQ(result.getX(), expected.getX());
    ASSERT_FLOAT_EQ(result.getY(), expected.getY());
}
