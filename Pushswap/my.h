/*
** EPITECH PROJECT, 2018
** delivery
** File description:
** my.h
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

struct var {
    int *list_a;
    int *list_b;
    int max_a;
    int max_b;
    int boucle;
    int space;
};

typedef struct var var_t;

int error(int argc, char **argv);
int my_strlen(char const *str);
int my_atoi(char *str);
void my_put_nbr(int nb);
void create_list_a(int argc, char **argv, var_t *var);
void my_put_nbr(int nb);
void my_putchar(char c);
void my_swap(int *a, int *b);
void swap_a(var_t *var);
int my_putstr(char const *str);
void init_var(var_t *var, int argc);
int check_succes(var_t *var, int argc);
void push_a(var_t *var, int argc);
void push_b(var_t *var, int argc);
void swap_a(var_t *var);
void sort_order(var_t *var, int argc);
void rotate_ra(var_t *var, int argc);
void free_list(var_t *var, int argc);