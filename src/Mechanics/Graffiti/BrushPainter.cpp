//
// Created by justus on 06.10.18.
//

#include "BrushPainter.h"

void BrushPainter::brushPaint(sf::RenderTexture &target, std::vector<sf::Vertex> &points, sf::Color c) {
    Brush brush(c);
    for(auto& p: points) {
        brush.update(p);
        target.draw(brush.brush);
    }
}
