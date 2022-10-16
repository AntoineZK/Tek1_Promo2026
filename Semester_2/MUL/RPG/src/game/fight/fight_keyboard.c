/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-antoine.khalidy
** File description:
** fight
*/

#include "rpg.h"

void keyboard_sword(void)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) && !rpg->player->attack_mode) {
        for (int dir = 0; dir < 4; dir++) {
            rpg->player->status == dir && rpg->player->is_able[SWORD] ?
            rpg->player->is_able[SWORD] = 2, rpg->player->sword[dir] = 1 : 0;
            rpg->player->status == dir && rpg->player->is_able[SWORD] ?
            player_attack_touch(rpg->player) : 0;
        }
    }
}

int choose_mode(void)
{
    if ((rpg->event.type == sfEvtKeyPressed && rpg->event.key.code ==
    rpg->options->keys[ARROW_KEY] && rpg->controller == KEYBOARD) ||
    (rpg->event.type == sfEvtJoystickButtonPressed &&
    rpg->event.joystickButton.button == (unsigned) rpg->joy->mode
    && rpg->controller == JOYSTICK)) {
        if (rpg->player->attack_mode) {
            my_putstr("Mode SWORD\n");
            rpg->player->attack_mode = 0;
            return (1);
        }
        if (!rpg->player->attack_mode) {
            my_putstr("Mode BOW\n");
            rpg->player->attack_mode = 1;
            return (1);
        }
    }
    return (0);
}

void keyboard_bow(void)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(rpg->window);
    sfVector2f mouse_pos = sfRenderWindow_mapPixelToCoords(rpg->window,
    mouse, rpg->view);

    if (sfMouse_isButtonPressed(sfMouseLeft) && rpg->player->attack_mode
    && rpg->controller == KEYBOARD) {
        if (rpg->player->is_able[BOW] == 1) {
            rpg->player->is_able[BOW] = 0;
            rpg->player->arrow = arrow_create(rpg->player->pos, mouse_pos);
        }
    }
}
