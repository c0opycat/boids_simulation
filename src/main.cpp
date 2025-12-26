//
// Created by arthur on 28/11/2025.
//

#include "Settings.hpp"
#include "Flock.hpp"
#include "utils/Utils.hpp"
#include <SFML/Graphics.hpp>

const float BOID_SIZE = 5.f;

void drawBoid(sf::RenderWindow& window, const bd::Boid& boid) {
    sf::ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(BOID_SIZE, 0));
    triangle.setPoint(1, sf::Vector2f(-BOID_SIZE / 2, BOID_SIZE / 2));
    triangle.setPoint(2, sf::Vector2f(-BOID_SIZE / 2, -BOID_SIZE / 2));

    triangle.setFillColor(sf::Color(200, 200, 200));
    triangle.setOutlineColor(sf::Color::White);
    triangle.setOutlineThickness(1.f);

    triangle.setPosition(boid.getPosition().getX(), boid.getPosition().getY());
    float angle = atan2(boid.getSpeed().getY(), boid.getSpeed().getX()) * 180.f / M_PI;
    triangle.setRotation(angle);

    window.draw(triangle);
}

int main() {
    Utils::Random::init();

    bd::Settings settings;
    bd::Flock flock(settings);

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

        flock.updateBoids(deltaTime);

        window.clear(sf::Color::Black);

        const DynamicArray<bd::Boid> boids = flock.getBoids();
        for (size_t i = 0; i < boids.size(); ++i) {
            drawBoid(window, boids[i]);
        }

        window.display();

    }

    return 0;
}