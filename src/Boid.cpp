//
// Created by arthur on 01/12/2025.
//

#include "Boid.hpp"

Boid::Boid(float x, float y, float speedx, float speedy)
    : _position(Vec2<float>(x, y)), _speed(Vec2<float>(speedx, speedy))
{
}

const Vec2<float> &Boid::getPosition() const {
    return _position;
}

const Vec2<float> &Boid::getSpeed() const {
    return _speed;
}

void Boid::setPosition(const Vec2<float>& newPosition) {
    _position = newPosition;
}
void Boid::setSpeed(const Vec2<float>& newSpeed) {
    _speed = newSpeed;
}

void Boid::addSpeed(const Vec2<float> &newSpeed) {
    _speed += newSpeed;
}

void Boid::UpdatePosition(float dt) {
    _position += _speed * dt;
}




