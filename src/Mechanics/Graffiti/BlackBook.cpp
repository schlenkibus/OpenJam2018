//
// Created by justus on 05.10.18.
//

#include <iostream>
#include "BlackBook.h"
#include "../../Application.h"
#include "BrushPainter.h"

BlackBook::BlackBook() {
    auto size = Application::get().getWindow().getRenderWindow().getSize();
    texture.create(500, 400);
    sprite.setPosition(0, 0);
    m_currentColor = sf::Color::Red;
}

void BlackBook::draw(sf::RenderWindow &window) {
    for(auto& piecePiece: m_piecePieces) {
        window.draw(piecePiece);
    }
    window.draw(sprite);
}

void BlackBook::update(float deltaTime) {
    texture.clear(sf::Color::Transparent);
    BrushPainter::brushPaint(texture, m_currentLine, m_currentColor);
    texture.display();
    sprite.setTexture(texture.getTexture());
}

bool BlackBook::onEvent(sf::Event &e) {
    if ((e.type == sf::Event::MouseMoved) && (mousedown == 1))
    {
        auto pos = sf::Mouse::getPosition(Application::get().getWindow().getRenderWindow());

        if(pos.x > 500 && pos.y > 400)
            return false;

        if(lastPoint.position != sf::Vector2f(pos.x, pos.y)) {
            m_currentLine.emplace_back(sf::Vertex(sf::Vector2f(pos)));
        }
        lastPoint = sf::Vertex(sf::Vector2f(pos));
    }
    else if (e.type == sf::Event::MouseButtonPressed)
    {
        mousedown = 1;
    }
    else if (e.type == sf::Event::MouseButtonReleased)
    {
        mousedown = 0;
        if(!m_currentLine.empty()) {
            m_currentPiece.addLine(m_currentLine, m_currentColor);
            m_piecePieces.emplace_back(sf::Sprite(m_currentPiece.getLastTexture()));
            m_currentLine.clear();
        }
    }
    return false;
}

void BlackBook::clear() {
    m_currentLine.clear();
    m_currentPiece.clear();
    m_piecePieces.clear();
}

void BlackBook::save() {

}
