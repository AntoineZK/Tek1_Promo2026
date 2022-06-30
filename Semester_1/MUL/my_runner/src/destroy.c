/*
** EPITECH PROJECT, 2022
** B-MUL-100-NCY-1-1-myrunner-antoine.khalidy
** File description:
** destroy
*/

#include "../include/my.h"
#include "../include/myrunner.h"

void destroy_all(sfSprite *sprite, sfTexture *texture)
{
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
}

void destroy_one(runner_t *runner)
{
    destroy_all(runner->menu_bg->sprite, runner->menu_bg->texture);
    destroy_all(runner->menu_exit->sprite, runner->menu_exit->texture);
    destroy_all(runner->menu_start->sprite, runner->menu_start->texture);
    destroy_all(runner->character_bg->sprite, runner->character_bg->texture);
    destroy_all(runner->character_home->sprite, runner->character_home->\
    texture);
    destroy_all(runner->game_background1->sprite, runner->game_background1->\
    texture);
    destroy_all(runner->game_background2->sprite, runner->game_background2->\
    texture);
    destroy_all(runner->character_ichigo->sprite, runner->character_ichigo->\
    texture);
    destroy_all(runner->character_toshiro->sprite, runner->character_toshiro->\
    texture);
    destroy_all(runner->ichigo_run->sprite, runner->ichigo_run->texture);
    destroy_all(runner->ichigo_jump->sprite, runner->ichigo_jump->texture);
    destroy_all(runner->toshiro_run->sprite, runner->toshiro_run->texture);
    destroy_all(runner->toshiro_jump->sprite, runner->toshiro_jump->texture);
    destroy_all(runner->parralax_one->sprite, runner->parralax_one->texture);
    destroy_all(runner->parralax_two->sprite, runner->parralax_two->texture);
}

void destroy_two(runner_t *runner)
{
    destroy_all(runner->win_back->sprite, runner->win_back->texture);
    destroy_all(runner->lose_back->sprite, runner->lose_back->texture);
    destroy_all(runner->quit->sprite, runner->quit->texture);
    sfMusic_destroy(runner->ost);
    sfSoundBuffer_destroy(runner->sound_jump_buffer);
    sfSound_destroy(runner->sound_jump);
    sfClock_destroy(runner->clock_ichigo);
    sfClock_destroy(runner->clock_toshiro);
    sfRenderWindow_destroy(runner->window);
}
