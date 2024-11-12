/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-mathias.roulleaux
** File description:
** Sprite
*/

#include "../include/Sprite.hpp"

Sprite::Sprite(std::string path, sf::Vector2f position): posi(position)
{
    textu.loadFromFile(path);
    textu.setSmooth(true);
    sprite.setTexture(textu);
    sprite.setPosition(posi);
    sprite.setScale(1.22f, 1.22f);
}

Sprite::~Sprite()
{
}

void Sprite::setTextu(std::string new_path)
{
    textu.loadFromFile(new_path);
    textu.setSmooth(true);
    sprite.setTexture(textu);
}

sf::Vector2f Sprite::getPosi()
{
    return posi;
}

void Sprite::setPosi(sf::Vector2f new_pos)
{
    posi = new_pos;
    sprite.setPosition(posi);
}

sf::Sprite Sprite::getSprite()
{
    return sprite;
}