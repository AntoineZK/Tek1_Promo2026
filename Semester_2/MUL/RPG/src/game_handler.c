/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-antoine.khalidy
** File description:
** game_handler
*/

#include "rpg.h"

void game_handler(void)
{
    if (rpg->scene == 0) {
        sfRenderWindow_clear(rpg->window, sfBlack);
        draw_game();
        draw_info();
        draw_minimap();
    } else if (rpg->scene == 1) {
        draw_inventory();
    }
}
