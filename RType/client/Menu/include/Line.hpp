/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-mathias.roulleaux
** File description:
** Line
*/

#ifndef LINE_HPP_
#define LINE_HPP_
#include "../include/Button.hpp"
#include "../include/Sprite.hpp"
#include "../include/Text.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include "Gameplay.hpp"
#include "ConnectionToServerManager.hpp"
#include "MessageComp.hpp"
class Line {
    public:
        Line(std::string path, sf::Vector2f position, std::string content, RequestType isThisPlayer, int id);
        ~Line();
        RequestType getThis();
        void setPos(sf::Vector2f);
        void setColor(sf::Color);
        sf::Sprite getSprite();
        sf::Text getText();
    protected:
    private:
        sf::Texture textu;
        sf::Sprite ship;
        sf::Font font;
        sf::Text text;
        RequestType _isThis; 
        sf::Vector2f _pos;
        sf::Color _color;
        int _id;
};

#endif /* !LINE_HPP_ */
