#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <memory>

class Piece: public std::enable_shared_from_this<Piece> {
private:
    typedef std::pair<std::vector<sf::Vertex>, sf::Color> Line;
public:
    Piece();
    void addLine(std::vector<sf::Vertex> line, sf::Color c);
    const std::vector<Line>& getLines() const;
    void clear(); //TODO REMOVE THIS!
    const std::vector<sf::Texture>& getTextures();
    const sf::Texture &getLastTexture();

protected:
    std::vector<Line> m_lines;
    std::vector<sf::Texture> m_textures;
    void addTexture(std::vector<sf::Vertex>& vector, sf::Color& c);
};