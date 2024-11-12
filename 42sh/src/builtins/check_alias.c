/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** check_alias.c
*/

#include "minishell.h"

char *get_token(char *new, int len, char **cmd, int nb_lines)
{
    int i = 0;

    for (int i = 0; cmd[i] != NULL; i++) {
        len += my_strlen(cmd[i]);
        len++;
    }
    free(new);
    new = malloc(sizeof(char) * len);
    for (int j = 0; cmd[j] != NULL; j++) {
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

void check_alias(room_t *room)
{
    char **cmd = my_cmd_to_exec(room->token);
    int len = 0;
    int nb_lines = count_lines(cmd);

    if (!cmd || !cmd[0] || my_strcmp(cmd[0], "alias") == 0)
        return;
    for (int i = 0; cmd[i] != NULL; i++) {
        for (int j = 0; aliases[j] != NULL; j++) {
            if (my_strcmp(aliases[j], cmd[i]) == 0) {
                free(cmd[i]);
                cmd[i] = my_strdup(def_alias[j]);
            }
        }
    }
    room->token = get_token(room->token, len, cmd, nb_lines);
    for (int i = 0; cmd[i]; i++)
        free(cmd[i]);
    free(cmd);
}

char **replace_by(char **cmd, int i)
{
    char *env = getenv(&cmd[i][1]);
    char *error = NULL;

    if (env == NULL) {
        error = malloc(sizeof(char) * strlen(cmd[i]) + 23);
        error = strcpy(error, &cmd[i][1]);
        error = strcat(error, ": Undefined variable.");
        cmd[i] = strdup(error);
        return (cmd);
    } else {
        free(cmd[i]);
        cmd[i] = malloc(sizeof(char) * 1000);
        cmd[i] = strcpy(cmd[i], env);
        return (cmd);
    }
}

void check_dolls(char **cmd)
{
    for (int i = 0; cmd[i] != NULL; i++) {
        if (cmd[i][0] == '$') {
            cmd = replace_by(cmd, i);
        }
    }
}
