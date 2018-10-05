//
// Created by justus on 05.10.18.
//

#include "BlackBook.h"
#include "../../Application.h"

BlackBook::BlackBook() {
    auto size = Application::get().getWindow().getRenderWindow().getSize();
    texture.create(size.x, size.y);
    sprite.setPosition(0, 0);
}

void BlackBook::draw(sf::RenderWindow &window) {
    window.draw(sprite);
    window.draw(&lines[0], lines.size(), sf::LinesStrip);
    sprite.setTexture(texture);
}

void BlackBook::update(float deltaTime) {

}

bool BlackBook::onEvent(sf::Event &e) {
    if ((e.type == sf::Event::MouseMoved) && (mousedown == 1))
    {
        auto pos = sf::Mouse::getPosition(Application::get().getWindow().getRenderWindow());
        lines.emplace_back(sf::Vertex(sf::Vector2f(pos)));
    }
    else if (e.type == sf::Event::MouseButtonPressed)
    {
        mousedown = 1;
    }
    else if (e.type == sf::Event::MouseButtonReleased)
    {
        mousedown = 0;
    }
    return false;
}

void BlackBook::clear() {
    lines.clear();
}

void BlackBook::save() {

}
