#include "BlockManager.h"

BlockManager::BlockManager() :
    BLOCK_ROW(7),
    BLOCK_COL(16),
    X_GAP(10),
    Y_GAP(10)
{
    int start_pos_x = 60;
    int start_pos_y = 20;
    int gap_x = 0;
    int gap_y = 0;

    for (int i = 0; i < BLOCK_ROW; i++) {
        for (int j = 0; j < BLOCK_COL; j++) {
            m_container.push_back(new Block);
            m_container[m_container.size() - 1]->load("images/block.png");
            m_container[m_container.size() - 1]->set_position(start_pos_x + gap_x, start_pos_y + gap_y);
            gap_x += m_container[m_container.size() - 1]->get_width() + X_GAP;
        }
        gap_x = 0;
        gap_y += m_container[m_container.size() - 1]->get_height() + Y_GAP;
    }
}

void BlockManager::update_all() {
    for (int i = 0; i < static_cast<int>(m_blocks_to_destroy.size()); i++) {
        delete m_container[m_blocks_to_destroy[i]];
        m_container.erase(m_container.begin() + m_blocks_to_destroy[i]);
    }

    m_blocks_to_destroy.clear();
}

void BlockManager::draw_all(sf::RenderWindow& window) {
    for (int i = 0; i < static_cast<int>(m_container.size()); i++) {
        m_container[i]->draw(window);
    }
}

int BlockManager::get_block_amount() {
    return static_cast<int>(m_container.size());
}

Block* BlockManager::get_block(int block_num) {
    if (block_num >= 0 && block_num < get_block_amount()) {
        return m_container[block_num]; 
    } else {
        // ERROR
    }
    return NULL;
}
void BlockManager::destroy_block(int block_num) {
    m_blocks_to_destroy.push_back(block_num); 
}
