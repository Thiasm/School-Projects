/*
** EPITECH PROJECT, 2018
** lib_my
** File description:
** my_strsplit.c
*/

#include "my.h"

static int array_size(char const *s, char c)
{
    int i = 0;
    int cnt = 0;

    while (*s) {
        if (i == 1 && *s == c)
            i = 0;
        if (i == 0 && *s != c) {
            i = 1;
            cnt++;
        }
        s++;
    }
    return (cnt);
}

static int word_len(char const *s, char c)
{
    int len = 0;

    while (*s && *s != c) {
        s++;
        len++;
    }
    return (len);
}

char **my_strsplit(char const *s, char c)
{
    int i = 0;
    int nb_word = array_size(s, c);
    char **tab = (char **)malloc(sizeof(char *) * ((array_size(s, c)) + 1));

    if (tab == NULL)
        return (NULL);
    while (nb_word--) {
        while (*s && *s == c)
            s++;
        tab[i] = my_strsub((const char *)s, 0, word_len(s, c));
        if (tab[i] == NULL)
            return (NULL);
        s = s + word_len(s, c);
        i++;
    }
    tab[i] = NULL;
    return (tab);
}
