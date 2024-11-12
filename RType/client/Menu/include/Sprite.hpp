/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-mathias.roulleaux
** File description:
** Sprite
*/

#ifndef SPRITE_HPP_
#define SPRITE_HPP_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class Sprite {
    public:
        Sprite(std::string path, sf::Vector2f position);
        ~Sprite();
        void setTextu(std::string);
        void setPosi(sf::Vector2f);
        sf::Vector2f getPosi();
        sf::Sprite getSprite();
    protected:
    private:
    sf::Vector2f posi;
    sf::Sprite sprite;
    sf::Texture textu;
};

#endif /* !SPRITE_HPP_ */
