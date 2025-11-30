//
// Created by lcooper on 29/11/2025.
//

#pragma once

#include <iostream>

namespace bd {
    class Settings {
        size_t _n; // Number of boids
        size_t _width; // Window's width
        size_t _height; // Window's height
        size_t _r; // Perception radius
        float _vmax; // Maximum velocity
        float _amax; // Maximum acceleration
        size_t _dmin; // Minimum distance
        float _wcoh; // Cohesion weight
        float _wsep; // Separation weight
        float _wali; // Alignment weight

    public:
        Settings();
        // Settings(const std::string configFilePath);

        size_t getN() const;
        size_t getWidth() const;
        size_t getHeight() const;
        size_t getR() const;
        float getVMax() const;
        float getAMax() const;
        size_t getDMin() const;
        float getWCoh() const;
        float getWSep() const;
        float getWAli() const;

        void setN(const size_t nb_boids);
        void setWidth(const size_t width);
        void setHeight(const size_t height);
        void setR(const size_t percep_radius);
        void setVMax(const float max_vel);
        void setAMax(const float max_acc);
        void setDMin(const size_t min_dist);
        void setWCoh(const float cohesion_w);
        void setWSep(const float separation_w);
        void setWAli(const float alignment_w);

        void display() const;
    };
}