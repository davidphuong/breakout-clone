#include <iostream>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <time.h>

#include "Constant.h"
#include "PS3Controller.h"
#include "Paddle.h"
#include "Ball.h"
#include "GameObjectManager.h"

void process_input();
void update();
void render();
bool is_intersecting(VisibleGameObject* A, VisibleGameObject* B);

sf::RenderWindow main_window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Breakout!");
GameObjectManager game_object_manager;
bool end_game = false;

int main(int argc, char* argv[]) {

    // Check that joystick #0 is connected.
    if (sf::Joystick::isConnected(0)) {
        std::cout << "Joystick is connected." << std::endl;
        srand(time(NULL));

        // Initializing game objects.
        Paddle* player = new Paddle;
        player->load("images/paddle.png");
        player->set_position(SCREEN_WIDTH / 2, SCREEN_HEIGHT - player->get_height());
        game_object_manager.add("player", player);

        Ball* game_ball = new Ball;
        game_ball->load("images/ball.png");
        game_ball->set_position(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
        game_object_manager.add("ball", game_ball);

        main_window.setFramerateLimit(60);

        // Game loop
        while (main_window.isOpen() && end_game == false) {
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
}

void update() {
    game_object_manager.update_all();
}

void render() {
    main_window.clear(sf::Color(255, 255, 255));
    game_object_manager.draw_all(main_window);
    main_window.display();
}

bool is_intersecting(VisibleGameObject* A, VisibleGameObject* B) {
    return (A->get_right() >= B->get_left() && A->get_left() <= B->get_right()
        && A->get_bottom() >= B->get_top() && A->get_top() <= B->get_bottom());
}
