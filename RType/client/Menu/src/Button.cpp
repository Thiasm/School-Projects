/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-mathias.roulleaux
** File description:
** Button
*/

#include "../include/Button.hpp"
#include <SFML/Graphics.hpp>

Button::Button(std::string words,sf::Vector2f location, int _id) {
    id = _id;
    font.loadFromFile("../re/ethnocentricrg.ttf");
    text.setFont(font);
    text.setString(words);
    text.setPosition(location.x,location.y);
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::White);
}


int Button::getId() {
    return id;
}

sf::Text Button::getTextDraw() {
    return text;
}


void Button::SetColor(sf::Color color)
{
    text.setFillColor(color);
}