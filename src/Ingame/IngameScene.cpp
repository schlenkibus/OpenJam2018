#include "IngameScene.h"
#include "../UI/Label.h"
#include "../UI/Button.h"
#include "../GameWindow.h"
#include "Details/ParticleSystem.h"
#include "../UI/GenericReactiveLabel.h"
#include "../UI/Overlay/Overlay.h"
#include "../Menu/MenuScene.h"
#include "../Mechanics/general/GameMap.h"
#include "../Application.h"

IngameScene::IngameScene(GameWindow& parent) : GameScene(parent) {
    m_gameObjects.push_back(std::make_unique<Overlay>());
    auto overlay = dynamic_cast<Overlay*>(m_gameObjects.back().get());
    if(overlay) {
        overlay->addChild(new Button(sf::Vector2f(0, 50), "Menu!", [&](sf::Event& e, Button& b){
            if(e.type == sf::Event::MouseButtonReleased &&
               e.mouseButton.button == sf::Mouse::Left) {
                if(b.containsPosition(m_parent.getMousePosition()))
                {
                    m_parent.setScene(std::make_shared<MenuScene>(Application::get().getWindow()));
                    return true;
                }
            }
            return false;
        }, nullptr));

        overlay->addChild(new GenericReactiveLabel([](float delta, Label& l) {
            auto fps = 1. / delta;
            l.setText(std::string("frameTime:") + std::to_string(delta) + "s FPS: " + std::to_string(fps));
        }, sf::Vector2f(0,0)));
    }

    m_gameObjects.emplace_back(std::make_unique<GameMap>());
}
