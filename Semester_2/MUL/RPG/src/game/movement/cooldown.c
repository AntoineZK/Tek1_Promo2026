/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-antoine.khalidy
** File description:
** cooldown
*/

#include "rpg.h"

void cooldown_calc(float cd, int ability)
{
    rpg->player->cd_time[ability] = sfClock_getElapsedTime
    (rpg->player->cd_clock[ability]);
    rpg->player->cd_sec[ability] = rpg->player->cd_time[ability].microseconds
    / 1000000.0;
    if (rpg->player->cd_sec[ability] >= cd) {
        sfClock_restart(rpg->player->cd_clock[ability]);
        rpg->player->is_able[ability] = 1;
    }
}

void cooldown(void)
{
    rpg->player->is_able[DASH] == 0 ? cooldown_calc
    (rpg->player->cd_value[DASH], DASH) : 0;
    rpg->player->is_able[SWORD] == 0 ? cooldown_calc
    (rpg->player->cd_value[SWORD], SWORD) : 0;
    rpg->player->is_able[BOW] == 2 ? cooldown_calc
    (rpg->player->cd_value[BOW], BOW) : 0;
}
