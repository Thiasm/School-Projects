/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** alias.c
*/

#include "minishell.h"

int count_lines(char **cmd)
{
    int nb_lines = 0;

    for (; cmd[nb_lines] != NULL; nb_lines++);
    return nb_lines;
}

char *get_alias(char *new, char **cmd, int len)
{
    int i = 0;
    int nb_lines = count_lines(cmd);

    for (int j = 2; cmd[j] != NULL; j++) {
        len += my_strlen(cmd[j]);
        len++;
    }
    new = malloc(sizeof(char) * len);
    for (int j = 2; cmd[j] != NULL; j++) {
        for (int k = 0; cmd[j][k] != '\0'; k++) {
            new[i] = cmd[j][k];
            i++;
        }
        if (j == nb_lines - 1)
            new[i] = '\0';
        else {
            new[i] = ' ';
            i++;
        }
    }
    return new;
}

void init_alias(void)
{
    if (!aliases) {
        aliases = malloc(sizeof(char *) * 1);
        aliases[0] = NULL;
        def_alias = malloc(sizeof(char *) * 1);
        def_alias[0] = NULL;
    }
}

void add_alias(char *new, char **cmd, int line)
{
    aliases = realloc(aliases, sizeof(char *) * (count_lines(aliases) + 2));
    def_alias = realloc(def_alias, sizeof(char *) *
        (count_lines(def_alias) + 2));
    aliases[line] = my_strdup(cmd[1]);
    aliases[line + 1] = NULL;
    def_alias[line] = my_strdup(new);
    def_alias[line + 1] = NULL;
}

void alias(char **cmd)
{
    char *new = NULL;
    int len = 0;
    int line = 0;
    int check = 0;

    if (count_lines(cmd) <= 2) {
        my_putstr_fd("Not enough arguments.\n", 2);
        return;
    }
    for (int i = 0; aliases[i] != NULL; i++) {
        if (my_strcmp(cmd[1], aliases[i]) == 0) {
            line = i;
            check++;
        }
    }
    if (check == 0)
        for (; aliases[line] != NULL; line++);
    new = get_alias(new, cmd, len);
    add_alias(new, cmd, line);
    free(new);
}