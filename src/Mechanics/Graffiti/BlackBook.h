#pragma once

#include <SFML/Graphics.hpp>
#include "../../GameObject.h"

class BlackBook : public GameObject {
public:
    BlackBook();
    void draw(sf::RenderWindow& window) override;
    void update(float deltaTime) override;
    bool onEvent(sf::Event& e) override;
    void clear();
    void save();
protected:
    std::vector <sf::Vertex> lines;
    sf::Texture texture;
    sf::Sprite sprite;
    int mousedown = 0;
};