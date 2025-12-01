//
// Created by arthur on 01/12/2025.
//

#include "gtest/gtest.h"
#include "../src/Boid.hpp"

using namespace bd;

TEST(BoidTest, Constructor) {
    const Boid b(10.f, 20.f, 1.f, -2.f);

    EXPECT_FLOAT_EQ(b.getPosition().getX(), 10.f);
    EXPECT_FLOAT_EQ(b.getPosition().getY(), 20.f);
    EXPECT_FLOAT_EQ(b.getSpeed().getX(), 1.f);
    EXPECT_FLOAT_EQ(b.getSpeed().getY(), -2.f);
}

TEST(BoidTest, SetPosition) {
    Boid b(0.f, 0.f, 0.f, 0.f);
    const Vec2<float> newPos(5.f, 7.f);

    b.setPosition(newPos);

    EXPECT_FLOAT_EQ(b.getPosition().getX(), 5.f);
    EXPECT_FLOAT_EQ(b.getPosition().getY(), 7.f);
}

TEST(BoidTest, SetSpeed) {
    Boid b(0.f, 0.f, 0.f, 0.f);
    const Vec2<float> newSpd(5.f, 7.f);
    b.setSpeed(newSpd);
    EXPECT_FLOAT_EQ(b.getSpeed().getX(), 5.f);
    EXPECT_FLOAT_EQ(b.getSpeed().getY(), 7.f);
}

TEST(BoidTest, AddSpeed) {
    Boid b(0.f, 0.f, 0.f, 0.f);
    const Vec2<float> newSpd(5.f, 7.f);
    b.addSpeed(newSpd);
    EXPECT_FLOAT_EQ(b.getSpeed().getX(), 5.f);
    EXPECT_FLOAT_EQ(b.getSpeed().getY(), 7.f);

    b.addSpeed(newSpd);
    EXPECT_FLOAT_EQ(b.getSpeed().getX(), 10.f);
    EXPECT_FLOAT_EQ(b.getSpeed().getY(), 14.f);
}

TEST(BoidTest, UpdatePosition) {
    Boid b(10.f, 20.f, 2.f, -4.f);

    float dt = 0.5f;

    b.UpdatePosition(dt);
    EXPECT_FLOAT_EQ(b.getPosition().getX(), 11.f);
    EXPECT_FLOAT_EQ(b.getPosition().getY(), 18.f);

    float z_dt = 0.f;
    b.UpdatePosition(z_dt);
    EXPECT_FLOAT_EQ(b.getPosition().getX(), 11.f);
    EXPECT_FLOAT_EQ(b.getPosition().getY(), 18.f);

}

