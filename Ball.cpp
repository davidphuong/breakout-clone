#include "Ball.h"
#include "PS3Controller.h"
#include "Constant.h"

Ball::Ball(float width, float height) :
    VisibleGameObject(width, height)
{
    m_ball.setRadius(width / 2);
    m_ball.setFillColor(sf::Color::Red);
    m_ball.setOrigin(m_width / 2, m_height / 2);
    m_ball.setPosition(0, 0);
}

void Ball::process_input() {
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

void Ball::update() {
    sf::Vector2f current_pos = get_position();

    if (current_pos.x - (m_width / 2.0) + m_velocity.x < 0) {
        // If Ball is going to go past left border,
        // do nothing
    } else if (current_pos.x + (m_width / 2) + m_velocity.x > SCREEN_WIDTH) {
        // If Ball is going to go past right border,
        // do nothing
    } else {
        m_ball.move(m_velocity.x, 0);
    }
}

void Ball::draw(sf::RenderWindow& window) {
    window.draw(m_ball);
}

void Ball::set_position(float x, float y) {
    m_ball.setPosition(x, y); 
}

sf::Vector2f Ball::get_position() {
    return m_ball.getPosition();
}

