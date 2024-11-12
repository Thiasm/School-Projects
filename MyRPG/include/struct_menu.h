/*
** EPITECH PROJECT, 2019
** My RPG
** File description:
** struct_menu
*/

#ifndef STRUCT_MENU_H_
#define STRUCT_MENU_H_

typedef struct texture_s {
    char *name;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f position;
    struct texture_s *next;
} texture_t;

typedef struct text_s {
    char *name;
    int color;
    sfText *text;
    sfVector2f position;
    struct text_s *next;
} text_t;

typedef struct text_value_s {
    char *name;
    char *value;
    int color;
    sfText *text;
    sfVector2f position;
    struct text_value_s *next;
} text_value_t;

#endif /* !STRUCT_MENU_H_ */
