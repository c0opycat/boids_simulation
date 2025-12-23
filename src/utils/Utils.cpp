//
// Created by lcooper on 30/11/2025.
//

#include "Utils.hpp"

namespace Utils {
    std::mt19937 Random::_eng;
    bool Random::_initialised = false;

    void Random::init() {
        if (!_initialised) {
            std::random_device rd;
            _eng.seed(rd());
            _initialised = true;
        }
    }

    float Random::rand_float(const float min, const float max) {
        if (!_initialised) {
            init();
        }
        std::uniform_real_distribution<float> u_dist(min, max);
        return u_dist(_eng);
    }

    size_t Random::rand_sizet(const size_t min, const size_t max) {
        if (!_initialised) {
            init();
        }
        std::uniform_int_distribution<size_t> u_dist(min, max);
        return u_dist(_eng);
    }


    bool is_between(const size_t val, const size_t min, const size_t max) {
        return val >= min && val <= max;
    }

    bool is_between(const float val, const float min, const float max) {
        return val >= min && val <= max;
    }
}
