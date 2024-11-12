/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-mathias.roulleaux
** File description:
** main
*/

#include "Server.hpp"
#include "errorServer.hpp"

int main(int ac, char **av)
{
    errorServer error(ac, av);

    if (error.getIsError() == false) {
        Server server(av[1], av[2]);
        server.launch();
    }
}