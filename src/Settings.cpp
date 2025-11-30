//
// Created by lcooper on 29/11/2025.
//

#include "Settings.hpp"
#include "Utils.hpp"

namespace bd {
    Settings::Settings() :
    _n(50),
    _width(800),
    _height(600),
    _r(50),
    _vmax(4.f),
    _amax(0.1f),
    _dmin(20),
    _wcoh(0.01f),
    _wsep(0.05f),
    _wali(0.125f) {}

    size_t Settings::getN() const {
        return _n;
    }

    size_t Settings::getWidth() const {
        return _width;
    }

    size_t Settings::getHeight() const {
        return _height;
    }

    size_t Settings::getR() const {
        return _r;
    }

    float Settings::getVMax() const {
        return _vmax;
    }

    float Settings::getAMax() const {
        return _amax;
    }

    size_t Settings::getDMin() const {
        return _dmin;
    }

    float Settings::getWCoh() const {
        return _wcoh;
    }

    float Settings::getWSep() const {
        return _wsep;
    }

    float Settings::getWAli() const {
        return _wali;
    }

    void Settings::setN(const size_t nb_boids) {
        if (Utils::is_between(nb_boids, 10, 200)) {
            _n = nb_boids;
        }
    }

    void Settings::setWidth(const size_t width) {
        _width = width;
    }

    void Settings::setHeight(const size_t height) {
        _height = height;
    }

    void Settings::setR(const size_t percep_radius) {
        if (Utils::is_between(percep_radius, 10, 100)) {
            _r = percep_radius;
        }
    }

    void Settings::setVMax(const float max_vel) {
        _vmax = max_vel;
    }

    void Settings::setAMax(const float max_acc) {
        _amax = max_acc;
    }

    void Settings::setDMin(const size_t min_dist) {
        if (Utils::is_between(min_dist, 5, 50)) {
            _dmin = min_dist;
        }
    }

    void Settings::setWCoh(const float cohesion_w) {
        if (Utils::is_between(cohesion_w, 0.f, 1.f)) {
            _wcoh = cohesion_w;
        }
    }

    void Settings::setWSep(const float separation_w) {
        if (Utils::is_between(separation_w, 0.f, 1.f)) {
            _wsep = separation_w;
        }
    }

    void Settings::setWAli(const float alignment_w) {
        if (Utils::is_between(alignment_w, 0.f, 1.f)) {
            _wali = alignment_w;
        }
    }

    void Settings::display() const {
        std::cout << "Settings:" << std::endl;
        std::cout << "  Number of boids (N): " << _n << std::endl;
        std::cout << "  Window Width: " << _width << std::endl;
        std::cout << "  Window Height: " << _height << std::endl;
        std::cout << "  Perception Radius (R): " << _r << std::endl;
        std::cout << "  Maximum Velocity (VMax): " << _vmax << std::endl;
        std::cout << "  Maximum Acceleration (AMax): " << _amax << std::endl;
        std::cout << "  Minimum Distance (DMin): " << _dmin << std::endl;
        std::cout << "  Cohesion Weight (WCoh): " << _wcoh << std::endl;
        std::cout << "  Separation Weight (WSep): " << _wsep << std::endl;
        std::cout << "  Alignment Weight (WAli): " << _wali << std::endl;
    }
}