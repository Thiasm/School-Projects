/*
** EPITECH PROJECT, 2018
** PSU_minishell_2018
** File description:
** builtins.c
*/

#include "minishell.h"

int builtins_len(void)
{
    return (my_tablen(builtin_str));
}

int is_in_builtins(char *cmd)
{
    char **cmds = my_cmd_to_exec(cmd);

    for (int i = 0; i < builtins_len(); i++) {
        if (my_strcmp(cmds[0], (builtin_str[i])) == 0) {
            return i + 1;
        }
    }
    return 0;

}

int check_builtin_cmd(char **cmds)
{
    for (int i = 0; i < builtins_len(); i++) {
        if (my_strcmp(cmds[0], (builtin_str[i])) == 0) {
            (builtin_func[i])(cmds);
            return i + 1;
        }
    }
    return 0;
}