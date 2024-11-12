/*
** EPITECH PROJECT, 2018
** my_str_to_word_array.c
** File description:
** Splits a string into words
*/

#include "my.h"

int is_alpha_num(char c)
{
    if (c != ' ' && c != '\0' && c != '\n' && c != '\r' && c != '\t')
        return 1;
    return 0;
}

int malloc_nbr_words(char const *str)
{
    int check = 0;
    int nbr = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        while (is_alpha_num(str[i]) == 1) {
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

int malloc_str_len(char const *str, int nbr)
{
    int len = 0;
    while (is_alpha_num(str[nbr]) != 0) {
        if (is_alpha_num(str[nbr]) != 1) {
            return (len + 1);
        }
        len++;
        nbr++;
    }
    return (len + 1);
}

char **my_str_to_word_array(char const *str)
{
    int i = 0;
    int j = 0;
    int len = 0;
    char **result = malloc(sizeof(char *)* malloc_nbr_words(str));

    while (str[len] != '\0' && !is_alpha_num(str[len]))
        len++;
    for (; str[len] != '\0';) {
        result[i] = malloc(sizeof(char)* malloc_str_len(str, len) + 1);
        for (j = 0; is_alpha_num(str[len]) != 0; j++) {
            result[i][j] = str[len];
            len++;
        }
        result[i][j] = '\0';
        while (str[len] != '\0' && is_alpha_num(str[len]) == 0)
            len++;
        i++;
    }
    result[i] = NULL;
    return result;
}
