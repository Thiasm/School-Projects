/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-mathias.roulleaux
** File description:
** main
*/

#include "../Menu/include/Menu.hpp"
#include "../include/Gameplay.hpp"
#include "ConnectionToServerManager.hpp"
#include "../include/Room.hpp"
#include "errorServer.hpp"

Manager manager;

int main(int ac, char **av)
{
    ConnectionToServerManager network;
    errorServer error(ac, av);

    if (error.getIsError() == false) {
       network.connect(av[1], std::stoi(av[2]));
        sf::RenderWindow wind(sf::VideoMode(1920, 1080), "R-Type");
        Menu menu(wind);
        menu.GameLoop();
        Room room(wind, network);
        room.GameLoop();
        network.player = room.getPlayer();
        Gameplay gp(wind, network);
        gp.GameLoop();
        network.disconnect();
   }
    return 0;
}