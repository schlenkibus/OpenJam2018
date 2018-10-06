#include <iostream>
#include "BlackBookScene.h"
#include "../../Mechanics/Graffiti/BlackBook.h"
#include "../../UI/Button.h"
#include "../../UI/GenericReactiveLabel.h"

BlackBookScene::BlackBookScene(GameWindow &parent) : GameScene(parent) {
    m_gameObjects.emplace_back(std::make_unique<GenericReactiveLabel>([](auto f, Label& l) {
        l.setText("ANUS");
    }, sf::Vector2f(100, 100)));

    auto blackBook = dynamic_cast<BlackBook*>(&*m_gameObjects.emplace_back(std::make_unique<BlackBook>()));

    m_gameObjects.emplace_back(std::make_unique<Button>(sf::Vector2f(0, 0), "Clear", [ = ](sf::Event& e, Button& b){
        if(e.type == sf::Event::MouseButtonReleased &&
           e.mouseButton.button == sf::Mouse::Left) {
            if(b.containsPosition(m_parent.getMousePosition()))
            {
                std::cout << "Clear!\n";
                blackBook->clear();
                return true;
            }
        }
        return false;
    }, nullptr));
}