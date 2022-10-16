/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-antoine.khalidy
** File description:
** sword
*/

#include "rpg.h"

void sword(int movement)
{
    rpg->player->time = sfClock_getElapsedTime(rpg->player->clock);
    rpg->player->sec = rpg->player->time.microseconds / 1000000.0;
    if (rpg->player->sec > 0.12) {
        sfClock_restart(rpg->player->clock);
        rpg->player->sword_status++;
    }
    DRAW_SPRITE(rpg->window, rpg->player->image[movement + 4]->sprite);
    if (rpg->player->sword_status == 6) {
        rpg->player->sword_status = 0;
        rpg->player->is_able[SWORD] = 0;
        rpg->player->sword[movement] = 0;
    }
}
