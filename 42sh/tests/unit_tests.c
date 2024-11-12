/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2018
** File description:
** unit_tests.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "minishell.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(builtins_len, test1)
{
    cr_assert_eq(builtins_len(), builtins_len());
}

Test(check_builtin_cmd, test1)
{
    char *tab[] = {"ls", "-l", "src", NULL};
    cr_assert_eq(check_builtin_cmd(tab), 0);
}

Test(check_builtin_cmd, test2)
{
    char *tab[] = {"env", NULL};
    cr_assert_eq(check_builtin_cmd(tab), 3);
}

Test(init_env, empty_env)
{
    cr_assert_eq(init_env(NULL), 84);
}

Test(init_env, test2)
{
    char *env[] = {"PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin"
        ":/home/thomas/.local/bin:/home/thomas/bin:/home/thomas/my_scripts",
        "USER=thomas", NULL};
    cr_assert_eq(init_env(env), 0);
}

Test(print_an_env, test1, .init = redirect_all_std)
{
    char *env[] = {"PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin"
        ":/home/thomas/.local/bin:/home/thomas/bin:/home/thomas/my_scripts",
        "USER=thomas", "EPITECH=42", NULL};
    char *cmd[] = {"printenv", "EPITECH", NULL};
    init_alias();
    init_env(env);
    print_an_env(cmd);
    cr_assert_stdout_eq_str("42\n");
}

Test(print_an_env, test2, .init = redirect_all_std)
{
    char *env[] = {"PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin"
        ":/home/thomas/.local/bin:/home/thomas/bin:/home/thomas/my_scripts",
        "USER=thomas", NULL};
    char *cmd[] = {"printenv", "USER", NULL};
    init_alias();
    init_env(env);
    print_an_env(cmd);
    cr_assert_stdout_eq_str("thomas\n");
}

Test(display_prompt, test1, .init = redirect_all_std)
{
    char *env[] = {"PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin"
        ":/home/thomas/.local/bin:/home/thomas/bin:/home/thomas/my_scripts",
        "USER=thomas", NULL};
    init_alias();
    init_env(env);
    display_prompt(42);
}

Test(display_prompt, test2, .init = redirect_all_std)
{
    char *env[] = {"PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin"
        ":/home/thomas/.local/bin:/home/thomas/bin:/home/thomas/my_scripts",
        "USER=thomas", "PWD=OH/NO", "HOME=OH", NULL};
    init_alias();
    init_env(env);
    display_prompt(42);
}

Test(display_prompt, test3, .init = redirect_all_std)
{
    char *env[] = {"PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin"
        ":/home/thomas/.local/bin:/home/thomas/bin:/home/thomas/my_scripts",
        NULL};
    init_alias();
    init_env(env);
    display_prompt(42);
}

Test(put_prompt, test1, .init = redirect_all_std)
{
    char *user = my_strdup("thamas");
    char *home = my_strdup("/home");
    char *cwd = my_strdup("/home/oksaj");

    put_prompt(user, home, cwd);
}

Test(put_prompt, test2, .init = redirect_all_std)
{
    char *user = my_strdup("thamas");
    char *home = my_strdup("/home");
    char *cwd = my_strdup("/");

    put_prompt(user, home, cwd);
}

Test(check_cmd, test1, .init = redirect_all_std)
{
    char *env[] = {"PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin"
        ":/home/thomas/.local/bin:/home/thomas/bin:/home/thomas/my_scripts",
        "USER=thomas", "PWD=OH/NO", "HOME=OH", NULL};
    char *cmd = my_strdup("ls");
    init_alias();
    init_env(env);
    cr_assert_eq(check_cmd(cmd), 0);
}

Test(check_cmd, test2, .init = redirect_all_std)
{
    char *env[] = {"PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin"
        ":/home/thomas/.local/bin:/home/thomas/bin:/home/thomas/my_scripts",
        "USER=thomas", "PWD=OH/NO", "HOME=OH", NULL};
    char *cmd = my_strdup("cd ..");
    init_alias();
    init_env(env);
    cr_assert_eq(check_cmd(cmd), 1);
}

