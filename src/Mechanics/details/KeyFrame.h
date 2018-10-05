#pragma once
#include <chrono>
#include <SFML/Audio.hpp>
#include <SFML/Graphics/Color.hpp>

struct KeyFrame {
    KeyFrame(sf::Vector2f pos, sf::Time time, double width, sf::Color color);
    sf::Time m_time;
    sf::Vector2f m_pos;
    sf::Color m_color;
    double m_width;
};