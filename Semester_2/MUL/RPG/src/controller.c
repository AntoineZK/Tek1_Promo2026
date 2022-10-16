/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-antoine.khalidy
** File description:
** controller
*/

#include "rpg.h"

void check_controller(void)
{
    if (sfJoystick_isConnected(0)) {
        rpg->controller = JOYSTICK;
        my_putstr("Joystick connected\n");
    } else
        rpg->controller = KEYBOARD;
}
