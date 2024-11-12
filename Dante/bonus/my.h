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
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>

struct data {
    char **maze;
    int height;
    int width;
};

typedef struct data data_t;

char **find_start(char **maze);
int get_data(data_t *data);
void error_handling(char *str, int y, data_t *data);
int path_finder(char **maze, int x, int y);
char **correct_algo(char **maze, data_t *data);



#endif
