/*
** EPITECH PROJECT, 2018
** delivery
** File description:
** error.c
*/

#include "my.h"

int error(int argc, char **argv)
{
    int j = 0;
    int height = my_atoi(argv[1]);
    int max = my_atoi(argv[2]);

    if (check_if_number(argv[1]) == 84)
        return (84);
    if (check_if_number(argv[2]) == 84)
        return (84);
    if (max <= 0)
        return (84);
    if (height < 1 || height > 99) {
        my_putstr("Error: this line is out of range\n");
        return (84);
    }
}

int check_if_number(char *str)
{
    int j = 0;

    while (j < my_strlen(str) - 1) {
        if (str[j] >= '0' && str[j] <= '9')
            j++;
        else
            return (84);
    }
    return (0);
}

void print_action(data_t *data, char *who)
{
    my_putstr(who);
    my_putstr(" removed ");
    my_put_nbr(data->matchs);
    my_putstr(" match(es) from line ");
    my_put_nbr(data->line);
    my_putchar('\n');
}
