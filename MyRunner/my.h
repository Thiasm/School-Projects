/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** runner
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Audio/Sound.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/System/Time.h>
#include <stdio.h>
#include <stdlib.h>
#include <SFML/Audio/SoundStatus.h>
#include <stddef.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>


struct var {
    struct timer {
    sfClock *clock_player;
    sfClock *clock_sword;
    sfClock *clock_bad;
    sfTime time_player;
    sfTime time_bad;
    sfTime time_sword;
    float seconds_bad;
    float seconds_player;
    float seconds_sword;
    } timer;

    struct menu {
    sfTexture *menu_tex;
    sfSprite *menu_spr;
    int menu;
    sfFont *font;
    sfText *score;
    sfText *play;
    sfText *quit;
    int sco;
    } menu;

    sfRenderWindow *window;
    sfEvent event;
};

typedef struct var var_t;

struct back {
    struct background {
    sfTexture *sky_tex;
    sfTexture *rock_tex;
    sfTexture *sand_tex;
    sfTexture *night_tex;
    sfTexture *block_tex;
    sfSprite *sky_spr;
    sfSprite *rock_spr;
    sfSprite *sand_spr;
    sfSprite *night_spr;
    sfSprite *block_spr;
    } background;
    struct player {
    sfTexture *sword_tex;
    sfIntRect rect_player;
    sfIntRect rect_sword;
    sfTexture *run_tex;
    sfTexture *jump_tex;
    sfSprite *run_spr;
    sfSprite *jump_spr;
    sfSprite *sword_spr;
    float y;
    } player; 
    struct music {
    sfMusic *music;
    sfMusic *menu;
    sfSound *jump_sound;
    sfSoundBuffer *jump_buffer;
    sfMusic *sword_sound;
    sfMusic *cut_sound;
    } music;
    sfTexture *bad_tex;
    sfSprite *bad_spr;
};

typedef struct back back_t;

struct map {
    char **map;
    int *block_x;
    int nb;
    int ground;
    FILE *fp;
};

typedef struct map map_t;

int main(int argc, char **argv, char **env);
void respawn_background(var_t *var, back_t *back);
void set_origin(var_t *var, back_t *back, map_t *map);
void gravity(var_t *var, back_t *back, map_t *map);
void anime_bad(var_t *var, back_t *back);
void display_player(var_t *var, back_t *back, map_t *map);
void draw_background(var_t *var, back_t *back);
void move_background(var_t *var, back_t *back);
void create_parallax(var_t *var, back_t *back, map_t *map);
void close_window(var_t *var);
void set_game_texture(var_t *var, back_t *back, map_t *map);
void init_var(var_t *var, back_t *back, map_t *map);
void set_score(var_t *var, back_t *back);
void set_backgroung_texture(var_t *var, back_t *back);
void set_player_texture(var_t *var, back_t *back);
char *my_itoc(int number);
void anime_bad(var_t *var, back_t *back);
void check_jump(var_t *var, back_t *back, map_t *map);
void game_loop(var_t *var, back_t *back, map_t *map);
void jump(var_t *var, back_t *back, map_t *map);
void check_lose(var_t *var, back_t *back, map_t *map);
void launch_game(var_t *var, back_t *back, map_t *map);
void init_rect(var_t *var, back_t *back);
void check_sword(var_t *var, back_t *back, map_t *map);
void cut_sword_rect(var_t *var, back_t *back);
void sword_background(var_t *var, back_t *back, map_t *map);
void check_hitbox(var_t *var, back_t *back);
void set_music_texture(var_t *var, back_t *back);
void game_menu(var_t *var, back_t *back);
void lose_menu(var_t *var, back_t *back, map_t *map);
void destroy_all(var_t *var, back_t *back);
void destroy_texture(var_t *var, back_t *back);
void destroy_sprite(var_t *var, back_t *back);
void destroy_music(back_t *back);
int create_map(int argc, char **argv, map_t *map);
void read_map(FILE *fp, map_t *map);
void move_display_block(map_t *map, var_t *var, back_t *back);
void parse_map(map_t *map);
void display_block(map_t *map, var_t *var, back_t *back);
void check_lose_bad(var_t *var, back_t *back, map_t *map);
void check_block_down(map_t *map);
void init_music(back_t *back);
int my_strcmp(char *str1, char *str2);