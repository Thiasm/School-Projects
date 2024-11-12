/*
** EPITECH PROJECT, 2019
** connect
** File description:
** functions to connect the terminals
*/

#include "navy.h"

info_t info;

void my_handler(int i, siginfo_t *signal, void *s)
{
    switch (info.step) {
    case 0:
        info.other_pid = signal->si_pid;
        info.step = 1;
        break;
    case 1:
        handler_step_1(i, signal ,s);
        break;
    case 2:
        handler_step_2(i, signal, s);
        break;
    }
}

void handler_step_1(int i, siginfo_t *signal, void *s)
{
    if (info.turn == 2) {
        usleep(2000);
        if (send_pos(i, signal, s) == 1)
            info.step = 2;
        kill(info.other_pid, SIGUSR1);
    }
}

void handler_step_2(int i, siginfo_t *signal, void *s)
{
    if (info.turn == 1) {
        usleep(5000);
        if (signal->si_signo == 12) {
            kill(info.other_pid, SIGUSR2);
            info.step = 4;
        }
        if (signal->si_signo == 10) {
            kill(info.other_pid, SIGUSR2);
            info.step = 3;
        }
    }
}

int send_pos(int i, siginfo_t *signal, void *s)
{
    if (signal->si_signo == 10) {
        if (info.play[0] >= '0' && info.play[0] <= '9') {
            info.play[0] += 1;
        } else
            info.play[1] += 1;
    } else {
        if (info.play[0] >= 'A' && info.play[0] <= 'H')
            return (1);
        if (info.play[0] >= '0' && info.play[0] <= '9')
            info.play[0] += 16;
    }
    return (0);
}

void init_struct(struct sigaction action)
{
    info.play[0] = '0';
    info.play[1] = '0';
    info.play[2] = '\0';
    info.other_pid = 0;
    info.step = 0;
    action.sa_sigaction = my_handler;
    action.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &action, NULL);
    sigaction(SIGUSR2, &action, NULL);
}
