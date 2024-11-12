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
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdarg.h>
#include <stddef.h>

#define READ_SIZE 1

struct block {
char *name;
char *file_name;
char **form;
int width;
int height;
int color;
int check;
struct block *next;
};

typedef struct block block_t;

struct data {
int level;
int size;
block_t *first_block;
block_t *last_block;
};

typedef struct data data_t;

typedef struct idx_s {
    int k;
    int i;
    int stop;
}idx_t;

#endif
