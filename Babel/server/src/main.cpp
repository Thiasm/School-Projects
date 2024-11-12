/*
** EPITECH PROJECT, 2020
** CPP_babel_2020
** File description:
** main
*/

#include "Server.hpp"
#include "errorServer.hpp"

int main(int ac, char **av)
{
    errorServer error(ac, av);

    if (error.getIsError() == false) {
        Server server;
        server.launch(av[1], av[2]);
    }
}