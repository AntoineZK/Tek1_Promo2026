/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-mydefender-antoine.khalidy
** File description:
** animation_mob
*/

#include "../include/defender.h"

static void anim_gob(sfSprite *sprite)
{
    sfIntRect rect = sfSprite_getTextureRect(sprite);

    rect.top = 0;
    rect.left += 108;
    if (rect.left == 756)
        rect.left = 0;
    rect.height = 108;
    rect.width = 108;
    sfSprite_setTextureRect(sprite, rect);
}

void animation_goblin(defender_t *def)
{
    def->mobs->time_mobs = sfClock_getElapsedTime(def->mobs->clock_monster);
    def->mobs->seconds_monster = def->mobs->time_mobs.microseconds / 1000000.0;
    if (def->mobs->seconds_monster > 0.12) {
        sfClock_restart(def->mobs->clock_monster);
        anim_gob(def->mobs->sprite);
    }
}

void anim_redm(sfSprite *sprite)
{
    sfIntRect rect = sfSprite_getTextureRect(sprite);

    rect.top = 0;
    rect.left += 100;
    if (rect.left == 1100)
        rect.left = 0;
    rect.height = 108;
    rect.width = 100;
    sfSprite_setTextureRect(sprite, rect);
}

void anim_tower_one(defender_t *def, sfVector2f pos)
{
    def->ts->time_tower = sfClock_getElapsedTime(def->ts->clock_tower);
    def->ts->sec_tower = def->ts->time_tower.microseconds / 1000000.0;
    if (def->ts->sec_tower > 0.12) {
        sfClock_restart(def->ts->clock_tower);
        anim_redm(def->ts->sprite);
    }
    sfSprite_setPosition(def->ts->sprite, pos);
    sfRenderWindow_drawSprite(def->wdw, def->ts->sprite, NULL);
}

void anim_tower_two(defender_t *def, sfVector2f pos)
{
    def->ts->time_tower = sfClock_getElapsedTime(def->ts->clock_tower);
    def->ts->sec_tower = def->ts->time_tower.microseconds / 1000000.0;
    if (def->ts->sec_tower > 0.12) {
        sfClock_restart(def->ts->clock_tower);
        anim_obe(def->ts->sprite);
    }
    sfSprite_setPosition(def->ts->sprite, pos);
    sfRenderWindow_drawSprite(def->wdw, def->ts->sprite, NULL);
}
