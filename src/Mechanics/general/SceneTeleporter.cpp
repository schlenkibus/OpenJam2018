#include "SceneTeleporter.h"
#include "../../Application.h"

void SceneTeleporter::update(float delta) {
    m_button.update(delta);
}

void SceneTeleporter::draw(sf::RenderWindow &window) {
    m_button.draw(window);
}

bool SceneTeleporter::onEvent(sf::Event &e) {
    return m_button.onEvent(e);
}

bool SceneTeleporter::eventCallback(sf::Event& e, Button& b) {
    if(b.containsPosition(sf::Mouse::getPosition(Application::get().getWindow().getRenderWindow()))) {
        if(e.type == sf::Event::MouseButtonReleased && e.mouseButton.button == sf::Mouse::Button::Left) {
            Application::get().getWindow().setScene(m_scene);
            return true;
        }
    }
    return false;
}