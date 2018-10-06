#pragma once

#include <SFML/Graphics/Image.hpp>
#include <vector>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/CircleShape.hpp>

class BrushPainter {
public:
    static void brushPaint(sf::RenderTexture& target, std::vector<sf::Vertex>& points, sf::Color c);
protected:
    struct Brush {
        explicit Brush(sf::Color c) {
            brush.setRadius(5);
            brush.setScale(1, 1.5);
            brush.setFillColor(c);
        }

        void update(const sf::Vertex& p) {
            brush.setPosition(p.position);
        }

        sf::CircleShape brush;
    };
};