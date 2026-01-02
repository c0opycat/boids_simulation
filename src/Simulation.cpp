#include "Simulation.hpp"
#include <string>
#include <functional>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <cmath>

// Helper to convert a float to a string with a specific precision
std::string to_string_with_precision(const float value, int precision = 3) {
    std::ostringstream out;
    out << std::fixed << std::setprecision(precision) << value;
    return out.str();
}

const float SLIDER_LENGTH = 150.f;
const std::string SAVE_DIR = "save/";

bd::Simulation::Simulation(Flock &flock) :
    _flock(flock),
    _window(sf::VideoMode(flock.getSettings().getWidth(), flock.getSettings().getHeight()), "Boids simulation"),
    _menu(nullptr),
    _n_label(nullptr),
    _n_slider(nullptr),
    _configTextBox(nullptr)
{
    _floatSliders = DynamicArray<SliderWidgetPair>();
    _intSliders = DynamicArray<SliderWidgetPair>();
    _floatSliderNames = DynamicArray<std::string>();
    _intSliderNames = DynamicArray<std::string>();
    _window.setFramerateLimit(60);
    if (!gui::Theme::loadFont("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf")) {
        std::cerr << "Failed to load font for UI!" << std::endl;
    }
    initUI();
}

bd::Simulation::~Simulation()
{
    delete _menu; // The menu is responsible for deleting its children widgets
}

void bd::Simulation::addFloatSlider(const std::string& name, const float min, const float max, const float initial, const std::function<void(float)>& setter)
{
    gui::Label* label = new gui::Label(name + ": " + to_string_with_precision(initial));
    gui::Slider* slider = new gui::Slider(SLIDER_LENGTH);
    label->setFillColor(sf::Color::White);
    slider->setStep(1);
    const float value = (initial - min) * 100.f / (max - min);
    slider->setValue(static_cast<int>(value));
    slider->setCallback([label, slider, name, min, max, setter] {
        const float newValue = static_cast<float>(slider->getValue()) * (max - min) / 100.f + min;
        setter(newValue);
        label->setText(name + ": " + to_string_with_precision(newValue));
    });
    _menu->add(label);
    _menu->add(slider);
    _floatSliders.push_back({label, slider});
    _floatSliderNames.push_back(name);
}

void bd::Simulation::addIntSlider(const std::string& name, const size_t min, const size_t max, const size_t initial, const std::function<void(size_t)>& setter)
{
    gui::Label* label = new gui::Label(name + ": " + std::to_string(initial));
    gui::Slider* slider = new gui::Slider(SLIDER_LENGTH);
    label->setFillColor(sf::Color::White);
    slider->setStep(1);
    const size_t value = (initial - min) * 100 / (max - min);
    slider->setValue(static_cast<int>(value));
    slider->setCallback([label, slider, name, min, max, setter] {
        const size_t newValue = static_cast<size_t>(round(static_cast<float>(slider->getValue()) * static_cast<float>(max - min) / 100.f + min));
        setter(newValue);
        label->setText(name + ": " + std::to_string(newValue));
    });
    _menu->add(label);
    _menu->add(slider);
    _intSliders.push_back({label, slider});
    _intSliderNames.push_back(name);
}

void bd::Simulation::updateAllUISliders()
{
    Settings& settings = _flock.getSettings();

    // Update Boid Count slider
    _n_label->setText("Boids: " + std::to_string(settings.getN()));
    const size_t n_value = (settings.getN() - n_min) * 100 / (n_max - n_min);
    _n_slider->setValue(static_cast<int>(n_value));

    // Update other int sliders
    const size_t r_val = (settings.getR() - r_min) * 100 / (r_max - r_min);
    _intSliders[0].slider->setValue(static_cast<int>(r_val));
    _intSliders[0].label->setText(_intSliderNames[0] + ": " + std::to_string(settings.getR()));

    const size_t dmin_val = (settings.getDMin() - dmin_min) * 100 / (dmin_max - dmin_min);
    _intSliders[1].slider->setValue(static_cast<int>(dmin_val));
    _intSliders[1].label->setText(_intSliderNames[1] + ": " + std::to_string(settings.getDMin()));

    // Update float sliders
    const float wcoh_val = settings.getWCoh() * 100;
    _floatSliders[0].slider->setValue(static_cast<int>(wcoh_val));
    _floatSliders[0].label->setText(_floatSliderNames[0] + ": " + to_string_with_precision(settings.getWCoh()));

    const float wsep_val = settings.getWSep() * 100;
    _floatSliders[1].slider->setValue(static_cast<int>(wsep_val));
    _floatSliders[1].label->setText(_floatSliderNames[1] + ": " + to_string_with_precision(settings.getWSep()));

    const float wali_val = settings.getWAli() * 100;
    _floatSliders[2].slider->setValue(static_cast<int>(wali_val));
    _floatSliders[2].label->setText(_floatSliderNames[2] + ": " + to_string_with_precision(settings.getWAli()));
}


