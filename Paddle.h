#ifndef PADDLE_H
#define PADDLE_H

#include "VisibleGameObject.h"
#include <SFML/Graphics.hpp>

class Paddle : public VisibleGameObject {
    public:
        Paddle(float width, float height);

        void process_input();
        void update();
        void draw(sf::RenderWindow& window);

        void set_position(float x, float y);

        sf::Vector2f get_position();

    private:
        sf::RectangleShape m_paddle;

        sf::Vector2f m_velocity;
};

#endif
