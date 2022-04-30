/*
** EPITECH PROJECT, 2022
** B-MUL-100-NCY-1-1-myrunner-antoine.khalidy
** File description:
** scene_management
*/

#include "../include/my.h"
#include "../include/myrunner.h"

void scene_management(runner_t *runner, linked_list *game)
{
    switch (runner->scene) {
        case (0):
            menu_draw(runner);
            break;
        case (1):
            character_menu_draw(runner);
            break;
        case (2):
            game_draw_ichigo(runner, game);
            break;
        case (3):
            game_draw_toshiro(runner, game);
            break;
        case (4):
            win_draw(runner);
            break;
        case (5):
            lose_draw(runner);
            break;
    }
}
