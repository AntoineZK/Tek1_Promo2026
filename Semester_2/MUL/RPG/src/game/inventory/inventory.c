/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-antoine.khalidy
** File description:
** inventory
*/

#include "rpg.h"

int activate_inventory(void)
{
    if ((rpg->event.type == sfEvtKeyPressed && rpg->event.key.code ==
    rpg->options->keys[INVENTORY_KEY]) ||
    (rpg->event.type == sfEvtJoystickButtonPressed &&
    rpg->event.joystickButton.button == (unsigned) rpg->joy->inventory)) {
        if (rpg->scene == 0) {
            rpg->scene = 1;
            return (1);
        }
        if (rpg->scene == 1) {
            rpg->scene = 0;
            return (1);
        }
    }
    return (0);
}
