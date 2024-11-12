/*
** EPITECH PROJECT, 2018
** my_str_to_word_array.c
** File description:
** Splits a string into words
*/

#include "minishell.h"

int is_ope(char *str, int w)
{
    if ((str[w] == '|' && str[w + 1] == '|') || (str[w] == '&' &&
        str[w + 1] == '&') || (str[w] == '<' && str[w + 1] == '<') ||
        (str[w] == '>' && str[w + 1] == '>')) {
            if (w > 0 && str[w - 1] == '\\')
                return 0;
        return 2;
    }
    if (str[w] == ';' || str[w] == '|' || str[w] == '<'
        || str[w] == '>' || str[w] == '&') {
        if (w > 0 && str[w - 1] == '\\')
                return 0;
        return 1;
    }
    return 0;
}

int find_cmd_size(char *str)
{
    int size = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (is_ope(str , i) >= 1)
            size += 2;
    }
    return size;
}

char *add_cmd_letter(char *str, int *y, char **cmd)
{
    int k = 0;
    int where = 0;
    char *new = NULL;

    if (cmd[y[0]] == NULL) {
        new = malloc(2);
        new[0] = str[y[1]];
    }
    else {
        where = my_strlen(cmd[y[0]]);
        new = malloc(sizeof(char) * (where + 2));
        for (k = 0; cmd[y[0]][k] != '\0'; k++)
            new[k] = cmd[y[0]][k];
        new[k] = str[y[1]];
        new[k + 1] = '\0';
    }
    new[where + 1] = '\0';
    return (new);
}

int my_cmd_to_tab_loop(char *str, int *y, int *nb, char **cmd)
{
    if ((*nb = is_ope(str, y[1])) > 0) {
        y[0] += 1;
        cmd[y[0]] = NULL;
        cmd[y[0]] = add_cmd_letter(str, y, cmd);
        if (*nb == 2) {
            y[1] += 1;
            cmd[y[0]] = add_cmd_letter(str, y, cmd);
            *nb = 0;
        }
        y[0] += 1;
        cmd[y[0]] = NULL;
        *nb -= 1;
        if (is_ope(str, y[1] + 1) > 0) {
            printf("syntax error near unexpected token\n");
            return -1;
        }
        return 1;
    }
    return 0;
}

char **my_cmd_to_tab(char *str)
{
    int size = find_cmd_size(str);
    int *y = malloc(sizeof(int) * 2);
    int nb = 0;
    int ret;
    char **cmd = malloc(sizeof(char *) * (size + 1));

    y[0] = 0;
    y[1] = 0;
    cmd[0] = NULL;
    for (y[1] = 0; str[y[1]] != '\0'; y[1]++) {
        nb = is_ope(str, y[1]);
        ret = my_cmd_to_tab_loop(str, y, &nb, cmd);
        if (ret == -1)
            return NULL;
        else if (ret == 0)
            cmd[y[0]] = add_cmd_letter(str, y, cmd);
    }
    cmd[y[0] + 1] = NULL;
    return (cmd);
}
