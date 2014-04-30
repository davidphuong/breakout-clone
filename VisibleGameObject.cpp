#include "VisibleGameObject.h"
#include <iostream>

VisibleGameObject::VisibleGameObject() {
    // Default values
    m_velocity.x = 0;
    m_velocity.y = 0;
}

void VisibleGameObject::load(std::string filename) {
    if (m_texture.loadFromFile(filename) != false) {
        m_sprite.setTexture(m_texture);
        m_sprite.setPosition(0, 0);
        m_sprite.setOrigin(get_width() / 2, get_height() / 2);
    } else {
        std::cout << "ERROR: could not load " << filename << std::endl;
    }
}

void VisibleGameObject::process_input() {

}

void VisibleGameObject::update() {

}

void VisibleGameObject::draw(sf::RenderWindow& window) {
    window.draw(m_sprite);
}

void VisibleGameObject::set_position(float x, float y) {
    m_sprite.setPosition(x, y);
}

float VisibleGameObject::get_width() {
    return m_sprite.getLocalBounds().width;
}

float VisibleGameObject::get_height() {
    return m_sprite.getLocalBounds().height;
}

sf::Vector2f VisibleGameObject::get_position() {
    return m_sprite.getPosition();
}
