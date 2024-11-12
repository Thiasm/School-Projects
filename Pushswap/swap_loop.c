/*
** EPITECH PROJECT, 2018
** swap_loop
** File description:
** pushswap
*/

#include "my.h"

int check_succes(var_t *var, int argc)
{
    int i = 0;

    while  (i < var->max_a - 1) {
        if (var->list_a[i] <= var->list_a[i + 1])
            i++;
        else {
            var->boucle = 0;
            return (0);
        }
    }
    return (1);
}

void sort_order(var_t *var, int argc)
{
    while (check_succes(var, argc) == 0) {
        if (var->list_a[0] > var->list_a[1])
            swap_a(var);
        if (check_succes(var, argc) == 0)
            push_b(var, argc);
    }
    while (var->max_b > 0)
        push_a(var, argc);
    if (check_succes(var, argc) == 0)
        sort_order(var, argc);
}
