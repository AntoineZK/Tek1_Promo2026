/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-antoine.khalidy
** File description:
** outside_maps
*/

#include "rpg.h"

void set_pos_player(void)
{
    sfVector2f tmp = {0, 0};

    for (int i = 0; i <= 11; ++i) {
        if (i == SW_LEFT || i == BOW_LEFT) {
            tmp = rpg->player->pos;
            tmp.x -= 128;
            tmp.y += 5;
            sfSprite_setPosition(rpg->player->image[i]->sprite, tmp);
        } else if (i == SW_UP || i == BOW_UP) {
            tmp = rpg->player->pos;
            tmp.y -= 128;
            sfSprite_setPosition(rpg->player->image[i]->sprite, tmp);
        } else
            sfSprite_setPosition(rpg->player->image[i]->sprite,
            rpg->player->pos);
    }
    sfView_setCenter(rpg->view, rpg->player->pos);
}

int is_outside_map(sfVector2f pos)
{
    if (pos.x < 0) {
        pos.x = 0;
        return (1);
    }
    if (pos.y < 0) {
        pos.y = 0;
        return (1);
    }
    if (pos.x > my_strlen(rpg->d_map[0][0]) * 128) {
        pos.x = my_strlen(rpg->d_map[0][0]) * 128;
        return (1);
    }
    if (pos.y > nb_line(rpg->d_map[0]) * 128) {
        pos.y = nb_line(rpg->d_map[0]) * 128;
        return (1);
    }
    return (0);
}
