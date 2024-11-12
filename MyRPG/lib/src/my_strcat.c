/*
** EPITECH PROJECT, 2018
** my_strcmp
** File description:
** Reproduce the behavior of the strcmp function.
*/

#include <stdlib.h>
int my_strlen(char *);

char *my_strcat(char *s1, char *s2)
{
    char *str = malloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2) + 1));
    int j = my_strlen(s1);

    for (int i = 0; s1[i] != '\0'; i++)
        str[i] = s1[i];
    for (int i = 0; s2[i] != '\0'; i++) {
        str[j] = s2[i];
        j++;
    }
    str[j] = '\0';
    return (str);
} 
