#include <iostream>
#include "DebugScene.h"
#include "Tools/NoiseGenerator.h"
#include "UI/Label.h"
#include "Mechanics/Graffiti/BlackBook.h"

DebugScene::DebugScene(GameWindow &parent) : GameScene(parent) {
    m_gameObjects.emplace_back(std::make_unique<BlackBook>());
}
