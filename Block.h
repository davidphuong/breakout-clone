#ifndef BLOCK_H
#define BLOCK_H

#include "VisibleGameObject.h"

class Block : public VisibleGameObject {
    public:
        Block();
        virtual void update();

    private:
        bool m_destroy;
};

#endif
