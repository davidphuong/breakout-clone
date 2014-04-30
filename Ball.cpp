#include "Ball.h"
#include "Constant.h"
#include "GameObjectManager.h"
#include "VisibleGameObject.h"

#include <stdlib.h>
#include <math.h>
#include <iostream>

bool is_intersecting(VisibleGameObject* A, VisibleGameObject* B);

Ball::Ball() {
    // m_angle = rand() % 360 + 1;
    m_angle = 315;
}

void Ball::update() {
    m_velocity.x = 4;
    m_velocity.y = 4;

    m_velocity.x = m_velocity.x * compute_x_component();
    m_velocity.y = m_velocity.y * compute_y_component();

    m_sprite.move(m_velocity.x, m_velocity.y);

    extern GameObjectManager game_object_manager;
    VisibleGameObject* player = game_object_manager.get_object("player");

    extern bool end_game;

    // Paddle checks
    if (is_intersecting(this, player) == true) {
        if (get_position().x >= player->get_left() && get_position().x <= player->get_right()) {
            // If ball is going to collide with the top of the paddle
            m_angle = 360 - m_angle;
        } else if (get_position().x < player->get_left()) {
            // If ball is going to collide with the left side of the paddle
            m_angle = 180 - m_angle;
        } else if (get_position().x > player->get_right()) {
            // If ball is going to collide with the right side of the paddle
            m_angle = 180 - m_angle;
        }
    }

    // Boundary checks
    if (get_left() < 0) {
        // If ball is going to go past left border,
        m_angle = 180 - m_angle;
        if (m_angle < 0) {
            m_angle = 360 + m_angle;
        }
    } else if (get_right() > SCREEN_WIDTH) {
        // If ball is going to go past right border,
        m_angle = 180 - m_angle;
        if (m_angle < 0) {
            m_angle = 360 + m_angle;
        }

    } else if (get_bottom() > SCREEN_HEIGHT) {
        // If ball is going to go past bottom border,
        // m_angle = 360 - m_angle;
        end_game = true;
    } else if (get_top() < 0) {
        // If ball is going to go past top border,
        m_angle = 360 - m_angle;
    }
}

float Ball::compute_x_component() {
    return static_cast<float>(cos(m_angle * (3.14159265 / 180)));    
}

float Ball::compute_y_component() {
    // Graphics Y axis is the opposite of normal axis Y.
    return -1.0 * static_cast<float>(sin(m_angle * (3.14159265 / 180)));    
}
