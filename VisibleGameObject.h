#ifndef VISIBLEGAMEOBJECT_H
#define VISIBLEGAMEOBJECT_H

#include <SFML/Graphics.hpp>
#include <string>

class VisibleGameObject {
    public:
        VisibleGameObject();

        void load(std::string filename);

        virtual void update() = 0;
        void draw(sf::RenderWindow& window);

        void set_position(float x, float y);

        float get_width();
        float get_height();

        sf::Vector2f get_position();
        sf::Vector2f get_velocity();

        float get_left();
        float get_right();
        float get_top();
        float get_bottom();

    protected:
        sf::Sprite m_sprite;
        sf::Vector2f m_velocity;

    private:
        sf::Texture m_texture;

};

#endif
