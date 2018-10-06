#pragma once

#include <SFML/Graphics.hpp>
#include "../../GameObject.h"
#include "Piece.h"

class BlackBook : public GameObject {
public:
    BlackBook();
    void draw(sf::RenderWindow& window) override;
    void update(float deltaTime) override;
    bool onEvent(sf::Event& e) override;
    void clear();
    void save();

protected:
    Piece m_currentPiece;
    std::vector<sf::Vertex> m_currentLine;
    short sampleRate = 50; //per se
    sf::Vertex lastPoint;
    sf::RenderTexture texture;
    sf::Sprite sprite;
    sf::Color m_currentColor;
    std::vector<sf::Sprite> m_piecePieces;
    int mousedown = 0;
};