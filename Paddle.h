#ifndef PADDLE_H
#define PADDLE_H

#include "VisibleGameObject.h"
#include <SFML/Graphics.hpp>

class Paddle : public VisibleGameObject {
    public:
        Paddle();

        virtual void update();
};

#endif
