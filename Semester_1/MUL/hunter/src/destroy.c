/*
** EPITECH PROJECT, 2022
** B-MUL-100-NCY-1-1-myhunter-antoine.khalidy
** File description:
** destroy
*/

#include "../include/my.h"
#include "../include/myhunter.h"

void sfdestroy(sfSprite *sprite, sfTexture *texture)
{
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
}

void destroy_one(hunter_t *hunter)
{
    sfdestroy(hunter->menu_back->sprite, hunter->menu_back->texture);
    sfdestroy(hunter->start->sprite, hunter->start->texture);
    sfdestroy(hunter->exit->sprite, hunter->exit->texture);
    sfdestroy(hunter->difficulty_back->sprite,
    hunter->difficulty_back->texture);
    sfdestroy(hunter->easy->sprite, hunter->easy->texture);
    sfdestroy(hunter->normal->sprite, hunter->normal->
    texture);
    sfdestroy(hunter->hard->sprite, hunter->hard->
    texture);
    sfdestroy(hunter->home->sprite, hunter->home->
    texture);
    sfdestroy(hunter->game_back->sprite, hunter->game_back->
    texture);
    sfdestroy(hunter->link->sprite, hunter->link->texture);
    sfdestroy(hunter->goblin->sprite, hunter->goblin->texture);
    sfdestroy(hunter->wyvern->sprite, hunter->wyvern->texture);
    sfdestroy(hunter->win_back->sprite, hunter->win_back->texture);
    sfdestroy(hunter->lose_back->sprite, hunter->lose_back->texture);
}

void destroy_two(hunter_t *hunter)
{
    sfMusic_destroy(hunter->zelda_ost);
    sfSoundBuffer_destroy(hunter->zelda_bow_buffer);
    sfSound_destroy(hunter->zelda_bow);
    sfClock_destroy(hunter->clock_monster);
    sfRenderWindow_destroy(hunter->window);
}
