#pragma once
#include <vector>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Image.hpp>
#include "details/KeyFrame.h"

class Piece {
public:
    Piece(std::vector<KeyFrame> frames);
    size_t getFrameCount();
    KeyFrame step();
protected:
    int it;
    std::vector<KeyFrame> m_frames;
    sf::RectangleShape m_shape;
};