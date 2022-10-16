/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-antoine.khalidy
** File description:
** fight_joystick
*/

#include "rpg.h"

void joystick_sword(void)
{
    if (sfJoystick_isButtonPressed(0, rpg->joy->attack) &&
    !rpg->player->attack_mode) {
        for (int dir = 0; dir < 4; dir++) {
            rpg->player->status == dir && rpg->player->is_able[SWORD] ?
            rpg->player->is_able[SWORD] = 2, rpg->player->sword[dir] = 1 : 0;
        }
    }
}

void joystick_bow(void)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(rpg->window);
    sfVector2f mouse_pos_f = {0, 0};

    rpg->joy->joy2.x > 0 ? mouse_pos.x += 5 : 0;
    rpg->joy->joy2.x < 0 ? mouse_pos.x -= 5 : 0;
    rpg->joy->joy2.y > 0 ? mouse_pos.y += 5 : 0;
    rpg->joy->joy2.y < 0 ? mouse_pos.y -= 5 : 0;
    sfMouse_setPositionRenderWindow(mouse_pos, rpg->window);
    mouse_pos_f = sfRenderWindow_mapPixelToCoords(rpg->window, mouse_pos,
    rpg->view);
    if (sfJoystick_isButtonPressed(0, rpg->joy->attack) &&
    rpg->player->attack_mode && rpg->controller == JOYSTICK) {
        if (rpg->player->is_able[BOW] == 1) {
            rpg->player->is_able[BOW] = 0;
            rpg->player->arrow = arrow_create(rpg->player->pos, mouse_pos_f);
        }
    }
}
