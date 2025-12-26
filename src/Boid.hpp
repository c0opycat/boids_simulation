//
// Created by arthur on 01/12/2025.
//

#pragma once
#include "containers/Vec2.hpp"

/**
 * @namespace bd
 * @brief The main namespace for the boids simulation project.
 */
namespace bd {
    class Boid {
    private:
        Vec2<float> _position;
        Vec2<float> _speed;

    public:
        Boid();
        Boid(float x, float y, float speedx, float speedy);

        const Vec2<float>& getPosition() const;
        const Vec2<float>& getSpeed() const;

        void setPosition(const Vec2<float>& newPosition);
        void setSpeed(const Vec2<float>& newSpeed);

        void UpdatePosition(float dt);
        void addSpeed(const Vec2<float>& newSpeed);

        bool operator==(const Boid& other) const;
        bool operator!=(const Boid& other) const;
    };

    std::ostream& operator<<(std::ostream& os, const Boid& boid);

}


