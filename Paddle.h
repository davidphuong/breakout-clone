#ifndef PADDLE_H
#define PADDLE_H

#include <SFML/Graphics.hpp>

class Paddle {
    public:
        Paddle(float width, float height);

        void process_input();
        void update();
        void draw(sf::RenderWindow& window);

        void set_position(float x, float y);

        float get_width();
        float get_height();
        sf::Vector2f get_position();

    private:
        sf::RectangleShape m_paddle;

        int m_width;
        int m_height;

        sf::Vector2f m_velocity;
};

#endif
