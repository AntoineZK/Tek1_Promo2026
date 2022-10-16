/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Espace de travail)
** File description:
** attack_hitbox
*/

#include "rpg.h"

void player_attack_touch(player_t *player)
{
    for (int i = 0; rpg->monsters[i]; ++i) {
        if (in_range(player->pos, rpg->monsters[i]->pos, 64)) {
            rpg->monsters[i]->hp -= 10;
        }
    }
}