Test(check_cmd, test3, .init = redirect_all_std)
{
    char *env[] = {"PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin"
        ":/home/thomas/.local/bin:/home/thomas/bin:/home/thomas/my_scripts",
        "USER=thomas", "PWD=OH/NO", "HOME=OH", NULL};
    char *cmd = my_strdup("/bin/ls");
    init_alias();
    init_env(env);
    cr_assert_eq(check_cmd(cmd), 0);
}

Test(check_cmd, test4, .init = redirect_all_std)
{
    char *env[] = {"PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin"
        ":/home/thomas/.local/bin:/home/thomas/bin:/home/thomas/my_scripts",
        "USER=thomas", "PWD=OH/NO", "HOME=OH", NULL};
    char *cmd = my_strdup("env");
    init_alias();
    init_env(env);
    cr_assert_eq(check_cmd(cmd), 3);
}

Test(check_cmd, test5, .init = redirect_all_std)
{
    char *env[] = {"PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin"
        ":/home/thomas/.local/bin:/home/thomas/bin:/home/thomas/my_scripts",
        "USER=thomas", "PWD=OH/NO", "HOME=OH", NULL};
    char *cmd = my_strdup("help");
    init_alias();
    init_env(env);
    cr_assert_eq(check_cmd(cmd), 8);
}

Test(check_cmd, test6, .init = redirect_all_std)
{
    char *env[] = {"PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin"
        ":/home/thomas/.local/bin:/home/thomas/bin:/home/thomas/my_scripts",
        "USER=thomas", "PWD=OH/NO", "HOME=OH", NULL};
    char *cmd = my_strdup("printenv USER");
    init_alias();
    init_env(env);
    cr_assert_eq(check_cmd(cmd), 7);
}

Test(check_cmd, test7, .init = redirect_all_std)
{
    char *env[] = {"PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin"
        ":/home/thomas/.local/bin:/home/thomas/bin:/home/thomas/my_scripts",
        "USER=thomas", "PWD=OH/NO", "HOME=OH", NULL};
    char *cmd = my_strdup("exit okok");
    init_alias();
    init_env(env);
    check_cmd(cmd);
}

Test(check_cmd, test8, .init = redirect_all_std)
{
    char *env[] = {"PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin"
        ":/home/thomas/.local/bin:/home/thomas/bin:/home/thomas/my_scripts",
        "USER=thomas", "PWD=OH/NO", "HOME=OH", NULL};
    char *cmd = my_strdup("cd ~");
    init_alias();
    init_env(env);
    cr_assert_eq(check_cmd(cmd), 1);
}

Test(check_cmd, test9, .init = redirect_all_std)
{
    char *env[] = {"PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin"
        ":/home/thomas/.local/bin:/home/thomas/bin:/home/thomas/my_scripts",
        "USER=thomas", "PWD=OH/NO", "HOME=/home", NULL};
    char *cmd = my_strdup("~/oui");
    init_alias();
    init_env(env);
    cr_assert_eq(check_cmd(cmd), 84);
}

Test(check_cmd, test10, .init = redirect_all_std)
{
    char *env[] = {"PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin"
        ":/home/thomas/.local/bin:/home/thomas/bin:/home/thomas/my_scripts",
        "USER=thomas", "PWD=OH/NO", "HOME=/home", NULL};
    char *cmd = my_strdup("cd ohno");
    init_alias();
    init_env(env);
    cr_assert_eq(check_cmd(cmd), 1);
}

Test(check_cmd, test11, .init = redirect_all_std)
{
    char *env[] = {"PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin"
        ":/home/thomas/.local/bin:/home/thomas/bin:/home/thomas/my_scripts",
        "USER=thomas", "PWD=OH/NO", "HOME=/home", NULL};
    char *cmd = my_strdup("cd");
    init_alias();
    init_env(env);
    cr_assert_eq(check_cmd(cmd), 1);
}

Test(check_cmd, test12, .init = redirect_all_std)
{
    char *env[] = {"PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin"
        ":/home/thomas/.local/bin:/home/thomas/bin:/home/thomas/my_scripts",
        "USER=thomas", "PWD=OH/NO", NULL};
    char *cmd = my_strdup("cd");
    init_alias();
    init_env(env);
    cr_assert_eq(check_cmd(cmd), 1);
}

