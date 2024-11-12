/*
** EPITECH PROJECT, 2018
** PSU_minishell_2018
** File description:
** signal_handling.c
*/

#include "minishell.h"

void free_sig_handler(signal_t **sig_handler)
{
    for (int idx = 1; idx < 49; idx++) {
        free(sig_handler[idx]->err);
        free(sig_handler[idx]);
    }
    free(sig_handler);
}

void alloc_sig_handler(signal_t **sig_handler)
{
    for (int idx = 1; idx < 49; idx++) {
        if ((sig_handler[idx] = malloc(sizeof(signal_t) * 1)) == NULL)
            my_putstr_fd("malloc of sig_handler failed\n", 2);
    }
}

void signal_catcher(int signal)
{
    if (signal == SIGINT) {
        my_putchar('\n');
        if (isatty(1) == 0)
            exit(84);
    }
    g_signal = signal;
}

int signal_handler(char reset_signal, int is_parent)
{
    int tmp = g_signal;

    if (reset_signal == 1) {
        g_signal = 0;
        return (tmp);
    }
    if (is_parent == (0)) {
        if (signal(SIGINT, SIG_IGN) == SIG_ERR)
            my_putstr_fd("Can't initiate signal handler.\n", 2);
    }
    else if (is_parent == 1) {
        if (signal(SIGINT, signal_catcher) == SIG_ERR)
            my_putstr_fd("Can't initiate signal handler.\n", 2);
    }
    if (signal(SIGTERM, SIG_IGN) == SIG_ERR ||
        signal(SIGQUIT, SIG_IGN) == SIG_ERR ||
        signal(SIGTSTP, SIG_IGN) == SIG_ERR ||
        signal(SIGTTIN, SIG_IGN) == SIG_ERR ||
        signal(SIGTTOU, SIG_IGN) == SIG_ERR)
        my_putstr_fd("Can't initiate ignored signals.\n", 2);
    return (-1);
}

void parent_exec(int *status)
{
    signal_t **sig_handler;

    signal_handler(0, 0);
    if ((sig_handler = malloc(sizeof(signal_t *) * (49))) == NULL) {
        my_putstr_fd("malloc of sig_handler failed\n", 2);
    }
    alloc_sig_handler(sig_handler);
    init_sig_handler(sig_handler);
    if (WTERMSIG(*status) < 49 && sig_handler[WTERMSIG(*status)] != NULL)
        my_printf("%s", sig_handler[WTERMSIG(*status)]->err);
    free_sig_handler(sig_handler);
    return;
}