#include <utility>

#pragma once

#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>
#include "../../GameScene.h"
#include "../../UI/Label.h"
#include "../../UI/GenericReactiveLabel.h"
#include "../../UI/Button.h"
#include "../../Application.h"

template<class T> struct tag{using type=T;};
template<class Tag> using type_t=typename Tag::type;

class SceneTeleporter {
public:
    template<class t>
    SceneTeleporter(tag<t> tag, sf::Vector2f pos, std::string text);
    void update(float delta);
    void draw(sf::RenderWindow& window);
    bool onEvent(sf::Event& e);
protected:
    bool eventCallback(sf::Event& e, Button& b);
    std::shared_ptr<GameScene> m_scene;
    Button m_button;
};

template<class t>
SceneTeleporter::SceneTeleporter(tag<t> tag, sf::Vector2f pos, std::string text) :
m_button(pos, std::move(text),
        std::bind(&SceneTeleporter::eventCallback, this, std::placeholders::_1, std::placeholders::_2),
        nullptr)
{
    m_scene = std::make_shared<t>(Application::get().getWindow());
}
