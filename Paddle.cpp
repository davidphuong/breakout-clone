#include "Paddle.h"
#include "PS3Controller.h"
#include "Constant.h"

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

void Paddle::process_input() {
    sf::Joystick::update();
    m_velocity.x = 0;

    // Joystick value returns from 0 to 100 in the 1st
    // and 4th quadrants where 100 being directly right.
    // Joystick value returns from 0 to -100 in the 2nd
    // and 3rd quadrants where -100 being directly left.
    float joystick_value = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
    m_velocity.x = joystick_value * 0.1;

    // if (sf::Joystick::isButtonPressed(0, PS3::LEFT)) {
    //     m_velocity.x -= 5.0;
    // }

    // if (sf::Joystick::isButtonPressed(0, PS3::RIGHT)) {
    //     m_velocity.x += 5.0;
    // }
}

void Paddle::update() {
    sf::Vector2f current_pos = get_position();

    if (current_pos.x - (m_width / 2.0) + m_velocity.x < 0) {
        // If Paddle is going to go past left border,
        // do nothing
    } else if (current_pos.x + (m_width / 2) + m_velocity.x > SCREEN_WIDTH) {
        // If Paddle is going to go past right border,
        // do nothing
    } else {
        m_paddle.move(m_velocity.x, 0);
    }
}

void Paddle::draw(sf::RenderWindow& window) {
    window.draw(m_paddle);
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
