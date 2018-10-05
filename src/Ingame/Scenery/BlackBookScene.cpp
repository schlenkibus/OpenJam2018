#include "BlackBookScene.h"
#include "../../Mechanics/Graffiti/BlackBook.h"
#include "../../UI/Button.h"

BlackBookScene::BlackBookScene(GameWindow &parent) : GameScene(parent) {
    m_gameObjects.emplace_back(std::make_unique<BlackBook>());

    auto blackBook = dynamic_cast<BlackBook*>(m_gameObjects.back().get());

    m_gameObjects.emplace_back(std::make_unique<Button>(sf::Vector2f(0, 0), "Clear", [&](sf::Event& e, Button& b){
        if(e.type == sf::Event::MouseButtonReleased &&
           e.mouseButton.button == sf::Mouse::Left) {
            if(b.containsPosition(m_parent.getMousePosition()))
            {
                blackBook->clear();
                return true;
            }
        }
        return false;
    }, nullptr));
}