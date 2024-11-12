/*
** EPITECH PROJECT, 2018
** PSU_minishell_2018
** File description:
** builtins_cmds.c
*/

#include "minishell.h"

char *add_home_path(char *cmd)
{
    char *home_path = get_env_var("HOME=");
    char *full_cmd = NULL;

    if (!cmd[1] || (cmd[1] == '/' && !cmd[2]))
        return (home_path);
    if (home_path) {
        if (!(full_cmd = (char *)malloc(sizeof(char) *
        (my_strlen(home_path) + my_strlen(cmd) + 1))))
            return (NULL);
        full_cmd = my_strcpy(full_cmd, home_path);
        full_cmd = my_strcat(full_cmd, &cmd[1]);
        full_cmd = my_strcat(full_cmd, "/");
        free(home_path);
        return (full_cmd);
    }
    return (NULL);
}

void pwd(char **args)
{
    char *dir = NULL;
    dir = getcwd(dir, 4096);
    (void)args;
    my_putstr(dir);
    my_putstr("\n");
    free(dir);
}

void help(char **args)
{
    (void)args;
    my_printf("Mathias shell, version 42.0.1\n");
    my_printf("Type program names and arguments, and hit enter.\n");
    my_printf("The following shell commands are built in:\n");
    for (int i = 0; i < builtins_len(); i++)
        my_printf("  - %s\n", builtin_str[i]);
    my_printf("Use the man command for information on other programs.\n");
}

void exit_sh(char **args)
{
    (void)args;
    int ret;

    if (args[1]) {
        if (!my_str_isnum(args[1]) && args[2] == NULL) {
            ret = my_getnbr(args[1]);
            my_freetab(g_env);
            my_freetab(args);
            exit(ret);
        } else {
            my_putstr_fd("exit: Expression Syntax.\n", 2);
            return;
        }
    } else {
        my_freetab(g_env);
        my_freetab(args);
        exit(0);
    }
}
