#include "VisibleGameObject.h"

VisibleGameObject::VisibleGameObject(float width, float height) :
    m_width(width),
    m_height(height)
{
    // Default values
    m_velocity.x = 0;
    m_velocity.y = 0;
}

void VisibleGameObject::process_input() {

}

void VisibleGameObject::update() {

}

void VisibleGameObject::draw(sf::RenderWindow& window) {

}

void VisibleGameObject::set_position(float x, float y) {

}

float VisibleGameObject::get_width() {
    return m_width;
}

float VisibleGameObject::get_height() {
    return m_height;
}

sf::Vector2f VisibleGameObject::get_position() {

}
