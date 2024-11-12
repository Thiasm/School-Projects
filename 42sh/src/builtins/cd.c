/*
** EPITECH PROJECT, 2018
** PSU_minishell_2018
** File description:
** cd.c
*/

#include "minishell.h"

int is_directory(const char *path)
{
    struct stat statbuf;

    if (stat(path, &statbuf) != 0)
        return 0;
    return S_ISDIR(statbuf.st_mode);
}

void what_err(char *cmd)
{
    if (access(cmd, F_OK) != 0) {
        my_putstr_fd(cmd, 2);
        my_putstr_fd(": No such file or directory.\n", 2);
        return;
    } else if (access(cmd, X_OK) != 0) {
        my_putstr_fd(cmd, 2);
        my_putstr_fd(": Permission denied.\n", 2);
        return;
    } else {
        if (is_directory(cmd) == 0) {
            my_putstr_fd(cmd, 2);
            my_putstr_fd(": Not a directory.\n", 2);
            return;
        } else
            perror(cmd);
    }
}

void cd_tilde(char **args, char *cmd, char *pwd)
{
    if (args[1][1] == '~') {
        my_putstr_fd("Unknow user: ~.\n", 2);
        return;
    }
    cmd = add_home_path(args[1]);
    if (cmd == NULL)
        my_putstr_fd("HOME: Undefined variable.\n", 2);
    else if (chdir(cmd) != 0)
        what_err(args[1]);
    else
        g_env = set_env_var("OLDPWD=", pwd);
    free(cmd);
}

void cd_else(char **args, char *pwd)
{
    char *cmd = get_env_var("OLDPWD=");

    if (args[1][0] == '-' && !args[1][1]) {
        if (cmd != NULL) {
            chdir(cmd);
            g_env = set_env_var("OLDPWD=", pwd);
        }
    } else {
        if (chdir(args[1]) != 0)
            what_err(args[1]);
        else
            g_env = set_env_var("OLDPWD=", pwd);
    }
    if (cmd)
        free(cmd);
}

void cd(char **args)
{
    char *cmd = NULL;
    char pwd[1024];

    my_bzero(pwd, 1024);
    getcwd(pwd, 1024);
    if (args[1] == NULL) {
        if ((cmd = get_env_var("HOME=")) == NULL) {
            my_putstr_fd("HOME: Undefined variable.\n", 2);
            return;
        }
        if (chdir(cmd) != 0)
            what_err(args[1]);
        else
            g_env = set_env_var("OLDPWD=", pwd);
    } else if (args[1][0] == '~') {
        cd_tilde(args, cmd, pwd);
    } else {
        cd_else(args, pwd);
    }
    if (cmd)
        free(cmd);
}
