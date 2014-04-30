#include "Ball.h"
#include "Constant.h"
#include "GameObjectManager.h"
#include "VisibleGameObject.h"

#include <stdlib.h>
#include <math.h>
#include <iostream>

Ball::Ball() {
    m_angle = rand() % 360 + 1;
    // m_angle = 45;
}

void Ball::update() {
    m_velocity.x = 3;
    m_velocity.y = 3;

    m_velocity.x = m_velocity.x * compute_x_component();
    m_velocity.y = m_velocity.y * compute_y_component();

    sf::Vector2f current_pos = get_position();

    extern GameObjectManager game_object_manager;
    VisibleGameObject* player = game_object_manager.get_object("player");

    extern bool end_game;

    // Paddle checks
    if (get_bottom() + m_velocity.y > player->get_top()
            && current_pos.x > player->get_left()
            && current_pos.x < player->get_right()) {
        // If ball is going to collide with the top of the paddle,
        m_angle = 360 - m_angle;
    }

    // Boundary checks
    if (get_left() + m_velocity.x < 0) {
        // If ball is going to go past left border,
        m_angle = 180 - m_angle;
        if (m_angle < 0) {
            m_angle = 360 + m_angle;
        }
    } else if (get_right() + m_velocity.x > SCREEN_WIDTH) {
        // If ball is going to go past right border,
        m_angle = 180 - m_angle;
        if (m_angle < 0) {
            m_angle = 360 + m_angle;
        }

    } else if (get_bottom() + m_velocity.y > SCREEN_HEIGHT) {
        // If ball is going to go past bottom border,
        // m_angle = 360 - m_angle;
        end_game = true;
    } else if (get_top() + m_velocity.y < 0) {
        // If ball is going to go past top border,
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

