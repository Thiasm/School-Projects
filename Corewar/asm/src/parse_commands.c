/*
** EPITECH PROJECT, 2019
** parse_commands.c
** File description:
** Separate all commands and retruns them in a char **.
*/

#include "asm.h"

static int is_alpha_numm(char c)
{
    if (c != ' ' && c != '\0' && c != '\n'
        && c != '\r' && c != '\t' && c != ',')
        return 1;
    return 0;
}

static int malloc_nbr_wordss(char const *str)
{
    int check = 0;
    int nbr = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        while (is_alpha_numm(str[i]) == 1) {
            if (check == 0)
                nbr++;
            check = 1;
            if (str[i + 1] == '\0')
                break;
            i++;
        }
        check = 0;
    }
    return nbr;
}

static int malloc_str_lenn(char const *str, int nbr)
{
    int len = 0;

    while (is_alpha_numm(str[nbr]) != 0) {
        if (is_alpha_numm(str[nbr]) != 1) {
            return (len + 1);
        }
        len++;
        nbr++;
    }
    return (len + 1);
}

char **parse_command(char const *str)
{
    int i = 0;
    int j = 0;
    int len = 0;
    char **result = malloc(sizeof(char *)* malloc_nbr_wordss(str));

    while (str[len] != '\0' && !is_alpha_numm(str[len]))
        len++;
    for (; str[len] != '\0';) {
        result[i] = malloc(sizeof(char)* malloc_str_lenn(str, len) + 1);
        for (j = 0; is_alpha_numm(str[len]) != 0; j++) {
            result[i][j] = str[len];
            len++;
        }
        result[i][j] = '\0';
        while (str[len] != '\0' && is_alpha_numm(str[len]) == 0)
            len++;
        i++;
    }
    result[i] = NULL;
    return result;
}