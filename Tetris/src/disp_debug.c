/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** disp_debug.c
*/

#include "tetris.h"
#include "proto.h"

void print_help(char **av)
{
    my_printf("Usage:  %s [options]\n", av[0]);
    my_putstr("Options:\n");
    my_putstr(" --help\t\t      Display this help\n");
    my_putstr(" -L --level={num}     Start Tetris at level num (def: 1)\n");
    my_putstr(" -l --key-left={K}    Move the tetrimino LEFT using the K");
    my_putstr(" key (def: left arrow)\n");
    my_putstr(" -r --key-right={K}   Move the tetrimino RIGHT using the K ");
    my_putstr("key (def: right arrow)\n");
    my_putstr(" -t --key-turn={K}    TURN the tetrimino clockwise 90d using");
    my_putstr(" the K key (def: toparrow)\n");
    my_putstr(" -d --key-drop={K}    DROP the tetrimino using the K key ");
    my_putstr("(def: down arrow)\n");
    my_putstr(" -q --key-quit={K}    QUIT the game using the K key ");
    my_putstr("(def: ‘q’ key)\n");
    my_putstr(" -p --key-pause={K}   PAUSE/RESTART the game using the K key ");
    my_putstr("(def: space bar)\n");
    my_putstr(" --map-size={row,col} Set the numbers of rows and columns of ");
    my_putstr("the map (def: 20,10)\n");
    my_putstr(" -w --without-next    Hide next tetrimino (def: false)\n");
    my_putstr(" -D --debug           Debug mode (def: false)\n");
}

void disp_keys(char **info)
{
    my_putstr("*** DEBUG MODE ***\n");
    my_putstr("Key Left : ");
    my_putstr(info[0]);
    my_putchar('\n');
    my_putstr("Key Right : ");
    my_putstr(info[1]);
    my_putchar('\n');
    my_putstr("Key Turn : ");
    my_putstr(info[2]);
    my_putchar('\n');
    my_putstr("Key Drop : ");
    my_putstr(info[3]);
    my_putchar('\n');
    my_putstr("Key Quit : ");
    my_putstr(info[4]);
    my_putchar('\n');
    my_putstr("Key Pause : ");
    my_putstr(info[5]);
    my_putchar('\n');
}

void disp_debug(char **info)
{
    disp_keys(info);
    my_putstr("Next : ");
    my_putstr(info[6]);
    my_putchar('\n');
    my_putstr("Level : ");
    my_putstr(info[7]);
    my_putchar('\n');
    my_putstr("Size : ");
    my_putstr(info[8]);
    my_putchar('\n');
}
