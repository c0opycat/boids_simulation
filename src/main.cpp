//
// Created by arthur on 28/11/2025.
//

#include <iostream>
#include "Boid.hpp"

int main() {
    std::cout << "Hello World!" << std::endl;

    bd::Boid b(10.f, 20.f, 1.f, -2.f);

    std::cout << b << std::endl;

    return 0;
}