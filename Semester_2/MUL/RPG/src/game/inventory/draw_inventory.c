/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-antoine.khalidy
** File description:
** draw_inventory
*/

#include "rpg.h"

void draw_inventory(void)
{
    sfView_setCenter(rpg->info->view, (sfVector2f) {960, 540});
    sfView_setViewport(rpg->info->view, (sfFloatRect) {0, 0, 1, 1});
    sfRenderWindow_setView(rpg->window, rpg->info->view);
    DRAW_SPRITE(rpg->window, rpg->inventory->image[0]->sprite);
    DRAW_SPRITE(rpg->window, rpg->inventory->image[5]->sprite);
    DRAW_SPRITE(rpg->window, rpg->inventory->image[6]->sprite);
    DRAW_SPRITE(rpg->window, rpg->inventory->image[1]->sprite);
    DRAW_SPRITE(rpg->window, rpg->inventory->image[2]->sprite);
    if (rpg->inventory->have_key)
        DRAW_SPRITE(rpg->window, rpg->inventory->image[3]->sprite);
    DRAW_SPRITE(rpg->window, rpg->inventory->image[4]->sprite);
}
