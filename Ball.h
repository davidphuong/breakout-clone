#ifndef BALL_H
#define BALL_H

#include "VisibleGameObject.h"

class Ball : public VisibleGameObject {
    public:
        Ball();

        virtual void update();

    private:
        float m_angle;

        float compute_x_component();
        float compute_y_component();
};

#endif
