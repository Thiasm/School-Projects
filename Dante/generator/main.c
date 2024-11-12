/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main
*/

#include "my.h"
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

int error_handling(int ac, char **av, data_t *data)
{
    data->type = 0;
    if (ac < 3 || ac > 4)
        return (84);
    if (ac == 4) {
        if (my_strcmp(av[3], "perfect") != 0 &&
            my_strcmp(av[3], "imperfect") != 0)
            return (84);
        if (my_strcmp(av[3], "perfect") == 1)
            data->type = 1;
    }
    data->x = atoi(av[1]);
    data->y = atoi(av[2]);
    if (data->x == 0 || data->y == 0)
        return (84);
}

int main(int ac, char **av)
{
    data_t data;

    srand(getpid() * time(NULL));
    if (error_handling(ac, av, &data) == 84)
        return (84);
    data.map = malloc_tab(data.x, data.y);
    if (data.type == 0)
        imperfect_maze(&data);
    else if (data.type == 1)
        perfect_maze(&data);
    print_free_map(&data);
    return (0);
}
