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
#include "Gui/Button.hpp"
#include "Gui/TextBox.hpp"
#include "Gui/Label.hpp"
#include "Gui/Slider.hpp"
#include "containers/DynamicArray.hpp"
#include <string>

/**
 * @struct SliderWidgetPair
 * @brief A simple struct to hold a pair of related Label and Slider widgets.
 */
struct SliderWidgetPair {
    gui::Label* label;   ///< Pointer to the Label widget associated with the slider.
    gui::Slider* slider; ///< Pointer to the Slider widget.
};

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
        Simulation(Flock& flock);

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
         * @brief Updates all UI sliders to reflect the current settings values.
         */
        void updateAllUISliders();

        /**
         * @brief Helper function to create a slider for a float setting.
         * @param name The label for the slider.
         * @param min The minimum value of the setting.
         * @param max The maximum value of the setting.
         * @param initial The initial value of the setting.
         * @param setter A function/lambda to be called when the slider's value changes.
         */
        void addFloatSlider(const std::string& name, float min, float max, float initial, const std::function<void(float)>& setter);

        /**
         * @brief Helper function to create a slider for a size_t setting.
         * @param name The label for the slider.
         * @param min The minimum value of the setting.
         * @param max The maximum value of the setting.
         * @param initial The initial value of the setting.
         * @param setter A function/lambda to be called when the slider's value changes.
         */
        void addIntSlider(const std::string& name, size_t min, size_t max, size_t initial, const std::function<void(size_t)>& setter);

        const float BOID_SIZE = 2.f; ///< Visual size of the boids.
        Flock& _flock;           ///< Reference to the flock being simulated.
        sf::RenderWindow _window;    ///< The main application window.
        gui::Menu* _menu;            ///< The root UI element containing the settings controls.

        /** @name Pointers to UI elements */
        ///@{
        gui::Label* _n_label;
        gui::Slider* _n_slider;
        gui::TextBox* _configTextBox;
        DynamicArray<SliderWidgetPair> _floatSliders;
        DynamicArray<SliderWidgetPair> _intSliders;
        DynamicArray<std::string> _floatSliderNames;
        DynamicArray<std::string> _intSliderNames;
        ///@}
    };
}
