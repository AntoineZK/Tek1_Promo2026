/*
** EPITECH PROJECT, 2022
** B-MUL-100-NCY-1-1-myhunter-antoine.khalidy
** File description:
** draw_one
*/

#include "../include/my.h"
#include "../include/myhunter.h"

void menu_draw(hunter_t *hunter)
{
    sfRenderWindow_drawSprite(hunter->window, \
    hunter->menu_back->sprite, NULL);
    sfRenderWindow_drawSprite(hunter->window, \
    hunter->start->sprite, NULL);
    sfRenderWindow_drawSprite(hunter->window, \
    hunter->exit->sprite, NULL);
    menu_text(hunter, 1);
}

void difficulty_draw(hunter_t *hunter)
{
    sfRenderWindow_drawSprite(hunter->window, \
    hunter->difficulty_back->sprite, NULL);
    sfRenderWindow_drawSprite(hunter->window, \
    hunter->easy->sprite, NULL);
    sfRenderWindow_drawSprite(hunter->window, \
    hunter->normal->sprite, NULL);
    sfRenderWindow_drawSprite(hunter->window, \
    hunter->hard->sprite, NULL);
    sfRenderWindow_drawSprite(hunter->window, \
    hunter->home->sprite, NULL);
    menu_text(hunter, 2);
}

void easy_draw(hunter_t *hunter)
{
    hunter->time_monster = sfClock_getElapsedTime(hunter->clock_monster);
    hunter->sec_monster = hunter->time_monster.microseconds / 1000000.0;
    if (hunter->sec_monster > 0.045) {
        sfClock_restart(hunter->clock_monster);
        animation_goblin(hunter->goblin->sprite);
        moving_goblin(hunter->goblin->sprite);
        animation_wyvern(hunter->wyvern->sprite);
        moving_wyvern(hunter->wyvern->sprite);
    }
    sfRenderWindow_drawSprite(hunter->window, \
    hunter->game_back->sprite, NULL);
    sfRenderWindow_drawSprite(hunter->window, \
    hunter->link->sprite, NULL);
    sfRenderWindow_drawSprite(hunter->window, \
    hunter->wyvern->sprite, NULL);
    sfRenderWindow_drawSprite(hunter->window, \
    hunter->goblin->sprite, NULL);
    score_text(hunter);
}

void normal_draw(hunter_t *hunter)
{
    hunter->time_monster = sfClock_getElapsedTime(hunter->clock_monster);
    hunter->sec_monster = hunter->time_monster.microseconds / 1000000.0;
    if (hunter->sec_monster > 0.03) {
        sfClock_restart(hunter->clock_monster);
        animation_goblin(hunter->goblin->sprite);
        moving_goblin(hunter->goblin->sprite);
        animation_wyvern(hunter->wyvern->sprite);
        moving_wyvern(hunter->wyvern->sprite);
    }
    sfRenderWindow_drawSprite(hunter->window, \
    hunter->game_back->sprite, NULL);
    sfRenderWindow_drawSprite(hunter->window, \
    hunter->link->sprite, NULL);
    sfRenderWindow_drawSprite(hunter->window, \
    hunter->wyvern->sprite, NULL);
    sfRenderWindow_drawSprite(hunter->window, \
    hunter->goblin->sprite, NULL);
    score_text(hunter);
}

void hard_draw(hunter_t *hunter)
{
    hunter->time_monster = sfClock_getElapsedTime(hunter->clock_monster);
    hunter->sec_monster = hunter->time_monster.microseconds / 1000000.0;
    if (hunter->sec_monster > 0.015) {
        sfClock_restart(hunter->clock_monster);
        animation_goblin(hunter->goblin->sprite);
        moving_goblin(hunter->goblin->sprite);
        animation_wyvern(hunter->wyvern->sprite);
        moving_wyvern(hunter->wyvern->sprite);
    }
    sfRenderWindow_drawSprite(hunter->window, \
    hunter->game_back->sprite, NULL);
    sfRenderWindow_drawSprite(hunter->window, \
    hunter->link->sprite, NULL);
    sfRenderWindow_drawSprite(hunter->window, \
    hunter->wyvern->sprite, NULL);
    sfRenderWindow_drawSprite(hunter->window, \
    hunter->goblin->sprite, NULL);
    score_text(hunter);
}
