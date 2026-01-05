/**
 * @file Settings.hpp
 * @brief Contains the declaration of the Settings class and related enums.
 */

#pragma once

#include <iostream>

namespace bd {

    /**
     * @enum Settings_bounds
     * @brief Defines the default values and boundaries for the simulation settings.
     */
    enum Settings_bounds {
        n_def = 50,      ///< Default number of boids.
        n_min = 10,      ///< Minimum number of boids.
        n_max = 200,     ///< Maximum number of boids.
        r_min = 10,      ///< Minimum perception radius.
        r_max = 100,     ///< Maximum perception radius.
        dmin_min = 5,    ///< Minimum distance for separation.
        dmin_max = 50,   ///< Maximum distance for separation.
    };

    /**
     * @class Settings
     * @brief Manages the simulation settings.
     *
     * This class holds all the parameters that control the boids simulation,
     * such as the number of boids, window dimensions, and rule weights.
     * It can be initialized with default values or from a configuration file.
     */
    class Settings {
        size_t _n;      ///< Number of boids.
        size_t _width;  ///< Window's width.
        size_t _height; ///< Window's height.
        size_t _r;      ///< Perception radius for boids.
        float _vmax;    ///< Maximum velocity of a boid.
        float _amax;    ///< Maximum acceleration of a boid.
        size_t _dmin;   ///< Minimum distance for separation.
        float _wcoh;    ///< Weight for the cohesion rule.
        float _wsep;    ///< Weight for the separation rule.
        float _wali;    ///< Weight for the alignment rule.
        float _wtar;    ///< Weight for the targeting rule.

    public:
        /**
         * @brief Default constructor.
         * Initializes settings with default values.
         */
        Settings();

        /**
         * @brief Constructor that loads settings from a file.
         * @param configFilePath Path to the configuration file.
         */
        Settings(const std::string& configFilePath);

        /** @name Getters */
        ///@{
        /**
         * @brief Gets the number of boids.
         * @return The number of boids.
         */
        size_t getN() const;

        /**
         * @brief Gets the width of the simulation window.
         * @return The width of the window.
         */
        size_t getWidth() const;

        /**
         * @brief Gets the height of the simulation window.
         * @return The height of the window.
         */
        size_t getHeight() const;

        /**
         * @brief Gets the perception radius for boids.
         * @return The perception radius.
         */
        size_t getR() const;

        /**
         * @brief Gets the maximum velocity of a boid.
         * @return The maximum velocity.
         */
        float getVMax() const;

        /**
         * @brief Gets the maximum acceleration of a boid.
         * @return The maximum acceleration.
         */
        float getAMax() const;

        /**
         * @brief Gets the minimum distance for the separation rule.
         * @return The minimum distance.
         */
        size_t getDMin() const;

        /**
         * @brief Gets the weight for the cohesion rule.
         * @return The cohesion weight.
         */
        float getWCoh() const;

        /**
         * @brief Gets the weight for the separation rule.
         * @return The separation weight.
         */
        float getWSep() const;

        /**
         * @brief Gets the weight for the alignment rule.
         * @return The alignment weight.
         */
        float getWAli() const;

        /**
         * @brief Gets the weight for the targeting rule.
         * @return The targeting weight.
         */
        float getWTar() const;
        ///@}

        /** @name Setters */
        ///@{
        /**
         * @brief Sets the number of boids.
         * @param nb_boids The new number of boids.
         */
        void setN(const size_t nb_boids);

        /**
         * @brief Sets the width of the simulation window.
         * @param width The new width.
         */
        void setWidth(const size_t width);

        /**
         * @brief Sets the height of the simulation window.
         * @param height The new height.
         */
        void setHeight(const size_t height);

        /**
         * @brief Sets the perception radius for boids.
         * @param percep_radius The new perception radius.
         */
        void setR(const size_t percep_radius);

        /**
         * @brief Sets the maximum velocity of a boid.
         * @param max_vel The new maximum velocity.
         */
        void setVMax(const float max_vel);

        /**
         * @brief Sets the maximum acceleration of a boid.
         * @param max_acc The new maximum acceleration.
         */
        void setAMax(const float max_acc);

        /**
         * @brief Sets the minimum distance for the separation rule.
         * @param min_dist The new minimum distance.
         */
        void setDMin(const size_t min_dist);

        /**
         * @brief Sets the weight for the cohesion rule.
         * @param cohesion_w The new cohesion weight.
         */
        void setWCoh(const float cohesion_w);

        /**
         * @brief Sets the weight for the separation rule.
         * @param separation_w The new separation weight.
         */
        void setWSep(const float separation_w);

        /**
         * @brief Sets the weight for the alignment rule.
         * @param alignment_w The new alignment weight.
         */
        void setWAli(const float alignment_w);

        /**
         * @brief Sets the weight for the targeting rule.
         * @param targeting_w The new targeting weight.
         */
        void setWTar(const float targeting_w);
        ///@}

        /**
         * @brief Saves the current settings to a file.
         * @param configFilePath Path to the configuration file.
         */
        void saveToFile(const std::string& configFilePath) const;

        /**
         * @brief Loads a file into the current settings.
         * @param configFilePath Path to the configuration file.
         */
        void loadFile(const std::string& configFilePath);
    };
}