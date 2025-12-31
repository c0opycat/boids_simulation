/**
 * @file Simulation.hpp
 * @brief Contains the declaration of the Simulation class.
 */

#pragma once

#include <SFML/Graphics.hpp>
#include <functional>
#include "Boid.hpp"
#include "Flock.hpp"
#include "Gui/Menu.hpp"

namespace bd {
    /**
     * @class Simulation
     * @brief Manages the main application loop, rendering, and UI for the boids simulation.
     */
    class Simulation {
    public:
        /**
         * @brief Constructs the main simulation environment.
         * @param flock A reference to the Flock object to be simulated and controlled.
         */
        Simulation(bd::Flock& flock);

        /**
         * @brief Destructor, cleans up dynamically allocated UI components.
         */
        ~Simulation();

        /**
         * @brief Starts and runs the main application loop.
         */
        void run();

    private:
        /**
         * @brief Draws a single boid to the window.
         * @param boid The boid to draw.
         */
        void drawBoid(const Boid& boid);

        /**
         * @brief Initializes all user interface components.
         */
        void initUI();

        /**
         * @brief Helper function to create a slider for a float setting.
         * @param name The label for the slider.
         * @param min The minimum value of the setting's range.
         * @param max The maximum value of the setting's range.
         * @param initial The initial value of the setting.
         * @param setter A function/lambda to be called when the slider's value changes.
         */
        void addFloatSlider(const std::string& name, const float min, const float max, const float initial, const std::function<void(float)>& setter);

        /**
         * @brief Helper function to create a slider for a size_t setting.
         * @param name The label for the slider.
         * @param min The minimum value of the setting's range.
         * @param max The maximum value of the setting's range.
         * @param initial The initial value of the setting.
         * @param setter A function/lambda to be called when the slider's value changes.
         */
        void addIntSlider(const std::string& name, const size_t min, const size_t max, const size_t initial, const std::function<void(size_t)>& setter);

        const float BOID_SIZE = 5.f; ///< Visual size of the boids.
        bd::Flock& _flock;           ///< Reference to the flock being simulated.
        sf::RenderWindow _window;    ///< The main application window.
        gui::Menu* _menu;            ///< The root UI element containing the settings controls.
    };
}