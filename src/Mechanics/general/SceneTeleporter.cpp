#include "SceneTeleporter.h"
#include "../../Application.h"

void SceneTeleporter::update(float delta) {
    m_label.update(delta);
}

void SceneTeleporter::draw(sf::RenderWindow &window) {
    m_label.draw(window);
}

void SceneTeleporter::onEvent(sf::Event &e) {
    auto mousePos = sf::Mouse::getPosition(Application::get().getWindow().getRenderWindow());
    if(e.MouseButtonReleased && e.mouseButton.button == sf::Mouse::Button::Left)
    {
        Application::get().getWindow().setScene(m_scene);
    }
}