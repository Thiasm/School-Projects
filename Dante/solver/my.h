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

typedef struct node {
    int cost;
    int x;
    int y;
    int close;
    struct node *next;
    struct node *parent;
} node_t;

struct list {
    node_t *first;
};

typedef struct list list_t;

struct data {
    char **maze;
    int height;
    int width;
    list_t list;
};

typedef struct data data_t;
 
void print_free_map(data_t *data);
char *my_strcpy(char *str);
void add_open(data_t *data, node_t *close);
int a_star(data_t *data);
void add_to_open(data_t *data, node_t *parent, int y, int x);
node_t *find_lowest_cost(data_t *data);
void print_path(data_t *data, node_t *node);
int open_number(data_t *data);
void find_friends(node_t *close, data_t *data);
int get_data(data_t *data);
void error_handling(char *str, int y, data_t *data);
int add_to_close(data_t *data, node_t *new);
int get_cost(data_t *data, int x, int y);
#endif
