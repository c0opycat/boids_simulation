//
// Created by lcooper on 03/12/2025.
//

#include "Flock.hpp"
#include "utils/Utils.hpp"
#include "rules/AlignmentRule.hpp"
#include "rules/CohesionRule.hpp"
#include "rules/SeparationRule.hpp"
#include <cmath>

bd::Flock::Flock(Settings& settings) : _settings(settings) {
    _boids = DynamicArray<Boid>();
    addBoids(_settings.getN());
}

bd::Flock::Flock(const size_t nb_boids, Settings& settings) : _settings(settings) {
    _boids = DynamicArray<Boid>();
    if (nb_boids < n_min) {
        addBoids(n_min);
    }
    else addBoids(nb_boids);
}

const DynamicArray<bd::Boid>& bd::Flock::getBoids() const {
    return _boids;
}

bd::Settings& bd::Flock::getSettings() const {
    return _settings;
}

void bd::Flock::addBoids(const size_t count) {
    size_t real_count = count;
    const size_t nb_boids = _boids.size();
    if (nb_boids + count > n_max) {
        real_count = n_max - nb_boids;
    }
    for (size_t i = 0; i < real_count; i++) {
        const float px = Utils::Random::rand_float(0.f, _settings.getWidth());
        const float py = Utils::Random::rand_float(0.f, _settings.getHeight());
        float sx = Utils::Random::rand_float(-_settings.getVMax(), _settings.getVMax());
        float sy = Utils::Random::rand_float(-_settings.getVMax(), _settings.getVMax());
        float speed = std::hypot(sx, sy);
        if (speed > _settings.getVMax()) {
            sx = sx / speed * _settings.getVMax();
            sy = sy / speed * _settings.getVMax();
        }
        Boid b(px, py, sx, sy);
        _boids.push_back(b);
    }
    _settings.setN(_boids.size());
}

void bd::Flock::addBoid(const Boid& boid) {
    if (_boids.size() < n_max) {
        _boids.push_back(boid);
        _settings.setN(_boids.size());
    }
}

void bd::Flock::removeBoids(const size_t count) {
    size_t real_count = count;
    const size_t nb_boids = _settings.getN();
    if (nb_boids - count < n_min) {
        real_count = nb_boids - n_min;
    }
    for (size_t i = 0; i < real_count; i++) {
        _boids.pop_back();
    }
    _settings.setN(_boids.size());
}

void bd::Flock::updateBoids(const float deltaTime) {
    const CohesionRule cr;
    const SeparationRule sr;
    const AlignmentRule ar;
    for (size_t i = 0; i < _boids.size(); i++) {
        Vec2<float> correction =
            cr.apply(_boids[i], *this) * _settings.getWCoh() +
                sr.apply(_boids[i], *this) * _settings.getWSep() +
                    ar.apply(_boids[i], *this) * _settings.getWAli();

        correction = correction.normalize_max(_settings.getAMax());

        Vec2<float> speed = _boids[i].getSpeed() + correction;

        speed = speed.normalize_max(_settings.getVMax());

        _boids[i].setPosition(_boids[i].getPosition() + speed * deltaTime);

        Vec2<float> pos = _boids[i].getPosition();

        if (pos.getX() < 0) {
            pos.setX(0);
            speed.setX(-speed.getX());
        } else if (pos.getX() > _settings.getWidth()) {
            pos.setX(_settings.getWidth());
            speed.setX(-speed.getX());
        }

        if (pos.getY() < 0) {
            pos.setY(0);
            speed.setY(-speed.getY());
        } else if (pos.getY() > _settings.getHeight()) {
            pos.setY(_settings.getHeight());
            speed.setY(-speed.getY());
        }

        _boids[i].setPosition(pos);
        _boids[i].setSpeed(speed);
    }
}

void bd::Flock::clearBoids() {
    _boids = DynamicArray<Boid>();
}

bool bd::Flock::areNeighbors(const Boid &b1, const Boid &b2) const {
    const Vec2<float> diff = b2.getPosition() - b1.getPosition();
    const float distance = diff.length();

    return b1 != b2 && distance < static_cast<float>(_settings.getR());
}

bool bd::Flock::isInBounds(const Boid &boid) const {
    if ((boid.getPosition().getX() < 0
        || boid.getPosition().getX() > _settings.getWidth())
         && ( boid.getPosition().getY() < 0  || boid.getPosition().getY() > _settings.getHeight())) {
        return false;
    }else {
        return true;
    }
}



