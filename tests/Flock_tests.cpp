#include "gtest/gtest.h"
#include "../src/Flock.hpp"
#include "../src/Settings.hpp"

TEST(FlockTest, DefaultConstructor) {
    bd::Settings settings;
    bd::Flock flock(settings);
    EXPECT_EQ(flock.getBoids().size(), bd::n_def);
    EXPECT_EQ(settings.getN(), bd::n_def);
    EXPECT_EQ(&flock.getSettings(), &settings);
}

TEST(FlockTest, NbBoidsConstructor) {
    const size_t nb_boids = 30;
    bd::Settings settings;
    bd::Flock flock(nb_boids, settings);
    EXPECT_EQ(flock.getBoids().size(), nb_boids);
    EXPECT_EQ(settings.getN(), nb_boids);
    EXPECT_EQ(&flock.getSettings(), &settings);
}

TEST(FlockTest, NbBoidsConstructorPastMin) {
    const size_t nb_boids = 2;
    bd::Settings settings;
    bd::Flock flock(nb_boids, settings);
    EXPECT_EQ(flock.getBoids().size(), bd::n_min);
    EXPECT_EQ(settings.getN(), bd::n_min);
    EXPECT_EQ(&flock.getSettings(), &settings);
}

TEST(FlockTest, AddBoids) {
    const size_t initial_boids = 10;
    const size_t boids_to_add = 5;
    bd::Settings settings;
    bd::Flock flock(initial_boids, settings);
    
    flock.addBoids(boids_to_add);
    
    EXPECT_EQ(flock.getBoids().size(), initial_boids + boids_to_add);
    EXPECT_EQ(settings.getN(), initial_boids + boids_to_add);

    const auto& boids = flock.getBoids();
    for (size_t i = 0; i < boids.size(); i++) {
        const bd::Boid& boid = boids[i];
        EXPECT_GE(boid.getPosition().getX(), -1e-5);
        EXPECT_LE(boid.getPosition().getX(), settings.getWidth());
        EXPECT_GE(boid.getPosition().getY(), -1e-5);
        EXPECT_LE(boid.getPosition().getY(), settings.getHeight());
        EXPECT_LE(boid.getSpeed().length(), settings.getVMax() + 1e-6);
    }
}

TEST(FlockTest, AddBoidsPastMax) {
    const size_t initial_boids = 190;
    const size_t boids_to_add = 20;
    bd::Settings settings;
    bd::Flock flock(initial_boids, settings);

    flock.addBoids(boids_to_add);

    EXPECT_EQ(flock.getBoids().size(), bd::n_max);
    EXPECT_EQ(settings.getN(), bd::n_max);
}

TEST(FlockTest, RemoveBoids) {
    const size_t initial_boids = 20;
    const size_t boids_to_remove = 5;
    bd::Settings settings;
    bd::Flock flock(initial_boids, settings);

    flock.removeBoids(boids_to_remove);

    EXPECT_EQ(flock.getBoids().size(), initial_boids - boids_to_remove);
    EXPECT_EQ(settings.getN(), initial_boids - boids_to_remove);
}

TEST(FlockTest, RemoveBoidsPastMin) {
    const size_t initial_boids = 15;
    const size_t boids_to_remove = 10;
    bd::Settings settings;
    bd::Flock flock(initial_boids, settings);

    flock.removeBoids(boids_to_remove);

    EXPECT_EQ(flock.getBoids().size(), bd::n_min);
    EXPECT_EQ(settings.getN(), bd::n_min);
}

TEST(FlockTest, AddBoid) {
    const size_t initial_boids = 10;
    bd::Settings settings;
    bd::Flock flock(initial_boids, settings);

    bd::Boid new_boid(5.f, 5.f, 0.f, 0.f);
    flock.addBoid(new_boid);

    EXPECT_EQ(flock.getBoids().size(), initial_boids + 1);
    EXPECT_EQ(settings.getN(), initial_boids + 1);
    EXPECT_EQ(flock.getBoids()[initial_boids].getPosition().getX(), 5.f);
    EXPECT_EQ(flock.getBoids()[initial_boids].getPosition().getY(), 5.f);
}

TEST(FlockTest, ClearBoids) {
    const size_t initial_boids = 20;
    bd::Settings settings;
    bd::Flock flock(initial_boids, settings);

    flock.clearBoids();

    const size_t expected = 0;
    EXPECT_EQ(flock.getBoids().size(), expected);
}

TEST(FlockTest, AreNeighbors) {
    bd::Settings settings;
    const bd::Flock flock(settings);

    const bd::Boid b1(0.f, 0.f, 0.f, 0.f);
    const bd::Boid b2(5.f, 0.f, 0.f, 0.f);
    const bd::Boid b3(0.f, 55.f, 0.f, 0.f);
    const bd::Boid b4(0.f, 0.f, 0.f, 0.f);

    EXPECT_TRUE(flock.areNeighbors(b1, b2));
    EXPECT_FALSE(flock.areNeighbors(b1, b3));
    EXPECT_FALSE(flock.areNeighbors(b1, b4)); // Same boid, so not neighbors
}

TEST(FlockTest, UpdateBoidsChangesPositions) {
    bd::Settings settings;
    settings.setVMax(10.f);
    bd::Flock flock(settings);
    flock.clearBoids();

    const bd::Boid initial_boid(0.f, 0.f, 5.f, 0.f);
    flock.addBoid(initial_boid);
    const float deltaTime = 1.0f;

    flock.updateBoids(deltaTime);

    const bd::Boid& updated_boid = flock.getBoids()[0];

    EXPECT_FLOAT_EQ(updated_boid.getPosition().getX(), 5.f);
    EXPECT_FLOAT_EQ(updated_boid.getPosition().getY(), 0.f);
    EXPECT_FLOAT_EQ(updated_boid.getSpeed().getX(), 5.f);
    EXPECT_FLOAT_EQ(updated_boid.getSpeed().getY(), 0.f);
}

    