#include "KeyFrame.h"

KeyFrame::KeyFrame(sf::Vector2f pos, sf::Time time, double width,
                   sf::Color color) : m_pos(pos), m_time(time), m_color(color), m_width(width) {
}
