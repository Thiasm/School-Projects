/*
** EPITECH PROJECT, 2018
** PSU_minishell_2018
** File description:
** display_prompt.c
*/

#include "minishell.h"

void print_french_flag(void)
{

    my_putstr("\x1b[44m");
    my_putchar(' ');
    my_putstr("\x1b[47m");
    my_putchar(' ');
    my_putstr("\x1b[41m");
    my_putchar(' ');
    my_putstr("\x1b[0m");
}

char *get_env_var(char *var)
{
    int start;
    char *tmp = NULL;
    char *content = NULL;

    for (int i = 0; g_env[i] != NULL; i++) {
        if (!my_strncmp(g_env[i], var, my_strlen(var))) {
            start = my_strlen(var);
            tmp = my_strsub(g_env[i], start, my_strlen(g_env[i]) - start);
            content = my_strdup(tmp);
            free(tmp);
            return content;
        }
    }
    return NULL;
}

char **set_env_var(char *s, char *content)
{
    char *tmp = NULL;

    for (int i = 0; g_env[i] != NULL; i++) {
        if (!my_strncmp(g_env[i], s, my_strlen(s)) && content) {
            tmp = my_strjoin(s, content);
            free(g_env[i]);
            g_env[i] = tmp;
            return g_env;
        }
    }
    return g_env;
}

void put_prompt(char *user, char *home, char *cwd)
{
    my_putchar('[');
    if (user)
        my_putstr(user);
    else
        my_putstr("unknow");
    my_putchar(' ');
    if (home && my_strstr(cwd, home)) {
        my_putchar('~');
        my_putstr(&my_strstr(cwd, home)[my_strlen(home)]);
    } else if (cwd[0])
        my_putstr(cwd);
    else
        my_putstr("nowhere");
    my_putchar(']');
    print_french_flag();
    my_putstr("$> ");
    free(user);
    free(home);
}

void display_prompt(int nb)
{
    char *pwd = NULL;
    char *home = NULL;
    char *user = NULL;
    char cwd[1024];

    if (!isatty(0))
        return;
    if (nb)
        pwd = get_env_var("PWD=");
    else
        pwd = my_strnew(1024);
    my_bzero(cwd, 1024);
    getcwd(cwd, 1024);
    g_env = set_env_var("PWD=", cwd);
    user = get_env_var("USER=");
    home = get_env_var("HOME=");
    put_prompt(user, home, cwd);
    free(pwd);
}
