/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** player_event
*/

#include "rpg.h"

void player_joystick(void)
{
    if (rpg->player->is_able[SWORD] == 2)
        return;
    rpg->joy->joy1.x = sfJoystick_getAxisPosition(0, sfJoystickX);
    rpg->joy->joy1.y = sfJoystick_getAxisPosition(0, sfJoystickY);
    rpg->joy->joy2.x = sfJoystick_getAxisPosition(0, sfJoystickU);
    rpg->joy->joy2.y = sfJoystick_getAxisPosition(0, sfJoystickV);
    move_joystick();
    dash_joystick();
    if (sfJoystick_isButtonPressed(0 , rpg->joy->minimap)) {
        rpg->mini_map->rect = (sfFloatRect) {0.20f , 0.20f, 0.60f, 0.60f};
    } else if (!sfJoystick_isButtonPressed(0 , rpg->joy->minimap))
        rpg->mini_map->rect = (sfFloatRect) {0.75f, 0, 0.25f, 0.25f};
    joystick_sword();
    joystick_bow();
    sfJoystick_update();
}

void player_keyboard(void)
{
    if (rpg->player->is_able[SWORD] == 2)
        return;
    move_keyboard();
    dash_keyboard();
    if (sfKeyboard_isKeyPressed(rpg->options->keys[MINIMAP_KEY])) {
        rpg->mini_map->rect = (sfFloatRect) {0.20f , 0.20f, 0.60f, 0.60f};
    } else if (!sfKeyboard_isKeyPressed(rpg->options->keys[MINIMAP_KEY]))
        rpg->mini_map->rect = (sfFloatRect) {0.75f, 0, 0.25f, 0.25f};
    keyboard_sword();
    keyboard_bow();
}

void player_event(void)
{
    if (rpg->player->is_talking)
        return;
    if (rpg->controller == JOYSTICK)
        player_joystick();
    if (rpg->controller == KEYBOARD)
        player_keyboard();
}
