#include "Piece.h"
#include "BrushPainter.h"
#include <SFML/Graphics.hpp>
#include <cassert>
#include <iostream>


Piece::Piece() {
    m_textures.reserve(400); //TODO Umgehen von Pointer Invalidation
};

void Piece::addLine(std::vector<sf::Vertex> line, sf::Color c) {
    m_lines.emplace_back(std::make_pair(line, c));
    addTexture(line, c);
}

const std::vector<Piece::Line> &Piece::getLines() const {
    return m_lines;
}

void Piece::clear() {
    m_lines.clear();
    m_textures.clear();
}

const std::vector<sf::Texture>& Piece::getTextures() {
    return m_textures;
}

void Piece::addTexture(std::vector<sf::Vertex>& vector, sf::Color& c) {
    sf::RenderTexture tex;
    tex.create(500, 400);
    tex.clear(sf::Color::Transparent);
    BrushPainter::brushPaint(tex, vector, c);
    tex.display();
    m_textures.emplace_back(sf::Texture(tex.getTexture()));
}

const sf::Texture &Piece::getLastTexture() {
    return m_textures.back();
}
