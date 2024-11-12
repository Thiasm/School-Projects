/*
** EPITECH PROJECT, 2019
** redir.c
** File description:
** redir
*/

#include "minishell.h"

void redir(room_t *room)
{
    int fd;
    int cpy;
    int i;

    cpy = dup(1);
    for (i = 0; my_isspace(room->right->token[i]); i++);
    if (access(&room->right->token[i], F_OK) == -1) {
        fd = open(&room->right->token[i], O_CREAT, 00664);
        close(fd);
    }
    fd = open(&room->right->token[i], O_RDWR);
    if (dup2(fd, 1) == - 1)
        my_putstr_fd("error: dup2 failed.", 2);
    exec_room(room->left);
    if (dup2(cpy, 1) == -1)
        my_putstr_fd("error: dup2 failed.", 2);
}

void redir_double(room_t *room)
{
    int fd;
    int cpy;
    int i;

    cpy = dup(1);
    for (i = 0; my_isspace(room->right->token[i]); i++);
    if (access(&room->right->token[i], F_OK) == -1) {
        fd = open(&room->right->token[i], O_CREAT, 00664);
        close(fd);
    }
    fd = open(&room->right->token[i], O_RDWR | O_APPEND);
    if (dup2(fd, 1) == - 1)
        my_putstr_fd("error: dup2 failed.", 2);
    exec_room(room->left);
    if (dup2(cpy, 1) == -1)
        my_putstr_fd("error: dup2 failed.", 2);
}

void redir_left(room_t *room)
{
    int fd;
    int cpy;
    int i;

    cpy = dup(0);
    for (i = 0; my_isspace(room->right->token[i]); i++);
    if (access(&room->right->token[i], F_OK) == -1) {
        room->right->token = realloc(room->right->token,
            my_strlen(room->right->token) + 29);
        my_putstr_fd(my_strcat(&room->right->token[i],
            ": No such file or directory\n"), 2);
        return;
    }
    fd = open(&room->right->token[i], O_RDWR);
    if (dup2(fd, 0) == - 1)
        my_putstr_fd("error: dup2 failed.", 2);
    exec_room(room->left);
    if (dup2(cpy, 0) == -1)
        my_putstr_fd("error: dup2 failed.", 2);
}

int create_file(char **tab, int i, room_t *room)
{
    int fd;

    if ((fd = open("d_redir_l.tmp", O_CREAT, 00664)) == -1)
        return 1;
    close(fd);
    fd = open("d_redir_l.tmp", O_RDWR | O_APPEND);
    for (int j = 0; tab[j] != NULL &&
        my_strcmp(tab[j], &room->right->token[i]) != 0; j++) {
        write(fd, tab[j], my_strlen(tab[j]));
        write(fd, "\n", 1);
    }
    close(fd);
    for (int j = 0; tab[j] != NULL; j++)
        free(tab[j]);
    free(tab);
    free(room->right->token);
    room->right->token = my_strdup("d_redir_l.tmp");
    redir_left(room);
    return 0;
}

void double_redir_left(room_t *room)
{
    char **tab = malloc(sizeof(char *) * 1);
    int line = 0;
    char *buff;
    int i;

    for (i = 0; my_isspace(room->right->token[i]); i++);
    tab[0] = NULL;
    my_putstr("? ");
    while ((buff = get_next_line(0)) != NULL) {
        tab = realloc(tab, sizeof(char *) * (line + 2));
        tab[line] = my_strdup(buff);
        free(buff);
        line++;
        tab[line] = NULL;
        if (my_strcmp(tab[line - 1], &room->right->token[i]) == 0)
            break;
        my_putstr("? ");
    }
    if (create_file(tab, i, room) == 1)
        return;
    remove("d_redir_l.tmp");
}