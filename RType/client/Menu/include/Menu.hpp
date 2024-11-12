/*
** EPITECH PROJECT, 2020
** R_Type
** File description:
** Menu
*/

#ifndef MENU_HPP_
#define MENU_HPP_

#include "../include/Button.hpp"
#include "../include/Sprite.hpp"
#include "../include/Text.hpp"
#include "../include/Pause.hpp"
#include <SFML/Graphics.hpp>
#include "Gameplay.hpp"

class Menu {
    public:
        Menu(sf::RenderWindow &);
        ~Menu();
        sf::RenderWindow * getwin();
        void GameLoop();
        void handleMoveMenu(Pause *pause);
        void change_color(Button *, Button *, Button *);
    protected:
    private:
        int which = 0;
        sf::Event event;
        sf::RenderWindow &win;
        bool isActive = true;

};

#endif /* !MENU_HPP_ */
