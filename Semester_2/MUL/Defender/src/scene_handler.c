/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** scene_handler
*/

#include "../include/defender.h"

void scene_handler(defender_t *defender, map_t *game)
{
    switch (defender->scene) {
        case (MENU):
            draw_menu(defender);
            break;
        case (GAME):
            draw_game(defender, game);
            break;
        case (SETTINGS):
            draw_settings(defender);
            break;
        case (TUTO):
            draw_tuto(defender);
            break;
        case (PAUSE):
            draw_pause(defender);
            break;
    }
    sfRenderWindow_display(defender->wdw);
}
