/*
** EPITECH PROJECT, 2018
** my_getnbr.c
** File description:
** Return a nbr from a given str
*/

char get_sign(char *str)
{
    int minus = 0;

    for (int len = 0; str[len] == '-' || str[len] == '+'; len++) {
        if (str[len] == '-')
            minus++;
    }
    if ((minus % 2) == 0)
        return ('+');
    else
        return ('-');
}

int my_getnbr(char *str)
{
    int nbr = 0;
    int i = 0;

    while (str[i] == '+' || str[i] == '-')
        i++;
    while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0') {
        nbr = (nbr + (str[i] - '0'));
        i++;
        if (str[i] >= '0' && str[i] <= '9')
            nbr *= 10;
    }
    if (get_sign(str) == '-')
        nbr *= -1;
    return (nbr);
}
