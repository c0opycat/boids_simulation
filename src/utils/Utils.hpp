/**
 * @file Utils.hpp
 * @brief Contains various utility functions and classes.
 */

#pragma once

#include <cmath>
#include <type_traits>
#include <stdexcept>
#include <random>

/**
 * @brief Checks if a value is close to zero.
 * @tparam T The type of the value.
 * @param val The value to check.
 * @return True if the value is close to zero, false otherwise.
 */
template <typename T>
bool is_close_to_zero(const T val) {
    // T is a float/double
    if (std::is_floating_point_v<T>) {
        // Check if it is close enough to 0 by comparing its absolute value to an epsilon
        return std::abs(val) < 1e-9;
    }
    return val == 0;
}

/**
 * @namespace Utils
 * @brief A namespace for utility functions and classes.
 */
namespace Utils {
    /**
     * @class Random
     * @brief A static class for random number generation.
     */
    class Random {
    public:
        /**
         * @brief Initializes the random number generator.
         */
        static void init();

        /**
         * @brief Generates a random float between min and max.
         * @param min The minimum value.
         * @param max The maximum value.
         * @return A random float.
         */
        static float rand_float(const float min, const float max);

        /**
         * @brief Generates a random size_t between min and max.
         * @param min The minimum value.
         * @param max The maximum value.
         * @return A random size_t.
         */
        static size_t rand_sizet(const size_t min, const size_t max);

    private:
        static std::mt19937 _eng; ///< The random number engine.
        static bool _initialised; ///< True if the engine has been initialized, false otherwise.
    };

    /**
     * @brief Checks if a denominator is close to zero.
     * @tparam T The type of the denominator.
     * @param denominator The denominator to check.
     * @throws std::invalid_argument if the denominator is close to zero.
     */
    template <typename T>
    void check_denominator(const T denominator) {
        if (is_close_to_zero(denominator)) {
            throw std::invalid_argument("Division by zero.");
        }
    }

    /**
     * @brief Checks if a value is between a min and a max value (inclusive).
     * @param val The value to check.
     * @param min The minimum value.
     * @param max The maximum value.
     * @return True if the value is between min and max, false otherwise.
     */
    bool is_between(const size_t val, const size_t min, const size_t max);

    /**
     * @brief Checks if a value is between a min and a max value (inclusive).
     * @param val The value to check.
     * @param min The minimum value.
     * @param max The maximum value.
     * @return True if the value is between min and max, false otherwise.
     */
    bool is_between(const float val, const float min, const float max);
}
