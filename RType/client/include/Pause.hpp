/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-mathias.roulleaux
** File description:
** Pause
*/

#ifndef PAUSE_HPP_
#define PAUSE_HPP_

#include "../Menu/include/Sprite.hpp"
#include "../Menu/include/Button.hpp"
#include "../Menu/include/Text.hpp"

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
//#include "Gameplay.hpp"

class Pause {
    public:
        Pause(sf::RenderWindow &wind, sf::Music *);
        ~Pause();
        void PauseLoop();
        void HandleInput(Text *);
        void changeColor(Button *, Button *, Button *);
        bool isActive = true; 
    protected:
    private:
        sf::RenderWindow &win;
        sf::Music *music;
        sf::Event event;
        int which = 0;
        int volume = 50;
};

#endif /* !PAUSE_HPP_ */
