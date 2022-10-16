/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-antoine.khalidy
** File description:
** bow
*/

#include "rpg.h"

void bow(int movement)
{
    rpg->player->time = sfClock_getElapsedTime(rpg->player->clock);
    rpg->player->sec = rpg->player->time.microseconds / 1000000.0;
    if (rpg->player->sec > 0.12) {
        sfClock_restart(rpg->player->clock);
    }
    DRAW_SPRITE(rpg->window, rpg->player->image[movement + 8]->sprite);
}
