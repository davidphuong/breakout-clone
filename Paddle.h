#ifndef PADDLE_H
#define PADDLE_H

#include "VisibleGameObject.h"
#include <SFML/Graphics.hpp>

class Paddle : public VisibleGameObject {
    public:
        Paddle();

        virtual void process_input();
        virtual void update();
};

#endif
