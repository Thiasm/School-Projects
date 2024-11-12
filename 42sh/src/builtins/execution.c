/*
** EPITECH PROJECT, 2019
** execution_command
** File description:
** 42sh
*/

#include "minishell.h"

int exit_status_catcher(int status, pid_t pid)
{
    waitpid(pid, &status, WUNTRACED);
    while (!WIFEXITED(status) && !WIFSIGNALED(status))
        waitpid(pid, &status, WUNTRACED);
    if (WIFSIGNALED(status))
        parent_exec(&status);
    return WEXITSTATUS(status);
}

int exec_cmd(char **cmds, char *cmd)
{
    pid_t pid;
    int status = 0;

    if (check_acces(cmd) != 0)
        return -1;
    pid = fork();
    if (pid == 0) {
        if (execve(cmd, cmds, g_env) != 0) {
            my_putstr_fd(cmds[0], 2);
            my_putstr_fd(": Command not found.\n", 2);
            exit(84);
            return -1;
        }
    } else if (pid < 0) {
        perror("mysh");
    } else {
        return exit_status_catcher(status, pid);
    }
    return 0;
}

int check_cmd_type(char **cmds)
{
    char *cmd = NULL;
    int ret = 0;

    if (cmds[0][0] == '/' || cmds[0][0] == '.') {
        ret = exec_cmd(cmds, cmds[0]);
    } else if (cmds[0][0] == '~') {
        cmd = add_home_path(cmds[0]);
        cmd[my_strlen(cmd) - 1] = '\0';
        ret = exec_cmd(cmds, cmd);
    } else {
        cmd = get_full_cmd(cmds[0]);
        if (cmd != NULL)
            ret = exec_cmd(cmds, cmd);
        else
            ret = exec_cmd(cmds, cmds[0]);
    }
    if (cmd)
        free(cmd);
    return ret;
}

int check_cmd(char *cmd)
{
    int ret = 1;
    char **cmds = NULL;
    list_t *list;

    if ((cmds = my_cmd_to_tab(cmd)) == NULL) {
        my_freetab(cmds);
        return 0;
    }
    if ((list = generate_tree(cmds)) == NULL)
        return 0;
    ret = read_tree(list);
    my_freetab(cmds);
    return ret;
}

int exec_room(room_t *room)
{
    char **cmd = NULL;
    int ret;

    check_alias(room);
    cmd = my_cmd_to_exec(room->token);
    check_dolls(cmd);
    if (cmd[0] == NULL || cmd[0][0] == '\0')
        return 0;
    if ((ret = check_builtin_cmd(cmd)) == 0) {
        ret = check_cmd_type(cmd);
    } else if (ret == builtins_len())
        return -1;
    my_freetab(cmd);
    return ret;
}
