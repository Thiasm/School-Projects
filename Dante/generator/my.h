/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

struct data {
    int type;
    int x;
    int y;
    char **map;
};

typedef struct data data_t;

void my_putstr(char *str);
void my_putchar(char c);
char **int_tab(int x, int y);
char **malloc_tab(int x, int y);
int error_handling(int ac, char **av, data_t *data);
void print_free_map(data_t *data);
int my_strcmp(char *string, char *str);
void imperfect_maze(data_t *data);
void perfect_maze(data_t *data);
void create_imperfect(data_t *data);
void fill_maze(data_t *data);
void ajust_perfect(data_t *data);
void perfect_algo(data_t *data);

#endif
