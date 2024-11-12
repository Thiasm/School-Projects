/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** solver
*/

#include "my.h"

void init_maze(char *av, data_t *data)
{
    FILE *fd;
    char *str = NULL;
    int y = 0;
    size_t size = 0;

    fd = fopen(av, "r");
    while (getline(&str, &size, fd) != -1)
        y += 1;
    fclose(fd);
    data->maze = malloc(sizeof(char *) * (y + 1));
    fd = fopen(av, "r");
    for (int i = 0; getline(&str, &size, fd) != -1; i++) {
        data->maze[i] = malloc(sizeof(char) * strlen(str));
        data->maze[i] = my_strcpy(str);
        error_handling(data->maze[i], i, data);
    }
    data->maze[y] = NULL;
    fclose(fd);
    free(str);
}

int main(int ac, char **av)
{
    data_t data;

    if (ac != 2)
        return (84);
    init_maze(av[1], &data);
    get_data(&data);
    if (data.height * data.width > 150000)
        return (0);
    if (a_star(&data) == 1)
        print_free_map(&data);
    return (0);
}