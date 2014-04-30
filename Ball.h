#ifndef BALL_H
#define BALL_H

#include "VisibleGameObject.h"
#include <SFML/Graphics.hpp>

class Ball : public VisibleGameObject {
    public:
        Ball(float width, float height);

        void process_input();
        void update();
        void draw(sf::RenderWindow& window);

        void set_position(float x, float y);

        sf::Vector2f get_position();

    private:
        sf::CircleShape m_ball;

        sf::Vector2f m_velocity;
};

#endif
