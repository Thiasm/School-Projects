/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** pushswap
*/

#include "my.h"

void init_var(var_t *var, int argc)
{
    var->max_a = argc - 1;
    var->max_b = 0;
    var->boucle = 0;
}

int main(int argc, char **argv)
{
    var_t var;

    if (error(argc, argv) == 84)
        return (0);
    if (argc > 600)
        return (0);
    init_var(&var, argc);
    create_list_a(argc, argv, &var);
    sort_order(&var, argc);
    free_list(&var, argc);
    my_putchar('\n');
    return (0);
}

void create_list_a(int argc, char **argv, var_t *var)
{
    int j = 0;

    var->list_a = malloc(sizeof(int) * (argc));
    var->list_b = malloc(sizeof(int) * (argc));
    for (int i = 1; i < argc; i++) {
        var->list_a[j] = my_atoi(argv[i]);
        j++;
    }
}

void free_list(var_t *var, int argc)
{
    free(var->list_a);
    free(var->list_b);
}

int error(int argc, char **argv)
{
    int j = 0;

    if (argc < 2) {
        write(2, "invalid argument\n", 17);
        return (84);
    }
    for (int i = 1; i < argc; i++) {
        while (j < my_strlen(argv[i])) {
            if (argv[i][j] == '-' && j == 0)
                j++;
            else if (argv[i][j] < '0' || argv[i][j] > '9') {
                write(2, "invalid argument\n", 17);
                return (84);
            }
            else
                j++;
        }
        j = 0;
    }
}
