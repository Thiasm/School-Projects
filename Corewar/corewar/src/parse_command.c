/*
** EPITECH PROJECT, 2018
** CPE_corewar_2018
** File description:
** parse_command.c
*/

#include "corewar.h"
#include "protos.h"

bool is_champion(char *name)
{
    int i = -1;

    if (!count_researched(name, '.'))
        return false;
    for (i = my_strlen(name); i != 0 && name[i] != '.'; i--);
    if (my_strncmp(name + i, ".cor\0", 5))
        return false;
    return true;
}

int load_dump(arena_t *arena, char **av, int *i)
{
    if (!my_strncmp("-dump\0", av[*i], 6)) {
        if (av[*i + 1] && !my_str_isnum(av[*i + 1])) {
            if ((arena->dump = my_getnbr(av[2])) < 1)
                return exit_prog(84, "error: dump cycle cannot be under 1.");
        } else
            return exit_prog(84, "error: dump cycle must be a number.");
        *i += 2;
    } else
        arena->dump = -1;
    return 0;
}

static bool prog_nbr_used(chmp_info_t *infos, int pos, int nbr)
{
    if (pos == 0)
        infos[0].prog_nbr = -1;
    for (int i = 0; i < pos; i++) {
        if (infos[i].prog_nbr == nbr)
            return exit_prog(true, "error: prog nbr already used.");
    }
    return false;
}

int load_prog_nbr(chmp_info_t *infos, char **av, int *i)
{
    static int pos = 0;

    if (av[*i] && !my_strncmp("-n\0", av[*i], 3)) {
        *i += 1;
        if (av[*i] && !my_str_isnum(av[*i]) &&
            !prog_nbr_used(infos, pos, my_getnbr(av[*i]))) {
            infos[pos].prog_nbr = my_getnbr(av[*i]) % MEM_SIZE;
            *i += 1;
            pos++;
            return 0;
        } else
            return 84;
    }
    infos[pos].prog_nbr = pos;
    pos++;
    return 0;
}

int load_add(chmp_info_t *infos, char **av, int *i)
{
    static int pos = 0;

    if (av[*i] && !my_strncmp("-a\0", av[*i], 3)) {
        *i += 1;
        if (av[*i] && !my_str_isnum(av[*i])) {
            infos[pos].load_add = my_getnbr(av[*i]) % MEM_SIZE;
            *i += 1;
            pos++;
            return 0;
        } else
            return exit_prog(84, "error: load address cannot be negative.");
    }
    infos[pos].load_add = -1;
    pos++;
    return 0;
}
