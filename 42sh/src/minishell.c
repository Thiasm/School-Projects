/*
** EPITECH PROJECT, 2018
** PSU_minishell_2018
** File description:
** minishell.c
*/

#include "minishell.h"

char *builtin_str[] = {
    "cd",
    "history",
    "env",
    "echo",
    "setenv",
    "unsetenv",
    "printenv",
    "help",
    "alias",
    "exit",
    NULL
};

void (*builtin_func[]) (char **) =
{
    &cd,
    &history,
    &print_env,
    &echo,
    &set_env,
    &unset_env,
    &print_an_env,
    &help,
    &alias,
    &exit_sh,
    NULL
};

char *get_cmd_path(char *cmd, char *path, DIR *dir)
{
    struct dirent *data;

    while ((data = readdir(dir))) {
        if (!my_strcmp(data->d_name, cmd)) {
            closedir(dir);
            if (path[my_strlen(path) - 1] == '/')
                return (my_strjoin(path, ""));
            return (my_strjoin(path, "/"));
        }
    }
    closedir(dir);
    return NULL;
}

char *get_full_cmd(char *cmd)
{
    char *full_path = get_env_var("PATH=");
    char **all_path = NULL;
    char *path = NULL;
    DIR *dir;

    if (!full_path)
        return (my_strjoin("/usr/bin/", cmd));
    all_path = my_strsplit(full_path, ':');
    for (int i = 0; all_path[i] != NULL; i++) {
        my_strfree(&full_path);
        if ((access(all_path[i], F_OK) == 0) && (dir = opendir(all_path[i])))
            full_path = get_cmd_path(cmd, all_path[i], dir);
        if (full_path != NULL) {
            my_freetab(all_path);
            path = my_strjoin(full_path, cmd);
            free(full_path);
            return path;
        }
    }
    my_freetab(all_path);
    return NULL;
}

int check_acces(char *cmd)
{
    if (access(cmd, F_OK) == 0) {
        if (access(cmd, X_OK) == -1) {
            my_putstr_fd(cmd, 2);
            my_putstr_fd(": Permission denied.\n", 2);
            return 1;
        }
    }
    if (is_directory(cmd)) {
        my_putstr_fd(cmd, 2);
        my_putstr_fd(": Permission denied.\n", 2);
        return 1;
    }
    return 0;
}

void minishell(void)
{
    char *cmd = NULL;

    init_alias();
    for (int nb = 0; 1; nb++) {
        signal_handler(1, 1);
        display_prompt(nb);
        check_file();
        if ((cmd = get_next_line(0)) == NULL) {
            free(cmd);
            return;
        }
        if (cmd[0] == 0) {
            free(cmd);
            continue;
        }
        add_to_history(cmd);
        if (check_cmd(cmd) < 0)
            return;
    }
}
