#include "Paddle.h"
#include "PS3Controller.h"

Paddle::Paddle(float width, float height) :
    m_width(width),
    m_height(height)
{
    m_paddle.setSize(sf::Vector2f(m_width, m_height));
    m_paddle.setFillColor(sf::Color::Black);
    m_paddle.setOrigin(m_width / 2, m_height / 2);
    m_paddle.setPosition(0, 0);

    m_velocity.x = 0;
    m_velocity.y = 0;
}

void Paddle::draw(sf::RenderWindow& window) {
    window.draw(m_paddle);
}

void Paddle::update() {
    m_velocity.x = 0;

    if (sf::Joystick::isButtonPressed(0, PS3::LEFT)) {
        m_velocity.x -= 5.0;
    }

    if (sf::Joystick::isButtonPressed(0, PS3::RIGHT)) {
        m_velocity.x += 5.0;
    }

    m_paddle.move(m_velocity.x, 0);
}

void Paddle::set_position(float x, float y) {
    m_paddle.setPosition(x, y); 
}

float Paddle::get_width() {
    return m_width;
}

float Paddle::get_height() {
    return m_height;
}

sf::Vector2f Paddle::get_position() {
    return m_paddle.getPosition();
}
