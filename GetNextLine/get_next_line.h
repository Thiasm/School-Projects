/*
** EPITECH PROJECT, 2018
** get_next_line
** File description:
** .h
*/

#include <stddef.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
static char *rest = NULL;
static char *tmp = NULL;

# ifndef READ_SIZE
#   define READ_SIZE (1)
# endif

char *end_of_line(char *new, int i);
char *stock_rest(char *new, int i);
char *get_next_line(int fd);
char *create_tmp(char *new, int i);
char *resize_tmp(char *new);
