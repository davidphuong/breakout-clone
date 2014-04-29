#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "PS3Controller.h"

void process_input();
void update();
void render();

// sf::RenderWindow main_window(sf::VideoMode(200, 200), "Breakout!");
sf::RenderWindow main_window(sf::VideoMode(1024, 768), "Breakout!");

int main(int argc, char* argv[]) {

    // Check that joystick #0 is connected.
    if (sf::Joystick::isConnected(0)) {
        std::cout << "Joystick is connected." << std::endl;
        while (main_window.isOpen()) {
            process_input();
            update();
            render();
        }
    } else {
        std::cout << "Joystick is NOT connected." << std::endl;
    }

    return 0;
}

void process_input() {
    sf::Event event;
    if (main_window.pollEvent(event)) {

        if (event.type == sf::Event::Closed) {
            main_window.close();
        } else if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape) {
                main_window.close();
            }
        } else if (event.type == sf::Event::JoystickButtonPressed) {
            switch (event.joystickButton.button) {
                case PS3::CROSS:
                    std::cout << "CROSS" << std::endl;
                    break;
                case PS3::SQUARE:
                    std::cout << "SQUARE" << std::endl;
                    break;
                case PS3::TRIANGLE:
                    std::cout << "TRIANGLE" << std::endl;
                    break;
                case PS3::CIRCLE:
                    std::cout << "CIRCLE" << std::endl;
                    break;
            }
        } else if (event.type == sf::Event::JoystickMoved) {
            std::cout << "axis: " <<  event.joystickMove.position << std::endl;
            if (event.joystickMove.axis == sf::Joystick::X) {
                // std::cout << "X axis: " <<  event.joystickMove.position << std::endl;
            }
            if (event.joystickMove.axis == sf::Joystick::Y) {
                // std::cout << "Y axis: " << event.joystickMove.position << std::endl;
            }
        }
    }
}

void update() {

}

void render() {

}
