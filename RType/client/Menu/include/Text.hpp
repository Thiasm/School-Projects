/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-mathias.roulleaux
** File description:
** Text
*/

#ifndef TEXT_HPP_
#define TEXT_HPP_

#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>

class Text {
    public:
        Text(std::string, int, sf::Vector2f, sf::Color);
        ~Text();
        sf::Text getText();
        void setText(std::string);
    protected:
    private:
        sf::Vector2f _pos;
        int _size;
        sf::Font font;
        sf::Text text;
        sf::Color _color;
};

#endif /* !TEXT_HPP_ */
