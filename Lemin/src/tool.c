/*
** EPITECH PROJECT, 2019
** tool.c
** File description:
** Usefull fonctions.
*/

#include "../include/my.h"

char *my_realloc(char *str, int size)
{
    char *new = malloc(sizeof(char) * (size + 1));
    int i = 0;

    if (str == NULL || new == NULL || size < 1)
        return (NULL);
    for (i = 0; i < size && str[i] != '\0'; i++)
        new[i] = str[i];
    new[i] = '\0';
    free(str);
    return (new);
}

char **my_realloc_tab(char **tab, int size)
{
    char **new_tab;
    int line = 0;
    int j = 0;

    while (tab[line] != NULL)
        line++;
    if ((new_tab = malloc(sizeof(char *) * (line + size + 1))) == NULL)
        return (NULL);
    new_tab[line + size] = NULL;
    while (j < line) {
        new_tab[j] = tab[j];
        j++;
    }
    free(tab);
    return (new_tab);
}

char *my_strcpy(char *src)
{
    int i = 0;
    char *dest = NULL;

    if (src == NULL)
        return (NULL);
    dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    while (src[i] != '\0') {
        dest[i] = src[i];
        i = i + 1;
    }
    dest[i] = '\0';
    return (dest);
}