#pragma once

#include "../../GameObject.h"

class GameMap : public GameObject {
public:
    GameMap();
    void update(float delta) override;
    void draw(sf::RenderWindow& window) override;
protected:
    std::vector<SceneTeleporter> m_mapPoints;
    sf::Sprite m_background;
};