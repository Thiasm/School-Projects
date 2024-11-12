/*
** EPITECH PROJECT, 2019
** navy
** File description:
** navy
*/

#include "navy.h"

char **create_map(char **map, char **pos, int opt)
{
    map[0] = my_str_dup(" |A B C D E F G H");
    map[1] = my_str_dup("-+---------------");
    map[2] = my_str_dup("1|. . . . . . . .");
    map[3] = my_str_dup("2|. . . . . . . .");
    map[4] = my_str_dup("3|. . . . . . . .");
    map[5] = my_str_dup("4|. . . . . . . .");
    map[6] = my_str_dup("5|. . . . . . . .");
    map[7] = my_str_dup("6|. . . . . . . .");
    map[8] = my_str_dup("7|. . . . . . . .");
    map[9] = my_str_dup("8|. . . . . . . .");
    map[10] = NULL;
    if (opt == 1)
        map = add_boats(map, pos);
    return (map);
}

void init_game(int ac, char **av, struct sigaction action, game_var_t *game_var)
{
    init_struct(action);
    my_putstr("my_pid:  ");
    my_put_nbr(getpid());
    my_putchar('\n');
    if (ac == 2)
        get_pid(action, game_var);
    if (ac == 3)
        have_pid(my_atoi(av[1]), action, game_var);
}

char **get_pos(char **pos, char *file)
{
    int fd = open(file, O_RDONLY);
    char *buff;

    if (fd == -1)
        return (NULL);
    for (int i = 0; i != 4; i++) {
        if ((buff = get_next_line(fd)) == NULL) {
            close(fd);
            return (NULL);
        }
        pos[i] = my_str_dup(buff);
    }
    if (get_next_line(fd) != NULL)
        return (NULL);
    close(fd);
    pos[4] = NULL;
    if (check_boats(pos) == 84)
        return (NULL);
    return (pos);
}

void init_game_var(game_var_t *game_var)
{
    game_var->map = malloc(sizeof(char *) * 11);
    game_var->enemy_map = malloc(sizeof(char *) * 11);
    game_var->life = 14;
    game_var->enemy_life = 14;
}

int main(int ac, char **av)
{
    struct sigaction action;
    game_var_t game_var;
    char **pos = malloc(sizeof(char *) * 5);

    if (pos == NULL)
        return (84);
    init_game_var(&game_var);
    if (error(ac, av) == 0)
        return (84);
    if ((pos = get_pos(pos, av[ac - 1])) == NULL) {
        write(2, "Invalid file.\n", 14);
        return (84);
    }
    if ((game_var.map = create_map(game_var.map, pos, 1)) == NULL) {
        write(2, "Invalid file.\n", 14);
        return (84);
    }
    game_var.enemy_map = create_map(game_var.enemy_map, pos, 2);
    init_game(ac, av, action, &game_var);
    return (game_loop(action, &game_var));
}
