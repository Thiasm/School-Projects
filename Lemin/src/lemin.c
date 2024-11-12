/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** lemin
*/

#include "../include/my.h"

int main(int ac, char **av, char **env)
{
    data_t data;

    if (ac != 1)
        return (84);
    init_var(&data);
    data.return_value = parse_file(av[1], &data);
    if (data.return_value == 0) {
        link_rooms(&data);
        create_graph(&data);
        data.path = launch_pathfinding(&data);
        create_way(&data);
    }
    if (print_data(&data) == 84)
        return 84;
    free_all(&data);
    return (data.return_value);
}

void init_var(data_t *data)
{
    data->ant_number = 0;
    data->end_y = 0;
    data->start_y = 0;
    data->file = NULL;
    data->list = NULL;
    data->return_value = 0;
    data->rooms = NULL;
    data->tunnels = NULL;
    data->path = malloc(sizeof(char *) * 1000);
}

void free_all(data_t *data)
{
    if (data->file) {
        for (int i = 0; data->file[i] != NULL; i++)
            free(data->file[i]);
        free(data->file);
    }
    if (data->rooms) {
        for (int i = 0; data->rooms[i] != NULL; i++)
            free(data->rooms[i]);
        free(data->rooms);
    }
    if (data->tunnels) {
        for (int i = 0; data->tunnels[i] != NULL; i++)
            free(data->tunnels[i]);
        free(data->tunnels);
    }
}

int print_data(data_t *data)
{
    my_printf("#number_of_ants\n");
    if (data->ant_number > 0)
        my_printf("%d\n", data->ant_number);
    print_rooms(data);
    my_printf("#tunnels\n");
    if (data->tunnels)
        for (int y = 0; data->tunnels[y] != NULL; y += 2)
            my_printf("%s-%s\n", data->tunnels[y], data->tunnels[y + 1]);
    return (print_path(data));
}

void print_rooms(data_t *data)
{
    my_printf("#rooms\n");
    if (!data->rooms) {
        my_printf("##start\n");
        my_printf("##end\n");
    }
    else {
        for (int i = 0; data->rooms[i] != NULL; i += 3) {
            if (data->start_y == i)
                my_printf("##start\n");
            if (data->end_y == i)
                my_printf("##end\n");
            my_printf("%s %s %s\n", data->rooms[i],
            data->rooms[i + 1], data->rooms[i + 2]);
        }
    }
}