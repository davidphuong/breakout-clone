#include "Paddle.h"
#include "PS3Controller.h"
#include "Constant.h"

Paddle::Paddle() {

}

void Paddle::update() {
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

    sf::Vector2f current_pos = get_position();

    if (current_pos.x - (get_width() / 2.0) + m_velocity.x < 0) {
        // If Paddle is going to go past left border,
        // do nothing
    } else if (current_pos.x + (get_width() / 2) + m_velocity.x > SCREEN_WIDTH) {
        // If Paddle is going to go past right border,
        // do nothing
    } else {
        m_sprite.move(m_velocity.x, 0);
    }
}
