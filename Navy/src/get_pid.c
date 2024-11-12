/*
** EPITECH PROJECT, 2019
** get pid
** File description:
** get pid
*/

#include "navy.h"

void get_pid(struct sigaction action, game_var_t *game_var)
{
    info.turn = 1;
    my_putstr("waiting for enemy connection...\n\n");
    while (info.other_pid == 0);
    usleep(2000);
    my_putstr("enemy connected\n\n");
    kill(info.other_pid, SIGUSR1);
}

void have_pid(int other, struct sigaction action, game_var_t *game_var)
{
    info.turn = 2;
    info.other_pid = other;
    kill(info.other_pid, SIGUSR1);
    while (info.other_pid == 0);
    usleep(2000);
    my_putstr("successfully connected\n\n");
    usleep(2000);
}