//
// Created by arthur on 28/11/2025.
//

#include <iostream>
#include "Settings.hpp"
#include "Boid.hpp"
#include "Utils.hpp"

int main() {
    Utils::Random::init();
    std::cout << "Hello World!" << std::endl;
    bd::Settings s;
    s.display();

    bd::Boid b(10.f, 20.f, 1.f, -2.f);

    std::cout << b << std::endl;

    return 0;
}