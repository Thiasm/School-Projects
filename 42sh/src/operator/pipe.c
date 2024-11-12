/*
** EPITECH PROJECT, 2019
** pipe.c
** File description:
** Handle pipe.
*/

#include "minishell.h"

static void exec_parent(room_t *room, list_t *list, int zero)
{
    if (room->right != NULL && room->right->type > 0) {
        exec_ope(room->right, list);
        exec_room(room->right->left);
        room->right->left->type = -1;
    }
    else if (room->right != NULL)
        exec_room(room->right);
    dup2(zero, 0);
    exit(0);
}

static void exec_child(room_t *room, int *tube, int one)
{
    if (room->left != NULL)
        exec_room(room->left);
    close(tube[1]);
    dup2(one, 1);
}

static int is_a_cmd(room_t *room)
{
    for (int i = 0; room->token[i] != '\0'; i++)
        if (!my_isspace(room->token[i]))
            return 1;
    return 0;
}

static int error_pipe(room_t *room, int *tube)
{
    pid_t pid;

    if (room->left == NULL || room->right == NULL ||
        !is_a_cmd(room->left) || !is_a_cmd(room->right))
        return exit_prog(-1, "Invalid null command.");
    if (is_in_builtins(room->right->token)) {
        exec_room(room->right);
        return -1;
    }
    if (pipe(tube) != 0)
        return exit_prog(-1, "Tube creation error.");
    pid = fork();
    if (pid < 0)
        return exit_prog(-1, "Process creation error.\n");
    return pid;
}

int pipe_handle(room_t *room, list_t *list)
{
    pid_t pid;
    int tube[2];
    int zero = dup(0);
    int one = dup(1);

    pid = error_pipe(room, tube);
    if (pid < 0)
        return -1;
    if (pid != 0) {
        close(tube[0]);
        if (dup2(tube[1], 1) == -1)
            return exit_prog(-1, "error: dup2 failed.\n");
        exec_child(room, tube, one);
    } else {
        close(tube[1]);
        if (dup2(tube[0], 0) == -1)
            return exit_prog(-1, "error: dup2 failed.\n");
        exec_parent(room, list, zero);
    }
    return exit_status_catcher(0, pid);
}
