/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-mathias.roulleaux
** File description:
** Text
*/

#include "../include/Text.hpp"

Text::Text(std::string content, int size, sf::Vector2f pos, sf::Color color): _size(size), _pos(pos), _color(color)
{
    font.loadFromFile("../re/ethnocentricrg.ttf");
    text.setFont(font);
    text.setString(content);
    text.setCharacterSize(_size);
    text.setPosition(_pos);
    text.setFillColor(_color);
}

void Text::setText(std::string newtext)
{
    text.setString(newtext);
}

Text::~Text()
{
}

sf::Text Text::getText()
{
    return text;
}
