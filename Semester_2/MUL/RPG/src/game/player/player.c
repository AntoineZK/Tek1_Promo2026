/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-antoine.khalidy
** File description:
** player
*/

#include "rpg.h"

static void player_bow(void)
{
    float rot = sfSprite_getRotation(rpg->player->arrow->obj->sprite);

    if (((rot >= 0 && rot < 45) || (rot >= 315 && rot < 360)) &&
    rpg->player->is_able[BOW] == 0)
        bow(RIGHT);
    if ((rot >= 135 && rot <= 225) && rpg->player->is_able[BOW] == 0)
        bow(LEFT);
    if ((rot >= 45 && rot < 135) && rpg->player->is_able[BOW] == 0)
        bow(DOWN);
    if ((rot > 225 && rot < 315) && rpg->player->is_able[BOW] == 0)
        bow(UP);
}

static void player_dash(int i)
{
    if (rpg->player->status == i && rpg->player->is_dash[i])
        dash(i);
}

static void player_normal(int i)
{
    if (rpg->player->status == i && rpg->player->is_anim[i])
        animation_player(rpg->player->image[i], 1024);
    else if (rpg->player->status == i && !rpg->player->is_anim[i]) {
        rpg->player->rect = (sfIntRect) {128, 0, 128, 128};
        sfSprite_setTextureRect(rpg->player->image[i]->sprite,
        rpg->player->rect);
        DRAW_SPRITE(rpg->window, rpg->player->image[i]->sprite);
    }
}

static void player_sword(int i)
{
    if (rpg->player->status == i && rpg->player->sword[i] &&
    rpg->player->is_able[SWORD] == 2) {
        sword(i);
    }
}

void player_draw(void)
{
    if (!rpg->player->is_dash[UP] && !rpg->player->is_dash[DOWN] &&
    !rpg->player->is_dash[LEFT] && !rpg->player->is_dash[RIGHT] &&
    !rpg->player->sword[UP] && !rpg->player->sword[DOWN] &&
    !rpg->player->sword[LEFT] && !rpg->player->sword[RIGHT] &&
    rpg->player->is_able[BOW])
        for (int i = 0; i <= 3; ++i)
            player_normal(i);
    if (!rpg->player->sword[UP] && !rpg->player->sword[DOWN] &&
    !rpg->player->sword[LEFT] && !rpg->player->sword[RIGHT])
        for (int i = 0; i <= 3; ++i)
            player_dash(i);
    if (rpg->player->is_able[BOW] == 0) {
            player_bow();
    } else {
        for (int i = 0; i <= 3; ++i) {
            player_sword(i);
        }
    }
}
