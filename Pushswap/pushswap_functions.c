/*
** EPITECH PROJECT, 2018
** pushswap_functions
** File description:
** Pushswap
*/

#include "my.h"

void push_b(var_t *var, int argc)
{
    int i = 0;
    int j = argc - 1;

    while (j > 0) {
        var->list_b[j] = var->list_b[j - 1];
        j--;
    }
    var->list_b[0] = var->list_a[0];
    while (i < argc - 1) {
        var->list_a[i] = var->list_a[i + 1];
        i++;
    }
    var->max_a--;
    var->max_b++;
    if (var->space == 1)
        my_putchar(' ');
    my_putstr("pb");
    var->space = 1;
}

void push_a(var_t *var, int argc)
{
    int i = 0;
    int j = argc - 1;

    while (j > 0) {
        var->list_a[j] = var->list_a[j - 1];
        j--;
    }
    var->list_a[0] = var->list_b[0];
    while (i < argc - 1) {
        var->list_b[i] = var->list_b[i + 1];
        i++;
    }
    var->max_a++;
    var->max_b--;
    if (var->space == 1)
        my_putchar(' ');
    my_putstr("pa");
    var->space = 1;
}

void swap_a(var_t *var)
{
    my_swap(&var->list_a[1], &var->list_a[0]);
    if (var->space == 1)
        my_putchar(' ');
    my_putstr("sa");
    var->space = 1;
}

void rotate_ra(var_t *var, int argc)
{
    int j = argc - 1;
    int c = var->list_a[var->max_a - 1];

    while (j > 0) {
        var->list_a[j] = var->list_a[j - 1];
        j--;
    }
    var->list_a[0] = c;
    if (var->space == 1)
        my_putchar(' ');
    my_putstr("rra");
    var->space = 1;
}
