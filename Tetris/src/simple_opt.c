/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** simple_opt.c
*/

#include "tetris.h"
#include "proto.h"

char *modify_level(char *line, char *new_str)
{
    if (my_atoi(new_str) == -1) {
        write(2, "Invalid level.\n", 15);
        return NULL;
    }
    free(line);
    line = my_str_dup(new_str);
    return line;
}

char *modify_key(char *line, char *new_str)
{
    char *key = NULL;
    int len = 0;
    int j = 0;

    if (new_str == NULL) {
        write(2, "Invalid argument.\n", 18);
        return NULL;
    }
    key = malloc(sizeof(char) * (my_strlen(new_str) + 1));
    for (int i = 0; new_str[i] != '\0'; i++) {
        key[j] = new_str[i];
        j++;
    }
    key[my_strlen(new_str)] = '\0';
    free(line);
    if (my_strcmp(key, " ") == 0)
        line = my_str_dup("(space)");
    else
        line = my_str_dup(key);
    free(key);
    return line;
}

int other_opt(char ***info, char **av, int *i)
{
    if (my_strcmp(av[(*i)], "-d") == 0) {
        if (((*info)[3] = modify_key((*info)[3], av[(*i) + 1])) == NULL)
            exit(84);
        (*i) += 2;
        return 1;
    }
    if (my_strcmp(av[(*i)], "-q") == 0) {
        if (((*info)[4] = modify_key((*info)[4], av[(*i) + 1])) == NULL)
            exit(84);
        (*i) += 2;
        return 1;
    }
    if (my_strcmp(av[(*i)], "-p") == 0) {
        if (((*info)[5] = modify_key((*info)[5], av[(*i) + 1])) == NULL)
            exit(84);
        (*i) += 2;
        return 1;
    }
    if (see_next(i, av, info) == 1)
        return 1;
    return 0;
}

int short_opt(int *i, char **av, char ***info)
{
    if (my_strcmp(av[(*i)], "-D") == 0 || my_strcmp(av[(*i)], "--debug") == 0) {
        (*i)++;
        return 1;
    }
    if (my_strcmp(av[(*i)], "-L") == 0) {
        if (((*info)[7] = modify_level((*info)[7], av[(*i) + 1])) == NULL)
            exit(84);
        (*i) += 2;
        return 1;
    }
    if (my_strcmp(av[(*i)], "-l") == 0) {
        if (((*info)[0] = modify_key((*info)[0], av[(*i) + 1])) == NULL)
            exit(84);
        (*i) += 2;
        return 1;
    }
    if (change_key_right(i, av, info) == 1)
        return 1;
    return 0;
}

char **modify_info(char **info, int ac, char **av)
{
    int i = 1;
    int check = 0;

    while (i < ac) {
        if (check == i) {
            write(2, "Invalid option.\n", 16);
            exit(84);
        }
        check = i;
        if (short_opt(&i, av, &info) == 1)
            continue;
        if (other_opt(&info, av, &i) == 1)
            continue;
        info = long_opt(info, av, &i);
    }
    return info;
}
