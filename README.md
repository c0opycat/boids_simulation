# Boids Simulation

## Overview

This project is part of a university course for Object-Oriented Conception. It implements a 2D boids simulation, demonstrating emergent flocking behavior based on a few simple rules. Boids are autonomous agents that follow three basic rules: separation, cohesion, and alignment. They can also follow a target on the screen.

## Requirements

To build and run this project, you will need:
*   A C++17 compatible compiler (e.g., g++).
*   SFML (Simple and Fast Multimedia Library) development libraries (version 2.5 or higher).
*   Doxygen (for generating API documentation).
*   Google Test (for running unit tests, included as a submodule).

## Building and Running

To build the project and run the simulation, navigate to the project root and run:
```bash
make
```

## Generating Documentation

To generate the Doxygen API documentation, run:
```bash
make docs
```
The documentation will be generated in the `docs/html` directory. Open `docs/html/index.html` or `docs.html` in your web browser.

## Project Structure

-   `src/`: Contains the main source code for the simulation.
    -   `Boid.hpp`, `Boid.cpp`: Defines the Boid class.
    -   `Flock.hpp`, `Flock.cpp`: Manages the collection of boids.
    -   `Settings.hpp`, `Settings.cpp`: Handles simulation parameters.
    -   `Simulation.hpp`, `Simulation.cpp`: Manages the boids simulation.
    -   `main.cpp`: The entry point of the application.
    -   `containers/`: Generic data structures.
        -   `DynamicArray.hpp`: Custom dynamic array.
        -   `Vec2.hpp`: 2D vector class.
    -   `rules/`: Implementations of boid behavior rules.
        -   `Rule.hpp`: Abstract base class for rules.
        -   `CohesionRule.hpp`, `CohesionRule.cpp`: Cohesion rule implementation.
        -   `AlignmentRule.hpp`, `AlignmentRule.cpp`: Alignment rule implementation.
        -   `SeparationRule.hpp`, `SeparationRule.cpp`: Separation rule implementation.
        -   `TargetingRule.hpp`, `TargetingRule.cpp`: Targeting rule implementation.
    -   `utils/`: Utility functions.
        -   `Utils.hpp`, `Utils.cpp`: General utility functions.
-   `lib/`: External libraries.
    -   `sfml-widgets/`: A custom GUI library used for interactive UI components in the simulation.
-   `tests/`: Contains unit tests for various components.
-   `Makefile`: Project Makefile for building, running, and generating docs.
-   `Doxyfile`: Doxygen configuration file.
-   `docs.html`: A link to the documentation.
