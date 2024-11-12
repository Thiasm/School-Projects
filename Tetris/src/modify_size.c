/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** modify_size.c
*/

#include "tetris.h"
#include "proto.h"

char *get_row(int start, char *row, char *opt)
{
    int len = 0;
    int j = 0;

    for (int i = start; opt[i] != ','; i++)
        len++;
    row = malloc(sizeof(char) * (len + 1));
    for (int i = start; opt[i] != ','; i++) {
        row[j] = opt[i];
        j++;
    }
    row[j] = '\0';
    if (my_atoi(row) == -1) {
        write(2, "Invalid size.\n", 14);
        return NULL;
    }
    return row;
}

char *get_col(int start, char *col, char *opt)
{
    int len = 0;
    int j = 0;

    for (int i = start; opt[i] != '\0'; i++)
        len++;
    col = malloc(sizeof(char) * (len + 1));
    for (int i = start; opt[i] != '\0'; i++) {
        col[j] = opt[i];
        j++;
    }
    col[j] = '\0';
    if (my_atoi(col) == -1) {
        write(2, "Invalid size.\n", 14);
        return NULL;
    }
    return col;
}

char *modify_wnd(char *line, char *opt)
{
    char *row = NULL;
    char *col = NULL;
    int start = 0;
    int check = 0;

    for (; opt[start] != '='; start++);
    start++;
    for (; opt[check] != '\0' && opt[check] != ','; check++);
    if (check == my_strlen(opt)) {
        write(2, "Invalid size.\n", 14);
        return NULL;
    }
    if ((row = get_row(start, row, opt)) == NULL)
        return NULL;
    start += my_strlen(row) + 1;
    if ((col = get_col(start, col, opt)) == NULL)
        return NULL;
    row = my_strcat(row, "*");
    line = my_strcat(row, col);
    free(row);
    return line;
}