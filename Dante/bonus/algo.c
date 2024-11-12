/*
** EPITECH PROJECT, 2019
** algo.c
** File description:
** algo
*/

#include "my.h"

int width_finder(char *str)
{
    int len = 0;

    while (str[len] != '\0')
        len++;
    len = len - 1;
    return (len);
}

int height_finder(char **maze)
{
    int len = 0;

    while (maze[len] != NULL)
        len++;
    return (len);
}

char **find_start(char **maze)
{
    if (maze[0][0] == '*')
        maze[0][0] = 'o';
    return (maze);
}

int path_finder(char **maze, int x, int y)
{
    if (maze[x][y] == '*')
        maze[x][y] = 'o';
    else
        return 0;
    if (x == height_finder(maze) - 1  && y == width_finder(maze[0]) - 1)
        return 1;
    if (x + 1 < height_finder(maze) && maze[x + 1][y] == '*')
        if (path_finder(maze, x + 1, y))
            return 1;
    if (x - 1 >= 0 && maze[x - 1][y] == '*')
        if (path_finder(maze, x - 1, y))
            return 1;
    if (y + 1 < width_finder(maze[0]) && maze[x][y + 1] == '*')
        if (path_finder(maze, x, y + 1))
            return 1;
    if (y - 1 >= 0 && maze[x][y - 1] == '*')
        if (path_finder(maze, x, y - 1))
            return 1;
    maze[x][y] = '*';
    return 0;
}

char **correct_algo(char **maze, data_t *data)
{
    if ((maze[0][2] == '*' || maze[1][1] == 'X') &&
        (maze[1][1] == '*' || maze[1][1] == 'X'))
        maze[0][1] = '*';
    maze[data->height - 1][data->width] = 'o';
    return (maze);
}
