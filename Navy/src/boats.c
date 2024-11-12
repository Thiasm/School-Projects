/*
** EPITECH PROJECT, 2019
** boats
** File description:
** functions to place the boats
*/

#include "navy.h"

char **fill_in_col(char **map, char *pos, int col)
{
    for (int i = pos[3] - 47 + 1; i != pos[6] - 47; i++) {
        if (map[i][col] != '.')
            return (NULL);
        map[i][col] = pos[0];
    }
    return (map);
}

char **fill_in_line(char **map, char *pos, int line)
{
    int col;

    for (int i = 2 + (pos[2] - 65) * 2 + 1; i != 2 + (pos[5] - 65) * 2; i++) {
        if (i % 2 == 0) {
            if (map[line][i] != '.')
                return (NULL);
            map[line][i] = pos[0];
        }
    }
    return (map);
}

char **place_boats(char **map, char *pos)
{
    int line;
    int col;

    col = 2 + (pos[2] - 65) * 2;
    line = pos[3] - 47;
    if (map[line][col] != '.')
        return (NULL);
    map[line][col] = pos[0];
    col = 2 + (pos[5] - 65) * 2;
    line = pos[6] - 47;
    if (map[line][col] != '.')
        return (NULL);
    map[line][col] = pos[0];
    if (pos[2] == pos[5]) {
        if ((map = fill_in_col(map, pos, col)) == NULL)
            return (NULL);
    }
    if (pos[3] == pos[6])
        map = fill_in_line(map, pos, line);
    return (map);
}

char **add_boats(char **map, char **pos)
{
    for (int i = 0; pos[i] != NULL; i++)
        if ((map = place_boats(map, pos[i])) == NULL)
            return (NULL);
    return (map);
}

int check_boats(char **pos)
{
    for (int i = 0; pos[i] != NULL; i++) {
        if (pos[i][0] < '2' || pos[i][0] > '5')
            return (84);
        if (pos[i][1] != ':' || pos[i][4] != ':')
            return (84);
        if (pos[i][2] < 'A' || pos[i][2] > 'H' || pos[i][5] < 'A' ||
            pos[i][5] > 'H')
            return (84);
        if (pos[i][3] < '1' || pos[i][3] > '8' || pos[i][6] < '1' ||
            pos[i][6] > '8')
            return (84);
        if (check_len(pos[i]) == 84)
            return (84);
    }
    if (count_boats(pos) == 84)
        return (84);
    return (0);
}