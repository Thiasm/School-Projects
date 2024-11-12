/*
** EPITECH PROJECT, 2018
** lib_functions
** File description:
** my_hunter
*/

#include "struct.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int rng = 0;

    while (str[rng] != '\0') {
        my_putchar(str[rng]);
        rng++;
    }
    return (0);
}

int my_strlen(char const *str)
{
    int rng = 0;

    while (str[rng] != '\0') {
        rng++;
    }
    return (rng);
}

int my_strcmp(char *str1, char *str2)
{
    int i = 0;
    int j = 0;
    if (my_strlen(str1) != my_strlen(str2))
        return (84);
    for (j = my_strlen(str1); j > 0; j--) {
        if (str1[i] == str2[i])
        i++;
        else
            return (84);
    }
    my_putstr("JEUX INSPIRE DE DUCK HUNT\n\nObjectif :\
    tirer sur les canards et obtenir le plus de points\nCLick gauche\
    = TIR\nTouche R : Rechargement\n");
    return (0);
}
