#include "gtest/gtest.h"
#include "../src/rules/CohesionRule.hpp"
#include "../src/Boid.hpp"
#include "../src/Flock.hpp"
#include "../src/Settings.hpp"

TEST(CohesionRuleTest, ApplyWithNeighbors) {
    bd::Settings settings;
    settings.setR(100.f); 
    bd::Flock flock(settings);
    flock.clearBoids();

    const bd::Boid boid(5.f, 5.f, 0.f, 0.f);
    const bd::Boid neighbor1(10.f, 10.f, 0.f, 0.f);
    const bd::Boid neighbor2(20.f, 20.f, 0.f, 0.f);
    const bd::Boid distantBoid(110.f, 110.f, 0.f, 0.f);

    flock.addBoid(boid);
    flock.addBoid(neighbor1);
    flock.addBoid(neighbor2);
    flock.addBoid(distantBoid);

    const bd::CohesionRule rule;
    const Vec2<float> result = rule.apply(boid, flock);

    const Vec2<float> expected = (neighbor1.getPosition() - boid.getPosition() + neighbor2.getPosition() - boid.getPosition()) / 2.f;
    ASSERT_FLOAT_EQ(result.getX(), expected.getX());
    ASSERT_FLOAT_EQ(result.getY(), expected.getY());
}

TEST(CohesionRuleTest, ApplyWithNoNeighbors) {
    bd::Settings settings;
    settings.setR(10.f);
    bd::Flock flock(settings);
    flock.clearBoids();

    const bd::Boid boid(5.f, 5.f, 0.f, 0.f);
    const bd::Boid distantBoid1(20.f, 20.f, 0.f, 0.f);
    const bd::Boid distantBoid2(30.f, 30.f, 0.f, 0.f);

    flock.addBoid(boid);
    flock.addBoid(distantBoid1);
    flock.addBoid(distantBoid2);

    const bd::CohesionRule rule;
    const Vec2<float> result = rule.apply(boid, flock);

    const Vec2<float> expected = {0.f, 0.f};
    ASSERT_FLOAT_EQ(result.getX(), expected.getX());
    ASSERT_FLOAT_EQ(result.getY(), expected.getY());
}

TEST(CohesionRuleTest, ApplyWithOnlySelf) {
    bd::Settings settings;
    settings.setR(10.f);
    bd::Flock flock(settings);
    flock.clearBoids();

    const bd::Boid boid(5.f, 5.f, 0.f, 0.f);
    flock.addBoid(boid);

    const bd::CohesionRule rule;
    const Vec2<float> result = rule.apply(boid, flock);

    const Vec2<float> expected = {0.f, 0.f};
    ASSERT_FLOAT_EQ(result.getX(), expected.getX());
    ASSERT_FLOAT_EQ(result.getY(), expected.getY());
}