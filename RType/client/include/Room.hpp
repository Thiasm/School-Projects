/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-mathias.roulleaux
** File description:
** Room
*/

#ifndef ROOM_HPP_
#define ROOM_HPP_

#include "../Menu/include/Button.hpp"
#include "../Menu/include/Sprite.hpp"
#include "../Menu/include/Text.hpp"
#include "../include/Pause.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include "ConnectionToServerManager.hpp"
#include "Gameplay.hpp"
#include "../Menu/include/Line.hpp"
#include "MessageComp.hpp"


class Room {
    public:
        Room(sf::RenderWindow &wind, ConnectionToServerManager &network);
        ~Room();
        void GameLoop();
        void DrawPlayer(Line *, Line *, Text *, Text *);
        bool getIsTwo();
        RequestType getPlayer();
    protected:
    private:
        sf::RenderWindow &win;
        sf::Event event;
        bool isActive = true;
        bool isTwo;
        ConnectionToServerManager &net;
        RequestType player;
        bool gameLaunch = false;
};

#endif /* !ROOM_HPP_ */
