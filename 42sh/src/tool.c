/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** tool
*/

#include "minishell.h"

char *my_itoc(int number)
{
    int tmp = number;
    int size = 1;
    char *score;

    if (number < 0)
        return (0);
    while (tmp >= 10) {
        tmp = tmp / 10;
        size++;
    }
    score = malloc(sizeof(char) * size + 1);
    tmp = number;
    score[size] = '\0';
    size--;
    while (size >= 0) {
        score[size] = tmp % 10 + 48;
        tmp = tmp / 10;
        size--;
    }
    return (score);
}
