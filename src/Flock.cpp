//
// Created by lcooper on 03/12/2025.
//

#include "Flock.hpp"
#include "utils/Utils.hpp"
#include "rules/AlignementRule.hpp"
#include "rules/CohesionRule.hpp"
#include "rules/SeparationRule.hpp"
#include <cmath>

bd::Flock::Flock(Settings& settings) : _settings(settings) {
    _boids = DynamicArray<Boid>();
    addBoids(n_def);
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
        float px = Utils::Random::rand_float(0.f, _settings.getWidth());
        float py = Utils::Random::rand_float(0.f, _settings.getHeight());
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
    const AlignementRule ar;
    for (size_t i = 0; i < _boids.size(); i++) {
        Vec2<float> speed = _boids[i].getSpeed();
        const Vec2<float> correction =
            cr.apply(_boids[i], *this) * _settings.getWCoh() +
                sr.apply(_boids[i], *this) * _settings.getWSep() +
                    ar.apply(_boids[i], *this) * _settings.getWAli();
        Vec2<float> newSpeed = speed + correction;

        _boids[i].setSpeed(newSpeed.normalize_max(_settings.getVMax()));
        _boids[i].setPosition(_boids[i].getPosition() + _boids[i].getSpeed() * deltaTime);
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



