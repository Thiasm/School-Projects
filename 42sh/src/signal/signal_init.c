/*
** EPITECH PROJECT, 2018
** PSU_minishell_2018
** File description:
** signal_init.c
*/

#include "minishell.h"

void init_sig_handler_3(signal_t **sig)
{
    sig[39]->err = my_strdup("Signal 39\n");
    sig[40]->err = my_strdup("Signal 40\n");
    sig[41]->err = my_strdup("Signal 41\n");
    sig[42]->err = my_strdup("Signal 42\n");
    sig[43]->err = my_strdup("Signal 43\n");
    sig[44]->err = my_strdup("Signal 44\n");
    sig[45]->err = my_strdup("Signal 45\n");
    sig[46]->err = my_strdup("Signal 46\n");
    sig[47]->err = my_strdup("Signal 47\n");
    sig[48]->err = my_strdup("Signal 48\n");
}

void init_sig_handler_2(signal_t **sig)
{
    sig[20]->err = my_strdup("Signal 20\0");
    sig[21]->err = my_strdup("Signal 21\0");
    sig[22]->err = my_strdup("Signal 22\0");
    sig[23]->err = my_strdup("Signal 23\0");
    sig[24]->err = my_strdup("Cputime limit exceeded\n");
    sig[25]->err = my_strdup("Filesize limit exceeded\n");
    sig[26]->err = my_strdup("Virtual time alarm\n");
    sig[27]->err = my_strdup("Profiling time alarm\n");
    sig[28]->err = my_strdup("Signal 28\0");
    sig[29]->err = my_strdup("Pollable event occured\n");
    sig[30]->err = my_strdup("Power failure\n");
    sig[31]->err = my_strdup("Bad system call\n");
    sig[32]->err = my_strdup("Signal 32\n");
    sig[33]->err = my_strdup("Signal 33\n");
    sig[34]->err = my_strdup("First Realtime Signal\n");
    sig[35]->err = my_strdup("Second Realtime Signal\n");
    sig[36]->err = my_strdup("Third Realtime Signal\n");
    sig[37]->err = my_strdup("Fourth Realtime Signal\n");
    sig[38]->err = my_strdup("Signal 38\n");
    init_sig_handler_3(sig);
}

void init_sig_handler(signal_t **sig)
{
    sig[1]->err = my_strdup("Hangup\n");
    sig[2]->err = my_strdup("\0");
    sig[3]->err = my_strdup("Quit\n");
    sig[4]->err = my_strdup("Illegal instruction\n");
    sig[5]->err = my_strdup("Trace/BPT trap\n");
    sig[6]->err = my_strdup("Abort\n");
    sig[7]->err = my_strdup("Bus error\n");
    sig[8]->err = my_strdup("Floating exception\n");
    sig[9]->err = my_strdup("Killed\n");
    sig[10]->err = my_strdup("User signal 1\n");
    sig[11]->err = my_strdup("Segmentation fault\n");
    sig[12]->err = my_strdup("User signal 2\n");
    sig[13]->err = my_strdup("Broken pipe\n");
    sig[14]->err = my_strdup("Alarm clock\n");
    sig[15]->err = my_strdup("Terminated\n");
    sig[16]->err = my_strdup("Stack limit exceeded\n");
    sig[17]->err = my_strdup("Signal 17\0");
    sig[18]->err = my_strdup("Signal 18\0");
    sig[19]->err = my_strdup("Signal 19\0");
    init_sig_handler_2(sig);
}