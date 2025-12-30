//
// Created by lcooper on 30/12/2025.
//

#include "Simulation.hpp"

bd::Simulation::Simulation(Flock &flock) : _flock(flock) {}

void bd::Simulation::drawBoid(sf::RenderWindow& window, const bd::Boid& boid) const {
    sf::ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(BOID_SIZE, 0));
    triangle.setPoint(1, sf::Vector2f(-BOID_SIZE / 2, BOID_SIZE / 2));
    triangle.setPoint(2, sf::Vector2f(-BOID_SIZE / 2, -BOID_SIZE / 2));

    triangle.setFillColor(sf::Color(200, 200, 200));
    triangle.setOutlineColor(sf::Color::White);
    triangle.setOutlineThickness(1.f);

    triangle.setPosition(boid.getPosition().getX(), boid.getPosition().getY());
    const float angle = atan2(boid.getSpeed().getY(), boid.getSpeed().getX()) * 180.f / M_PI;
    triangle.setRotation(angle);

    window.draw(triangle);
}

void bd::Simulation::run() const {
    const Settings& settings = _flock.getSettings();
    sf::RenderWindow window(sf::VideoMode(settings.getWidth(), settings.getHeight()), "Boids simulation");
    window.setFramerateLimit(60);

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        float deltaTime = clock.restart().asSeconds() * 100;

        _flock.updateBoids(deltaTime);

        window.clear(sf::Color::Black);

        const DynamicArray<bd::Boid> boids = _flock.getBoids();
        for (size_t i = 0; i < boids.size(); ++i) {
            drawBoid(window, boids[i]);
        }

        window.display();
    }
}
