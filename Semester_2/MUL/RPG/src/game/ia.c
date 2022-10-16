/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-antoine.khalidy
** File description:
** range
*/

#include "rpg.h"

int in_range(sfVector2f pos_a, sfVector2f pos_b, float range)
{
    double value = vector_norm((sfVector2f)
    {pos_a.x - pos_b.x, pos_a.y - pos_b.y});
    if (value <= range) {
        return (1);
    } else {
        return (0);
    }
}

void follow_player(sfVector2f pos_a, sfVector2f pos_b, monster_t *mstr)
{
    double norm = sqrt(pow(pos_a.y - pos_b.y, 2) +
    pow(pos_a.x - pos_b.x, 2));
    sfVector2f direction = (sfVector2f) {(pos_a.x - pos_b.x)/norm,
    (pos_a.y - pos_b.y)/norm};
    sfVector2f speed = {direction.x / 2, direction.y / 2};
    sfVector2f new_pos = {mstr->pos.x + speed.x, mstr->pos.y + speed.y};
    mstr->pos = new_pos;
    mstr->angle = atan2(direction.y, direction.x) * 180 / M_PI;
    mstr->moving_status += 1;
}
