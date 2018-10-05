#pragma once

#include "../../GameObject.h"

class BaseCanvas : public GameObject {
public:
    explicit BaseCanvas(sf::Vector2f pos, sf::Vector2f size);
    void draw(sf::RenderWindow& window) override;
    void update(float deltaTime) override;
protected:

};