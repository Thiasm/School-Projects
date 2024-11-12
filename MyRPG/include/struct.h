/*
** EPITECH PROJECT, 2019
** struct.h
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct pnj_s {
    char *name;
    int x;
    int y;
    int meet;
    char *text_a;
    char *text_b;
    struct pnj_s *next;
} pnj_t;

typedef struct map_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f position;
} map_t;

typedef struct monster_s {
    char *name;
    int pv;
    int deg;
    int xp;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f position;
    sfIntRect rect;
    int x;
    int y;
    int type;
    struct monster_s *next;
} monster_t;

typedef struct info_s {
    char *name;
    int pv;
    int deg;
    int xp;
    struct info_s *next;
} info_t;

typedef struct st_game_s {
    sfFont *font;
    sfText *text;
    sfVector2f position;
    sfTexture *dialogt;
    sfSprite *dialogs;
    char *name;
    struct st_game_s *next;
} st_game_t;

typedef struct fight_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f position;
    sfTexture *texture_s;
    sfSprite *sprite_s;
    sfVector2f position_s;
    struct st_game_s *next;
} fight_t;

typedef struct world_s {
    struct map_s *next_m;
    struct pnj_s *next_p;
    struct monster_s *next_e;
    struct info_s *next_i;
} world_t;

typedef struct stat_player_s {
    int pv;
    int pv_max;
    int mana;
    int xp;
    int xp_next;
    char *class;
    int smart;
    int crit;
    int strg;
    int dex;
    int lvl;
    sfMusic *sound_attack;
    sfIntRect rect;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f position;
} stat_player_t;

typedef struct player_s {
    sfIntRect rect;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f position;
    int genre;
    int direct;
    int pos_x;
    int pos_y;
    sfClock *deplacement;
    int tour;
    struct stat_player_s *next;
} player_t;

typedef struct texture_game_s {
    char *name;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f position;
} texture_game_t;

typedef struct text_inventory_s {
    sfText *pv;
    sfText *mana;
    sfText *xp;
    sfText *xp_next;
    sfText *class;
    sfText *smart;
    sfText *crit;
    sfText *strg;
    sfText *dex;
    sfText *lvl;
} text_inventory_t;

typedef struct other_s {
    sfMusic *background_music;
    sfMusic *step_sound;
    sfMusic *click_sound;
    int pause;
    sfClock *clock_m;
    sfText *text;
    sfFont *font;
    sfTime time_m;
    float second_m;
    sfFont *game_font;
    sfTexture *texture;
    sfSprite *sprite;
    sfTexture *dialogt;
    sfSprite *dialogs;
    char **quest;
    int quest_nb;
    int **main_pnj;
    sfVector2f vector;
    int display;
    int display_inventory;
    struct texture_game_s *inventory;
    struct text_inventory_s *text_inv;
} other_t;

typedef struct option_s {
    int volume;
    int key_up;
    int key_down;
    int key_left;
    int key_right;
    int key_inventory;
} option_t;

typedef struct dialog_s {
    char *name;
    sfFont *font;
    sfText *text;
    sfVector2f position;
    sfTexture *dialogt;
    sfSprite *dialogs;
} dialog_t;

typedef struct general_s {
    sfRenderWindow *window;
    sfFloatRect rect;
    sfVector2f move;
    sfVector2f bar_pos;
    sfView *view;
    int live;
    int **array;
    int chose;
    int mov;
    struct option_s option;
    struct dialog_s *next_d;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f position;
    sfClock *clock;
    sfTime time;
    float second;
    int check;
} general_t;

#endif