Test(check_cmd, test13, .init = redirect_all_std)
{
    char *env[] = {"PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin"
        ":/home/thomas/.local/bin:/home/thomas/bin:/home/thomas/my_scripts",
        "USER=thomas", "PWD=OH/NO", NULL};
    char *cmd = my_strdup("unsetenv USER");
    init_alias();
    init_env(env);
    cr_assert_eq(check_cmd(cmd), 6);
}

Test(check_cmd, test14, .init = redirect_all_std)
{
    char *env[] = {"PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin"
        ":/home/thomas/.local/bin:/home/thomas/bin:/home/thomas/my_scripts",
        "USER=thomas", "PWD=OH/NO", NULL};
    char *cmd = my_strdup("unsetenv USER");
    init_alias();
    init_env(env);
    cr_assert_eq(check_cmd(cmd), 6);
}

Test(check_cmd, test15, .init = redirect_all_std)
{
    char *env[] = {"PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin"
        ":/home/thomas/.local/bin:/home/thomas/bin:/home/thomas/my_scripts",
        "USER=thomas", "PWD=OH/NO", NULL};
    char *cmd = my_strdup("epitech");
    init_alias();
    init_env(env);
    cr_assert_eq(check_cmd(cmd), 84);
}

Test(check_cmd, test16, .init = redirect_all_std)
{
    char *env[] = {"PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin"
        ":/home/thomas/.local/bin:/home/thomas/bin:/home/thomas/my_scripts",
        "USER=thomas", "PWD=OH/NO", NULL};
    char *cmd = my_strdup("cd ~/Download");
    init_alias();
    init_env(env);
    cr_assert_eq(check_cmd(cmd), 1);
}

Test(check_cmd, test17, .init = redirect_all_std)
{
    char *env[] = {"PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin"
        ":/home/thomas/.local/bin:/home/thomas/bin:/home/thomas/my_scripts",
        "USER=thomas", "PWD=OH/NO", NULL};
    char *cmd = my_strdup("cd unit_tests");
    init_alias();
    init_env(env);
    cr_assert_eq(check_cmd(cmd), 1);
}

Test(check_cmd, test18, .init = redirect_all_std)
{
    char *env[] = {"PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin"
        ":/home/thomas/.local/bin:/home/thomas/bin:/home/thomas/my_scripts",
        "USER=thomas", "PWD=OH/NO", NULL};
    char *cmd = my_strdup("cd ~~");
    init_alias();
    init_env(env);
    cr_assert_eq(check_cmd(cmd), 1);
}

Test(check_cmd, test19, .init = redirect_all_std)
{
    char *env[] = {"PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin"
        ":/home/thomas/.local/bin:/home/thomas/bin:/home/thomas/my_scripts",
        "USER=thomas", "HOME=/home/thomas", NULL};
    char *cmd = my_strdup("cd ~/Downloads");
    init_alias();
    init_env(env);
    cr_assert_eq(check_cmd(cmd), 1);
}

Test(check_cmd, test20, .init = redirect_all_std)
{
    char *env[] = {"PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin"
        ":/home/thomas/.local/bin:/home/thomas/bin:/home/thomas/my_scripts",
        "USER=thomas", "HOME=/home/thomas", NULL};
    char *cmd = my_strdup("cd -");
    init_alias();
    init_env(env);
    cr_assert_eq(check_cmd(cmd), 1);
}

Test(check_cmd, test21, .init = redirect_all_std)
{
    char *env[] = {"PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin"
        ":/home/thomas/.local/bin:/home/thomas/bin:/home/thomas/my_scripts",
        "USER=thomas", "HOME=/home/thomas", NULL};
    char *cmd = my_strdup("printenv");
    init_alias();
    init_env(env);
    cr_assert_eq(check_cmd(cmd), 7);
}

Test(check_cmd, test22, .init = redirect_all_std)
{
    char *env[] = {"PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin"
        ":/home/thomas/.local/bin:/home/thomas/bin:/home/thomas/my_scripts",
        "USER=thomas", "HOME=/home/thomas", NULL};
    char *cmd = my_strdup("printenv HOME=");
    init_alias();
    init_env(env);
    cr_assert_eq(check_cmd(cmd), 7);
}

