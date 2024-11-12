/*
** EPITECH PROJECT, 2019
** my_str_to_wordtab
** File description:
** transforme the char * in the char **
*/

#include <stdlib.h>

int cp_word(char *str, char c)
{
    int n = 1;

    for (int i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
        if ((str[i] == c || str[i] == '\t') && str[i + 1] != '\0')
            n++;
    }
    return (n);
}

int cp_char(char *str, char c)
{
    int i = 0;

    while (str[i] != c && str[i] != '\0' && str[i] != '\n' && str[i] != '\t')
        i++;
    i++;
    return (i);
}

char **my_str_to_wordtab(char *str, char c)
{
    char **tab = malloc(sizeof(char *) * (cp_word(str, c) + 1));
    int a = 0;
    int d = 0;
    int k = 0;

    for (int i = 0; str[i] != '\n' && str[i] != '\0';) {
        if (str[i] == c || str[i] == '\n' || str[i] == '\t') {
            while (str[i] == c || str[i] == '\t')
                i++;
            if ((str[0] != ' ' && str[0] != '\t') || k != 0)
                a++;
            d = 0;
        }
        k++;
        tab[a] = malloc(sizeof(char) * (cp_char(str + i, c) + 1));
        while (str[i] != c && str[i] != '\n' && str[i] != '\0'
               && str[i] != '\t')
            tab[a][d++] = str[i++];
    }
    return (tab);
}
