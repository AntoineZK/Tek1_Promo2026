/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-antoine.khalidy
** File description:
** collison
*/

#include "rpg.h"

static int check_on_map(char to_find, sfVector2f pos, int hitbox)
{
    if (is_outside_map(pos))
        return (1);
    if (find_char_map(rpg->d_map[0], pos, to_find, hitbox))
        return (1);
    return (0);
}

sfVector2f walls(sfVector2f pos, int *anim, int value, int hitbox)
{
    if (anim[DOWN] && check_on_map('1', pos, hitbox)) {
        pos.y -= value;
    }
    if (anim[UP] && check_on_map('1', pos, hitbox)) {
        pos.y += value;
    }
    if (anim[LEFT] && check_on_map('1', pos, hitbox)) {
        pos.x += value;
    }
    if (anim[RIGHT] && check_on_map('1', pos, hitbox)) {
        pos.x -= value;
    }
    return (pos);
}

void collision(void)
{
    rpg->player->pos = walls(rpg->player->pos, rpg->player->is_anim, 5, 124);
    for (int i = 0; rpg->monsters[i]; i++)
        rpg->monsters[i]->pos = walls(rpg->monsters[i]->pos,
        rpg->monsters[i]->status, 2, 128);
}
