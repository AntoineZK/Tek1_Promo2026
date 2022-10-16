/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-mydefender-antoine.khalidy
** File description:
** anim_tower
*/

#include "../include/defender.h"

void anim_obe(sfSprite *sprite)
{
    sfIntRect rect = sfSprite_getTextureRect(sprite);

    rect.top = 0;
    rect.left += 85;
    if (rect.left == 1190)
        rect.left = 0;
    rect.height = 108;
    rect.width = 85;
    sfSprite_setTextureRect(sprite, rect);
}

void anim_heart(sfSprite *sprite)
{
    sfIntRect rect = sfSprite_getTextureRect(sprite);

    rect.top = 0;
    rect.left += 100;
    if (rect.left == 900)
        rect.left = 0;
    rect.height = 116;
    rect.width = 100;
    sfSprite_setTextureRect(sprite, rect);
}

void animation_heart(defender_t *def)
{
    def->t_heart = sfClock_getElapsedTime(def->c_heart);
    def->sec_heart = def->t_heart.microseconds / 1000000.0;
    if (def->sec_heart > 0.12) {
        sfClock_restart(def->c_heart);
        anim_heart(def->game.g_heart->sprite);
    }
    draw_sprite(def, def->game.g_heart);
}

void anim_coin(sfSprite *sprite)
{
    sfIntRect rect = sfSprite_getTextureRect(sprite);

    rect.top = 0;
    rect.left += 100;
    if (rect.left == 500)
        rect.left = 0;
    rect.height = 116;
    rect.width = 100;
    sfSprite_setTextureRect(sprite, rect);
}

void animation_coin(defender_t *def)
{
    def->t_coin = sfClock_getElapsedTime(def->c_coin);
    def->sec_coin = def->t_coin.microseconds / 1000000.0;
    if (def->sec_coin > 0.12) {
        sfClock_restart(def->c_coin);
        anim_coin(def->game.g_coin->sprite);
    }
    draw_sprite(def, def->game.g_coin);
}