Test(check_cmd, test23, .init = redirect_all_std)
{
    char *env[] = {"PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin"
        ":/home/thomas/.local/bin:/home/thomas/bin:/home/thomas/my_scripts",
        "USER=thomas", "HOME=/home/thomas", NULL};
    char *cmd = my_strdup("printenv HOME= 422222222222");
    init_alias();
    init_env(env);
    cr_assert_eq(check_cmd(cmd), 7);
}

Test(check_cmd, test24, .init = redirect_all_std)
{
    char *env[] = {"PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin"
        ":/home/thomas/.local/bin:/home/thomas/bin:/home/thomas/my_scripts",
        "USER=thomas", "HOME=/home/thomas", NULL};
    char *cmd = my_strdup("/");
    init_alias();
    init_env(env);
    cr_assert_eq(check_cmd(cmd), -1);
}

Test(check_cmd, test25, .init = redirect_all_std)
{
    char *env[] = {"PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin"
        ":/home/thomas/.local/bin:/home/thomas/bin:/home/thomas/my_scripts",
        "USER=thomas", "HOME=/home/thomas", NULL};
    char *cmd = my_strdup("setenv USER");
    init_alias();
    init_env(env);
    cr_assert_eq(check_cmd(cmd), 5);
}

Test(check_cmd, test26, .init = redirect_all_std)
{
    char *env[] = {"PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin"
        ":/home/thomas/.local/bin:/home/thomas/bin:/home/thomas/my_scripts",
        "USER=thomas", "HOME=/home/thomas", NULL};
    char *cmd = my_strdup("setenv U_)ER");
    init_alias();
    init_env(env);
    cr_assert_eq(check_cmd(cmd), 5);
}

Test(check_cmd, test27, .init = redirect_all_std)
{
    char *env[] = {"PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin"
        ":/home/thomas/.local/bin:/home/thomas/bin:/home/thomas/my_scripts",
        "USER=thomas", "HOME=/home/thomas", NULL};
    char *cmd = my_strdup("setenv USER thamas apsa");
    init_alias();
    init_env(env);
    cr_assert_eq(check_cmd(cmd), 5);
}

Test(check_cmd, test28, .init = redirect_all_std)
{
    char *env[] = {"PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin"
        ":/home/thomas/.local/bin:/home/thomas/bin:/home/thomas/my_scripts",
        "USER=thomas", "HOME=/home/thomas", NULL};
    char *cmd = my_strdup("setenv");
    init_alias();
    init_env(env);
    cr_assert_eq(check_cmd(cmd), 5);
}

Test(check_cmd, test29, .init = redirect_all_std)
{
    char *env[] = {"PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin"
        ":/home/thomas/.local/bin:/home/thomas/bin:/home/thomas/my_scripts",
        "USER=thomas", "HOME=/home/thomas", NULL};
    char *cmd = my_strdup("echo EPITECH");
    init_alias();
    init_env(env);
    cr_assert_eq(check_cmd(cmd), 4);
}

Test(check_cmd, test30, .init = redirect_all_std)
{
    char *env[] = {"PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin"
        ":/home/thomas/.local/bin:/home/thomas/bin:/home/thomas/my_scripts",
        "USER=thomas", "HOME=/home/thomas", NULL};
    char *cmd = my_strdup("echo -n EPITECH");
    init_alias();
    init_env(env);
    cr_assert_eq(check_cmd(cmd), 4);
}

Test(check_cmd, test31, .init = redirect_all_std)
{
    char *env[] = {"PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin"
        ":/home/thomas/.local/bin:/home/thomas/bin:/home/thomas/my_scripts",
        "USER=thomas", "HOME=/home/thomas", NULL};
    char *cmd = my_strdup("echo -n \\nO \\u");
    init_alias();
    init_env(env);
    cr_assert_eq(check_cmd(cmd), 4);
}

Test(check_cmd, test32, .init = redirect_all_std)
{
    char *env[] = {"PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin"
        ":/home/thomas/.local/bin:/home/thomas/bin:/home/thomas/my_scripts",
        "USER=thomas", "HOME=/home/thomas", NULL};
    char *cmd = my_strdup("ls | cat -e");
    init_alias();
    init_env(env);
    cr_assert_eq(check_cmd(cmd), 0);
}

