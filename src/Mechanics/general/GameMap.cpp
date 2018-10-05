//
// Created by justus on 05.10.18.
//

#include "GameMap.h"
#include "../../Ingame/Scenery/BlackBookScene.h"

GameMap::GameMap() {
    m_mapPoints.emplace_back(std::make_shared<SceneTeleporter>(tag<BlackBookScene>{}, sf::Vector2f(0, 0), "BlackBook"));
}

void GameMap::update(float delta) {
    for(auto& p: m_mapPoints) {
        p->update(delta);
    }
}

void GameMap::draw(sf::RenderWindow &window) {
    for(auto& p: m_mapPoints) {
        p->draw(window);
    }
}

bool GameMap::onEvent(sf::Event &e) {
    for(auto& p: m_mapPoints) {
        if(p->onEvent(e))
            return true;
    }
    return false;
}
