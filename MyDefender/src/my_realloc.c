/*
** EPITECH PROJECT, 2019
** my_realloc
** File description:
** minishell1
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

int **my_realloc_int(int **tab, int size)
{
    int **new_tab;
    int line = 0;
    int j = 0;

    while (tab[line] != NULL)
        line++;
    if ((new_tab = malloc(sizeof(int *) * (line + size + 1))) == NULL)
        return (NULL);
    new_tab[line + size] = NULL;
    while (j < line) {
        new_tab[j] = tab[j];
        j++;
    }
    free(tab);
    return (new_tab);
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