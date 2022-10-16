/*
** EPITECH PROJECT, 2022
** rpg_alone
** File description:
** animation
*/

#include "rpg.h"

void animation(sfSprite *sprite, sfIntRect anim, int max_decal)
{
    sfIntRect rect = sfSprite_getTextureRect(sprite);

    rect.top = anim.top;
    rect.left += anim.left;
    if (rect.left == max_decal)
        rect.left = 0;
    rect.height = anim.height;
    rect.width = anim.width;
    sfSprite_setTextureRect(sprite, rect);
}

void animation_player(game_obj *game_obj, int length)
{
    rpg->player->time = sfClock_getElapsedTime(rpg->player->clock);
    rpg->player->sec = rpg->player->time.microseconds / 1000000.0;
    if (rpg->player->sec > 0.12) {
        sfClock_restart(rpg->player->clock);
        animation(game_obj->sprite, rpg->player->rect, length);
    }
    DRAW_SPRITE(rpg->window, game_obj->sprite);
}

void sword_animation(game_obj *game_obj, int length)
{
    rpg->player->time = sfClock_getElapsedTime(rpg->player->clock);
    rpg->player->sec = rpg->player->time.microseconds / 1000000.0;
    if (rpg->player->sec > 0.12) {
        sfClock_restart(rpg->player->clock);
        animation(game_obj->sprite, rpg->player->rect, length);
    }
    DRAW_SPRITE(rpg->window, game_obj->sprite);
}

void dash_animation(game_obj *image, int length)
{
    rpg->player->time = sfClock_getElapsedTime(rpg->player->clock);
    rpg->player->sec = rpg->player->time.microseconds / 1000000.0;
    sfSprite *actual = NULL;
    sfIntRect rect = sfSprite_getTextureRect(image->sprite);
    if (rpg->player->sec > 0.10) {
        sfClock_restart(rpg->player->clock);
        animation(image->sprite, rpg->player->rect, length);
    }
    actual = sfSprite_copy(image->sprite);
    sfSprite_setColor(actual, sfColor_fromRGBA(200, 200, 200, 70 +
    (1 - ((float) rect.left / length)) * 185));
    DRAW_SPRITE(rpg->window, actual);
    sfSprite_destroy(actual);
}

void monster_animation(monster_t *mstr, int movement)
{
    mstr->time = sfClock_getElapsedTime(mstr->clock);
    mstr->sec = mstr->time.microseconds / 1000000.0;
    if (mstr->sec > 0.10) {
        sfClock_restart(mstr->clock);
        animation(mstr->obj[movement]->sprite, mstr->rect, mstr->len);
    }
    mstr->moving_status++;
    DRAW_SPRITE(rpg->window, mstr->obj[movement]->sprite);
}
