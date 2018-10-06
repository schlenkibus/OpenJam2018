#pragma once

#include <SFML/Audio.hpp>
#include <vector>
#include <iostream>
#include "Label.h"
#include "Button.h"

template <class T>
class ComboBox : public GameObject {
public:
    ComboBox(sf::Vector2f pos, std::initializer_list<T> items);
    T getSelectedItem() const;
    void selectItem(size_t item);
    void draw(sf::RenderWindow& window) override;
    bool onEvent(sf::Event& e) override;
    void update(float delta) override;
protected:
    size_t m_index;
    Button* m_currentButton = nullptr;
    sf::Vector2f m_pos;
    std::vector<std::pair<T, Button>> m_items;
    bool m_isOpen = false;
};

template<class T>
ComboBox<T>::ComboBox(sf::Vector2f pos, std::initializer_list<T> items) : m_pos(pos) {
    m_index = 0;

    size_t index = 0;
    for(auto item: items) {
        m_items.emplace_back(std::make_pair(item, Button(pos, std::to_string(item), [=](sf::Event& e, Button& b) {
            selectItem(index);
            std::cout << "set m_index to: " << index <<'\n';
            return false;
        }, nullptr)));
        index++;
    }
    m_currentButton = &m_items.back().second;
}

template<class T>
T ComboBox<T>::getSelectedItem() const {
    return m_items.at(m_index).first;
}

template<class T>
void ComboBox<T>::selectItem(size_t item) {
    m_index = item;
}

template<class T>
void ComboBox<T>::draw(sf::RenderWindow &window) {
    if(m_isOpen) {

    } else {
        auto oldPos = m_currentButton->getPosition();
        m_currentButton->setPosition(m_pos);
        m_currentButton->draw(window);
        m_currentButton->setPosition(oldPos)
    }
}

template<class T>
bool ComboBox<T>::onEvent(sf::Event &e) {

    return false;
}

template<class T>
void ComboBox<T>::update(float delta) {

}
