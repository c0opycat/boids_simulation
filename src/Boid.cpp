#include "Boid.hpp"

using namespace bd;

Boid::Boid() : _position(Vec2<float>(0.f,0.f)), _speed(Vec2<float>(0.f,0.f)) {}

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

bool Boid::operator==(const Boid& other) const {
    return _position == other._position && _speed == other._speed;
}

bool Boid::operator!=(const Boid& other) const {
    return !(*this == other);
}

std::ostream &bd::operator<<(std::ostream& os, const Boid& boid) {
    return os << "Position : " <<boid.getPosition() << " / vitesse : " << boid.getSpeed() << std::endl;
}




