/*
** EPITECH PROJECT, 2019
** print_map
** File description:
** navy
*/

#include "navy.h"

info_t info;

void print_my_map(char **map)
{
    my_putstr("my positions:\n");
    for (int i = 0; map[i] != NULL; i++) {
        my_putstr(map[i]);
        my_putchar('\n');
    }
    my_putchar('\n');
}

void print_enemy_map(char **enemy_map)
{
    my_putstr("enemy's positions:\n");
    for (int i = 0; enemy_map[i] != NULL; i++) {
        my_putstr(enemy_map[i]);
        my_putchar('\n');
    }
    my_putchar('\n');
}

int check_len(char *pos)
{
    int count = 0;

    if (pos[2] == pos[5]) {
        count++;
        if (pos[3] - pos[6] != pos[0] - '0' - 1 && pos[6] - pos[3] != pos[0]
            - '0' - 1)
            return (84);
    }
    if (pos[3] == pos[6]) {
        count++;
        if (pos[2] - pos[5] != pos[0] - '0' - 1 && pos[5] - pos[2] != pos[0]
            - '0' - 1)
            return (84);
    }
    if (count == 2)
        return (84);
    return (0);
}

int count_boats(char **pos)
{
    int count_2 = 0;
    int count_3 = 0;
    int count_4 = 0;
    int count_5 = 0;

    for (int i = 0; pos[i] != NULL; i++) {
        if (pos[i][0] == '2')
            count_2++;
        if (pos[i][0] == '3')
            count_3++;
        if (pos[i][0] == '4')
            count_4++;
        if (pos[i][0] == '5')
            count_5++;
    }
    if (count_2 != 1 || count_3 != 1 || count_4 != 1 || count_5 != 1)
        return (84);
    return (0);
}