#include <iostream>
#include "BlackBookScene.h"
#include "../../Mechanics/Graffiti/BlackBook.h"
#include "../../UI/Button.h"
#include "../../UI/GenericReactiveLabel.h"
#include "../../UI/ComboBox.h"

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
                blackBook->clear();
                return true;
            }
        }
        return false;
    }, nullptr));

    auto comboBox = dynamic_cast<ComboBox<int>*>(
            &*m_gameObjects.emplace_back(
                    std::make_unique<ComboBox<int>>(sf::Vector2f(100, 0), std::initializer_list<int>{1,2,3,4})));

    m_gameObjects.emplace_back(std::make_unique<Button>(sf::Vector2f(100, 50), "Save", [ = ](sf::Event& e, Button& b){
        if(e.type == sf::Event::MouseButtonReleased &&
           e.mouseButton.button == sf::Mouse::Left) {
            if(b.containsPosition(m_parent.getMousePosition()))
            {
                blackBook->save(comboBox->getSelectedItem());
                return true;
            }
        }
        return false;
    }, nullptr));
}