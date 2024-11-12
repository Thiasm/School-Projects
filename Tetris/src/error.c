/*
** EPITECH PROJECT, 2019
** error
** File description:
** tetris
*/

#include "tetris.h"
#include "proto.h"

char *stradd(char *origin, char *add)
{
    int i = 0;
    int size = my_strlen(origin) + my_strlen(add);
    char *good;

    good = malloc(sizeof(char) * (size + 1));
    for (i = 0; origin[i]; i++)
        good[i] = origin[i];
    for (int j = 0; add[j] != '\0'; j++) {
        good[i] = add[j];
        i++;
    }
    good[i] = '\0';
    return (good);
}

int verify_form(block_t *block)
{
    int height = 0;
    int width = 0;
    int i = 0;
    int tmp;

    for (height = 0; block->form[height] != NULL; height++) {
        for (width = 0; block->form[height][width] != '\0'; width++) {
            if (block->form[height][width] != '*'
                && block->form[height][width] != ' ')
                block->check = -1;
            if (width >= block->width && block->form[height][width] == '*')
                block->check = -1;
        }
    }
    if (height > block->height)
        block->check = -1;
    return (0);
}
