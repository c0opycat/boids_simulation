//
// Created by lcooper on 29/11/2025.
//

#include "Settings.hpp"
#include "Utils.hpp"
#include <fstream>
#include <sstream>

namespace bd {
    Settings::Settings() :
    _n(n_def),
    _width(800),
    _height(600),
    _r(50),
    _vmax(4.f),
    _amax(0.1f),
    _dmin(20),
    _wcoh(0.01f),
    _wsep(0.05f),
    _wali(0.125f) {}

    Settings::Settings(const std::string& configFilePath) :
    _n(n_def),
    _width(800),
    _height(600),
    _r(50),
    _vmax(4.f),
    _amax(0.1f),
    _dmin(20),
    _wcoh(0.01f),
    _wsep(0.05f),
    _wali(0.125f) {
        std::ifstream configFile(configFilePath);
        if (!configFile.is_open()) {
            std::cerr << "Could not open file " << configFilePath << std::endl;
            return;
        }
        std::string line;
        while (std::getline(configFile, line)) {
            std::istringstream iss(line);
            std::string key, value;
            if (std::getline(iss, key, '=') && std::getline(iss, value)) {
                try {
                    if (key == "n") setN(std::stoul(value));
                    else if (key == "width") setWidth(std::stoul(value));
                    else if (key == "height") setHeight(std::stoul(value));
                    else if (key == "r") setR(std::stoul(value));
                    else if (key == "vmax") setVMax(std::stof(value));
                    else if (key == "amax") setAMax(std::stof(value));
                    else if (key == "dmin") setDMin(std::stoul(value));
                    else if (key == "wcoh") setWCoh(std::stof(value));
                    else if (key == "wsep") setWSep(std::stof(value));
                    else if (key == "wali") setWAli(std::stof(value));
                } catch (const std::invalid_argument& e) {
                    std::cerr << "Could not parse the value for " << key << std::endl;
                }
            }
        }
        configFile.close();
    }

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
        if (Utils::is_between(nb_boids, n_min, n_max)) {
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
        if (Utils::is_between(percep_radius, r_min, r_max)) {
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
        if (Utils::is_between(min_dist, dmin_min, dmin_max)) {
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

    void Settings::saveToFile(const std::string& configFilePath) const {
        std::ofstream configFile(configFilePath);
        if (!configFile.is_open()) {
            std::cerr << "Could not open file " << configFilePath << std::endl;
        }
        else {
            configFile << "n=" << getN() << "\n";
            configFile << "width=" << getWidth() << "\n";
            configFile << "height=" << getHeight() << "\n";
            configFile << "r=" << getR() << "\n";
            configFile << "vmax=" << getVMax() << "\n";
            configFile << "amax=" << getAMax() << "\n";
            configFile << "dmin=" << getDMin() << "\n";
            configFile << "wcoh=" << getWCoh() << "\n";
            configFile << "wsep=" << getWSep() << "\n";
            configFile << "wali=" << getWAli() << "\n";
        }
    }
}