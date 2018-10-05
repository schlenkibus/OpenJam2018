#include <utility>

#pragma once

#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>
#include "../../GameScene.h"
#include "../../UI/Label.h"

class SceneTeleporter {
public:
    template<class t>
    SceneTeleporter(sf::Vector2f pos, std::string text);
    void update(float delta);
    void draw(sf::RenderWindow& window);
    void onEvent(sf::Event& e);
protected:
    std::shared_ptr<GameScene> m_scene;
    Label m_label;
};

template<class t>
SceneTeleporter::SceneTeleporter(sf::Vector2f pos, std::string text) : m_label(pos, std::move(text)) {
    m_scene = std::make_shared<t>();
}
