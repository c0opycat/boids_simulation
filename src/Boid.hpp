//
// Created by arthur on 01/12/2025.
//

#pragma once
#include "containers/Vec2.hpp"
#include <ostream>

/**
 * @namespace bd
 * @brief The main namespace for the boids simulation project.
 */
namespace bd {
    /**
     * @class Boid
     * @brief Represents a single boid in the simulation.
     *
     * A Boid has a position and a speed, both represented by 2D vectors.
     * It provides methods for updating its state and accessing its properties.
     */
    class Boid {
    private:
        Vec2<float> _position; /**< The current 2D position of the boid. */
        Vec2<float> _speed;    /**< The current 2D speed (velocity) of the boid. */

    public:
        /**
         * @brief Default constructor. Initializes a boid with zero position and speed.
         */
        Boid();

        /**
         * @brief Constructs a boid with specified initial position and speed.
         * @param x The initial x-coordinate of the boid's position.
         * @param y The initial y-coordinate of the boid's position.
         * @param speedx The initial x-component of the boid's speed.
         * @param speedy The initial y-component of the boid's speed.
         */
        Boid(float x, float y, float speedx, float speedy);

        /**
         * @brief Gets the current position of the boid.
         * @return A constant reference to the boid's 2D position vector.
         */
        const Vec2<float>& getPosition() const;

        /**
         * @brief Gets the current speed (velocity) of the boid.
         * @return A constant reference to the boid's 2D speed vector.
         */
        const Vec2<float>& getSpeed() const;

        /**
         * @brief Sets the position of the boid.
         * @param newPosition The new 2D position vector for the boid.
         */
        void setPosition(const Vec2<float>& newPosition);

        /**
         * @brief Sets the speed (velocity) of the boid.
         * @param newSpeed The new 2D speed vector for the boid.
         */
        void setSpeed(const Vec2<float>& newSpeed);

        /**
         * @brief Updates the boid's position based on its current speed and a time delta.
         * @param dt The time step (delta time) for the update.
         */
        void UpdatePosition(float dt);

        /**
         * @brief Adds a new speed vector to the boid's current speed.
         * @param newSpeed The speed vector to add.
         */
        void addSpeed(const Vec2<float>& newSpeed);

        /**
         * @brief Compares two boids for equality.
         * Two boids are considered equal if their positions and speeds are identical.
         * @param other The other boid to compare with.
         * @return True if the boids are equal, false otherwise.
         */
        bool operator==(const Boid& other) const;

        /**
         * @brief Compares two boids for inequality.
         * @param other The other boid to compare with.
         * @return True if the boids are not equal, false otherwise.
         */
        bool operator!=(const Boid& other) const;
    };

    /**
     * @brief Overloads the stream insertion operator to print Boid objects.
     * @param os The output stream.
     * @param boid The Boid object to print.
     * @return A reference to the output stream.
     */
    std::ostream& operator<<(std::ostream& os, const Boid& boid);

}

