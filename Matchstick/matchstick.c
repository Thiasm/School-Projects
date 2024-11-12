/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** main
*/

#include "my.h"

int main(int argc, char **argv)
{
    data_t data;
    int win;

    if (argc != 3)
        return (84);
    if (error(argc, argv) == 84)
        return (84);
    game_init(&data, argv);
    win = game_loop(&data);
    if (win == 84)
        return (0);
    my_putstr((win == 1) ? "I lost...snif...but I'll get you next time!!\n" :
    "You lost, too bad...\n");
    return (win);
}

int game_loop(data_t *data)
{
    int value = 0;

    print_map(data);
    data->print_line = 0;
    data->print_matches = 0;
    value = player_turn(data);
    data->ask_matches = 1;
    if (value == 2) {
        print_map(data);
        return (2);
    }
    if (value == 84)
        return (84);
    print_map(data);
    if (ia_turn(data) == 1) {
        print_map(data);
        return (1);
    }
    game_loop(data);
}

void init_var(data_t *data, char **argv)
{
    data->ask_matches = 1;
    data->height = my_atoi(argv[1]);
    data->max_matchs = my_atoi(argv[2]);
    data->nb_stick = (data->height * data->height);
    data->matchs = 0;
    data->line = 0;
    data->width = (data->height * 2) + 1;
    data->map = malloc(sizeof(char *) * (data->height + 2));
    for (int h = 0; h < data->height + 2; h++)
        data->map[h] = malloc((sizeof(char) * (data->width) + 1));
}

int game_init(data_t *data, char **argv)
{
    init_var(data, argv);
    create_map(data);
}
