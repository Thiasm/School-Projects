/*
** EPITECH PROJECT, 2018
** PSU_minishell_2018
** File description:
** minishell.h
*/

#ifndef READ_SIZE
#define READ_SIZE 1024
#endif /* !READ_SIZE */

#ifndef MYSH
#define MYSH

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>

#include "my.h"

char **aliases;
char **def_alias;

struct signal_s {
    int signal;
    char *err;
};

typedef struct signal_s signal_t;

typedef struct room
{
    int type;
    char *token;
    struct room *right;
    struct room *left;
    struct room *next;
    struct room *previous;
    struct room *back;
} room_t;

typedef struct list
{
    int nb_ope;
    struct room *root;
    struct room *first;
    struct room *last;
} list_t;

char **g_env;

/* core */
void minishell(void);
int check_file(void);
void display_prompt(int nb);
void put_prompt(char *user, char *home, char *cwd);
void parent_exec(int *status);
int check_acces(char *cmd);
char **my_cmd_to_tab(char *str);
int check_cmd(char *cmd);
char *add_home_path(char *cmd);
char *get_full_cmd(char *cmd);
int exec_cmd(char **cmds, char *cmd);
int is_directory(const char *path);
int exit_status_catcher(int status, pid_t pid);

/* env */
int init_env(char **env);
char *get_env_var(char *var);
char **set_env_var(char *s, char *content);
int is_env_var(char *cmd);

/* built-ins */
extern char *builtin_str[];
extern void (*builtin_func[]) (char **);

int builtins_len(void);
int is_in_builtins(char *cmd);
int check_builtin_cmd(char **cmds);

void add_to_history(char *cmd);
void history(char **av);
void cd(char **cmds);
void print_env(char **cmds);
void echo(char **av);
void set_env(char **cmds);
void unset_env(char **cmds);
void print_an_env(char **cmds);
void help(char **cmds);
void exit_sh(char **cmds);
void alias(char **cmd);
void check_alias(room_t *room);
void init_alias(void);
int count_lines(char **cmd);
void check_dolls(char **cmd);
void pwd(char **cmds);

/* tree */

list_t *create_list(char **cmd);
list_t *create_mark(void);
list_t *generate_tree(char **cmd);
void add_to_branch(room_t *room);
void print_tree(list_t *list);
void add_token(char *str, list_t *list);
void simple_command(list_t *list);
int find_type(char *str);
int read_tree(list_t *list);
char *my_itoc(int number);

int exec_room(room_t *room);

void exec_ope(room_t *room, list_t *list);

char **my_cmd_to_exec(char *str);

int check_cmd_type(char **cmds);


/* operators */
void exec_double_pipe(room_t *room, list_t *list);
void exec_double_perluette(room_t *room, list_t *list);
void exec_semicolon(room_t *room, list_t *list);
void redir(room_t *room);
void redir_double(room_t *room);
void redir_left(room_t *room);
void double_redir_left(room_t *room);
int pipe_handle(room_t *room, list_t *list);

/* signal */
int g_signal;
int signal_handler(char reset_signal, int is_parent);
void init_sig_handler(signal_t **sig);

#endif /* !MYSH */
