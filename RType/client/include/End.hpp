/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-mathias.roulleaux
** File description:
** End
*/

#ifndef END_HPP_
#define END_HPP_
#include "../Menu/include/Button.hpp"
#include "../Menu/include/Sprite.hpp"
#include "../Menu/include/Text.hpp"
#include "../include/Pause.hpp"
#include <SFML/Graphics.hpp>

class End {
    public:
        End(sf::RenderWindow &wind);
        ~End();
        void EndLoop();
    protected:
    private:
        sf::Event event;
        sf::RenderWindow &win;
};

#endif /* !END_HPP_ */
