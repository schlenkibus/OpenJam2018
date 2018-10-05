#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include "../../GameObject.h"
#include "SceneTeleporter.h"

class GameMap : public GameObject {
public:
    GameMap();
    void update(float delta) override;
    void draw(sf::RenderWindow& window) override;
    bool onEvent(sf::Event& e) override;
protected:
    std::vector<std::shared_ptr<SceneTeleporter>> m_mapPoints;
    sf::Sprite m_background;
};