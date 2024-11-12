/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main
*/

#include "rpg.h"

int check_malloc(general_t *general, other_t *other, player_t *player,
world_t *world)
{
    if (general == NULL)
        return (EXIT_ERROR);
    if (other == NULL)
        return (EXIT_ERROR);
    if (player == NULL)
        return (EXIT_ERROR);
    if (world == NULL)
        return (EXIT_ERROR);
    return (EXIT_OK);
}

int main (int ac, char **av, char **env)
{
    general_t *general = malloc(sizeof(general_t));
    other_t *other = malloc(sizeof(other_t));
    player_t *player = malloc(sizeof(player_t));
    world_t *world = malloc(sizeof(world_t));

    if (check_malloc(general, other, player, world) == 84) {
        write(2, "Error: No more empty place!\n", 28);
        return (EXIT_ERROR);
    }
    if (my_getenv(env, "DISPLAY") == NULL)
        return (EXIT_ERROR);
    if (verify_all_files() == false)
        return (EXIT_ERROR);
    if (ac == 2 && av[1]) {
        my_printf("USAGE:\n./my_rpg\n");
        return (EXIT_OK);
    }
    menu_main_initiliaze(general, world, player, other);
    return (EXIT_ERROR);
}