Test(check_cmd, test33, .init = redirect_all_std)
{
    char *env[] = {"PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin"
        ":/home/thomas/.local/bin:/home/thomas/bin:/home/thomas/my_scripts",
        "USER=thomas", "HOME=/home/thomas", NULL};
    char *cmd = my_strdup("ls | cat -e | cat -e | cat -e");
    init_alias();
    init_env(env);
    cr_assert_eq(check_cmd(cmd), 0);
}

Test(check_cmd, test34, .init = redirect_all_std)
{
    char *env[] = {"PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin"
        ":/home/thomas/.local/bin:/home/thomas/bin:/home/thomas/my_scripts",
        "USER=thomas", "HOME=/home/thomas", NULL};
    char *cmd = my_strdup("| cat -e | cat -e | cat -e");
    init_alias();
    init_env(env);
    cr_assert_eq(check_cmd(cmd), 0);
}

Test(check_cmd, test35, .init = redirect_all_std)
{
    char *env[] = {"PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin"
        ":/home/thomas/.local/bin:/home/thomas/bin:/home/thomas/my_scripts",
        "USER=thomas", "HOME=/home/thomas", NULL};
    char *cmd = my_strdup("ls | cat -e | ");
    init_alias();
    init_env(env);
    cr_assert_eq(check_cmd(cmd), 0);
}

Test(check_cmd, test36, .init = redirect_all_std)
{
    char *env[] = {"PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin"
        ":/home/thomas/.local/bin:/home/thomas/bin:/home/thomas/my_scripts",
        "USER=thomas", "HOME=/home/thomas", NULL};
    char *cmd = my_strdup("ls | cat -e |");
    init_alias();
    init_env(env);
    cr_assert_eq(check_cmd(cmd), 0);
}

Test(check_cmd, test37, .init = redirect_all_std)
{
    char *env[] = {"USER=thomas", "HOME=/home/thomas", NULL};
    char *cmd = my_strdup("ls | cat -e |");
    init_alias();
    init_env(env);
    cr_assert_eq(check_cmd(cmd), 0);
}

Test(check_cmd, test38, .init = redirect_all_std)
{
    char *env[] = {"USER=thomas", "HOME=/home/thomas", NULL};
    char *cmd = my_strdup("</etc/hosts od -c | grep xx | wc >> /tmp/z -l");
    init_alias();
    init_env(env);
    cr_assert_eq(check_cmd(cmd), 0);
}

Test(check_cmd, test39, .init = redirect_all_std)
{
    char *env[] = {"USER=thomas", "HOME=/home/thomas", NULL};
    char *cmd = my_strdup("cd - && echo OK");
    init_alias();
    init_env(env);
    cr_assert_eq(check_cmd(cmd), 0);
}

Test(check_cmd, test40, .init = redirect_all_std)
{
    char *env[] = {"USER=thomas", "HOME=/home/thomas", NULL};
    char *cmd = my_strdup("ls >> /tmp/z");
    init_alias();
    init_env(env);
    cr_assert_eq(check_cmd(cmd), 0);
}

Test(pwd, test1, .init = redirect_all_std)
{
    char *env[] = {"PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin"
        ":/home/thomas/.local/bin:/home/thomas/bin:/home/thomas/my_scripts",
        "USER=thomas", "PWD=OH/NO", NULL};
    char *cmd[] = {"pwd", NULL};
    init_alias();
    init_env(env);
    pwd(cmd);
}

Test(exit, test1, .init = redirect_all_std)
{
    char *env[] = {"PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin"
        ":/home/thomas/.local/bin:/home/thomas/bin:/home/thomas/my_scripts",
        "USER=thomas", "PWD=OH/NO", NULL};
    char **cmd = malloc(sizeof(char *) * 3);
    cmd[0] = my_strdup("exit");
    cmd[1] = my_strdup("oke");
    cmd[2] = NULL;
    init_alias();
    init_env(env);
    exit_sh(cmd);
}

Test(exit, test2, .init = redirect_all_std)
{
    char *env[] = {"PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin"
        ":/home/thomas/.local/bin:/home/thomas/bin:/home/thomas/my_scripts",
        "USER=thomas", "PWD=OH/NO", NULL};
    char **cmd = malloc(sizeof(char *) * 2);
    cmd[0] = my_strdup("exit");
    cmd[1] = NULL;
    init_alias();
    init_env(env);
    exit_sh(cmd);
}
