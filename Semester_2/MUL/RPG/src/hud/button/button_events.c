/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-mydefender-tom.pierron
** File description:
** button_events
*/

#include "hud/button.h"
#include "rpg.h"

int button_is_clicked(button *button, int mouse_x, int mouse_y)
{
    if (button->disable || !button->callback)
        return (1);
    if (mouse_x >= button->position.x &&
    mouse_x <= button->position.x + button->size.x) {
        if (mouse_y >= button->position.y &&
        mouse_y <= button->position.y + button->size.y)
            return (button->callback(button->args));
    }
    return (1);
}

void button_is_hover(button *button, int mouse_x, int mouse_y)
{
    if (button->disable)
        return;
    if (mouse_x >= button->position.x &&
    mouse_x <= button->position.x + button->size.x) {
        if (mouse_y >= button->position.y &&
        mouse_y <= button->position.y + button->size.y)
            button->hover = sfTrue;
    }
    button->hover = sfFalse;
}