void bd::Simulation::initUI() {
    Settings& settings = _flock.getSettings();

    _menu = new gui::Menu(_window);
    _menu->setPosition(10, 10);

    // Save/Load file management
    _configTextBox = new gui::TextBox();
    _configTextBox->setText("config_1.txt");
    _menu->add(_configTextBox);

    gui::Button* loadButton = new gui::Button("Load");
    loadButton->setCallback([this] {
        const std::string filename = _configTextBox->getText();
        if (!filename.empty()) {
            const size_t current_boids = _flock.getSettings().getN();
            _flock.getSettings().loadFile(SAVE_DIR + filename);
            const size_t new_nb_boids = _flock.getSettings().getN();

            if (new_nb_boids > current_boids) {
                _flock.addBoids(new_nb_boids - current_boids);
            } else if (new_nb_boids < current_boids) {
                _flock.removeBoids(current_boids - new_nb_boids);
            }
            updateAllUISliders();
        }
    });
    _menu->add(loadButton);

    gui::Button* saveButton = new gui::Button("Save");
    saveButton->setCallback([this] {
        const std::string filename = _configTextBox->getText();
        if (!filename.empty()) {
            _flock.getSettings().saveToFile(SAVE_DIR + filename);
        }
    });
    _menu->add(saveButton);

    // Boid Count (N)
    _n_label = new gui::Label("Boids: " + std::to_string(settings.getN()));
    _n_slider = new gui::Slider(SLIDER_LENGTH);
    _n_label->setFillColor(sf::Color::White);
    _n_slider->setStep(1);
    const size_t value = (settings.getN() - n_min) * 100 / (n_max - n_min);
    _n_slider->setValue(static_cast<int>(value));
    _n_slider->setCallback([this] {
        Settings& s = _flock.getSettings();
        const size_t new_nb_boids = static_cast<size_t>(round(static_cast<double>(_n_slider->getValue()) * static_cast<double>(n_max - n_min) / 100.f + static_cast<double>(n_min)));
        const size_t current_boids = s.getN();
        if (new_nb_boids != current_boids) {
            if (new_nb_boids > current_boids) {
                _flock.addBoids(new_nb_boids - current_boids);
            } else {
                _flock.removeBoids(current_boids - new_nb_boids);
            }
        }
        _n_label->setText("Boids: " + std::to_string(s.getN()));
    });
    _menu->add(_n_label);
    _menu->add(_n_slider);

    // Other sliders
    addIntSlider("Perception radius", r_min, r_max, settings.getR(), [&](const size_t val){ _flock.getSettings().setR(val); });
    addIntSlider("Minimal distance", dmin_min, dmin_max, settings.getDMin(), [&](const size_t val){ _flock.getSettings().setDMin(val); });
    addFloatSlider("Cohesion weight", 0.f, 1.f, settings.getWCoh(), [&](const float val){ _flock.getSettings().setWCoh(val); });
    addFloatSlider("Separation weight", 0.f, 1.f, settings.getWSep(), [&](const float val){ _flock.getSettings().setWSep(val); });
    addFloatSlider("Alignment weight", 0.f, 1.f, settings.getWAli(), [&](const float val){ _flock.getSettings().setWAli(val); });
}

void bd::Simulation::drawBoid(const bd::Boid& boid) {
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

    _window.draw(triangle);
}

void bd::Simulation::run() {
    sf::Clock clock;

    while (_window.isOpen()) {
        sf::Event event;
        while (_window.pollEvent(event)) {
            _menu->onEvent(event);
            if (event.type == sf::Event::Closed) {
                _window.close();
            }
        }

        const float deltaTime = clock.restart().asSeconds() * 100;
        _flock.updateBoids(deltaTime);

        _window.clear(sf::Color::Black);

        const DynamicArray<bd::Boid>& boids = _flock.getBoids();
        for (size_t i = 0; i < boids.size(); ++i) {
            drawBoid(boids[i]);
        }

        _window.draw(*_menu);

        _window.display();
    }
}