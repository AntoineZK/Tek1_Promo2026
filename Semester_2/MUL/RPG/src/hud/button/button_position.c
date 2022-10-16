/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-mydefender-tom.pierron
** File description:
** button_position
*/

#include "hud/button.h"

void button_set_position(button *button, int x, int y)
{
    button->position.x = x;
    button->position.y = y;
    sfSprite_setPosition(button->sprite, button->position);
}

void button_move(button *button, int x, int y)
{
    button->position.x += x;
    button->position.y += y;
    sfSprite_setPosition(button->sprite, button->position);
}
