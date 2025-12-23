/**
 * @file Flock.hpp
 * @brief Contains the declaration of the Flock class.
 */

#pragma once

#include "containers/DynamicArray.hpp"
#include "Boid.hpp"
#include "Settings.hpp"

namespace bd {
    /**
     * @class Flock
     * @brief Manages a collection of Boid objects.
     */
    class Flock {
        DynamicArray<Boid> _boids; ///< The dynamic array holding all boid objects.
        Settings& _settings;       ///< Reference to the simulation settings.
    public:
        /**
         * @brief Constructs a Flock with default number of boids.
         * @param settings Reference to the simulation settings.
         */
        Flock(Settings& settings);

        /**
         * @brief Constructs a Flock with a specified number of boids.
         * @param nb_boids The initial number of boids in the flock.
         * @param settings Reference to the simulation settings.
         */
        Flock(const size_t nb_boids, Settings& settings);

        /// @name Getters
        ///@{
        /**
         * @brief Gets a constant reference to the dynamic array of boids.
         * @return A const reference to the _boids DynamicArray.
         */
        const DynamicArray<Boid>& getBoids() const;

        /**
         * @brief Gets a reference to the simulation settings.
         * @return A reference to the Settings object.
         */
        Settings& getSettings() const;
        ///@}

        /**
         * @brief Adds a specified number of randomly initialized boids to the flock.
         * @param count The number of boids to add.
         */
        void addBoids(const size_t count);

        /**
         * @brief Adds a single boid to the flock.
         * @param boid The boid object to add.
         */
        void addBoid(const Boid& boid);

        /**
         * @brief Removes a specified number of boids from the end of the flock.
         * @param count The number of boids to remove.
         */
        void removeBoids(const size_t count);

        /**
         * @brief Clears all boids from the flock.
         */
        void clearBoids();

        /**
         * @brief Updates the state of all boids in the flock.
         * @param deltaTime The time elapsed since the last update.
         */
        void updateBoids(const float deltaTime);
    };
}
