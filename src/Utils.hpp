//
// Created by lcooper on 28/11/2025.
//

#pragma once

#include <cmath>
#include <type_traits>
#include <stdexcept>
#include <random>

template <typename T>
bool is_close_to_zero(const T val) {
    // T is a float/double
    if (std::is_floating_point_v<T>) {
        // Check if it is close enough to 0 by comparing its absolute value to an epsilon
        return std::abs(val) < 1e-9;
    }
    return val == 0;
}

namespace Utils {
    // Random number generation
    class Random {
    public:
        static void init();
        static float rand_float(const float min, const float max);
        static size_t rand_sizet(const size_t min, const size_t max);

    private:
        static std::mt19937 _eng;
        static bool _initialised;
    };

    template <typename T>
    void check_denominator(const T denominator) {
        if (is_close_to_zero(denominator)) {
            throw std::invalid_argument("Division by zero.");
        }
    }

    bool is_between(const size_t val, const size_t min, const size_t max);
    bool is_between(const float val, const float min, const float max);
}
