/*
** EPITECH PROJECT, 2018
** create_texture
** File description:
** runner
*/

#include "my.h"

void set_game_texture(var_t *var, back_t *back, map_t *map)
{
    set_backgroung_texture(var, back);
    set_player_texture(var, back);
    set_music_texture(var, back);
    set_score(var, back);
}

void set_backgroung_texture(var_t *var, back_t *back)
{
    back->background.night_tex =
    sfTexture_createFromFile("./Texture/night.png", NULL);
    back->background.night_spr = sfSprite_create();
    sfSprite_setTexture(back->background.night_spr,
    back->background.night_tex, sfTrue);
    back->background.sky_tex =
    sfTexture_createFromFile("./Texture/sky.png", NULL);
    back->background.sky_spr = sfSprite_create();
    sfSprite_setTexture(back->background.sky_spr,
    back->background.sky_tex, sfTrue);
    back->background.sand_tex =
    sfTexture_createFromFile("./Texture/sand.png", NULL);
    back->background.sand_spr = sfSprite_create();
    sfSprite_setTexture(back->background.sand_spr,
    back->background.sand_tex, sfTrue);
    back->background.rock_tex =
    sfTexture_createFromFile("./Texture/rock.png", NULL);
    back->background.rock_spr = sfSprite_create();
    sfSprite_setTexture(back->background.rock_spr,
    back->background.rock_tex, sfTrue);
}

void set_player_texture(var_t *var, back_t *back)
{
    back->player.sword_tex =
    sfTexture_createFromFile("./Texture/sword_attack.png", NULL);
    back->player.sword_spr = sfSprite_create();
    sfSprite_setTexture(back->player.sword_spr, back->player.sword_tex, sfTrue);
    back->player.run_tex = sfTexture_createFromFile("./Texture/run.png", NULL);
    back->player.run_spr = sfSprite_create();
    sfSprite_setTexture(back->player.run_spr, back->player.run_tex, sfTrue);
    back->player.jump_tex =
    sfTexture_createFromFile("./Texture/jump.png", NULL);
    back->player.jump_spr = sfSprite_create();
    sfSprite_setTexture(back->player.jump_spr, back->player.jump_tex, sfTrue);
    back->bad_tex = sfTexture_createFromFile("./Texture/bad.png", NULL);
    back->bad_spr = sfSprite_create();
    sfSprite_setTexture(back->bad_spr, back->bad_tex, sfTrue);
    back->music.jump_buffer =
    sfSoundBuffer_createFromFile("./music/jump_sound.flac");
    back->music.jump_sound = sfSound_create();
    sfSound_setBuffer(back->music.jump_sound, back->music.jump_buffer);
}

void set_music_texture(var_t *var, back_t *back)
{
    var->menu.menu_tex = sfTexture_createFromFile("./Texture/menu.png", NULL);
    var->menu.menu_spr = sfSprite_create();
    sfSprite_setTexture(var->menu.menu_spr, var->menu.menu_tex, sfTrue);
    back->background.block_tex =
    sfTexture_createFromFile("./Texture/block.png", NULL);
    back->background.block_spr = sfSprite_create();
    sfSprite_setTexture(back->background.block_spr,
    back->background.block_tex, sfTrue);
    back->music.music = sfMusic_createFromFile("./music/music.flac");
    back->music.menu = sfMusic_createFromFile("./music/music_menu.flac");
    back->music.sword_sound = sfMusic_createFromFile("./music/sword_sound.wav");
    back->music.cut_sound = sfMusic_createFromFile("./music/cut.flac");
}

void display_player(var_t *var, back_t *back, map_t *map)
{
    sfSprite_setTextureRect(back->player.run_spr, back->player.rect_player);
    sfRenderWindow_drawSprite(var->window, back->player.run_spr, NULL);
    sfSprite_setPosition(back->player.run_spr,
    (sfVector2f) {0, back->player.y});
    var->timer.time_player = sfClock_getElapsedTime(var->timer.clock_player);
    var->timer.seconds_player = var->timer.time_player.microseconds / 1000000.0;
    if (var->timer.seconds_player >= 0.07) {
        if (back->player.rect_player.left == 860 &&
        back->player.rect_player.top == 300)
            back->player.rect_player.left = 0;
        back->player.rect_player.left += 215;
        sfClock_restart(var->timer.clock_player);
    }
}
