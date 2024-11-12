/*
** EPITECH PROJECT, 2019
** your_turn
** File description:
** navy
*/

#include "navy.h"

char *check_input(char *input)
{
    my_putstr("attack: ");
    input = get_next_line(0);
    if (input == NULL)
        return ("aa");
    if (my_strlen(input) > 2 || my_strlen(input) < 2)
        return (NULL);
    if (input[0] < 'A' || input[0] > 'H')
        return (NULL);
    if (input[1] < '1' || input[1] > '8')
        return (NULL);
    return (input);
}

int your_turn(struct sigaction action, game_var_t *game_var)
{
    char *input = NULL;
    int first;
    int second;

    while ((input = check_input(input)) == NULL)
        my_putstr("wrong position\n");
    if (input[0] == 'a' && input[1] == 'a')
        return (84);
    first = input[0] - 64;
    second = input[1] - 48;
    info.play[0] = input[0];
    info.play[1] = input[1];
    for (int i = 0; i < first; i++) {
        usleep(5000);
        kill(info.other_pid, SIGUSR1);
        pause();
    }
    usleep(5000);
    kill(info.other_pid, SIGUSR2);
    pause();
    send_number(input, second);
}

void send_number(char *input, int second)
{
    for (int j = 0; j < second; j++) {
        usleep(5000);
        kill(info.other_pid, SIGUSR1);
        pause();
    }
    usleep(5000);
    kill(info.other_pid, SIGUSR2);
    pause();
    my_putstr(input);
    my_putstr(": ");
}
