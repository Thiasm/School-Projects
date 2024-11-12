/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** solver
*/

#include "my.h"

void print_free_map(data_t *data)
{
    for (int y = 0; y < data->height - 1; y++)
            printf("%s\n", data->maze[y]);
        printf("%s", data->maze[data->height - 1]);
    for (int i = 0; data->maze[i] != NULL; i++)
        free(data->maze[i]);
    free(data->maze);
}

char *my_strcpy(char *str)
{
    char *new;
    int i;

    new = malloc((strlen(str) + 1));
    for (i = 0; str[i]; i++)
        new[i] = str[i];
    new[i] = '\0';
    return (new);
}

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
    path_finder(data.maze, 0, 1);
    data.maze = find_start(data.maze);
    data.maze = correct_algo(data.maze, &data);
    print_free_map(&data);
    return (0);
}
