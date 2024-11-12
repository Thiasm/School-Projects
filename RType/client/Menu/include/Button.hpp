/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-mathias.roulleaux
** File description:
** Button
*/

#ifndef BUTTON_HPP_
#define BUTTON_HPP_

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>

class Button {
public:
    Button (std::string, sf::Vector2f location, int);
    sf::Text getTextDraw();
    void SetColor(sf::Color);
    int getId();
private:
    sf::Vector2f posi;
    sf::Text text;
    sf::Font font;
    int id;
};

#endif /* !BUTTON_HPP_ */
