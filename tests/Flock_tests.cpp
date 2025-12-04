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
        EXPECT_LE(boid.getSpeed().length(), settings.getVMax());
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