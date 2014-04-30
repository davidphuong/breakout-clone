#include "GameObjectManager.h"

GameObjectManager::GameObjectManager() {

}

GameObjectManager::~GameObjectManager() {
    std::for_each(m_container.begin(), m_container.end(), deallocator());
}

void GameObjectManager::add(std::string name, VisibleGameObject* object) {
    m_container.insert(std::pair<std::string, VisibleGameObject*>(name, object)); 
}

void GameObjectManager::remove(std::string name) {
    std::map<std::string, VisibleGameObject*>::iterator result = m_container.find(name);

    if (result != m_container.end()) {
        delete result->second;
        m_container.erase(result);
    }
} 

VisibleGameObject* GameObjectManager::get_object(std::string name) {
    std::map<std::string, VisibleGameObject*>::const_iterator result = m_container.find(name);

    if (result == m_container.end()) {
        return NULL;
    } else {
        return result->second;
    }
}

void GameObjectManager::update_all() {
    std::map<std::string, VisibleGameObject*>::const_iterator itr = m_container.begin();

    while (itr != m_container.end()) {
        itr->second->update();
        itr++;
    }
}

void GameObjectManager::draw_all(sf::RenderWindow& window) {
    std::map<std::string, VisibleGameObject*>::const_iterator itr = m_container.begin();

    while (itr != m_container.end()) {
        itr->second->draw(window);
        itr++;
    }
}
