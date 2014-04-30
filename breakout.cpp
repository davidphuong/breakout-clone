#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Constant.h"
#include "PS3Controller.h"
#include "Paddle.h"
#include "Ball.h"

void process_input();
void update();
void render();

sf::RenderWindow main_window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Breakout!");
Paddle player(200, 10);
Ball game_ball(50, 50);


int main(int argc, char* argv[]) {

    // Check that joystick #0 is connected.
    if (sf::Joystick::isConnected(0)) {
        std::cout << "Joystick is connected." << std::endl;

        player.set_position(SCREEN_WIDTH / 2, SCREEN_HEIGHT - player.get_height());
        game_ball.set_position(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

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
        }
    }

    player.process_input();
    game_ball.process_input();
}

void update() {
    player.update();
    game_ball.update();
}

void render() {
    main_window.clear(sf::Color(255, 255, 255));

    player.draw(main_window);    
    game_ball.draw(main_window);
    main_window.display();
}
