/*
** EPITECH PROJECT, 2019
** game
** File description:
** functions for the game loop
*/

#include "navy.h"

info_t info;

int game_loop(struct sigaction action, game_var_t *game_var)
{
    int print = 2;

    while (1) {
        usleep(5000);
        print_all(&print, game_var);
        if (info.turn == 1) {
            if (game_turn_1(action, game_var) == 84)
                return (0);
        }
        else if (info.turn == 2)
            game_turn_2(action, game_var);
        info.play[0] = '0';
        info.play[1] = '0';
        info.step = 1;
        print += 1;
        if (check_win(game_var) == 0)
            return (0);
        if (check_win(game_var) == 1)
            return (1);
    }
    return (2);
}

void print_all(int *print, game_var_t *game_var)
{
    if (*print == 2) {
        print_my_map(game_var->map);
        print_enemy_map(game_var->enemy_map);
        *print = 0;
    }
}

int game_turn_1(struct sigaction action, game_var_t *game_var)
{
    if (your_turn(action, game_var) == 84)
        return (84);
    info.step = 2;
    while (info.step == 2);
    if (info.step == 3) {
        my_putstr("missed\n\n");
        add_missed(game_var);
    }
    else if (info.step == 4) {
        game_var->enemy_life -= 1;
        my_putstr("hit\n\n");
        add_hit(game_var);
    }
    info.turn = 2;
    return (0);
}

int check_win(game_var_t *game_var)
{
    if (game_var->life == 0) {
        print_my_map(game_var->map);
        print_enemy_map(game_var->enemy_map);
        my_putstr("\nEnemy won\n");
        return (1);
    }
    else if (game_var->enemy_life == 0) {
        print_my_map(game_var->map);
        print_enemy_map(game_var->enemy_map);
        my_putstr("\nI won\n");
        return (0);
    }
    return (2);
}

void game_turn_2(struct sigaction action, game_var_t *game_var)
{
    my_putstr("waiting for enemy's attack...\n");
    while (info.step == 1);
    is_hit(game_var);
    info.turn = 1;
}
