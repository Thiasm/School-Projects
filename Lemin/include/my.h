/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** include for the defender
*/

#ifndef _MY_H
#define _MY_H

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct room_s
{
    char *name;
    int id;
    int ant;
    struct room_s *single_next;
    struct room_s **next;
    struct room_s *previous;
} room_t;

typedef struct	list_s
{
    room_t *first;
    room_t *last;
    room_t *way;
    int size;
} list_t;

struct data {
    int ant_number;
    char **path;
    char **file;
    char **rooms;
    char **tunnels;
    int start_y;
    int end_y;
    int return_value;
    list_t *list;
    int check;
};

typedef struct data data_t;

#endif

int main(int ac, char **av, char **env);
char *my_strcpy(char *src);
list_t *create_first(data_t *data);
char **tunnels_to_tab(char *str, char **tab, int y);
char **my_realloc_tab(char **tab, int size);
int parse_file(char *filepath, data_t *data);
int sort_tunnels(data_t *data);
int find_ant_nbr(data_t *data);
int start_end_error(data_t *data, char **tab);
void my_putchar(char c);
int check_if_tunnels(char *str);
void my_putstr(char *str);
void free_all(data_t *data);
int my_atoi(char *str);
int my_strlen(char const *str);
void my_put_nbr(int nb);
void create_way(data_t *data);;
char **clear_comment(char **file);
void print_rooms(data_t *data);
char **room_to_tab(char *str, char **tab, int y);
int sort_data(data_t *data);
void init_var(data_t *data);
void ant_forward(data_t *data, int *space, room_t *room);
int check_if_room(char *str);
int sort_rooms(data_t *data);
int print_path(data_t *data);
int error_room(data_t *data);
int place_room_error_bis(data_t *data, int j, int where);
int place_room_error(data_t *data);
int number_room_error_bis(data_t *data, int j, int where);
int number_room_error(data_t *data);
void my_printf(char *str, ...);
void check_arrived(data_t *data, int *space, int *arrived, room_t *room);
void my_put_nbr_int(int nb);
room_t *add_way(data_t *data, int i);
void test_flag_nb(char *str, int *i, va_list ap);
void test_flag(char *str, int *i, va_list ap);
int print_data(data_t *data);
char **room_to_tab_2(int i, char *str, char **tab, int x);
int count_start_end(char **file, int nbr_start, int nbr_end);
int my_strcmp(char *string, char *str);
void link_rooms(data_t *data);
void create_graph(data_t *data);
char **return_path(data_t *data, int check, int previous_id, int where);
int pathfinding(data_t *data, int status);
int how_many_next(char *name, char **link);
char **launch_pathfinding(data_t *data);
