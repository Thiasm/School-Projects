/*
** EPITECH PROJECT, 2018
** CPE_corewar_2018
** File description:
** my_nbrlen.c
*/

int higher_nums(int nbr)
{
    if (nbr >= 10000000) {
        if (nbr >= 1000000000)
            return 10;
        if (nbr >= 100000000)
            return 9;
        return 8;
    }
    if (nbr >= 1000000)
        return 7;
    return 6;
}

int my_nbrlen(int nbr)
{
    if (nbr >= 100000)
        return (higher_nums(nbr));
    else {
        if (nbr >= 1000) {
            if (nbr >= 10000)
                return 5;
            return 4;
        } else {
            if (nbr >= 100)
                return 3;
            if (nbr >= 10)
                return 2;
        }
        return 1;
    }
}