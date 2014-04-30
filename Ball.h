#ifndef BALL_H
#define BALL_H

#include "VisibleGameObject.h"
#include <SFML/Graphics.hpp>

class Ball : public VisibleGameObject {
    public:
        Ball();

        void update();

    private:
        float m_angle;

        float compute_x_component();
        float compute_y_component();
};

#endif
