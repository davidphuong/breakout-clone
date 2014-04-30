#include "Ball.h"
#include "Constant.h"

#include <stdlib.h>
#include <math.h>
#include <iostream>

Ball::Ball() {
    m_angle = rand() % 360 + 1;
    // m_angle = 45;
}

void Ball::process_input() {
    // Empty
}

void Ball::update() {
    m_velocity.x = 3;
    m_velocity.y = 3;

    m_velocity.x = m_velocity.x * compute_x_component();
    m_velocity.y = m_velocity.y * compute_y_component();

    sf::Vector2f current_pos = get_position();

    if (current_pos.x - (get_width() / 2.0) + m_velocity.x < 0) {
        // If Paddle is going to go past left border,
        m_angle = 180 - m_angle;
        if (m_angle < 0) {
            m_angle = 360 + m_angle;
        }
    } else if (current_pos.x + (get_width() / 2) + m_velocity.x > SCREEN_WIDTH) {
        // If Paddle is going to go past right border,
        m_angle = 180 - m_angle;
        if (m_angle < 0) {
            m_angle = 360 + m_angle;
        }

    } else if (current_pos.y + (get_height() / 2) + m_velocity.y > SCREEN_HEIGHT) {
        // If Paddle is going to go past bottom border,
        m_angle = 360 - m_angle;
    } else if (current_pos.y - (get_height() / 2) + m_velocity.y < 0) {
        // If Paddle is going to go past top border,
        m_angle = 360 - m_angle;
    }

    m_sprite.move(m_velocity.x, m_velocity.y);
}

float Ball::compute_x_component() {
    return static_cast<float>(cos(m_angle * (3.14159265 / 180)));    
}

float Ball::compute_y_component() {
    // Graphics Y axis is the opposite of normal axis Y.
    return -1.0 * static_cast<float>(sin(m_angle * (3.14159265 / 180)));    
}
