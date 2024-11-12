/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** long_opt.c
*/

#include "tetris.h"
#include "proto.h"

char *get_key(int start, char *opt, char *key)
{
    int j = 0;

    if (opt[start] == '\0') {
        write(2, "Invalid key.\n", 13);
        return NULL;
    }
    for (int i = start; opt[i] != '\0'; i++) {
        key[j] = opt[i];
        j++;
    }
    key[j] = '\0';
    if (my_strcmp(key , " ") == 0) {
        free(key);
        key = my_str_dup("(space)");
    }
    return key;
}

char *long_modify_key(char *line, char *opt)
{
    int start = 0;
    int len = 0;
    char *key = NULL;

    for (; opt[start] != '='; start++);
    start++;
    for (int i = start; opt[i] != '\0'; i++)
        len++;
    key = malloc(sizeof(char) * (len + 1));
    if ((key = get_key(start, opt, key)) == NULL)
        return NULL;
    free(line);
    if (my_strncmp("--level=", opt, 8) == 0) {
        if (my_atoi(key) == -1) {
            write(2, "Invalid level.\n", 15);
            return NULL;
        }
    }
    line = my_str_dup(key);
    free(key);
    return line;
}

char **other_long_opt(char **info, char **av, int *i)
{
    if (my_strncmp("--key-quit=", av[(*i)], 11) == 0) {
        if ((info[4] = long_modify_key(info[4], av[(*i)])) == NULL)
            exit(84);
        (*i)++;
        return info;
    }
    if (my_strncmp("--key-pause=", av[(*i)], 12) == 0) {
        if ((info[5] = long_modify_key(info[5], av[(*i)])) == NULL)
            exit(84);
        (*i)++;
        return info;
    }
    if (modify_num(&info ,av, i) == 1)
        return info;
    return info;
}

char **long_opt(char **info, char **av, int *i)
{
    if (long_key_sides(&info, av, i) == 1)
        return info;
    if (my_strncmp("--key-turn=", av[(*i)], 11) == 0) {
        if ((info[2] = long_modify_key(info[2], av[(*i)])) == NULL)
            exit(84);
        (*i)++;
        return info;
    }
    if (my_strncmp("--key-drop=", av[(*i)], 11) == 0) {
        if ((info[3] = long_modify_key(info[3], av[(*i)])) == NULL)
            exit(84);
        (*i)++;
        return info;
    }
    info = other_long_opt(info, av, i);
    return info;
}