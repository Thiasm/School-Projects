/*
** EPITECH PROJECT, 2018
** lib_function
** File description:
** bsq
*/

int my_strlen(char *str)
{
    int rng = 0;

    while (str[rng] != '\n') {
        rng++;
    }
    return (rng);
}

int my_strlen_tot(char *str)
{
    int rng = 0;

    while (str[rng] != '\0') {
        rng++;
    }
    return (rng);
}

int get_nb_rows(char *buffer)
{
    int count = 0;
    int f = 0;

    while (buffer[count] >= 48 && 57 >= buffer[count]) {
        f = f * 10 + (buffer[count] - 48);
        count = count + 1;
    }
    return (f);
}

int my_putstr(char const *str)
{
    int rng = 0;

    while (str[rng] != '\0') {
        my_putchar(str[rng]);
        rng++;
    }
    return (0);
}

void my_putchar(char c)
{
    write(1, &c, 1);
}
