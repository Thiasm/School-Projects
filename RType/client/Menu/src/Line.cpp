/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-mathias.roulleaux
** File description:
** Line
*/

#include "../include/Line.hpp"
#include "ConnectionToServerManager.hpp"
Line::Line(std::string path, sf::Vector2f position, std::string content, RequestType isThisPlayer, int id): _isThis(isThisPlayer), _pos(position), _id(id)
{
    if (_isThis == RequestType::PLAYER1 && id == 1 || _isThis == RequestType::PLAYER2 && id == 2)
        _color = sf::Color::Green;
    else 
        _color = sf::Color::White;
    textu.loadFromFile(path);
    textu.setSmooth(true);
    ship.setTexture(textu);
    ship.setPosition(_pos);
    font.loadFromFile("../re/ethnocentricrg.ttf");
    text.setFont(font);
    text.setString(content);
    text.setPosition(_pos.x + 250, _pos.y);
    text.setCharacterSize(30);
    text.setFillColor(_color);
}


Line::~Line()
{
}

RequestType Line::getThis()
{
    return (_isThis);
}

void Line::setPos(sf::Vector2f posi)
{
    _pos = posi;
}

void Line:: setColor(sf::Color col)
{
    _color = col;
}

sf::Sprite Line::getSprite()
{
    return (ship);
}

sf::Text Line::getText()
{
    return (text);
}