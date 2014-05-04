#ifndef BLOCKMANAGER_H
#define BLOCKMANAGER_H

#include "Block.h"
#include <vector>

class BlockManager {
    public:
        BlockManager();

        void update_all();
        void draw_all(sf::RenderWindow& window);

        int get_block_amount();
        Block* get_block(int block_num);

        void destroy_block(int block_num);

    private:
        std::vector<Block*> m_container;
        std::vector<int> m_blocks_to_destroy;

        const int BLOCK_ROW;
        const int BLOCK_COL;

        const int X_GAP;
        const int Y_GAP;
};

#endif
