//
// Created by lcooper on 30/11/2025.
//

#include "Utils.hpp"

namespace Utils {
    bool is_between(const size_t val, const size_t min, const size_t max) {
        return val >= min && val <= max;
    }

    bool is_between(const float val, const float min, const float max) {
        return val >= min && val <= max;
    }
}