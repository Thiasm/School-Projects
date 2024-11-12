/*
** EPITECH PROJECT, 2018
** runner
** File description:
** origin
*/

#include "my.h"

void set_origin(var_t *var, back_t *back, map_t *map)
{
    sfSprite_setOrigin(back->background.block_spr, (sfVector2f) {0, -760});
    sfSprite_setOrigin(back->player.run_spr, (sfVector2f) {-180, -680});
    sfSprite_setOrigin(back->player.sword_spr, (sfVector2f) {-180, -680});
    sfSprite_setOrigin(back->player.jump_spr, (sfVector2f) {-180, -680});
    sfSprite_setOrigin(back->bad_spr, (sfVector2f) {-2000, -760});
    sfSprite_setOrigin(var->menu.menu_spr, (sfVector2f) {-600, -200});
    sfText_setOrigin(var->menu.play, (sfVector2f) {-600, -200});
    sfSprite_setPosition(back->bad_spr, (sfVector2f)
    {map->block_x[map->nb - 1], 0});
}

void destroy_all(var_t *var, back_t *back)
{
    destroy_music(back);
    destroy_sprite(var, back);
    destroy_texture(var, back);
    sfFont_destroy(var->menu.font);
    sfText_destroy(var->menu.play);
    sfText_destroy(var->menu.score);
    sfRenderWindow_destroy(var->window);
}

void destroy_music(back_t *back)
{
    sfMusic_destroy(back->music.menu);
    sfMusic_destroy(back->music.music);
    sfSound_destroy(back->music.jump_sound);
    sfSoundBuffer_destroy(back->music.jump_buffer);
    sfMusic_destroy(back->music.sword_sound);
    sfMusic_destroy(back->music.cut_sound);
}

void destroy_sprite(var_t *var, back_t *back)
{
    sfSprite_destroy(back->background.block_spr);
    sfSprite_destroy(back->background.sky_spr);
    sfSprite_destroy(back->background.night_spr);
    sfSprite_destroy(back->background.rock_spr);
    sfSprite_destroy(back->background.sand_spr);
    sfSprite_destroy(back->player.jump_spr);
    sfSprite_destroy(back->player.run_spr);
    sfSprite_destroy(back->player.sword_spr);
    sfSprite_destroy(back->bad_spr);
    sfSprite_destroy(var->menu.menu_spr);
}

void destroy_texture(var_t *var, back_t *back)
{
    sfTexture_destroy(back->background.block_tex);
    sfTexture_destroy(back->background.sky_tex);
    sfTexture_destroy(back->background.night_tex);
    sfTexture_destroy(back->background.rock_tex);
    sfTexture_destroy(back->background.sand_tex);
    sfTexture_destroy(back->player.jump_tex);
    sfTexture_destroy(back->player.run_tex);
    sfTexture_destroy(back->player.sword_tex);
    sfTexture_destroy(back->bad_tex);
    sfTexture_destroy(var->menu.menu_tex);
}
