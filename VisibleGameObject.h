#ifndef VISIBLEGAMEOBJECT_H
#define VISIBLEGAMEOBJECT_H

#include <SFML/Graphics.hpp>

class VisibleGameObject {
    public:
        VisibleGameObject(float width, float height);

        virtual void process_input() = 0;
        virtual void update() = 0;
        virtual void draw(sf::RenderWindow& window);

        virtual void set_position(float x, float y);

        float get_width();
        float get_height();
        virtual sf::Vector2f get_position();

    protected:
        float m_width;
        float m_height;

    private:
        sf::Vector2f m_velocity;

};

#endif
