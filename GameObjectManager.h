#ifndef GAMEOBJECTMANAGER_H
#define GAMEOBJECTMANAGER_H

#include "VisibleGameObject.h"

#include <SFML/Graphics.hpp>
#include <string>
#include <map>

class GameObjectManager {
    public:
        GameObjectManager();
        ~GameObjectManager();

        void add(std::string name, VisibleGameObject* object);
        void remove(std::string name); 

        VisibleGameObject* get_object(std::string name);

        void update_all();
        void draw_all(sf::RenderWindow& window);
    
    private:
        std::map<std::string, VisibleGameObject*> m_container; 

        struct deallocator {
            void operator()(const std::pair<std::string, VisibleGameObject*>& p) {
                delete p.second;
            }
        };
};

#endif
